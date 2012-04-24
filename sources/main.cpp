#include "Hilaris.h"
#include "processors/Pong.h"

int main(){
	
	Hilaris hilaris;
	hilaris.setConsoleLogLevel(INFO);	
	
	Camera* cam = hilaris.getCamera(new DebayerBinaryDirect(200, false));
	
	cam->addFrameProcessor(new Pong());
	
	StreamServer s(cam);
	s.start();

	return 0;
}
