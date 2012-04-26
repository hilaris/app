#include "Hilaris.h"

int main(){

	Hilaris hilaris;
	hilaris.setConsoleLogLevel(DEBUG);
	
	DebayerBinaryDirect* db = new DebayerBinaryDirect();
	
	db->setThreshold(150);
	
	Camera* cam = hilaris.getCamera(db);
	BinaryImage* raw = (BinaryImage* )cam->captureImage();
	
	raw->invert();
	raw->save("../hilaris/examples/images/inverted.bmp");
	
	return 0;
}
