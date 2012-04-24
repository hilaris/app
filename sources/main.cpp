#include "Hilaris.h"
#include "processors/FingertipDetection.h"

int main(){
	
	Hilaris hilaris;
	hilaris.setConsoleLogLevel(INFO);	
	
	Camera* cam = hilaris.getCamera(new DebayerBinaryDirect());
	
	cam->setAutoExposure(false);
	cam->addFrameProcessor(new FingertipDetection());
	
	StreamServer s(cam);
	s.start();

	return 0;
}
