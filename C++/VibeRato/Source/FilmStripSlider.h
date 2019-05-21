/*
  ==============================================================================

    FilmStripSlider.h
    Created: 21 May 2019 12:22:26am
    Author:  Donnacha

  ==============================================================================
*/
#include "../JuceLibraryCode/JuceHeader.h"
#pragma once
class FilmStripSlider
{
	public:
		FilmStripSlider (Image *_knobStrip);
		void drawFrame (Graphics &g, int x, int y, int width, int height, Slider &slider);
		Image *knobStrip;

	private:
		
		int frameCount;
		int frameSize;
		bool isVerticalStrip;
};