
#include "oscar.h"
#include "Hilaris.h"
#include "StreamServer.h"
#include "Image.h"
#include "BGRImageFactory.h"
#include "DebayerBGRFast.h"

#include "GreyscaleImageFactory.h"
#include "DebayerGreyscaleFast.h"
#include "DebayerBGRBilinear.h"

int main(){
	
	Hilaris hilaris;
	hilaris.setConsoleLogLevel(DEBUG);
	
	// create a red image
	GreyscaleImage img = GreyscaleImageFactory::create(16, 16, 128);
	
	// save
	img.save("grey.bmp");
	
	return 0;
}
