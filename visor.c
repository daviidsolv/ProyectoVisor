#include "tigr/tigr.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "./icons.h"
#include "./parser.h"

#define MAX_ICONS 10

Tigr *backdrop, *screen;


int main(int argc, char *argv[])
{	
	
	readFile();

	int totalIcons = GetTotalIcons();
	printf("Number of icons in xml defined: %d \n", totalIcons);

	struct Icon icons[MAX_ICONS];

	for(int i = 0; i < totalIcons; i++) {
		icons[i] = ReadIcon(i);
		printf("Getting icon: %s , with name: %s at %d : %d\n", icons[i].file, icons[i].text, icons[i].posx, icons[i].posy);
	}

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

		for(int i = 0; i < totalIcons; i++) {
			printIcon(screen, icons[i].file, icons[i].text, icons[i].posx, icons[i].posy);
		}


		// Update the window.
		tigrUpdate(screen);
	}

	tigrFree(backdrop);
	tigrFree(screen);
	return 0;
}
