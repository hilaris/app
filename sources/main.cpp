
#include "Hilaris.h"
#include "StreamServer.h"
#include "Image.h"
#include "BGRImageFactory.h"

int main(){
	
	Hilaris hilaris;
	hilaris.setConsoleLogLevel(DEBUG);
		
	Camera* camera = hilaris.getCamera(OSC_PICTURE_GREYSCALE);
	camera->setAutoExposure(true);	
	
	RawImage* img   = camera->captureImage();
	BGRImage  image = BGRImageFactory::getBilinearDebayered(img);
	
	image.save("meep.bmp");
	
	//Image*  image = camera->captureImage();
	
	//image->toGreyscale();
	
	//image->save("foo.bmp");
	
	//StreamServer srv(camera);
	
	//srv.start();
	
	//while(1);
	
	return 0;
}
