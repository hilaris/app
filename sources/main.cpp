#include "Hilaris.h"
#include "processors/EdgeProcessor.h"

int main(){
	
	Hilaris hilaris;
	hilaris.setConsoleLogLevel(DEBUG);	

	ov_init();

	Camera* cam = hilaris.getCamera(new DebayerBinaryDirect());
	cam->setAutoExposure(false);	
	cam->addFrameProcessor(new EdgeProcessor());

	StreamServer s(cam);
	
	s.start();
	
	return 0;
}
