/**
 * @file window.cpp
 * Code for the Window class
 *
 * Copyright (C) 2012 Janne Enberg aka. Lietu
 * Distributed with new BSD and MIT licenses.
 */


#include "dialog.h"

SPAIT::Dialog::Dialog(void) {

	// Create the about action
	this->aboutAction = new QAction(tr("&About"), this);
	connect(this->aboutAction, SIGNAL(triggered()), this, SLOT(show()));

	// Create the quit action
	this->quitAction = new QAction(tr("&Quit"), this);
	connect(this->quitAction, SIGNAL(triggered()), qApp, SLOT(quit()));

	// Set the main window title
	this->setWindowTitle(tr("About SPAIT"));

	// Create the about text
	this->aboutText = new QLabel();
	this->aboutText->setTextFormat(Qt::RichText);
	this->aboutText->setText(
		"<h1>SPAIT</h1>"
		"<p>"
			"S/PDIF Anti-Idle Tool"
		"</p>"
		"<p>"
			"This tool will sit in your tray and generate a" "<br>"
			"constant very low volume noise to keep digital" "<br>"
			"sound devices from detecting the lack of sound and going" "<br>"
			"into stand-by mode."
		"</p>"
		"<p>"
			"Created by Janne Enberg aka. Lietu" "<br>"
			"find out more by visiting "
			"<a href='http://lietu.net/' name=\"Lietu's homepage\">lietu.net</a>"
		"</p>"
	);


	// Create the main window layout, which will only have the about text
	QVBoxLayout *mainLayout = new QVBoxLayout;
	mainLayout->addWidget(this->aboutText);
	this->setLayout(mainLayout);

	// Set the window size
	this->resize(200, 200);

	// Hide the main window by default
	// .. no-one wants to look at that thing
	this->setVisible(false);
}

void SPAIT::Dialog::setup(void) {

	// Create and display the tray icon
	this->setTrayIcon();

	// Start playing our sound
	this->playSound();

}

void SPAIT::Dialog::setVisible(bool visible) {
	QDialog::setVisible(visible);
}

void SPAIT::Dialog::closeEvent(QCloseEvent *event) {
	if (this->trayIcon->isVisible()) {
		this->hide();
		event->ignore();
	}
}

/**
	Handler for when the tray icon is activated
*/
void SPAIT::Dialog::trayClick(QSystemTrayIcon::ActivationReason reason) {
	switch (reason) {
		case QSystemTrayIcon::Trigger:
		case QSystemTrayIcon::DoubleClick:
			this->setVisible(true);
			break;
		default:
			;
	}
}

/**
	Set up the tray icon
*/
void SPAIT::Dialog::setTrayIcon(void) {

	// Create the tray icon menu
	this->trayIconMenu = new QMenu(this);
	this->trayIconMenu->addAction(this->aboutAction);
	this->trayIconMenu->addSeparator();
	this->trayIconMenu->addAction(this->quitAction);

	// Create the tray icon, set the menu, and icon
	this->trayIcon = new QSystemTrayIcon(this);
	this->trayIcon->setContextMenu(this->trayIconMenu);
	this->trayIcon->setIcon(QIcon(":/icon/sound.svg"));

	// Listen to clicks on the tray icon
	this->connect(
		this->trayIcon,
		SIGNAL(activated(QSystemTrayIcon::ActivationReason)),
		this,
		SLOT(trayClick(QSystemTrayIcon::ActivationReason))
	);


	// And now show it
	this->trayIcon->show();
}

/**
	Start playing the sound
*/
void SPAIT::Dialog::playSound(void) {

	// Path to our sound file
	QString soundFile(QApplication::applicationDirPath());
	soundFile.append("/sound/sound.wav");

	// Create the sound, looping infinitely
	this->sound = new QSound(soundFile);
	this->sound->setLoops(-1);

	// And play it
	this->sound->play();
}
