#include "Hilaris.h"
//#include "processors/EdgeProcessor.h"

int main(){
	
	Hilaris hilaris;
	hilaris.setConsoleLogLevel(DEBUG);	

	ov_init();

	Camera* cam = hilaris.getCamera(new DebayerGreyscaleFast());
	cam->setAutoExposure(false);	
	
	GreyscaleImage* grey = (GreyscaleImage*) cam->captureImage();
	
	grey->save("warning.bmp");
	
	return 0;
}
