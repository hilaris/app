#ifndef _LEDFRAMEPROCESSOR_H_
#define _LEDFRAMEPROCESSOR_H_

#include <unistd.h>

#include "oscar.h"
#include "Hilaris.h"

class LEDFrameProcessor: public FrameProcessor
{
	public:
	
		LEDFrameProcessor(Hilaris* hilaris);
		Image* process(Image* image);
	
	private:
	
		Hilaris* hilaris;
		int state;
};

#endif
