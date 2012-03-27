
#include "Hilaris.h"
#include "StreamServer.h"

int main(){
	
	Hilaris hilaris;
	
	hilaris.setConsoleLogLevel(DEBUG);
	
	/*
	Camera* camera = hilaris.getCamera();
	
	OscLog(DEBUG, "Error: %d\n", camera->getLastError());
	
	Image* image = camera->captureImage();
		
	image->save("/home/httpd/1.bmp");
	
	image->filter(&GAUSS3X3);
	
	image->save("/home/httpd/2.bmp");
	
	printf("%p", image);
	*/
	
	StreamServer srv;
	
	srv.start();
	
	sleep(1);
	
	srv.message = "bliiiiiiiiip";
	
	sleep(1);
	
	srv.message = "huhuuuuu";
	
	sleep(1);
	
	srv.stop();
	
	
	
	return 0;
}
