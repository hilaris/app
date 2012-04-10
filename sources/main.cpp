#include "Hilaris.h"

int main(){
	
	Hilaris hilaris;
	hilaris.setConsoleLogLevel(DEBUG);
	
	Camera* cam = hilaris.getCamera(0, 0, 100, 100, new DebayerBGRFast());
	
	BGRImage* bgr = (BGRImage*)cam->captureImage();
	
	// save
	bgr->save("aoi.bmp");
	
	return 0;
}
