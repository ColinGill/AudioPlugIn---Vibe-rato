/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"


//==============================================================================
/**
*/
class NewProjectAudioProcessorEditor  : public AudioProcessorEditor,
										public Slider::Listener,
										public Button::Listener
{
public:
    NewProjectAudioProcessorEditor (NewProjectAudioProcessor&);
    ~NewProjectAudioProcessorEditor();

    //==============================================================================
    void paint (Graphics&) override;
    void resized() override;
	void sliderValueChanged(Slider* sliderThatWasMoved) override;
	void buttonClicked(Button* buttonThatWasClicked) override;
	
private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
	//void setRate(float Hz) { rateHz = Hz; };

	bool footSwitchPressed = false;
	bool toggleSwitchPressed = false;
	bool waveform = 0, repaintFlag = false;
	//AudioParameterFloat* RateHz;
	//AudioParameterFloat* Depth;
	
	Image cachedImage_depthKnobFilmRoll_png_1;
	Image cachedImage_RateKnobFilmRoll_png_1;
	Image cachedImage_BaseModel_png_1;
	Image cachedImage_ledOff_png_1;
	Image cachedImage_ledOn_png_2;
	Image cachedImage_switch_left_png_3;
	Image cachedImage_switch_right_png_;
	Image cachedImage_footswitchDown_png_5;
	Image cachedImage_footswitchUp_png2_6;

    NewProjectAudioProcessor& processor;
	ScopedPointer<Slider> Dknob;
	ScopedPointer<Slider> Rknob;
	ScopedPointer<ImageButton> OnOffSwitch;
	ScopedPointer<ImageButton> LedOnOff;
	ScopedPointer<ImageButton> ToggleSwitch;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (NewProjectAudioProcessorEditor)
};
