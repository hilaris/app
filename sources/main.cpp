#include "Hilaris.h"

#include "processors/BinaryProcessor.h"

int main(){
	
	Hilaris hilaris;
	hilaris.setConsoleLogLevel(DEBUG);
	

	Camera* cam = hilaris.getCamera(new DebayerGreyscaleFast());
	
	cam->addFrameProcessor(new BinaryProcessor());
	
	StreamServer s(cam);
	s.start();
	
	return 0;
}
