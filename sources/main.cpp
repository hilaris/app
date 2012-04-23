#include "Hilaris.h"
#include "processors/RandomBoxes.h"

int main(){
	
	Hilaris hilaris;
	hilaris.setConsoleLogLevel(DEBUG);	

	ov_init();

	Camera* cam = hilaris.getCamera(new DebayerBGRFast());
	cam->setAutoExposure(true);	
	cam->addFrameProcessor(new RandomBoxes());

	StreamServer s(cam);
	
	s.start();
	
	return 0;
}
