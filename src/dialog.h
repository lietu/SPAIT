/**
 * @file window.h
 * Header for the Window class
 *
 * Copyright (C) 2012 Janne Enberg aka. Lietu
 * Distributed with new BSD and MIT licenses.
 */

#ifndef WINDOW_H
#define WINDOW_H

#include <QSystemTrayIcon>
#include <QDialog>
#include <QtGui>
#include <QSound>

QT_BEGIN_NAMESPACE
class QAction;
class QLabel;
class QMenu;
QT_END_NAMESPACE

namespace SPAIT {
	class Dialog : public QDialog
	{
		Q_OBJECT

		public:
			Dialog();
			void setup(void);
			void setVisible(bool);

		protected:
			void closeEvent(QCloseEvent*);
			void playSound(void);

		protected slots:
			void trayClick(QSystemTrayIcon::ActivationReason);

		protected:
			void createMessageGroupBox(void);
			void createActions(void);
			void setTrayIcon(void);

			QLabel* aboutText;

			QAction *aboutAction;
			QAction *quitAction;

			QSystemTrayIcon *trayIcon;
			QMenu *trayIconMenu;
			QSound* sound;
	};
}

#endif
