#include "Hilaris.h"

int main(){

	Hilaris hilaris;
	hilaris.setConsoleLogLevel(DEBUG);
	
	Camera* cam = hilaris.getCamera(new DebayerGreyscaleFast());
	GreyscaleImage* raw = (GreyscaleImage* )cam->captureImage();
	
	raw->histogram()->equalize();
	raw->save("../hilaris/examples/images/histogram.bmp");
	
	return 0;
}
