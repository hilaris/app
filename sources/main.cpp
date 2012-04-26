#include "Hilaris.h"

int main(){

	Hilaris hilaris;
	hilaris.setConsoleLogLevel(DEBUG);
		
	Camera* cam = hilaris.getCamera(new DebayerGreyscaleFast());
	BGRImage* raw = (BGRImage* )cam->captureImage();
	
	raw->save("../hilaris/examples/images/greyscale.bmp");
	
	return 0;
}
