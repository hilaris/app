#include "FingertipDetection.h"

FingertipDetection::FingertipDetection()
{
	this->background = NULL;
	ov.addObject(new Text(10,10,2,"PONG!", 0xFFFFFF, 0x000000));
}

Image* FingertipDetection::process(Image* image)
{
	//((GreyscaleImage*)image)->sobel(8);
	
	if(this->background == NULL)
	{
		this->background = new GreyscaleImage(image->getWidth(), image->getHeight());
		this->backgroundold = new GreyscaleImage(image->getWidth(), image->getHeight());
		memcpy(this->background->getDataPtr(), image->getDataPtr(), image->getWidth() * image->getHeight());
		memcpy(this->backgroundold->getDataPtr(), image->getDataPtr(), image->getWidth() * image->getHeight());
	}
	else
	{
		memcpy(this->backgroundold->getDataPtr(), this->background->getDataPtr(), this->background->getWidth() * this->background->getHeight());
		memcpy(this->background->getDataPtr(), image->getDataPtr(), image->getWidth() * image->getHeight());
		for(int i = 0; i < image->getHeight(); i ++)
		{
			for(int j = 0; j < image->getWidth(); j ++)
			{
				uint8 n, o, a;
				if((n=((GreyscaleImage*)image)->pixel(i,j)) > 30 +(o=((GreyscaleImage*)this->backgroundold)->pixel(i,j)))
				{
					a = 255;
				}
				else if(n>=o)
				{
					a = n - o;
				}
				else
				{
					a = 0;
				}
				((GreyscaleImage*)image)->pixel(i,j) = a;
			}
		}
	}
	
	//((GreyscaleImage*)image)->sobel(2);
	/*
	for(int i = 0; i < image->getHeight(); i ++)
	{
		for(int j = 0; j < image->getWidth(); j ++)
		{
			((GreyscaleImage*)image)->pixel(i,j) = ((GreyscaleImage*)image)->pixel(i,j) < ((GreyscaleImage*)this->background)->pixel(i,j)?0:((GreyscaleImage*)image)->pixel(i,j)-((GreyscaleImage*)this->background)->pixel(i,j);

		}
	}
	*/
	
	
	
	image->drawOverlay(&ov);
	
	return image;
}
