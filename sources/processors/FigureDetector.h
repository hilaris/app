#ifndef _FIGUREDETECTOR_H_
#define _FIGUREDETECTOR_H_

#include <unistd.h>

#include "oscar.h"
#include "Hilaris.h"

class FigureDetector: public FrameProcessor
{
	public:
	
		FigureDetector(Hilaris* hilaris);
		Image* process(Image* image);
	
	private:
	
		Hilaris* hilaris;
		BinaryImage* binary;
		Text* text;
};

#endif
