
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
		
	Camera* camera = hilaris.getCamera();
	camera->setAutoExposure(true);	
	
	BGRImage* img  = (BGRImage*)camera->captureImage();

	img->save("debayered.bmp");	

	

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
