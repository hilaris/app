#include "Pong.h"

Pong::Pong()
{
	this->current  = Pong::STARTUP;
	this->next     = Pong::STARTUP_ALT;
	
	this->doSwitch = 10;
	this->introSwitch = 100;
	
	this->screenStart    = NULL;
	this->screenStartAlt = NULL;
	this->screenMenu     = NULL;
	
	this->overlayStart = NULL;
	this->overlayStartAlt = NULL;
	this->overlayMenu = NULL;
}

Image* Pong::process(Image* image)
{
	image = (BinaryImage*) image;
	
	if(this->screenStart == NULL)
	{
		this->screenStart = new BinaryImage(image->getWidth(), image->getHeight(), 0);
		
		// create Overlay
		this->overlayStart = new Overlay();
		this->overlayStart->addObject(new Text(image->getWidth() / 2, image->getHeight() / 2, 3, "PONG!+", 255, 0));
		this->overlayStart->addObject(new Text(image->getWidth() / 2, image->getHeight() / 2 + 50, 1, "Jim Schmid", 255, 0));
		this->overlayStart->addObject(new Text(image->getWidth() / 2, image->getHeight() / 2 + 60, 1, "Michael Kreis", 255, 0));
		
		this->screenStart->drawOverlay(this->overlayStart);
	}
	
	if(this->screenStartAlt == NULL)
	{
		this->screenStartAlt = new BinaryImage(image->getWidth(), image->getHeight(), 1);
		
		// create Overlay
		this->overlayStartAlt = new Overlay();
		this->overlayStartAlt->addObject(new Text(image->getWidth() / 2, image->getHeight() / 2, 3, "PONG!+", 0, 255));
		this->overlayStartAlt->addObject(new Text(image->getWidth() / 2, image->getHeight() / 2 + 50, 1, "Jim Schmid", 0, 255));
		this->overlayStartAlt->addObject(new Text(image->getWidth() / 2, image->getHeight() / 2 + 60, 1, "Michael Kreis", 0, 255));
		
		this->screenStartAlt->drawOverlay(this->overlayStartAlt);
	}
	
	if(this->screenMenu == NULL)
	{
		this->screenMenu = new BinaryImage(image->getWidth(), image->getHeight(), 0);
		
		this->overlayMenu = new Overlay();
		this->overlayMenu->addObject(new Text(image->getWidth() / 2 - 100, 20, 5, "0", 255, 0));
		this->overlayMenu->addObject(new Text(image->getWidth() / 2 + 75, 20, 5, "0", 255, 0));
		
		this->screenMenu->drawOverlay(this->overlayMenu);
	}
	
	switch(this->current)
	{
		case Pong::STARTUP:
			
			Debug::log("State: Startup\n");
				
			// replace image with a black one
			memcpy(image->getDataPtr(), this->screenStart->getDataPtr(), image->getWidth() * image->getHeight());
			this->next = Pong::STARTUP_ALT;
			
			this->doSwitch <= 0 ? this->doSwitch = 10 : this->doSwitch --;
			this->introSwitch <= 0 ? this->next = Pong::MENU : this->introSwitch --;
		
		break;
		
		case Pong::STARTUP_ALT:
		
			Debug::log("State: Startup Alternative\n");
			
			// replace image with a white one
			memcpy(image->getDataPtr(), this->screenStartAlt->getDataPtr(), image->getWidth() * image->getHeight());
			this->next = Pong::STARTUP;
			
			this->doSwitch <= 0 ? this->doSwitch = 10 : this->doSwitch --;
			this->introSwitch <= 0 ? this->next = Pong::MENU : this->introSwitch --;
			
		break;
		
		case Pong::MENU:
		
			Debug::log("State: Menu\n");
			
			memcpy(image->getDataPtr(), this->screenMenu->getDataPtr(), image->getWidth() * image->getHeight());
			
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
