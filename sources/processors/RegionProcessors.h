#ifndef _REGION_PROCESSOR_H_
#define _REGION_PROCESSOR_H_

#include <string.h>

#include "FrameProcessor.h"
#include "BinaryImage.h"
#include "BinaryImageFactory.h"
#include "Debug.h"

class RegionProcessors : public FrameProcessor
{
	public:
		Image* process(Image* image);
};

#endif
