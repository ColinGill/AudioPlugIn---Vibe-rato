/*
  ==============================================================================

  This is an automatically generated GUI class created by the Projucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Projucer version: 5.2.0

  ------------------------------------------------------------------------------

  The Projucer is part of the JUCE library - "Jules' Utility Class Extensions"
  Copyright (c) 2015 - ROLI Ltd.

  ==============================================================================
*/

#pragma once

//[Headers]     -- You can add your own extra header files here --
#include "JuceHeader.h"
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Projucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class images  : public Component,
                public Button::Listener
{
public:
    //==============================================================================
    images ();
    ~images();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    //[/UserMethods]

    void paint (Graphics& g) override;
    void resized() override;
    void buttonClicked (Button* buttonThatWasClicked) override;

    // Binary resources:
    static const char* croppedPedal_png;
    static const int croppedPedal_pngSize;
    static const char* croppedPedal_png2;
    static const int croppedPedal_png2Size;
    static const char* ledOff_png;
    static const int ledOff_pngSize;
    static const char* ledOn_png;
    static const int ledOn_pngSize;
    static const char* footswitchDown_png;
    static const int footswitchDown_pngSize;
    static const char* footswitchUp_png;
    static const int footswitchUp_pngSize;
    static const char* switch_left_png;
    static const int switch_left_pngSize;
    static const char* switch_right_png;
    static const int switch_right_pngSize;
    static const char* depthKnobFilmRoll_png;
    static const int depthKnobFilmRoll_pngSize;
    static const char* rateKnobFilmRoll_png;
    static const int rateKnobFilmRoll_pngSize;


private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    //[/UserVariables]

    //==============================================================================
    ScopedPointer<ImageButton> imageButton4;
    Image cachedImage_croppedPedal_png2_1;
    Image cachedImage_ledOff_png_2;
    Image cachedImage_ledOn_png_3;
    Image cachedImage_footswitchDown_png_4;
    Image cachedImage_footswitchUp_png_5;
    Image cachedImage_switch_left_png_6;
    Image cachedImage_switch_right_png_7;
    Image cachedImage_depthKnobFilmRoll_png_8;
    Image cachedImage_rateKnobFilmRoll_png_9;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (images)
};

//[EndFile] You can add extra defines here...
//[/EndFile]
