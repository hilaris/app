
#include "Hilaris.h"
#include "StreamServer.h"
#include "Image.h"

int main(){
	
	Hilaris hilaris;
	
	hilaris.setConsoleLogLevel(DEBUG);
	
	Camera* camera = hilaris.getCamera();
	//Image*  image = camera->captureImage();
	
	//image->toGreyscale();
	
	//image->save("foo.bmp");
	
	StreamServer srv(camera);
	
	srv.start();
	
	while(1);
	
	return 0;
}
