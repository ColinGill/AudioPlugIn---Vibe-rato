/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"


//==============================================================================
/**
*/
class NewProjectAudioProcessor  : public AudioProcessor
{
public:
    //==============================================================================
    NewProjectAudioProcessor();
    ~NewProjectAudioProcessor();

    //==============================================================================
    void prepareToPlay (double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;

   #ifndef JucePlugin_PreferredChannelConfigurations
    bool isBusesLayoutSupported (const BusesLayout& layouts) const override;
   #endif

    void processBlock (AudioSampleBuffer&, MidiBuffer&) override;

    //==============================================================================
    AudioProcessorEditor* createEditor() override;
    bool hasEditor() const override;

    //==============================================================================
    const String getName() const override;

    bool acceptsMidi() const override;
    bool producesMidi() const override;
    bool isMidiEffect () const override;
    double getTailLengthSeconds() const override;

    //==============================================================================
    int getNumPrograms() override;
    int getCurrentProgram() override;
    void setCurrentProgram (int index) override;
    const String getProgramName (int index) override;
    void changeProgramName (int index, const String& newName) override;

    //==============================================================================
    void getStateInformation (MemoryBlock& destData) override;
    void setStateInformation (const void* data, int sizeInBytes) override;
	
	void setRateHz(float hz) { rate_Hz = hz; };
	void setDepth(float d) { depth_ = d; };
	
	void setWaveform(bool wf) {  waveformSelect = wf; };
	void enablePedal(bool ep) { pedalEnabled = ep; };
	
	float getRateHz() { return rate_Hz; };
	float getDepth() { return depth_; };
	
	bool getFootSwitchState(){ return pedalEnabled; };
	bool getWaveform() { return waveformSelect; };
	

private:
    //=============================================================================//
	float rate_Hz = 0.5, depth_ = 1.0, previousRate, previousSample;
	float scaledHz, scaledDepth;
	bool pedalEnabled = false;
	bool waveformSelect = 0;
	bool holdSample = false;
	float scaleHz(float hz) { return hz *20; };
	AudioParameterFloat* RateHz;
	
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (NewProjectAudioProcessor)
};
