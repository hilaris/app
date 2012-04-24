#ifndef _FINGERTIP_PROCESSOR_
#define _FINGERTIP_PROCESSOR_

#include "oscar.h"
#include "FrameProcessor.h"
#include "BinaryImage.h"
#include "Overlay.h"
#include "Text.h"

class FingertipDetection: public FrameProcessor
{
	public:
		BGRImage* background;
		Overlay ov;
		FingertipDetection();
		Image* process(Image* image);
};

#endif
