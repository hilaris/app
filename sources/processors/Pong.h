#ifndef _PONG_H_
#define _PONG_H_

#include "oscar.h"
#include "FrameProcessor.h"
#include "BinaryImage.h"
#include "Overlay.h"
#include "Text.h"

class Pong: public FrameProcessor
{
	public:
		BinaryImage* background;
		Pong();
		Image* process(Image* image);
};

#endif
