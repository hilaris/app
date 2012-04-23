#include "Hilaris.h"

int main(){
	
	Hilaris hilaris;
	hilaris.setConsoleLogLevel(NONE);
	
	Camera* camera = hilaris.getCamera();
	
	StreamServer srv(camera);
	srv.start();
	
		
	return 0;
}
