/*
  ==============================================================================

	FilmStripSlider.cpp
	Created: 21 May 2019 12:22:26am
	Author:  Donnacha

  ==============================================================================
*/

#include "FilmStripSlider.h"
FilmStripSlider::FilmStripSlider(Image *_knobStrip ,unsigned int numOfPositions) : knobStrip(_knobStrip) , frameCount(numOfPositions)
{	
		frameSize = knobStrip->getHeight() / frameCount;
		isVerticalStrip = true;
}


void FilmStripSlider::drawFrame(Graphics &g, int x, int y, int width, int height, Slider &slider)
{
	const double div = (slider.getMaximum()+ slider.getInterval()) / frameCount;
	double pos =  (int)(slider.getValue()/ div);

	g.drawImage(*knobStrip, x, y, width, height, 0, (int)(pos*frameSize), width, height, false);

	
}