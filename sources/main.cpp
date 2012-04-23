#include "Hilaris.h"

#include "processors/EdgeProcessor.h"



int main(){
	
	Hilaris hilaris;
	hilaris.setConsoleLogLevel(DEBUG);
	
	Camera* cam = hilaris.getCamera(new DebayerGreyscaleFast());
	cam->setAutoExposure(true);	
	cam->addFrameProcessor(new EdgeProcessor());
	
	StreamServerNoThread s(cam);
	
	s.start();
	
	return 0;
}
