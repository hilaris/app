#include "Hilaris.h"

int main(){

	Hilaris hilaris;
	hilaris.setConsoleLogLevel(DEBUG);	

	Camera* cam = hilaris.getCamera(new DebayerBinaryDirect());
	RawImage* raw = (RawImage* )cam->captureImage();
	
	raw->save("../hilaris/examples/images/binary.bmp");
	
	return 0;
}
