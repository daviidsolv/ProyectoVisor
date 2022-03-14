#include "tigr/tigr.h"
#include "icons.h"
#include <string.h>

void printIcon(Tigr *screen, char filename[], char iconName[], int x, int y) {

    //char file[] = "./icons/";
    //strcat(file, filename);

    // Load our sprite.
	Tigr *icono = tigrLoadImage(filename);
	if (!icono)
		tigrError(0, "Cannot load icono");
    
    tigrBlitAlpha(screen, icono, x*32, y*40, 0, 0, icono->w, icono->h, 1.0f);
    tigrPrint(screen, tfont, (x*32), (y*36)+32, tigrRGB(0x00, 0x00, 0x00), iconName);
}
