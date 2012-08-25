/**
 * @file spait.h
 * Header for the SPAIT class
 *
 * Copyright (C) 2012 Janne Enberg aka. Lietu
 * Distributed with new BSD and MIT licenses.
 */

#ifndef SPAIT_H
#define SPAIT_H

// Include the SPAIT's requirements
#include <QtGui>
#include "dialog.h"

namespace SPAIT {
	class SPAIT {
		public:
			// Constructor and destructor
			SPAIT(int, char*[]);
			~SPAIT();

			// Methods
			int run();

		protected:

			// Properties
			QApplication* app;
			Dialog* dialog;
	};
}

#endif // SPAIT_H
