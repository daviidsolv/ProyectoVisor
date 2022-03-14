#include "tigr/tigr.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "icons.h"
#include <iostream>

using namespace std;


Tigr *backdrop, *screen;


int main(int argc, char *argv[])
{	
	
	// Make a window and an off-screen backdrop.
	screen = tigrWindow(320, 200, "GUI", 0);
	backdrop = tigrBitmap(screen->w, screen->h);

	// Fill in the background.
	tigrClear(backdrop, tigrRGB(255,255,255));
	
    // Repeat till they close the window.
	while (!tigrClosed(screen) && !tigrKeyDown(screen, TK_ESCAPE))
	{
		
	
		// Composite the GUI
		tigrBlit(screen, backdrop, 0,0,0,0, backdrop->w, backdrop->h);
		//dibuja el icono y texto
		printIcon(screen, "./icons/audio.png", "test icon", 0, 1);
		printIcon(screen, "./icons/internet.png", "test icon", 0, 2);
		printIcon(screen, "./icons/audio.png", "test icon2", 0, 0);


		// Update the window.
		tigrUpdate(screen);
	}

	tigrFree(backdrop);
	tigrFree(screen);
	return 0;
}
