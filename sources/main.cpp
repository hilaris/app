#include "Hilaris.h"
#include "processors/LEDFrameProcessor.h"

int main(){

	Hilaris hilaris;
	hilaris.setConsoleLogLevel(NONE);
	
	Camera* camera = hilaris.getCamera();
	camera->addFrameProcessor(new LEDFrameProcessor(&hilaris));
	
	StreamServer srv(camera);
	srv.start();
	
	return 0;
}
