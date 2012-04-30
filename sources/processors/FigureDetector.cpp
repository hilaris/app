#include "FigureDetector.h"

FigureDetector::FigureDetector(Hilaris* hilaris)
{
	this->hilaris = hilaris;
	this->binary  = NULL;
	this->text    = NULL;
}

Image* FigureDetector::process(Image* image)
{
	if(this->binary == NULL)
	{
		// create new binary image
		this->binary = new BinaryImage(image->getWidth(), image->getHeight());
	}
	
	if(this->text == NULL)
	{
		this->text = new Text(0, 0, 1, "Not recognized.", 0xFFFFFF, 0x000000);
	}
	
	((BGRImage *)image)->convert(this->binary, 120, false);
		
	// processing image from the middle
	uint16 m_y = binary->getWidth() / 2;
	
	// max height / width
	uint16 max_h = 0;
	uint16 max_w = 0;
	
	uint16 min_x = this->binary->getHeight();
	uint16 min_y = this->binary->getWidth();
	uint16 max_x = 0;
	uint16 max_y = 0;
	
	uint32 area  = 0;
	
	int i;
	int j;
	
	for(i = 0; i < m_y; i ++)
	{		
		// x from the top
		uint16 x_t = 0;
	
		// x from the bottom
		uint16 x_b = binary->getHeight() - 1;
		
		// exit this loop
		bool not_found = false;
		
		while(x_t < binary->getHeight())
		{
			if(binary->pixel(x_t, m_y + i) != 0)
			{
				x_t ++;
				not_found = true;
			}
			else
			{
				// store minimum x value for drawing
				min_x = min_x > x_t ? x_t : min_x;
				
				not_found = false;
				break;
			}
		}
		
		if(not_found) break;
	
		while(x_b > 0)
		{
			if(binary->pixel(x_b, m_y + i) != 0)
			{
				x_b --;
				not_found = true;
			}
			else
			{
				// store minimum x value for drawing
				max_x = max_x < x_b ? x_b : max_x;
				
				not_found = false;
				break;
			}
		}
		
		if(not_found) break;
		
		max_h = max_h < (x_b - x_t) ? x_b - x_t : max_h;
		area += (x_b - x_t);
		
	}
	
	for(j = 0; j < m_y; j ++)
	{		
		// x from the top
		uint16 x_t = 0;
	
		// x from the bottom
		uint16 x_b = binary->getHeight() - 1;
		
		// exit this loop
		bool not_found = false;
		
		while(x_t < binary->getHeight())
		{
			if(binary->pixel(x_t, m_y - j) != 0)
			{
				x_t ++;
				not_found = true;
			}
			else
			{
				// store minimum x value for drawing
				min_x = min_x > x_t ? x_t : min_x;
				
				not_found = false;
				break;
			}
		}
		
		if(not_found) break;
	
		while(x_b > 0)
		{
			if(binary->pixel(x_b, m_y - j) != 0)
			{
				x_b --;
				not_found = true;
			}
			else
			{
				// store minimum x value for drawing
				max_x = max_x < x_b ? x_b : max_x;
				
				not_found = false;
				break;
			}
		}
		
		if(not_found) break;
		
		max_h = max_h < (x_b - x_t) ? x_b - x_t : max_h;		
		area += (x_b - x_t);
	}
	
	max_w = i + j;
	
	min_y = m_y - j;
	max_y = m_y + i;
	
	
	int ratio_a = abs( (int)max_h - (int)max_w);
	int ratio_b = abs(((int)max_h * (int)max_w) - (int)area);
	int ratio_c = abs(ratio_b - area);
	
	printf("a: %d, b: %d, c: %d\n", ratio_a, ratio_b, ratio_c);
	
	if(ratio_a < 15 && ratio_a > 0)
	{
		if(ratio_b < 2000 && ratio_b > 10)
		{
			this->text->setText("Quadrat.");
			
			Box bx(max_y, min_x, min_y, max_x, 0x0000FF);
			image->drawObject(&bx);
		}
		else
		{
			this->text->setText("Kreis.");
			
			Ellipse el(max_y, min_x, min_y, max_x, 0x0000FF);
			image->drawObject(&el);
		}
	}
	else if(ratio_c < 1000 && ratio_c > 0)
	{
		this->text->setText("Dreieck.");
		
		Box bx(max_y, min_x, min_y, max_x, 0x0000FF);
		image->drawObject(&bx);
	}
	else
	{
		this->text->setText("Not recognized.");
	}
	
	image->drawObject(this->text);
	
	return image;
}
