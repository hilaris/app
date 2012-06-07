#include "Hilaris.h"

int main(int argc, const char* argv[])
{
	Hilaris hilaris;
	
	//write your code here and have fun ;) hilari(ou)s...isn't it?
	
	Camera* cam = hilaris.getCamera(new DebayerGreyscaleFast());
	
	Image* img = cam->captureImage();

	((GreyscaleImage*)img)->sobel(7);
	
	img->save("sobel.bmp");
	
	return 0;	
}
