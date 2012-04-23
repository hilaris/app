#include "Hilaris.h"


int main(){
	
	Hilaris hilaris;
	hilaris.setConsoleLogLevel(DEBUG);
		
	BGRImage image = BGRImageFactory::create(200, 200, 255, 255, 255);
	
	Text* t = new Text(10, 20, 1, "fmepoo", 0x00FF00, 0x0000FF);
	t->draw(&image);
	
	Box* b = new Box(10, 20, 30, 40, 0xFF0000);
	b->draw(&image);
	
	image.save("overlay-fancy.bmp");
	
	return 0;
}
