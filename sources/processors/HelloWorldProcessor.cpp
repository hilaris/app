#include "HelloWorldProcessor.h"

Image* HelloWorldProcessor::process(Image* image)
{
	Text t(10, 10, 2, "Hello World!", 0xFFFFFF, 0x000000);
	
	image->drawObject(&t);
	
	return image;
}
