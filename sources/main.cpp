#include "Hilaris.h"

#include "processors/RegionProcessors.h"

int main(){
	
	Hilaris hilaris;
	hilaris.setConsoleLogLevel(DEBUG);

	Camera* cam = hilaris.getCamera(new DebayerBGRStandard());
	
	//cam->addFrameProcessor(new RegionProcessors());

	StreamServer s(cam);
	s.start();
	
	return 0;
}
