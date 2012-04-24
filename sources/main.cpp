#include "Hilaris.h"
#include "processors/FingertipDetection.h"

int main(){
	
	Hilaris hilaris;
	hilaris.setConsoleLogLevel(INFO);	
	
	Camera* cam = hilaris.getCamera(new DebayerBGRFast());
	
	cam->setAutoExposure(false);
	cam->setShutterWidth(10000);
	cam->addFrameProcessor(new FingertipDetection());
	
	StreamServer s(cam);
	s.start();

	return 0;
}
