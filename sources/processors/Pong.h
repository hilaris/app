#ifndef _PONG_H_
#define _PONG_H_

#include <unistd.h>

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
			STARTUP_ALT,
			MENU
		};
		
		enum State current;
		enum State next;
		
		int doSwitch;
		int introSwitch;
		
		BinaryImage* screenStart;
		BinaryImage* screenStartAlt;
		BinaryImage* screenMenu;
		
		Overlay* overlayStart;
		Overlay* overlayStartAlt;
		Overlay* overlayMenu;
};

#endif
