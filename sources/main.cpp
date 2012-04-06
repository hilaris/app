
#include "oscar.h"
#include "Hilaris.h"
#include "StreamServer.h"
#include "Image.h"
#include "GreyscaleImageFactory.h"
#include "DebayerGreyscaleFast.h"

int main(){
	
	Hilaris hilaris;
	hilaris.setConsoleLogLevel(NONE);
	
	Camera* camera = hilaris.getCamera(new DebayerGreyscaleFast());
	camera->setAutoExposure(true);	
	
	while(1)
	{
		GreyscaleImage* img  = (GreyscaleImage*)camera->captureImage();

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
