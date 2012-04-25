#ifndef _FINGERTIP_PROCESSOR_
#define _FINGERTIP_PROCESSOR_

#include <vector>
#include <set>

#include "oscar.h"
#include "FrameProcessor.h"
#include "BinaryImage.h"
#include "Overlay.h"
#include "Text.h"

class FingertipDetection: public FrameProcessor
{
	public:
		GreyscaleImage* bg1;
		GreyscaleImage* bg2;
		Overlay ov;
		FingertipDetection();
		Image* process(Image* image);
};

#endif
