#include "Hilaris.h"

int main(){

	Hilaris hilaris;
	hilaris.setConsoleLogLevel(Debug::NONE);
		
	Camera* camera = hilaris.getCamera(new DebayerBGRHalfsize());//new DebayerGreyscaleFast()); //new DebayerBinaryDirect(120));
	
	//camera->addFrameProcessor(new FigureDetector(&hilaris));
	camera->setAutoExposure(true);
	
	
	StreamServer srv(camera);
	srv.start();
	
	return 0;
}
