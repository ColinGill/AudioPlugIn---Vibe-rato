/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"
#include "FilmStripSlider.h"
#include "images.cpp"


//==============================================================================
NewProjectAudioProcessorEditor::NewProjectAudioProcessorEditor (NewProjectAudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p)
{
	
	cachedImage_BaseModel_png_1 = ImageCache::getFromMemory(croppedPedal_png2, croppedPedal_png2Size);
	cachedImage_depthKnobFilmRoll_png_1 = ImageCache::getFromMemory(depthKnobFilmRoll_png, depthKnobFilmRoll_pngSize);
	cachedImage_RateKnobFilmRoll_png_1 = ImageCache::getFromMemory(rateKnobFilmRoll_png, rateKnobFilmRoll_pngSize);

	addAndMakeVisible(OnOffSwitch = new ImageButton("onoffswitch"));
	OnOffSwitch->addListener(this);

	OnOffSwitch->setImages(false, true, true,
		ImageCache::getFromMemory(footswitchUp_png, footswitchUp_pngSize), 1.000f, Colour(0x00000000),
		Image(), 1.000f, Colour(0x00000000),
		Image(), 1.000f, Colour(0x00000000));
	

	addAndMakeVisible(LedOnOff = new ImageButton("onoffLed"));
	LedOnOff->addListener(this);
	LedOnOff->setImages(false, true, true,
		ImageCache::getFromMemory(ledOff_png, ledOff_pngSize), 1.000f, Colour(0x00000000),
		Image(), 1.000f, Colour(0x00000000),
		Image(), 1.000f, Colour(0x00000000));

	addAndMakeVisible(ToggleSwitch = new ImageButton("Toggleonoff"));
	ToggleSwitch->addListener(this);
	ToggleSwitch->setImages(false, true, true,
		ImageCache::getFromMemory(switch_left_png, switch_left_pngSize), 1.000f, Colour(0x00000000),
		Image(), 1.000f, Colour(0x00000000),
		Image(), 1.000f, Colour(0x00000000));
		

	addAndMakeVisible(Rknob = new Slider("RKnob"));
	Rknob->setRange(0, 1, 0.01);
	Rknob->setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
	Rknob->setTextBoxStyle(Slider::TextBoxLeft, false, 0, 0);
	Rknob->addListener(this);
	previousRate = processor.getRateHz();
	Rknob->setValue(processor.getRateHz());
	Rknob->setAlpha(0);


	addAndMakeVisible(Dknob = new Slider("DKnob"));
	Dknob->setRange(0, 1, 0.01);
	Dknob->setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
	Dknob->setTextBoxStyle(Slider::TextBoxLeft, false, 0, 0);
	Dknob->addListener(this);
	Dknob->setAlpha(0);
	previousDepth = processor.getDepth();
	Dknob->setValue(processor.getDepth());
	

	footSwitchPressed = processor.getFootSwitchState();
	toggleSwitchPressed = processor.getWaveform();
    setSize (318, 455);
	repaintFlag = true;
	startTimer(10);
}

NewProjectAudioProcessorEditor::~NewProjectAudioProcessorEditor()
{
	Dknob = nullptr;
	Rknob = nullptr;
	OnOffSwitch = nullptr;
	LedOnOff = nullptr;
	ToggleSwitch = nullptr;
}

//==============================================================================
void NewProjectAudioProcessorEditor::paint (Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
	FilmStripSlider fssDepth(&cachedImage_depthKnobFilmRoll_png_1);
	FilmStripSlider fssRate(&cachedImage_RateKnobFilmRoll_png_1);

    g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));
    g.setColour (Colours::white);
    g.setFont (15.0f);
	g.drawImage(cachedImage_BaseModel_png_1, 0,0, cachedImage_BaseModel_png_1.getWidth(), cachedImage_BaseModel_png_1.getHeight(),0, 0, cachedImage_BaseModel_png_1.getWidth(), cachedImage_BaseModel_png_1.getHeight(), false);
	
	if (repaintFlag == true) {

		if (footSwitchPressed == true)
		{
			LedOnOff->setBounds(140, 0, 42, 43);
			LedOnOff->setImages(false, true, true,
				ImageCache::getFromMemory(ledOn_png, ledOn_pngSize), 1.000f, Colour(0x00000000),
				Image(), 1.000f, Colour(0x00000000),
				Image(), 1.000f, Colour(0x00000000));

			OnOffSwitch->setBounds(118, 294, 82, 123);
			OnOffSwitch->setImages(false, true, true,
				ImageCache::getFromMemory(footswitchDown_png, footswitchDown_pngSize), 1.000f, Colour(0x00000000),
				Image(), 1.000f, Colour(0x00000000),
				Image(), 1.000f, Colour(0x00000000));
			repaintFlag = false;
		}

		else
		{
			LedOnOff->setBounds(140, 0, 42, 43);
			LedOnOff->setImages(false, true, true,
				ImageCache::getFromMemory(ledOff_png, ledOff_pngSize), 1.000f, Colour(0x00000000),
				Image(), 1.000f, Colour(0x00000000),
				Image(), 1.000f, Colour(0x00000000));

			OnOffSwitch->setBounds(120, 289, 80, 130);
			OnOffSwitch->setImages(false, true, true,
				ImageCache::getFromMemory(footswitchUp_png, footswitchUp_pngSize), 1.000f, Colour(0x00000000),
				Image(), 1.000f, Colour(0x00000000),
				Image(), 1.000f, Colour(0x00000000));
			repaintFlag = false;
		}


		if (toggleSwitchPressed == true)
		{
			ToggleSwitch->setBounds(136, 133, 61, 89);
			ToggleSwitch->setImages(false, false, false,
				ImageCache::getFromMemory(switch_right_png, switch_right_pngSize), 1.000f, Colour(0x00000000),
				Image(), 1.000f, Colour(0x00000000),
				Image(), 1.000f, Colour(0x00000000));
			repaintFlag = false;
		}

		else
		{
			ToggleSwitch->setBounds(132, 130, 49, 82);
			ToggleSwitch->setImages(false, false, false,
				ImageCache::getFromMemory(switch_left_png, switch_left_pngSize), 1.000f, Colour(0x00000000),
				Image(), 1.000f, Colour(0x00000000),
				Image(), 1.000f, Colour(0x00000000));
			repaintFlag = false;
		}	
	}
	
	fssDepth.drawFrame(g, 0, 26, 208, 110, *Dknob , processor.getDepth());
	fssRate.drawFrame(g, 0, 24, 456, 110, *Rknob , processor.getRateHz());
	
	
}

void NewProjectAudioProcessorEditor::resized()
{
	
	OnOffSwitch->setBounds(120, 289, 80, 130);
	LedOnOff->setBounds(139, 9, 42, 43);
	Dknob->setBounds(50, 20, 110, 110);
	Rknob->setBounds(170, 20, 110, 110);
	ToggleSwitch->setBounds(130, 130, 49, 82);
}

void NewProjectAudioProcessorEditor::sliderValueChanged(Slider* sliderThatWasMoved)
{
	if (sliderThatWasMoved == Rknob)
	{
		processor.setRateHz((float)(sliderThatWasMoved->getValue()));
	}
	else if (sliderThatWasMoved == Dknob)
	{
		processor.setDepth((float)(sliderThatWasMoved->getValue()));
	}
}


void NewProjectAudioProcessorEditor::buttonClicked(Button* buttonThatWasClicked)
{
	

	if (buttonThatWasClicked == OnOffSwitch)
	{
		repaintFlag = true;
		footSwitchPressed = !footSwitchPressed;
		processor.enablePedal(footSwitchPressed);
	}
	else if (buttonThatWasClicked == ToggleSwitch)
	{
		repaintFlag = true;
		toggleSwitchPressed = !toggleSwitchPressed;
		processor.setWaveform(toggleSwitchPressed);
	}

}

void NewProjectAudioProcessorEditor::timerCallback()
{
	if (previousRate != processor.getRateHz())
	{
		repaint();
		previousRate = processor.getRateHz();
	}
	else if (previousDepth != processor.getDepth())
	{
		repaint();
		previousDepth = processor.getDepth();
	}
}


