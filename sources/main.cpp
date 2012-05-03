#include "Hilaris.h"
#include "processors/FigureDetector.h"

int main(){

	Hilaris hilaris;
	hilaris.setConsoleLogLevel(Debug::NONE);
		
	Camera* camera = hilaris.getCamera();//new DebayerGreyscaleFast()); //new DebayerBinaryDirect(120));
	
	//camera->addFrameProcessor(new FigureDetector(&hilaris));
	camera->setAutoExposure(false);
	
	StreamServer srv(camera);
	srv.start();
	
	return 0;
}
