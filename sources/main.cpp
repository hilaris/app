
#include "Hilaris.h"

int main(){
	
	Hilaris hilaris;
	Camera* camera = hilaris.getCamera();
	
	Image* image = camera->captureImage();
	
	printf("%p", image);
	
	return 0;
}
