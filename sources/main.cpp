
#include "oscar.h"
#include "Hilaris.h"
#include "StreamServer.h"
#include "Image.h"
#include "GreyscaleImageFactory.h"
#include "BGRImageFactory.h"
#include "BinaryImageFactory.h"

int main(){
	
	Hilaris hilaris;
	hilaris.setConsoleLogLevel(DEBUG);
		
	Camera* camera = hilaris.getCamera(OSC_PICTURE_GREYSCALE);
	camera->setAutoExposure(true);	
	
	RawImage* img  = camera->captureImage();
	BinaryImage image = BinaryImageFactory::getFastDebayered(img, 90, false);
	
	printf("width %d\n", image.getWidth());
	
	image.save("meepbin.bmp");

	
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
