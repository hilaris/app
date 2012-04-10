#include "Hilaris.h"

int main(){
	
	Hilaris hilaris;
	hilaris.setConsoleLogLevel(DEBUG);
	

	Camera* cam = hilaris.getCamera(new DebayerBGRFast());
	
	//cam->addFrameProcessor(new BinaryProcessor());
	
	StreamServer s(cam);
	s.start();
	
	return 0;
}
