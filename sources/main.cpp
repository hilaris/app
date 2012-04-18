#include "Hilaris.h"

#include "processors/BinaryProcessor.h"

int main(){
	
	Hilaris hilaris;
	hilaris.setConsoleLogLevel(NONE);

	Camera* cam = hilaris.getCamera(new DebayerGreyscaleFast());
	
	cam->setAutoExposure(true);
	//cam->addFrameProcessor(new BinaryProcessor());

	StreamServer s(cam);
	s.start();

	
	return 0;
}
