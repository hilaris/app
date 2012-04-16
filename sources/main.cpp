#include "Hilaris.h"

#include "processors/RegionProcessors.h"

int main(){
	
	Hilaris hilaris;
	hilaris.setConsoleLogLevel(NONE);

	Camera* cam = hilaris.getCamera(new DebayerGreyscaleFast());
	
	cam->addFrameProcessor(new RegionProcessors());

	StreamServer s(cam);
	s.start();
	
	return 0;
}
