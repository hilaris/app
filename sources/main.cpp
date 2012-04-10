#include "Hilaris.h"

int main(){
	
	Hilaris hilaris;
	hilaris.setConsoleLogLevel(DEBUG);
	
	// create a red image
	RGBImage img = RGBImageFactory::create(16, 16, 150, 150, 255);
	
	// save
	img.save("rgb.bmp");
	
	return 0;
}
