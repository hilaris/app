
#include "oscar.h"
#include "Hilaris.h"
#include "StreamServer.h"
#include "Image.h"
#include "BGRImageFactory.h"
#include "DebayerBGRFast.h"

#include "GreyscaleImageFactory.h"
#include "DebayerGreyscaleVector.h"
#include "DebayerBGRBilinear.h"

int main(){
	
	Hilaris hilaris;
	hilaris.setConsoleLogLevel(ALERT);
	
	Camera* camera = hilaris.getCamera(new DebayerBGRBilinear());
	camera->setAutoExposure(true);	
	
	Image* i = camera->captureImage();
	#if defined(OSC_HOST)
	i->save("testdebayered.bmp");
	#endif

	#if defined(OSC_TARGET)
	i->save("/home/httpd/test.bmp");
	#endif
	
	StreamServer s(camera);
	s.start();
	
	
	return 0;
}
