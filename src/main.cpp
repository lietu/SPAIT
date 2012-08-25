/**
 * @file main.cpp
 * Main file for the SPAIT project
 *
 * Copyright (C) 2012 Janne Enberg aka. Lietu
 * Distributed with new BSD and MIT licenses.
 */

// Include SPAIT class
#include "spait.h"


/**
	Main entrypoint for the application

	@param[in] argc The number or arguments given
	@param[in] argv The arguments array
	@returns Exit code for the application
*/
int main(int argc, char *argv[]) {
	// Create instance of the SPAIT class
	SPAIT::SPAIT* spait = new SPAIT::SPAIT(argc, argv);

	// Run it and catch whatever it returns
	int exitCode = spait->run();

	// Destroy SPAIT
	delete spait;

	// Return the exit code
	return exitCode;
}
