#include "Hilaris.h"
#include "processors/FingertipDetection.h"
#include "processors/BallProcessor.h"

int main(){
	
	Hilaris hilaris;
	hilaris.setConsoleLogLevel(INFO);	

	Camera* cam = hilaris.getCamera(new DebayerGreyscaleFast());
	cam->setAutoExposure(true);

	cam->addFrameProcessor(new FingertipDetection());
	cam->addFrameProcessor(new BallProcessor());
	
	StreamServer s(cam);
	s.start();

	return 0;
}
