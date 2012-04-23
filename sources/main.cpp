#include "Hilaris.h"


int main(){
	
	Hilaris hilaris;
	hilaris.setConsoleLogLevel(DEBUG);
	

	Camera* cam = hilaris.getCamera(new DebayerGreyscaleFast());
	cam->setAutoExposure(true);	
	cam->addFrameProcessor(new EdgeProcessor());
	
	Image* img = cam->captureImage();
	
	Text* t = new Text(10,10,1,"blupp", 0x0000FF, 0x000000);
	
	t.draw(img);
	
	img->save("text.bmp");
	
	return 0;
}
