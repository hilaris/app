#include "Pong.h"

Pong::Pong()
{
	this->current  = Pong::STARTUP;
	this->next     = Pong::STARTUP_ALT;
	
	this->doSwitch = 10;
	
	this->screenStart    = NULL;
	this->screenStartAlt = NULL;
	
	this->overlayStart = NULL;
	this->overlayStartAlt = NULL;
}

Image* Pong::process(Image* image)
{
	image = (BinaryImage*) image;
	
	if(this->screenStart == NULL)
	{
		this->screenStart = new BinaryImage(image->getWidth(), image->getHeight(), 0);
		
		// create Overlay
		this->overlayStart = new Overlay();
		this->overlayStart->addObject(new Text(10, 10, 3, "PONG!+", 1, 0));
		
		this->screenStart->drawOverlay(this->overlayStart);
	}
	
	if(this->screenStartAlt == NULL)
	{
		this->screenStartAlt = new BinaryImage(image->getWidth(), image->getHeight(), 1);
		
		// create Overlay
		this->overlayStartAlt = new Overlay();
		this->overlayStartAlt->addObject(new Text(10, 10, 3, "PONG!+", 1, 0));
		
		this->screenStart->drawOverlay(this->overlayStartAlt);
	}
	
	switch(this->current)
	{
		case Pong::STARTUP:
						
			// replace image with a black one
			memcpy(image->getDataPtr(), this->screenStart->getDataPtr(), image->getWidth() * image->getHeight());
			this->next = Pong::STARTUP_ALT;
			
			this->doSwitch <= 0 ? this->doSwitch = 10 : this->doSwitch --;
		
		break;
		
		case Pong::STARTUP_ALT:
		
			// replace image with a white one
			memcpy(image->getDataPtr(), this->screenStart->getDataPtr(), image->getWidth() * image->getHeight());
			this->next = Pong::STARTUP;
			
			this->doSwitch <= 0 ? this->doSwitch = 10 : this->doSwitch --;
			
		break;
	}
	
	// do the switch
	if(this->doSwitch <= 0)
	{
		this->current = this->next;
	}
	
	for(int i = 0; i < image->getHeight(); i++)
	{
		for(int j = 0; j < image->getWidth(); j++)
		{
			((BinaryImage*)image)->pixel(i, j) = ((BinaryImage*)image)->pixel(i, j) > 0 ? 255 : 0;
		}
	}
	
	return image;
}
