#include "Hilaris.h"

int main(){

	Hilaris hilaris;
	hilaris.setConsoleLogLevel(INFO);	

	Camera* cam = hilaris.getCamera(new DebayerBGRBilinear());
	cam->setAutoExposure(true);

	//cam->addFrameProcessor(new FingertipDetection());
	//cam->addFrameProcessor(new BallProcessor());
	
	//StreamServer s(cam);
	//s.start();
	
	return 0;
}
