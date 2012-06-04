#include "Hilaris.h"

int main(int argc, const char* argv[])
{
	Hilaris hilaris;
	hilaris.setConsoleLogLevel(Debug::ALERT);
	uint32 cyclesStart, cyclesEnd;
	
	OscSupWdtInit();
	
	cyclesStart = OscSupCycGet();
	Camera* cam = hilaris.getCamera(new DebayerBGRFast());
	cyclesEnd = OscSupCycGet();
	
	printf("time to load camera: %dus\n", OscSupCycToMicroSecs(cyclesEnd - cyclesStart));

	int i;
	uint32 total = 0;
	Image* image;
	
	for(i=0; i<1000;i++)
	{
		OscSupWdtKeepAlive();
		cyclesStart = OscSupCycGet();
		image = cam->captureImage();
		cyclesEnd = OscSupCycGet();
		
		uint32 time = OscSupCycToMicroSecs(cyclesEnd - cyclesStart);
		total += time;
		
		printf("image %d taken in %dus\n", i, time);
	}
	
	printf("average time to capture an image %dus\n", total/1000);
	
	OscSupWdtClose();
	
	return 0;	
}
