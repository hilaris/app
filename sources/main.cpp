#include "Hilaris.h"

int main(){
	
	Hilaris hilaris;
	Camera* camera = hilaris.getCamera(new DebayerBinaryDirect());
	
	BinaryImage* image = (BinaryImage*) camera->captureImage();
	
	image->sobel(2);
	image->save("sobel.bmp");

	
	return 0;
}
