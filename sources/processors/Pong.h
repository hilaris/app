#ifndef _PONG_H_
#define _PONG_H_

#include "oscar.h"
#include "FrameProcessor.h"
#include "BinaryImage.h"
#include "Overlay.h"
#include "DrawableObject.h"
#include "Text.h"
#include "Debug.h"

class Pong: public FrameProcessor
{
	public:
	
		Pong();
		Image* process(Image* image);
	
	private:
	
		enum State
		{
			STARTUP,
			STARTUP_ALT
		};
		
		enum State current;
		enum State next;
		
		int doSwitch;
		
		BinaryImage* screenStart;
		BinaryImage* screenStartAlt;
		
		Overlay* overlayStart;
		Overlay* overlayStartAlt;
};

#endif
