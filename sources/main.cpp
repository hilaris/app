
#include "Hilaris.h"
#include "StreamServer.h"

int main(){
	
	Hilaris hilaris;
	
	hilaris.setConsoleLogLevel(DEBUG);
	hilaris.setFileLogLevel(NONE);
	
	Camera* camera = hilaris.getCamera();
	Image*  image = camera->captureImage();
		
	image->save("foo.bmp");
	
	return 0;
}
