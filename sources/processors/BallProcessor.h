#ifndef _BALL_PROCESSOR_
#define _BALL_PROCESSOR_

#include "Ellipse.h"
#include "FrameProcessor.h"

class BallProcessor : public FrameProcessor
{
	public:
		BallProcessor();
		Image* process(Image* img);
		Ellipse* ball;
		int mvX;
		int mvY;
};

#endif 

