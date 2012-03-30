
#include "Hilaris.h"
#include "StreamServer.h"
#include "Image.h"

int main(){
	
	Hilaris hilaris;
	
	hilaris.setConsoleLogLevel(DEBUG);
	hilaris.setFileLogLevel(NONE);
	
	Camera* camera = hilaris.getCamera();

	/*	
	OscLog(DEBUG, "Error: %d\n", camera->getLastError());
	
	Image* image = camera->captureImage();
		
	image->save("/home/httpd/1.bmp");
	
	image->filter(&GAUSS3X3);
	
	image->save("/home/httpd/2.bmp");
	
	printf("%p", image);
	*/
	
	StreamServer srv;
	
	srv.start();
	
	int i = 0;
	
	while(1)
	{
		char msg[100];
		
		sprintf(msg, "message nr: %d", i++);
		Image*  image = camera->captureImage();

		srv.insertImage(*image);
		usleep(4000);
	}
	
	srv.stop();
	
	return 0;
}
