#include "FingertipDetection.h"

FingertipDetection::FingertipDetection()
{
	this->background = NULL;
	ov.addObject(new Text(10,10,2,"PONG!", 0xFFFFFF, 0x000000));
}

Image* FingertipDetection::process(Image* image)
{
	if(this->background == NULL)
	{
		this->background = new BGRImage(image->getWidth(), image->getHeight());
		memcpy(this->background->getDataPtr(), image->getDataPtr(), image->getWidth() * image->getHeight());
	}
	
	//((BGRImage*)image)->subtract(this->background);
	
	//((GreyscaleImage*)image)->sobel(10);
	
	image->drawOverlay(&ov);
	
	return image;
}
