
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
	BGRImage bin = BGRImageFactory::getFastDebayered(img);
	
	for(int i = 0; i < bin.getHeight(); i ++)
	{
		for(int j = 0; j < bin.getWidth(); j ++)
		{
			if(j % 3 == 0)
			{
				bin(i, j) = 255;
			}
			else
			{
				bin(i, j) = 0;
			}
		}
	}
	
	bin.save("meep.bmp");

	
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
