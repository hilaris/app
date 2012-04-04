
#include "oscar.h"
#include "Hilaris.h"
#include "StreamServer.h"
#include "Image.h"
#include "BinaryImageFactory.h"
#include "GreyscaleImageFactory.h"
#include "BGRImageFactory.h"
#include "BinaryImageFactory.h"
#include "DebayerBGRFast.h"

int main(){
	
	Hilaris hilaris;
	hilaris.setConsoleLogLevel(DEBUG);
		
	Camera* camera = hilaris.getCamera(OSC_PICTURE_GREYSCALE);
	camera->setAutoExposure(true);	
	
	RawImage* img  = (RawImage*)camera->captureImage();
	
	BGRImage i(img->getWidth()/2, img->getHeight()/2);
	DebayerBGRFast debayer;
	
	if(debayer.debayer(img, &i))
	{
		i.save("debayered.bmp");	
	}
	else
	{
		printf("failed\n");
	}
	

	//bin.save("meep_centroid.bmp");
	
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
