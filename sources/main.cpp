#include "Hilaris.h"

int main(){
	
	Hilaris hilaris;
	hilaris.setConsoleLogLevel(DEBUG);
	
	// create a red image
	BGRImage img = BGRImageFactory::create(16, 16, 150, 150, 255);
	
	// save
	img.save("pink.bmp");
	
	return 0;
}
