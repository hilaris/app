
#include "Hilaris.h"

int main(){
	
	Hilaris hilaris;
	
	hilaris.setConsoleLogLevel(DEBUG);
	
	Camera* camera = hilaris.getCamera();
	
	OscLog(DEBUG, "Error: %d\n", camera->getLastError());
	
	Image* image = camera->captureImage();
	
	printf("%p", image);
	
	return 0;
}
