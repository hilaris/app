#include "Pong.h"

Pong::Pong()
{
	this->background = NULL;
}

Image* Pong::process(Image* image)
{
	if(this->background == NULL)
	{
		this->background = new BinaryImage(image->getWidth(), image->getHeight());
		memcpy(this->background->getDataPtr(), image->getDataPtr(), image->getWidth() * image->getHeight());
	}
	
	((BinaryImage*)image)->subtract(this->background);
	
	//((GreyscaleImage*)image)->sobel(10);
	

	
	return image;
}
