/**
 * @file spait.cpp
 * Code for the SPAIT class
 *
 * Copyright (C) 2012 Janne Enberg aka. Lietu
 * Distributed with new BSD and MIT licenses.
 */

// Include the header
#include "spait.h"


/**
	SPAIT constructor
*/
SPAIT::SPAIT::SPAIT(int argc, char *argv[]) {

	// Create the application instance
	this->app = new QApplication(argc, argv);

	// Create the "dialog" that will actually be the Qt application
	this->dialog = new Dialog();

}

/**
	Destructor
*/
SPAIT::SPAIT::~SPAIT() {

	// Destroy the "dialog"
	delete this->dialog;

	// Destroy the application
	delete this->app;

}


/**
	Start the application

	@param[in] argc The number or arguments given
	@param[in] argv The arguments array
	@returns Exit code for the application
*/
int SPAIT::SPAIT::run() {

	// Make sure system tray is actually available
	if (!QSystemTrayIcon::isSystemTrayAvailable()) {

		QMessageBox::critical(0, QObject::tr("SPAIT"), QObject::tr("Qt doesn't support system tray on this system."));

		return 1;
	}

	// Make sure we don't quit when the last window is closed
	QApplication::setQuitOnLastWindowClosed(false);

	// Set up the "dialog"
	this->dialog->setup();

	// Run the application, return the exit code from it
	return this->app->exec();
}
