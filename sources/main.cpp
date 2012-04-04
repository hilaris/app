
#include "oscar.h"
#include "Hilaris.h"
#include "StreamServer.h"
#include "Image.h"
#include "BGRImageFactory.h"
#include "DebayerBGRStandard.h"

int main(){
	
	Hilaris hilaris;
	hilaris.setConsoleLogLevel(DEBUG);
	
	Camera* camera = hilaris.getCamera(new DebayerBGRStandard());
	camera->setAutoExposure(true);	
	
	while(1)
	{
		BGRImage* img  = (BGRImage*)camera->captureImage();

		img->save("/home/httpd/debayered.bmp");	
		sleep(1);
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
