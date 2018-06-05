const electron = require('electron');
const url = require('url');
const path = require('path');

const {app, BrowserWindow, Menu, ipcMain} = electron;

// SET env
// process.env.NODE_ENV = 'production';

let mainWindow;
let addWindow;

// Listen for the app to be reader
app.on('ready', function(){
	// Create New Window
	mainWindow = new BrowserWindow({});
	// Load html file into the Window
	mainWindow.loadURL(url.format({
		pathname: path.join(__dirname, 'oui.html'),
		protocol: 'file:',
		slashes: true
	}));

	// Quit app when closed
	mainWindow.on('closed', () => {app.quit()});
	//Garbage collection Handle
	// BUild menu from template
	const mainMenu = Menu.buildFromTemplate(mainMenuTemplate);
	// Insert menu
	Menu.setApplicationMenu(mainMenu);

});

// Handle create add window
function createAddWindow(){
	// Create New Window
	addWindow = new BrowserWindow({
		width: 300,
		height: 200,
		title: 'Add SHhopping list Item'
	});
	// Load html file into the Window
	addWindow.loadURL(url.format({
		pathname: path.join(__dirname, 'addWindow.html'),
		protocol: 'file:',
		slashes: true
	}));

	addWindow.on('close', function(){
		addWindow = null;
	});
}

//	Catch item:add
ipcMain.on('item:add', function(e, item){
	mainWindow.webContents.send('item:add', item);
	addWindow.close();
})

// Create menu template
const mainMenuTemplate = [
	{
		label: 'File',
		submenu: [
			{
				label: 'Record'
			},
			{
				label: 'Quit',
				accelerator: process.platform == 'darwin' ? 'Command+Q' : 'Ctrl+Q',
				click(){
					app.quit();
				}
			}
		]

	}
];

// If mac, add empty object to menu

if (process.platform == 'darwin'){
	mainMenuTemplate.unshift({});
}

// Add developer tools item if not in production
if (process.env.NODE_ENV != 'production'){
	mainMenuTemplate.push({
		label: 'Developer Tools',
		submenu: [
			{
				label: 'Toggle DevTools',
				accelerator: process.platform == 'darwin' ? 'Command+I' : 'Ctrl+I',
				click(item, focusedWindow){
					focusedWindow.toggleDevTools();
				}
			},
			{
				role: 'reload'
			}
		]
	});
}




//let addWindow;
