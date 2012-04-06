
#include "oscar.h"
#include "Hilaris.h"
#include "StreamServer.h"
#include "Image.h"
#include "BGRImageFactory.h"
#include "DebayerBGRFast.h"

#include "GreyscaleImageFactory.h"
#include "DebayerGreyscaleFast.h"

int main(){
	
	Hilaris hilaris;
	hilaris.setConsoleLogLevel(ALERT);
	
	Camera* camera = hilaris.getCamera(new DebayerGreyscaleFast());
	camera->setAutoExposure(true);	
	
	StreamServer s(camera);
	s.start();
	
	while(1);
	
	return 0;
}
