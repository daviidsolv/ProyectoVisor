#include "tigr/tigr.h"
#include "GUIICONS.h"

void printIcon(Tigr *screen, char filename[], char iconName[], int x, int y) {

    // Load our sprite.
	Tigr *icono = tigrLoadImage(filename);
	if (!icono)
		tigrError(0, "Cannot load icono");
    
    tigrBlitAlpha(screen, icono, x*40, y*40, 0, 0, icono->w, icono->h, 1.0f);
    tigrPrint(screen, tfont, (x*40), (y*40)+32, tigrRGB(0x00, 0x00, 0x00), iconName);

    tigrFree(icono);
}
