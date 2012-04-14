#include "Hilaris.h"
#include "processors/RegionProcessors.h"

int main(){
	
	Hilaris hilaris;
	hilaris.setConsoleLogLevel(DEBUG);
	
	Camera* cam = hilaris.getCamera(new DebayerGreyscaleFast());
	cam->addFrameProcessor(new RegionProcessors());
	
	StreamServer srv(cam);
	srv.start();
	
	return 0;
}
