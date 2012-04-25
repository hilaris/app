#include "Hilaris.h"
#include "processors/FingertipDetection.h"
#include "processors/BallProcessor.h"
#include "Median.h"

int main(){

	Hilaris hilaris;
	hilaris.setConsoleLogLevel(INFO);	
	
	Median* m = new Median(90040, 5);
	m->insert(1,123);
	m->insert(1,13);
	m->insert(1,12);
	m->insert(1,223);
	m->insert(1,23);
	m->insert(1,23);
	/*
	Camera* cam = hilaris.getCamera(new DebayerGreyscaleFast());
	cam->setAutoExposure(true);

	cam->addFrameProcessor("Finger", new FingertipDetection());
	cam->addFrameProcessor("Ball", new BallProcessor());
	
	StreamServer s(cam);
	s.start();
	*/
	
	return 0;
}
