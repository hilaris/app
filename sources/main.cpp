
#include "oscar.h"
#include "Hilaris.h"
#include "StreamServer.h"
#include "Image.h"
#include "BGRImageFactory.h"
#include "DebayerBGRFast.h"

#include "GreyscaleImageFactory.h"
#include "DebayerGreyscaleFast.h"
#include "DebayerBGRBilinear.h"

#include "processors/TestProcessor.h"

int main(){
	
	Hilaris hilaris;
	hilaris.setConsoleLogLevel(ALERT);
	
	Camera* camera = hilaris.getCamera(new DebayerBGRFast());
	camera->setAutoExposure(true);
	
	camera->addFrameProcessor(new TestProcessor());
		
	StreamServer s(camera);
	s.start();
	
	
	return 0;
}
