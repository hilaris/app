#include "BallProcessor.h"

#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#define MAXSPEED 15
#define BALLSIZE 10

BallProcessor::BallProcessor()
{
	srand ( time(NULL) );
	this->ball = new Ellipse(50,115,50+BALLSIZE,115+BALLSIZE,0xFFFFFF, true);
	this->mvX = rand() % MAXSPEED;
	this->mvY = rand() % MAXSPEED;
}

Image* BallProcessor::process(Image* img)
{
	this->ball->draw(img);
	
	if((this->ball->x1 + BALLSIZE + this->mvX) == img->getWidth())
		this->ball->x1 = img->getWidth()-BALLSIZE;
	else if((this->ball->x1 + BALLSIZE + this->mvX) > img->getWidth())
	{
		this->mvX = this->mvX * (-1);
		this->ball->x1 += this->mvX;
	}
	else if(this->ball->x1 + this->mvX == 0)
		this->ball->x1 = 0;
	else if(this->ball->x1 + this->mvX < 0)
	{
		this->mvX = this->mvX * (-1);
		this->ball->x1 += this->mvX;
	}
	else
		this->ball->x1 += this->mvX;
		
	if((this->ball->y1 + BALLSIZE + this->mvY) == img->getHeight())
		this->ball->y1 = img->getHeight()-BALLSIZE;
	else if((this->ball->y1 + BALLSIZE + this->mvY) > img->getHeight())
	{
		this->mvY = this->mvY * (-1);
		this->ball->y1 += this->mvY;
	}
	else if(this->ball->y1 + this->mvY == 0)
		this->ball->y1 = 0;
	else if(this->ball->y1 + this->mvY < 0)
	{
		this->mvY = this->mvY * (-1);
		this->ball->y1 += this->mvY;
	}
	else
		this->ball->y1 += this->mvY;
	
	
	this->ball->x2 = this->ball->x1 + BALLSIZE;
	this->ball->y2 = this->ball->y1 + BALLSIZE;
	
	return img;
}
