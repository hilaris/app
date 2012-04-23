#include "Hilaris.h"

int main(){
	
	Hilaris hilaris;
	hilaris.setConsoleLogLevel(DEBUG);
	
	Camera* cam = hilaris.getCamera(new DebayerGreyscaleFast());
	GreyscaleImage* grey = (GreyscaleImage*)cam->captureImage();
	
	grey->save("not-equalized.bmp");
	
	grey->histogram()->equalize();
	
	grey->save("equalized.bmp");
	
	return 0;
}
