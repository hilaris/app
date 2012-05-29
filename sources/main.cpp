#include "Hilaris.h"

int main(){
	Hilaris hilaris;
	hilaris.setConsoleLogLevel(Debug::NONE);
	
	//OscCreate(&OscModule_dspl);
	
	Camera* camera = hilaris.getCamera(new DebayerBGRHalfsize());//new DebayerGreyscaleFast()); //new DebayerBinaryDirect(120));
	
	//camera->addFrameProcessor(new FigureDetector(&hilaris));
	camera->setAutoExposure(true);
	
	Image* image = camera->captureImage();
	
	image->save("blupp.bmp");
	
	StreamServer srv(camera);
	srv.start();
	
	return 0;
}
