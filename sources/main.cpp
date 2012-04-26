#include "Hilaris.h"

int main(){

	Hilaris hilaris;
	hilaris.setConsoleLogLevel(DEBUG);
	
	DebayerBinaryDirect* db = new DebayerBinaryDirect();
	
	db->setThreshold(150);
	
	Camera* cam = hilaris.getCamera(db);
	BinaryImage* raw = (BinaryImage* )cam->captureImage();
	
	raw->sobel();
	raw->save("../hilaris/examples/images/sobel.bmp");
	
	return 0;
}
