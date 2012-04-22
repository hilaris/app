#include "Hilaris.h"

#include "processors/RegionProcessors.h"

int main(){
	
	Hilaris hilaris;
	
	printf("version %s\n", hilaris.getOscarVersion());
	
	hilaris.setConsoleLogLevel(DEBUG);
	
	Camera* cam = hilaris.getCamera(new DebayerGreyscaleFast());
	cam->setAutoExposure(true);
	
	StreamServer s(cam);
	s.start();

	
	return 0;
}
