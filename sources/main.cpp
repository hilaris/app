#include "Hilaris.h"
#include "processors/RandomBoxes.h"

int main(){
	
	Hilaris hilaris;
	hilaris.setConsoleLogLevel(DEBUG);	
	
	Camera* cam = hilaris.getCamera(new DebayerGreyscaleFast());
	cam->setAutoExposure(true);	
	cam->addFrameProcessor(new RandomBoxes());

	StreamServer s(cam);
	
	s.start();
	
	return 0;
}
