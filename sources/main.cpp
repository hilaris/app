#include "Hilaris.h"

#include "processors/TestProcessor.h"

int main(){
	
	Hilaris hilaris;
	hilaris.setConsoleLogLevel(NONE);

	Camera* cam = hilaris.getCamera(new DebayerBGRFast());
	
	cam->addFrameProcessor(new TestProcessor());

	StreamServer s(cam);
	s.start();
	
	return 0;
}
