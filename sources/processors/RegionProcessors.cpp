#include "RegionProcessors.h"

Image* RegionProcessors::process(Image* image)
{
	GreyscaleImage* tmp = (GreyscaleImage* ) image;
	
	BinaryImage binary = BinaryImageFactory::getFromGreyscaleImage(*tmp, 127, false);

	binary.label();
	binary.drawBoundingBox();
	
	for(int i = 0; i < binary.getHeight(); i++)
	{
		for(int j = 0; j < binary.getWidth(); j++)
		{
			(*tmp)(i, j) = binary(i, j) == 0 ? 0 : 255;
		}
	}
	
	return image;
}
