#include <math.h>
#include <new>
#include <distingnt/api.h>
#define AIRWINDOWS_NAME "Slew"
#define AIRWINDOWS_DESCRIPTION "A slew clipper, which darkens treble in an unusual way."
#define AIRWINDOWS_GUID NT_MULTICHAR( 'A','S','l','e' )
#define AIRWINDOWS_KERNELS
enum {

	kParam_One =0,
	//Add your parameters here...
	kNumberOfParameters=1
};
enum { kParamInput1, kParamOutput1, kParamOutput1mode,
kParam0, };
static const uint8_t page2[] = { kParamInput1, kParamOutput1, kParamOutput1mode };
static const _NT_parameter	parameters[] = {
NT_PARAMETER_AUDIO_INPUT( "Input 1", 1, 1 )
NT_PARAMETER_AUDIO_OUTPUT_WITH_MODE( "Output 1", 1, 13 )
{ .name = "Clamping", .min = 0, .max = 1000, .def = 0, .unit = kNT_unitNone, .scaling = kNT_scaling1000, .enumStrings = NULL },
};
static const uint8_t page1[] = {
kParam0, };
enum { kNumTemplateParameters = 3 };
#include "../include/template1.h"
struct _kernel {
	void render( const Float32* inSourceP, Float32* inDestP, UInt32 inFramesToProcess );
	void reset(void);
	float GetParameter( int index ) { return owner->GetParameter( index ); }
	_airwindowsAlgorithm* owner;

		Float32 lastSample;
		uint32_t fpd;
	
	struct _dram {
		};
	_dram* dram;
};
_kernel kernels[1];

#include "../include/template2.h"
#include "../include/templateKernels.h"
void _airwindowsAlgorithm::_kernel::render( const Float32* inSourceP, Float32* inDestP, UInt32 inFramesToProcess ) {
#define inNumChannels (1)
{

	//This code will pass-thru the audio data.
	//This is where you want to process data to produce an effect.

	
	UInt32 nSampleFrames = inFramesToProcess;
	const Float32 *sourceP = inSourceP;
	Float32 *destP = inDestP;
	Float32 overallscale = 1.0f;
	overallscale /= 44100.0f;
	overallscale *= GetSampleRate();
	Float32 inputSample;
	Float32 outputSample;
	Float32 clamp;
	Float32 threshold = pow((1-GetParameter( kParam_One )),4)/overallscale;
	
	while (nSampleFrames-- > 0) {
		
		inputSample = *sourceP;
		if (fabs(inputSample)<1.18e-23f) inputSample = fpd * 1.18e-17f;
		
		sourceP += inNumChannels;
		
		clamp = inputSample - lastSample;
		outputSample = inputSample;
		if (clamp > threshold)
			outputSample = lastSample + threshold;
		if (-clamp > threshold)
			outputSample = lastSample - threshold;
		lastSample = outputSample;
		
		//begin 32 bit floating point dither
		int expon; frexpf((float)outputSample, &expon);
		fpd ^= fpd << 13; fpd ^= fpd >> 17; fpd ^= fpd << 5;
		outputSample += ((float(fpd)-uint32_t(0x7fffffff)) * 5.5e-36l * pow(2,expon+62));
		//end 32 bit floating point dither
		
		
		*destP = outputSample;
		destP += inNumChannels;
	}
}
}
void _airwindowsAlgorithm::_kernel::reset(void) {
{
	lastSample = 0.0;
	fpd = 1.0; while (fpd < 16386) fpd = rand()*UINT32_MAX;
}
};
