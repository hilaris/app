
#include "oscar.h"
#include "Hilaris.h"
#include "StreamServer.h"
#include "Image.h"
#include "BinaryImageFactory.h"
#include "GreyscaleImageFactory.h"
#include "BGRImageFactory.h"

int main(){
	
	Hilaris hilaris;
	hilaris.setConsoleLogLevel(DEBUG);
		
	Camera* camera = hilaris.getCamera(OSC_PICTURE_GREYSCALE);
	camera->setAutoExposure(true);	
	
	RawImage* img  = camera->captureImage();
	GreyscaleImage grey = GreyscaleImageFactory::getFastDebayered(img);
	
	if(!grey.filter(&MEDIAN5X5))
	{
		OscLog(DEBUG, "FOOOOOOOOOOOOOOOO!!!!!");
	}
	
	grey.save("meep.bmp");

	
	//Image* image = camera->captureImage();
	
	//image->toGreyscale();
	
	//image->save("foo.bmp");
	
	//StreamServer srv(camera);
	
	//srv.start();
	
	//while(1);

	//GreyscaleImage GreyscaleImageFactory::getVectorDebayered(RawImage* raw)
	//GreyscaleImage GreyscaleImageFactory::getHalfsizeDebayered(RawImage* raw)
	
	return 0;
}
