#include "Hilaris.h"

int main(){

	Hilaris hilaris;
	hilaris.setConsoleLogLevel(DEBUG);
	
	Camera* cam = hilaris.getCamera(new DebayerBinaryDirect());
	BinaryImage* raw = (BinaryImage* )cam->captureImage();
	
	raw->save("../hilaris/examples/images/binary.bmp");
	
	return 0;
}
