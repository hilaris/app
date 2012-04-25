#include "FingertipDetection.h"

FingertipDetection::FingertipDetection()
{
	ov.addObject(new Text(10,10,2,"PONG!", 0xFFFFFF, 0x000000));
	this->bg1 = NULL;
	this->bg2 = NULL;
}

Image* FingertipDetection::process(Image* image)
{
	//((GreyscaleImage*)image)->sobel(8);
	
	if(this->bg1 == NULL || this->bg2 == NULL)
	{
		GreyscaleImage* copy1 = new GreyscaleImage(image->getWidth(), image->getHeight());
		copy1->copyData(image->getDataPtr());
		GreyscaleImage* copy2 = new GreyscaleImage(image->getWidth(), image->getHeight());
		copy2->copyData(image->getDataPtr());
		this->bg1 = copy1;
		this->bg2 = copy2;		
	}
	else
	{
		this->bg2->copyData(this->bg1->getDataPtr());
		this->bg1->copyData(image->getDataPtr());
		
		for(int i = 0; i < image->getHeight(); i ++)
		{
			for(int j = 0; j < image->getWidth(); j ++)
			{
				uint8 a, n ,o;
					
				if((n=((GreyscaleImage*)image)->pixel(i,j)) >= 20+(o=this->bg2->pixel(i,j)))
				{
					a = 255;
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
