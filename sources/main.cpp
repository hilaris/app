
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
	BinaryImage bin = BinaryImageFactory::getFastDebayered(img);
	
	bin.save("meep_before.bmp");
	
	bin.erode(&DISK8);
	
	bin.save("meep_eroded.bmp");
	
	BinaryImage bin2 = BinaryImageFactory::getFastDebayered(img);
	bin2.dilate(&DISK8);
	
	bin2.save("meep_dilated.bmp");

	
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
