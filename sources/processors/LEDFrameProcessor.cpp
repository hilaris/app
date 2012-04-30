#include "LEDFrameProcessor.h"

LEDFrameProcessor::LEDFrameProcessor(Hilaris* hilaris)
{
	this->state = 0;
	this->hilaris = hilaris;
}

Image* LEDFrameProcessor::process(Image* image)
{
	if(this->state % 20 == 0)
	{
		this->hilaris->io()->led()->toggle();
	}
	
	this->hilaris->io()->led()->setColor(255 - 255 % this->state, 255 % this->state);
	
	this->state ++;
	
	return image;
}
