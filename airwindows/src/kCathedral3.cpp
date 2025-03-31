#include <math.h>
#include <new>
#include <distingnt/api.h>
#define AIRWINDOWS_NAME "kCathedral3"
#define AIRWINDOWS_DESCRIPTION "A giant cathedral-like space using Bezier undersampling."
#define AIRWINDOWS_GUID NT_MULTICHAR( 'A','k','C','c' )
enum {

	kParam_A =0,
	kParam_B =1,
	kParam_C =2,
	kParam_D =3,
	kParam_E =4,
	//Add your parameters here...
	kNumberOfParameters=5
};
const int dscBuf = 90;
const int predelay = 15000; const int vlfpredelay = 11000;
const int delayA = 824; const int delayB = 982; const int delayC = 753; const int delayD = 402; const int delayE = 1206; const int delayF = 1235; const int delayG = 1396; const int delayH = 1330; const int delayI = 248; const int delayJ = 62; const int delayK = 1407; const int delayL = 40; const int delayM = 245; const int delayN = 1088; const int delayO = 775; const int delayP = 13; const int delayQ = 1299; const int delayR = 127; const int delayS = 1497; const int delayT = 386; const int delayU = 11; const int delayV = 971; const int delayW = 1403; const int delayX = 81; const int delayY = 1480; //7 to 162 ms, 860 seat hall  
enum { kParamInputL, kParamInputR, kParamOutputL, kParamOutputLmode, kParamOutputR, kParamOutputRmode,
kParam0, kParam1, kParam2, kParam3, kParam4, };
static const uint8_t page2[] = { kParamInputL, kParamInputR, kParamOutputL, kParamOutputLmode, kParamOutputR, kParamOutputRmode };
static const _NT_parameter	parameters[] = {
NT_PARAMETER_AUDIO_INPUT( "Input L", 1, 1 )
NT_PARAMETER_AUDIO_INPUT( "Input R", 1, 2 )
NT_PARAMETER_AUDIO_OUTPUT_WITH_MODE( "Output L", 1, 13 )
NT_PARAMETER_AUDIO_OUTPUT_WITH_MODE( "Output R", 1, 14 )
{ .name = "Top dB", .min = 7000, .max = 14000, .def = 10000, .unit = kNT_unitNone, .scaling = kNT_scaling100, .enumStrings = NULL },
{ .name = "Regen", .min = 0, .max = 1000, .def = 500, .unit = kNT_unitNone, .scaling = kNT_scaling1000, .enumStrings = NULL },
{ .name = "DeRez", .min = 0, .max = 1000, .def = 1000, .unit = kNT_unitNone, .scaling = kNT_scaling1000, .enumStrings = NULL },
{ .name = "Predelay", .min = 0, .max = 1000, .def = 0, .unit = kNT_unitNone, .scaling = kNT_scaling1000, .enumStrings = NULL },
{ .name = "Wetness", .min = 0, .max = 1000, .def = 250, .unit = kNT_unitNone, .scaling = kNT_scaling1000, .enumStrings = NULL },
};
static const uint8_t page1[] = {
kParam0, kParam1, kParam2, kParam3, kParam4, };
enum { kNumTemplateParameters = 6 };
#include "../include/template1.h"
 
	double gainOutL;
 	double gainOutR;
		
	
	
	
	
	double feedbackAL;
	double feedbackBL;
	double feedbackCL;
	double feedbackDL;
	double feedbackEL;
	
	double feedbackER;
	double feedbackJR;
	double feedbackOR;
	double feedbackTR;
	double feedbackYR;
	
	int countAL;
	int countBL;
	int countCL;
	int countDL;
	int countEL;
	int countFL;
	int countGL;
	int countHL;
	int countIL;
	int countJL;
	int countKL;
	int countLL;		
	int countML;		
	int countNL;		
	int countOL;		
	int countPL;		
	int countQL;		
	int countRL;		
	int countSL;		
	int countTL;		
	int countUL;		
	int countVL;		
	int countWL;		
	int countXL;		
	int countYL;		
	
	int countAR;
	int countBR;
	int countCR;
	int countDR;
	int countER;
	int countFR;
	int countGR;
	int countHR;
	int countIR;
	int countJR;
	int countKR;
	int countLR;		
	int countMR;		
	int countNR;		
	int countOR;		
	int countPR;		
	int countQR;		
	int countRR;		
	int countSR;		
	int countTR;		
	int countUR;		
	int countVR;		
	int countWR;		
	int countXR;		
	int countYR;
	
	int countZ;		
	int countVLF;		
		
	enum {
		prevSampL1,
		prevSlewL1,
		prevSampR1,
		prevSlewR1,
		prevSampL2,
		prevSlewL2,
		prevSampR2,
		prevSlewR2,
		prevSampL3,
		prevSlewL3,
		prevSampR3,
		prevSlewR3,
		prevSampL4,
		prevSlewL4,
		prevSampR4,
		prevSlewR4,
		prevSampL5,
		prevSlewL5,
		prevSampR5,
		prevSlewR5,
		prevSampL6,
		prevSlewL6,
		prevSampR6,
		prevSlewR6,
		prevSampL7,
		prevSlewL7,
		prevSampR7,
		prevSlewR7,
		prevSampL8,
		prevSlewL8,
		prevSampR8,
		prevSlewR8,
		prevSampL9,
		prevSlewL9,
		prevSampR9,
		prevSlewR9,
		prevSampL10,
		prevSlewL10,
		prevSampR10,
		prevSlewR10,
		pear_total
	}; //fixed frequency pear filter for ultrasonics, stereo
	
	
	double vibratoL;
	double vibratoR;
	double vibAL;
	double vibAR;
	double vibBL;
	double vibBR;
	
	double subAL;
	double subAR;
	double subBL;
	double subBR;
	double subCL;
	double subCR;
	
	double sbAL;
	double sbAR;
	double sbBL;
	double sbBR;
	double sbCL;
	double sbCR;
	
	double dBaPosL;
	int dBaXL;
	
	double dBaPosR;
	int dBaXR;
	
	double dBbPosL;
	int dBbXL;
	
	double dBbPosR;
	int dBbXR;
	
	double dBcPosL;
	int dBcXL;	
	
	double dBcPosR;
	int dBcXR;	
	
	double dBdPosL;
	int dBdXL;	
	
	double dBdPosR;
	int dBdXR;	
	
	double dBePosL;
	int dBeXL;	
	
	double dBePosR;
	int dBeXR;	
	
	enum {
		bez_AL,
		bez_AR,
		bez_BL,
		bez_BR,
		bez_CL,
		bez_CR,	
		bez_InL,
		bez_InR,
		bez_UnInL,
		bez_UnInR,
		bez_SampL,
		bez_SampR,
		bez_cycle,
		bez_total
	}; //the new undersampling. bez signifies the bezier curve reconstruction
	
	uint32_t fpdL;
	uint32_t fpdR;

	struct _dram {
		double aAL[delayA+5];
	double aBL[delayB+5];
	double aCL[delayC+5];
	double aDL[delayD+5];
	double aEL[delayE+5];
	double aFL[delayF+5];
	double aGL[delayG+5];
	double aHL[delayH+5];
	double aIL[delayI+5];
	double aJL[delayJ+5];
	double aKL[delayK+5];
	double aLL[delayL+5];
	double aML[delayM+5];
	double aNL[delayN+5];
	double aOL[delayO+5];
	double aPL[delayP+5];
	double aQL[delayQ+5];
	double aRL[delayR+5];
	double aSL[delayS+5];
	double aTL[delayT+5];
	double aUL[delayU+5];
	double aVL[delayV+5];
	double aWL[delayW+5];
	double aXL[delayX+5];
	double aYL[delayY+5];
	double aAR[delayA+5];
	double aBR[delayB+5];
	double aCR[delayC+5];
	double aDR[delayD+5];
	double aER[delayE+5];
	double aFR[delayF+5];
	double aGR[delayG+5];
	double aHR[delayH+5];
	double aIR[delayI+5];
	double aJR[delayJ+5];
	double aKR[delayK+5];
	double aLR[delayL+5];
	double aMR[delayM+5];
	double aNR[delayN+5];
	double aOR[delayO+5];
	double aPR[delayP+5];
	double aQR[delayQ+5];
	double aRR[delayR+5];
	double aSR[delayS+5];
	double aTR[delayT+5];
	double aUR[delayU+5];
	double aVR[delayV+5];
	double aWR[delayW+5];
	double aXR[delayX+5];
	double aYR[delayY+5];
	double aZL[predelay+5];
	double aZR[predelay+5];
	double aVLFL[vlfpredelay+5];
	double aVLFR[vlfpredelay+5];
	double pearA[pear_total]; //probably worth just using a number here
	double pearB[pear_total]; //probably worth just using a number here
	double pearC[pear_total]; //probably worth just using a number here
	double pearD[pear_total]; //probably worth just using a number here
	double pearE[pear_total]; //probably worth just using a number here
	double pearF[pear_total]; //probably worth just using a number here
	double dBaL[dscBuf+5];
	double dBaR[dscBuf+5];
	double dBbL[dscBuf+5];
	double dBbR[dscBuf+5];
	double dBcL[dscBuf+5];
	double dBcR[dscBuf+5];
	double dBdL[dscBuf+5];
	double dBdR[dscBuf+5];
	double dBeL[dscBuf+5];
	double dBeR[dscBuf+5];
	double bez[bez_total];
	};
	_dram* dram;
#include "../include/template2.h"
#include "../include/templateStereo.h"
void _airwindowsAlgorithm::render( const Float32* inputL, const Float32* inputR, Float32* outputL, Float32* outputR, UInt32 inFramesToProcess ) {

	UInt32 nSampleFrames = inFramesToProcess;
	double overallscale = 1.0;
	overallscale /= 44100.0;
	overallscale *= GetSampleRate();	
	
	double refdB = GetParameter( kParam_A );
	double topdB = 0.000000075 * pow(10.0,refdB/20.0) * overallscale * 0.000025;
	//the final 0.0001 scales it to the internal reverb path
	
	double regen = (1.0-pow(1.0-GetParameter( kParam_B ),3.0))*0.00029;
	double derez = GetParameter( kParam_C )/overallscale;
	if (derez < 0.0005) derez = 0.0005; if (derez > 1.0) derez = 1.0;
	derez = 1.0 / ((int)(1.0/derez));
	//this hard-locks derez to exact subdivisions of 1.0
	
	int pearStages = 5;
	double pear = 0.2/derez; if (pear > 1.0) pear = 1.0; //inside derez filter
	double pearScaled = 0.15/overallscale; //outside derez filter
	
	int adjPredelay = predelay*GetParameter( kParam_D )*derez;	
	int adjSubDelay = vlfpredelay*derez;
	double wet = GetParameter( kParam_E )*2.0;
	double dry = 2.0 - wet;
	if (wet > 1.0) wet = 1.0; else wet *= wet;
	if (wet < 0.0) wet = 0.0;
	if (dry > 1.0) dry = 1.0;
	if (dry < 0.0) dry = 0.0;
	//this reverb makes 50% full dry AND full wet, not crossfaded.
	//that's so it can be on submixes without cutting back dry channel when adjusted:
	//unless you go super heavy, you are only adjusting the added verb loudness.
	
	while (nSampleFrames-- > 0) {
		double inputSampleL = *inputL;
		double inputSampleR = *inputR;
		if (fabs(inputSampleL)<1.18e-23) inputSampleL = fpdL * 1.18e-17;
		if (fabs(inputSampleR)<1.18e-23) inputSampleR = fpdR * 1.18e-17;
		double drySampleL = inputSampleL;
		double drySampleR = inputSampleR;
		
		dram->bez[bez_cycle] += derez;
		dram->bez[bez_SampL] += ((inputSampleL+dram->bez[bez_InL]) * derez);
		dram->bez[bez_SampR] += ((inputSampleR+dram->bez[bez_InR]) * derez);
		dram->bez[bez_InL] = inputSampleL; dram->bez[bez_InR] = inputSampleR;
		if (dram->bez[bez_cycle] > 1.0) { //hit the end point and we do a reverb sample
			dram->bez[bez_cycle] = 0.0;
			
			//predelay
			dram->aZL[countZ] = dram->bez[bez_SampL];
			dram->aZR[countZ] = dram->bez[bez_SampR];
			countZ++; if (countZ < 0 || countZ > adjPredelay) countZ = 0;
			double avgSampL = dram->aZL[countZ-((countZ > adjPredelay)?adjPredelay+1:0)];
			double avgSampR = dram->aZR[countZ-((countZ > adjPredelay)?adjPredelay+1:0)];
			//end predelay
			
			//begin SubTight section
			double outSampleL = avgSampL * 0.00187;
			double outSampleR = avgSampR * 0.00187;
			double scale = 0.5+fabs(outSampleL*0.5);
			outSampleL = (subAL+(sin(subAL-outSampleL)*scale));
			subAL = outSampleL*scale;
			scale = 0.5+fabs(outSampleR*0.5);
			outSampleR = (subAR+(sin(subAR-outSampleR)*scale));
			subAR = outSampleR*scale;
			scale = 0.5+fabs(outSampleL*0.5);
			outSampleL = (subBL+(sin(subBL-outSampleL)*scale));
			subBL = outSampleL*scale;
			scale = 0.5+fabs(outSampleR*0.5);
			outSampleR = (subBR+(sin(subBR-outSampleR)*scale));
			subBR = outSampleR*scale;
			scale = 0.5+fabs(outSampleL*0.5);
			outSampleL = (subCL+(sin(subCL-outSampleL)*scale));
			subCL = outSampleL*scale;
			scale = 0.5+fabs(outSampleR*0.5);
			outSampleR = (subCR+(sin(subCR-outSampleR)*scale));
			subCR = outSampleR*scale;
			outSampleL = -outSampleL; outSampleR = -outSampleR;
			if (outSampleL > 0.25) outSampleL = 0.25; if (outSampleL < -0.25) outSampleL = -0.25;
			if (outSampleR > 0.25) outSampleR = 0.25; if (outSampleR < -0.25) outSampleR = -0.25;
			outSampleL *= 16.0;
			outSampleR *= 16.0;
			avgSampL -= outSampleL;
			avgSampR -= outSampleR;
			//end SubTight section
						
			//VLF predelay
			dram->aVLFL[countVLF] = outSampleL;
			dram->aVLFR[countVLF] = outSampleR;
			countVLF++; if (countVLF < 0 || countVLF > adjSubDelay) countVLF = 0;
			outSampleL = dram->aVLFL[countVLF-((countVLF > adjSubDelay)?adjSubDelay+1:0)] * 2.0;
			outSampleR = dram->aVLFR[countVLF-((countVLF > adjSubDelay)?adjSubDelay+1:0)] * 2.0;
			//end VLF predelay
			
			avgSampL += outSampleL;
			avgSampR += outSampleR;
			//having re-added our VLF delayed channel we can now re-use outSample
			
			dram->aAL[countAL] = avgSampL + (feedbackAL * regen);
			dram->aBL[countBL] = avgSampL + (feedbackBL * regen);
			dram->aCL[countCL] = avgSampL + (feedbackCL * regen);
			dram->aDL[countDL] = avgSampL + (feedbackDL * regen);
			dram->aEL[countEL] = avgSampL + (feedbackEL * regen);
			
			dram->aER[countER] = avgSampR + (feedbackER * regen);
			dram->aJR[countJR] = avgSampR + (feedbackJR * regen);
			dram->aOR[countOR] = avgSampR + (feedbackOR * regen);
			dram->aTR[countTR] = avgSampR + (feedbackTR * regen);
			dram->aYR[countYR] = avgSampR + (feedbackYR * regen);
			
			countAL++; if (countAL < 0 || countAL > delayA) countAL = 0;
			countBL++; if (countBL < 0 || countBL > delayB) countBL = 0;
			countCL++; if (countCL < 0 || countCL > delayC) countCL = 0;
			countDL++; if (countDL < 0 || countDL > delayD) countDL = 0;
			countEL++; if (countEL < 0 || countEL > delayE) countEL = 0;
			
			countER++; if (countER < 0 || countER > delayE) countER = 0;
			countJR++; if (countJR < 0 || countJR > delayJ) countJR = 0;
			countOR++; if (countOR < 0 || countOR > delayO) countOR = 0;
			countTR++; if (countTR < 0 || countTR > delayT) countTR = 0;
			countYR++; if (countYR < 0 || countYR > delayY) countYR = 0;
			
			double outAL = dram->aAL[countAL-((countAL > delayA)?delayA+1:0)];
			double outBL = dram->aBL[countBL-((countBL > delayB)?delayB+1:0)];
			double outCL = dram->aCL[countCL-((countCL > delayC)?delayC+1:0)];
			double outDL = dram->aDL[countDL-((countDL > delayD)?delayD+1:0)];
			double outEL = dram->aEL[countEL-((countEL > delayE)?delayE+1:0)];
			
			double outER = dram->aER[countER-((countER > delayE)?delayE+1:0)];
			double outJR = dram->aJR[countJR-((countJR > delayJ)?delayJ+1:0)];
			double outOR = dram->aOR[countOR-((countOR > delayO)?delayO+1:0)];
			double outTR = dram->aTR[countTR-((countTR > delayT)?delayT+1:0)];
			double outYR = dram->aYR[countYR-((countYR > delayY)?delayY+1:0)];
			
			//-------- one
			
			dram->aFL[countFL] = ((outAL*3.0) - ((outBL + outCL + outDL + outEL)*2.0));
			dram->aGL[countGL] = ((outBL*3.0) - ((outAL + outCL + outDL + outEL)*2.0));
			dram->aHL[countHL] = ((outCL*3.0) - ((outAL + outBL + outDL + outEL)*2.0));
			dram->aIL[countIL] = ((outDL*3.0) - ((outAL + outBL + outCL + outEL)*2.0));
			dram->aJL[countJL] = ((outEL*3.0) - ((outAL + outBL + outCL + outDL)*2.0));
			
			dram->aDR[countDR] = ((outER*3.0) - ((outJR + outOR + outTR + outYR)*2.0));
			dram->aIR[countIR] = ((outJR*3.0) - ((outER + outOR + outTR + outYR)*2.0));
			dram->aNR[countNR] = ((outOR*3.0) - ((outER + outJR + outTR + outYR)*2.0));
			dram->aSR[countSR] = ((outTR*3.0) - ((outER + outJR + outOR + outYR)*2.0));
			dram->aXR[countXR] = ((outYR*3.0) - ((outER + outJR + outOR + outTR)*2.0));
			
			countFL++; if (countFL < 0 || countFL > delayF) countFL = 0;
			countGL++; if (countGL < 0 || countGL > delayG) countGL = 0;
			countHL++; if (countHL < 0 || countHL > delayH) countHL = 0;
			countIL++; if (countIL < 0 || countIL > delayI) countIL = 0;
			countJL++; if (countJL < 0 || countJL > delayJ) countJL = 0;
			
			countDR++; if (countDR < 0 || countDR > delayD) countDR = 0;
			countIR++; if (countIR < 0 || countIR > delayI) countIR = 0;
			countNR++; if (countNR < 0 || countNR > delayN) countNR = 0;
			countSR++; if (countSR < 0 || countSR > delayS) countSR = 0;
			countXR++; if (countXR < 0 || countXR > delayX) countXR = 0;
			
			double outFL = dram->aFL[countFL-((countFL > delayF)?delayF+1:0)];
			double outGL = dram->aGL[countGL-((countGL > delayG)?delayG+1:0)];
			double outHL = dram->aHL[countHL-((countHL > delayH)?delayH+1:0)];
			double outIL = dram->aIL[countIL-((countIL > delayI)?delayI+1:0)];
			double outJL = dram->aJL[countJL-((countJL > delayJ)?delayJ+1:0)];
			
			double outDR = dram->aDR[countDR-((countDR > delayD)?delayD+1:0)];
			double outIR = dram->aIR[countIR-((countIR > delayI)?delayI+1:0)];
			double outNR = dram->aNR[countNR-((countNR > delayN)?delayN+1:0)];
			double outSR = dram->aSR[countSR-((countSR > delayS)?delayS+1:0)];
			double outXR = dram->aXR[countXR-((countXR > delayX)?delayX+1:0)];
			
			//-------- two
			
			dram->aKL[countKL] = ((outFL*3.0) - ((outGL + outHL + outIL + outJL)*2.0));
			dram->aLL[countLL] = ((outGL*3.0) - ((outFL + outHL + outIL + outJL)*2.0));
			dram->aML[countML] = ((outHL*3.0) - ((outFL + outGL + outIL + outJL)*2.0));
			dram->aNL[countNL] = ((outIL*3.0) - ((outFL + outGL + outHL + outJL)*2.0));
			dram->aOL[countOL] = ((outJL*3.0) - ((outFL + outGL + outHL + outIL)*2.0));
			
			dram->aCR[countCR] = ((outDR*3.0) - ((outIR + outNR + outSR + outXR)*2.0));
			dram->aHR[countHR] = ((outIR*3.0) - ((outDR + outNR + outSR + outXR)*2.0));
			dram->aMR[countMR] = ((outNR*3.0) - ((outDR + outIR + outSR + outXR)*2.0));
			dram->aRR[countRR] = ((outSR*3.0) - ((outDR + outIR + outNR + outXR)*2.0));
			dram->aWR[countWR] = ((outXR*3.0) - ((outDR + outIR + outNR + outSR)*2.0));
			
			countKL++; if (countKL < 0 || countKL > delayK) countKL = 0;
			countLL++; if (countLL < 0 || countLL > delayL) countLL = 0;
			countML++; if (countML < 0 || countML > delayM) countML = 0;
			countNL++; if (countNL < 0 || countNL > delayN) countNL = 0;
			countOL++; if (countOL < 0 || countOL > delayO) countOL = 0;
			
			countCR++; if (countCR < 0 || countCR > delayC) countCR = 0;
			countHR++; if (countHR < 0 || countHR > delayH) countHR = 0;
			countMR++; if (countMR < 0 || countMR > delayM) countMR = 0;
			countRR++; if (countRR < 0 || countRR > delayR) countRR = 0;
			countWR++; if (countWR < 0 || countWR > delayW) countWR = 0;
			
			double outKL = dram->aKL[countKL-((countKL > delayK)?delayK+1:0)];
			double outLL = dram->aLL[countLL-((countLL > delayL)?delayL+1:0)];
			double outML = dram->aML[countML-((countML > delayM)?delayM+1:0)];
			double outNL = dram->aNL[countNL-((countNL > delayN)?delayN+1:0)];
			double outOL = dram->aOL[countOL-((countOL > delayO)?delayO+1:0)];
			
			double outCR = dram->aCR[countCR-((countCR > delayC)?delayC+1:0)];
			double outHR = dram->aHR[countHR-((countHR > delayH)?delayH+1:0)];
			double outMR = dram->aMR[countMR-((countMR > delayM)?delayM+1:0)];
			double outRR = dram->aRR[countRR-((countRR > delayR)?delayR+1:0)];
			double outWR = dram->aWR[countWR-((countWR > delayW)?delayW+1:0)];
			
			//-------- three
			
			dram->aPL[countPL] = ((outKL*3.0) - ((outLL + outML + outNL + outOL)*2.0));
			dram->aQL[countQL] = ((outLL*3.0) - ((outKL + outML + outNL + outOL)*2.0));
			dram->aRL[countRL] = ((outML*3.0) - ((outKL + outLL + outNL + outOL)*2.0));
			dram->aSL[countSL] = ((outNL*3.0) - ((outKL + outLL + outML + outOL)*2.0));
			dram->aTL[countTL] = ((outOL*3.0) - ((outKL + outLL + outML + outNL)*2.0));
			
			dram->aBR[countBR] = ((outCR*3.0) - ((outHR + outMR + outRR + outWR)*2.0));
			dram->aGR[countGR] = ((outHR*3.0) - ((outCR + outMR + outRR + outWR)*2.0));
			dram->aLR[countLR] = ((outMR*3.0) - ((outCR + outHR + outRR + outWR)*2.0));
			dram->aQR[countQR] = ((outRR*3.0) - ((outCR + outHR + outMR + outWR)*2.0));
			dram->aVR[countVR] = ((outWR*3.0) - ((outCR + outHR + outMR + outRR)*2.0));
			
			countPL++; if (countPL < 0 || countPL > delayP) countPL = 0;
			countQL++; if (countQL < 0 || countQL > delayQ) countQL = 0;
			countRL++; if (countRL < 0 || countRL > delayR) countRL = 0;
			countSL++; if (countSL < 0 || countSL > delayS) countSL = 0;
			countTL++; if (countTL < 0 || countTL > delayT) countTL = 0;
			
			countBR++; if (countBR < 0 || countBR > delayB) countBR = 0;
			countGR++; if (countGR < 0 || countGR > delayG) countGR = 0;
			countLR++; if (countLR < 0 || countLR > delayL) countLR = 0;
			countQR++; if (countQR < 0 || countQR > delayQ) countQR = 0;
			countVR++; if (countVR < 0 || countVR > delayV) countVR = 0;
			
			double outPL = dram->aPL[countPL-((countPL > delayP)?delayP+1:0)];
			double outQL = dram->aQL[countQL-((countQL > delayQ)?delayQ+1:0)];
			double outRL = dram->aRL[countRL-((countRL > delayR)?delayR+1:0)];
			double outSL = dram->aSL[countSL-((countSL > delayS)?delayS+1:0)];
			double outTL = dram->aTL[countTL-((countTL > delayT)?delayT+1:0)];
			
			double outBR = dram->aBR[countBR-((countBR > delayB)?delayB+1:0)];
			double outGR = dram->aGR[countGR-((countGR > delayG)?delayG+1:0)];
			double outLR = dram->aLR[countLR-((countLR > delayL)?delayL+1:0)];
			double outQR = dram->aQR[countQR-((countQR > delayQ)?delayQ+1:0)];
			double outVR = dram->aVR[countVR-((countVR > delayV)?delayV+1:0)];
			
			//-------- four
			
			dram->aVL[countVL] = ((outQL*3.0) - ((outPL + outRL + outSL + outTL)*2.0));
			dram->aWL[countWL] = ((outRL*3.0) - ((outPL + outQL + outSL + outTL)*2.0));
			dram->aXL[countXL] = ((outSL*3.0) - ((outPL + outQL + outRL + outTL)*2.0));
			dram->aYL[countYL] = ((outTL*3.0) - ((outPL + outQL + outRL + outSL)*2.0));
			
			dram->aAR[countAR] = ((outBR*3.0) - ((outGR + outLR + outQR + outVR)*2.0));
			dram->aFR[countFR] = ((outGR*3.0) - ((outBR + outLR + outQR + outVR)*2.0));
			dram->aKR[countKR] = ((outLR*3.0) - ((outBR + outGR + outQR + outVR)*2.0));
			dram->aPR[countPR] = ((outQR*3.0) - ((outBR + outGR + outLR + outVR)*2.0));
			
			double outUL = ((outPL*3.0) - ((outQL + outRL + outSL + outTL)*2.0)) - (dram->aUL[(countUL+1)-((countUL+1 > delayU)?delayU+1:0)]*0.618033988749894848204586);
			double outUR = ((outVR*3.0) - ((outBR + outGR + outLR + outQR)*2.0)) - (dram->aUR[(countUR+1)-((countUR+1 > delayU)?delayU+1:0)]*0.618033988749894848204586);
			dram->aUL[countUL] = outUL; outUL *= 0.618033988749894848204586;
			dram->aUR[countUR] = outUR; outUR *= 0.618033988749894848204586;
			countUL++; if (countUL < 0 || countUL > delayU) countUL = 0;
			countUR++; if (countUR < 0 || countUR > delayU) countUR = 0;
			outUL += dram->aUL[countUL-((countUL > delayU)?delayU+1:0)];
			outUR += dram->aUR[countUR-((countUR > delayU)?delayU+1:0)];
			//the 11-length delay slot becomes a sole allpass
			
			vibBL = vibAL; vibAL = outUL;
			vibBR = vibAR; vibAR = outUR; //tiny two sample delay chains
			vibratoL += fpdL * 0.5e-13; if (vibratoL > M_PI*2.0) vibratoL -= M_PI*2.0;
			vibratoR += fpdR * 0.5e-13; if (vibratoR > M_PI*2.0) vibratoR -= M_PI*2.0;
			double quadL = sin(vibratoL)+1.0;
			double quadR = sin(vibratoR)+1.0;
			//quadrature delay points play back from a position in delay chains
			if (quadL < 1.0) outUL = (outUL*(1.0-quadL))+(vibAL*quadL);
			else outUL = (vibAL*(1.0-(quadL-1.0)))+(vibBL*(quadL-1.0));
			if (quadR < 1.0) outUR = (outUR*(1.0-quadR))+(vibAR*quadR);
			else outUR = (vibAR*(1.0-(quadR-1.0)))+(vibBR*(quadR-1.0));
			//also, pitch drift this allpass slot for very subtle motion
			
			countVL++; if (countVL < 0 || countVL > delayV) countVL = 0;
			countWL++; if (countWL < 0 || countWL > delayW) countWL = 0;
			countXL++; if (countXL < 0 || countXL > delayX) countXL = 0;
			countYL++; if (countYL < 0 || countYL > delayY) countYL = 0;
			
			countAR++; if (countAR < 0 || countAR > delayA) countAR = 0;
			countFR++; if (countFR < 0 || countFR > delayF) countFR = 0;
			countKR++; if (countKR < 0 || countKR > delayK) countKR = 0;
			countPR++; if (countPR < 0 || countPR > delayP) countPR = 0;
			
			double outVL = dram->aVL[countVL-((countVL > delayV)?delayV+1:0)];
			double outWL = dram->aWL[countWL-((countWL > delayW)?delayW+1:0)];
			double outXL = dram->aXL[countXL-((countXL > delayX)?delayX+1:0)];
			double outYL = dram->aYL[countYL-((countYL > delayY)?delayY+1:0)];
			
			double outAR = dram->aAR[countAR-((countAR > delayA)?delayA+1:0)];
			double outFR = dram->aFR[countFR-((countFR > delayF)?delayF+1:0)];
			double outKR = dram->aKR[countKR-((countKR > delayK)?delayK+1:0)];
			double outPR = dram->aPR[countPR-((countPR > delayP)?delayP+1:0)];
			
			//-------- five
			
			feedbackAL = ((outAR*3.0) - ((outFR + outKR + outPR + outUR)*2.0));
			feedbackER = ((outUL*3.0) - ((outVL + outWL + outXL + outYL)*2.0));
			for (int x = 0; x < 1; x += 4) {
				double slew = ((feedbackAL - dram->pearA[x]) + dram->pearA[x+1])*pear*0.5;
				dram->pearA[x] = feedbackAL = (pear * feedbackAL) + ((1.0-pear) * (dram->pearA[x] + dram->pearA[x+1]));
				dram->pearA[x+1] = slew;
				slew = ((feedbackER - dram->pearA[x+2]) + dram->pearA[x+3])*pear*0.5;
				dram->pearA[x+2] = feedbackER = (pear * feedbackER) + ((1.0-pear) * (dram->pearA[x+2] + dram->pearA[x+3]));
				dram->pearA[x+3] = slew;
			}
			//Air Discontinuity A begin
			feedbackAL *= topdB;
			if (feedbackAL < -0.222) feedbackAL = -0.222; if (feedbackAL > 0.222) feedbackAL = 0.222;
			dram->dBaL[dBaXL] = feedbackAL; dBaPosL *= 0.5; dBaPosL += fabs((feedbackAL*((feedbackAL*0.25)-0.5))*0.5);
			int dBdly = floor(dBaPosL*dscBuf);
			double dBi = (dBaPosL*dscBuf)-dBdly;
			feedbackAL = dram->dBaL[dBaXL-dBdly +((dBaXL-dBdly < 0)?dscBuf:0)]*(1.0-dBi);
			dBdly++; feedbackAL += dram->dBaL[dBaXL-dBdly +((dBaXL-dBdly < 0)?dscBuf:0)]*dBi;
			dBaXL++; if (dBaXL < 0 || dBaXL >= dscBuf) dBaXL = 0;
			feedbackAL /= topdB;
			feedbackER *= topdB;
			if (feedbackER < -0.222) feedbackER = -0.222; if (feedbackER > 0.222) feedbackER = 0.222;
			dram->dBaR[dBaXR] = feedbackER; dBaPosR *= 0.5; dBaPosR += fabs((feedbackER*((feedbackER*0.25)-0.5))*0.5);
			dBdly = floor(dBaPosR*dscBuf);
			dBi = (dBaPosR*dscBuf)-dBdly;
			feedbackER = dram->dBaR[dBaXR-dBdly +((dBaXR-dBdly < 0)?dscBuf:0)]*(1.0-dBi);
			dBdly++; feedbackER += dram->dBaR[dBaXR-dBdly +((dBaXR-dBdly < 0)?dscBuf:0)]*dBi;
			dBaXR++; if (dBaXR < 0 || dBaXR >= dscBuf) dBaXR = 0;
			feedbackER /= topdB;
			//Air Discontinuity A end			
			
			feedbackBL = ((outVL*3.0) - ((outUL + outWL + outXL + outYL)*2.0));
			feedbackJR = ((outFR*3.0) - ((outAR + outKR + outPR + outUR)*2.0));
			for (int x = 0; x < pearStages; x += 4) {
				double slew = ((feedbackBL - dram->pearB[x]) + dram->pearB[x+1])*pear*0.5;
				dram->pearB[x] = feedbackBL = (pear * feedbackBL) + ((1.0-pear) * (dram->pearB[x] + dram->pearB[x+1]));
				dram->pearB[x+1] = slew;
				slew = ((feedbackJR - dram->pearB[x+2]) + dram->pearB[x+3])*pear*0.5;
				dram->pearB[x+2] = feedbackJR = (pear * feedbackJR) + ((1.0-pear) * (dram->pearB[x+2] + dram->pearB[x+3]));
				dram->pearB[x+3] = slew;
			}
			//Air Discontinuity B begin
			feedbackBL *= topdB;
			if (feedbackBL < -0.222) feedbackBL = -0.222; if (feedbackBL > 0.222) feedbackBL = 0.222;
			dram->dBbL[dBbXL] = feedbackBL;  dBbPosL *= 0.5; dBbPosL += fabs((feedbackBL*((feedbackBL*0.25)-0.5))*0.5);
			dBdly = floor(dBbPosL*dscBuf); dBi = (dBbPosL*dscBuf)-dBdly;
			feedbackBL = dram->dBbL[dBbXL-dBdly +((dBbXL-dBdly < 0)?dscBuf:0)]*(1.0-dBi);
			dBdly++; feedbackBL += dram->dBbL[dBbXL-dBdly +((dBbXL-dBdly < 0)?dscBuf:0)]*dBi;
			dBbXL++; if (dBbXL < 0 || dBbXL >= dscBuf) dBbXL = 0;
			feedbackBL /= topdB;
			feedbackJR *= topdB;
			if (feedbackJR < -0.222) feedbackJR = -0.222; if (feedbackJR > 0.222) feedbackJR = 0.222;
			dram->dBbR[dBbXR] = feedbackJR;  dBbPosR *= 0.5; dBbPosR += fabs((feedbackJR*((feedbackJR*0.25)-0.5))*0.5);
			dBdly = floor(dBbPosR*dscBuf); dBi = (dBbPosR*dscBuf)-dBdly;
			feedbackJR = dram->dBbR[dBbXR-dBdly +((dBbXR-dBdly < 0)?dscBuf:0)]*(1.0-dBi);
			dBdly++; feedbackJR += dram->dBbR[dBbXR-dBdly +((dBbXR-dBdly < 0)?dscBuf:0)]*dBi;
			dBbXR++; if (dBbXR < 0 || dBbXR >= dscBuf) dBbXR = 0;
			feedbackJR /= topdB;
			//Air Discontinuity B end			
			
			feedbackCL = ((outWL*3.0) - ((outUL + outVL + outXL + outYL)*2.0));
			feedbackOR = ((outKR*3.0) - ((outAR + outFR + outPR + outUR)*2.0));
			for (int x = 0; x < pearStages; x += 4) {
				double slew = ((feedbackCL - dram->pearC[x]) + dram->pearC[x+1])*pear*0.5;
				dram->pearC[x] = feedbackCL = (pear * feedbackCL) + ((1.0-pear) * (dram->pearC[x] + dram->pearC[x+1]));
				dram->pearC[x+1] = slew;
				slew = ((feedbackOR - dram->pearC[x+2]) + dram->pearC[x+3])*pear*0.5;
				dram->pearC[x+2] = feedbackOR = (pear * feedbackOR) + ((1.0-pear) * (dram->pearC[x+2] + dram->pearC[x+3]));
				dram->pearC[x+3] = slew;
			}
			//Air Discontinuity C begin
			feedbackCL *= topdB;
			if (feedbackCL < -0.222) feedbackCL = -0.222; if (feedbackCL > 0.222) feedbackCL = 0.222;
			dram->dBcL[dBcXL] = feedbackCL;  dBcPosL *= 0.5; dBcPosL += fabs((feedbackCL*((feedbackCL*0.25)-0.5))*0.5);
			dBdly = floor(dBcPosL*dscBuf); dBi = (dBcPosL*dscBuf)-dBdly;
			feedbackCL = dram->dBcL[dBcXL-dBdly +((dBcXL-dBdly < 0)?dscBuf:0)]*(1.0-dBi);
			dBdly++; feedbackCL += dram->dBcL[dBcXL-dBdly +((dBcXL-dBdly < 0)?dscBuf:0)]*dBi;
			dBcXL++; if (dBcXL < 0 || dBcXL >= dscBuf) dBcXL = 0;
			feedbackCL /= topdB;
			feedbackOR *= topdB;
			if (feedbackOR < -0.222) feedbackOR = -0.222; if (feedbackOR > 0.222) feedbackOR = 0.222;
			dram->dBcR[dBcXR] = feedbackOR;  dBcPosR *= 0.5; dBcPosR += fabs((feedbackOR*((feedbackOR*0.25)-0.5))*0.5);
			dBdly = floor(dBcPosR*dscBuf); dBi = (dBcPosR*dscBuf)-dBdly;
			feedbackOR = dram->dBcR[dBcXR-dBdly +((dBcXR-dBdly < 0)?dscBuf:0)]*(1.0-dBi);
			dBdly++; feedbackOR += dram->dBcR[dBcXR-dBdly +((dBcXR-dBdly < 0)?dscBuf:0)]*dBi;
			dBcXR++; if (dBcXR < 0 || dBcXR >= dscBuf) dBcXR = 0;
			feedbackOR /= topdB;
			//Air Discontinuity C end			
			
			feedbackDL = ((outXL*3.0) - ((outUL + outVL + outWL + outYL)*2.0));
			feedbackTR = ((outPR*3.0) - ((outAR + outFR + outKR + outUR)*2.0));
			for (int x = 0; x < pearStages; x += 4) {
				double slew = ((feedbackDL - dram->pearD[x]) + dram->pearD[x+1])*pear*0.5;
				dram->pearD[x] = feedbackDL = (pear * feedbackDL) + ((1.0-pear) * (dram->pearD[x] + dram->pearD[x+1]));
				dram->pearD[x+1] = slew;
				slew = ((feedbackTR - dram->pearD[x+2]) + dram->pearD[x+3])*pear*0.5;
				dram->pearD[x+2] = feedbackTR = (pear * feedbackTR) + ((1.0-pear) * (dram->pearD[x+2] + dram->pearD[x+3]));
				dram->pearD[x+3] = slew;
			}
			//Air Discontinuity D begin
			feedbackDL *= topdB;
			if (feedbackDL < -0.222) feedbackDL = -0.222; if (feedbackDL > 0.222) feedbackDL = 0.222;
			dram->dBdL[dBdXL] = feedbackDL;  dBdPosL *= 0.5; dBdPosL += fabs((feedbackDL*((feedbackDL*0.25)-0.5))*0.5);
			dBdly = floor(dBdPosL*dscBuf); dBi = (dBdPosL*dscBuf)-dBdly;
			feedbackDL = dram->dBdL[dBdXL-dBdly +((dBdXL-dBdly < 0)?dscBuf:0)]*(1.0-dBi);
			dBdly++; feedbackDL += dram->dBdL[dBdXL-dBdly +((dBdXL-dBdly < 0)?dscBuf:0)]*dBi;
			dBdXL++; if (dBdXL < 0 || dBdXL >= dscBuf) dBdXL = 0;
			feedbackDL /= topdB;
			feedbackTR *= topdB;
			if (feedbackTR < -0.222) feedbackTR = -0.222; if (feedbackTR > 0.222) feedbackTR = 0.222;
			dram->dBdR[dBdXR] = feedbackTR;  dBdPosR *= 0.5; dBdPosR += fabs((feedbackTR*((feedbackTR*0.25)-0.5))*0.5);
			dBdly = floor(dBdPosR*dscBuf); dBi = (dBdPosR*dscBuf)-dBdly;
			feedbackTR = dram->dBdR[dBdXR-dBdly +((dBdXR-dBdly < 0)?dscBuf:0)]*(1.0-dBi);
			dBdly++; feedbackTR += dram->dBdR[dBdXR-dBdly +((dBdXR-dBdly < 0)?dscBuf:0)]*dBi;
			dBdXR++; if (dBdXR < 0 || dBdXR >= dscBuf) dBdXR = 0;
			feedbackTR /= topdB;
			//Air Discontinuity D end
			
			
			feedbackEL = ((outYL*3.0) - ((outUL + outVL + outWL + outXL)*2.0));
			feedbackYR = ((outUR*3.0) - ((outAR + outFR + outKR + outPR)*2.0));
			for (int x = 0; x < pearStages; x += 4) {
				double slew = ((feedbackEL - dram->pearE[x]) + dram->pearE[x+1])*pear*0.5;
				dram->pearE[x] = feedbackEL = (pear * feedbackEL) + ((1.0-pear) * (dram->pearE[x] + dram->pearE[x+1]));
				dram->pearE[x+1] = slew;
				slew = ((feedbackYR - dram->pearE[x+2]) + dram->pearE[x+3])*pear*0.5;
				dram->pearE[x+2] = feedbackYR = (pear * feedbackYR) + ((1.0-pear) * (dram->pearE[x+2] + dram->pearE[x+3]));
				dram->pearE[x+3] = slew;
			}
			//Air Discontinuity E begin
			feedbackEL *= topdB;
			if (feedbackEL < -0.222) feedbackEL = -0.222; if (feedbackEL > 0.222) feedbackEL = 0.222;
			dram->dBeL[dBeXL] = feedbackEL;  dBePosL *= 0.5; dBePosL += fabs((feedbackEL*((feedbackEL*0.25)-0.5))*0.5);
			dBdly = floor(dBePosL*dscBuf); dBi = (dBePosL*dscBuf)-dBdly;
			feedbackEL = dram->dBeL[dBeXL-dBdly +((dBeXL-dBdly < 0)?dscBuf:0)]*(1.0-dBi);
			dBdly++; feedbackEL += dram->dBeL[dBeXL-dBdly +((dBeXL-dBdly < 0)?dscBuf:0)]*dBi;
			dBeXL++; if (dBeXL < 0 || dBeXL >= dscBuf) dBeXL = 0;
			feedbackEL /= topdB;
			feedbackYR *= topdB;
			if (feedbackYR < -0.222) feedbackYR = -0.222; if (feedbackYR > 0.222) feedbackYR = 0.222;
			dram->dBeR[dBeXR] = feedbackYR;  dBePosR *= 0.5; dBePosR += fabs((feedbackYR*((feedbackYR*0.25)-0.5))*0.5);
			dBdly = floor(dBePosR*dscBuf); dBi = (dBePosR*dscBuf)-dBdly;
			feedbackYR = dram->dBeR[dBeXR-dBdly +((dBeXR-dBdly < 0)?dscBuf:0)]*(1.0-dBi);
			dBdly++; feedbackYR += dram->dBeR[dBeXR-dBdly +((dBeXR-dBdly < 0)?dscBuf:0)]*dBi;
			dBeXR++; if (dBeXR < 0 || dBeXR >= dscBuf) dBeXR = 0;
			feedbackYR /= topdB;
			//Air Discontinuity E end			
			//which we need to feed back into the input again, a bit
			
			inputSampleL = (outUL + outVL + outWL + outXL + outYL)*0.0008;
			inputSampleR = (outAR + outFR + outKR + outPR + outUR)*0.0008;
			//and take the final combined sum of outputs, corrected for Householder gain
			
			//begin SubBoost section
			outSampleL = inputSampleL * 0.00186;
			outSampleR = inputSampleR * 0.00186;
			scale = 0.5+fabs(outSampleL*0.5);
			outSampleL = (sbAL+(sin(sbAL-outSampleL)*scale));
			sbAL = outSampleL*scale;
			scale = 0.5+fabs(outSampleR*0.5);
			outSampleR = (sbAR+(sin(sbAR-outSampleR)*scale));
			sbAR = outSampleR*scale;
			scale = 0.5+fabs(outSampleL*0.5);
			outSampleL = (sbBL+(sin(sbBL-outSampleL)*scale));
			sbBL = outSampleL*scale;
			scale = 0.5+fabs(outSampleR*0.5);
			outSampleR = (sbBR+(sin(sbBR-outSampleR)*scale));
			sbBR = outSampleR*scale;
			scale = 0.5+fabs(outSampleL*0.5);
			outSampleL = (sbCL+(sin(sbCL-outSampleL)*scale));
			sbCL = outSampleL*scale;
			scale = 0.5+fabs(outSampleR*0.5);
			outSampleR = (sbCR+(sin(sbCR-outSampleR)*scale));
			sbCR = outSampleR*scale;
			outSampleL = -outSampleL; outSampleR = -outSampleR;
			if (outSampleL > 0.25) outSampleL = 0.25; if (outSampleL < -0.25) outSampleL = -0.25;
			if (outSampleR > 0.25) outSampleR = 0.25; if (outSampleR < -0.25) outSampleR = -0.25;
			outSampleL *= 32.0;
			outSampleR *= 32.0;
			inputSampleL += outSampleL;
			inputSampleR += outSampleR;
			//end SubBoost section
			
			dram->bez[bez_CL] = dram->bez[bez_BL];
			dram->bez[bez_BL] = dram->bez[bez_AL];
			dram->bez[bez_AL] = inputSampleL;
			dram->bez[bez_SampL] = 0.0;
			
			dram->bez[bez_CR] = dram->bez[bez_BR];
			dram->bez[bez_BR] = dram->bez[bez_AR];
			dram->bez[bez_AR] = inputSampleR;
			dram->bez[bez_SampR] = 0.0;
		}
		double CBL = (dram->bez[bez_CL]*(1.0-dram->bez[bez_cycle]))+(dram->bez[bez_BL]*dram->bez[bez_cycle]);
		double CBR = (dram->bez[bez_CR]*(1.0-dram->bez[bez_cycle]))+(dram->bez[bez_BR]*dram->bez[bez_cycle]);
		double BAL = (dram->bez[bez_BL]*(1.0-dram->bez[bez_cycle]))+(dram->bez[bez_AL]*dram->bez[bez_cycle]);
		double BAR = (dram->bez[bez_BR]*(1.0-dram->bez[bez_cycle]))+(dram->bez[bez_AR]*dram->bez[bez_cycle]);
		double CBAL = (dram->bez[bez_BL]+(CBL*(1.0-dram->bez[bez_cycle]))+(BAL*dram->bez[bez_cycle]))*0.125;
		double CBAR = (dram->bez[bez_BR]+(CBR*(1.0-dram->bez[bez_cycle]))+(BAR*dram->bez[bez_cycle]))*0.125;
		inputSampleL = CBAL;
		inputSampleR = CBAR;
		
		if (inputSampleL > 1.0) inputSampleL = 1.0;
		if (inputSampleL < -1.0) inputSampleL = -1.0;
		if (inputSampleR > 1.0) inputSampleR = 1.0;
		if (inputSampleR < -1.0) inputSampleR = -1.0;
		
		for (int x = 0; x < 1; x += 4) {
			double slew = ((inputSampleL - dram->pearF[x]) + dram->pearF[x+1])*pearScaled*0.5;
			dram->pearF[x] = inputSampleL = (pearScaled * inputSampleL) + ((1.0-pearScaled) * (dram->pearF[x] + dram->pearF[x+1]));
			dram->pearF[x+1] = slew;
			slew = ((inputSampleR - dram->pearF[x+2]) + dram->pearF[x+3])*pearScaled*0.5;
			dram->pearF[x+2] = inputSampleR = (pearScaled * inputSampleR) + ((1.0-pearScaled) * (dram->pearF[x+2] + dram->pearF[x+3]));
			dram->pearF[x+3] = slew;
		}
		
		if (wet < 1.0) {inputSampleL *= wet; inputSampleR *= wet;}
		if (dry < 1.0) {drySampleL *= dry; drySampleR *= dry;}
		inputSampleL += drySampleL; inputSampleR += drySampleR;
		//this is our submix verb dry/wet: 0.5 is BOTH at FULL VOLUME
		//purpose is that, if you're adding verb, you're not altering other balances
		
		//begin 32 bit stereo floating point dither
		int expon; frexpf((float)inputSampleL, &expon);
		fpdL ^= fpdL << 13; fpdL ^= fpdL >> 17; fpdL ^= fpdL << 5;
		inputSampleL += ((double(fpdL)-uint32_t(0x7fffffff)) * 5.5e-36l * pow(2,expon+62));
		frexpf((float)inputSampleR, &expon);
		fpdR ^= fpdR << 13; fpdR ^= fpdR >> 17; fpdR ^= fpdR << 5;
		inputSampleR += ((double(fpdR)-uint32_t(0x7fffffff)) * 5.5e-36l * pow(2,expon+62));
		//end 32 bit stereo floating point dither
		
		*outputL = inputSampleL;
		*outputR = inputSampleR;
		//direct stereo out
		
		inputL += 1;
		inputR += 1;
		outputL += 1;
		outputR += 1;
	}
	};
int _airwindowsAlgorithm::reset(void) {

{
	gainOutL = gainOutR = 1.0;
		
	for(int count = 0; count < delayA+2; count++) {dram->aAL[count] = 0.0; dram->aAR[count] = 0.0;}
	for(int count = 0; count < delayB+2; count++) {dram->aBL[count] = 0.0; dram->aBR[count] = 0.0;}
	for(int count = 0; count < delayC+2; count++) {dram->aCL[count] = 0.0; dram->aCR[count] = 0.0;}
	for(int count = 0; count < delayD+2; count++) {dram->aDL[count] = 0.0; dram->aDR[count] = 0.0;}
	for(int count = 0; count < delayE+2; count++) {dram->aEL[count] = 0.0; dram->aER[count] = 0.0;}
	for(int count = 0; count < delayF+2; count++) {dram->aFL[count] = 0.0; dram->aFR[count] = 0.0;}
	for(int count = 0; count < delayG+2; count++) {dram->aGL[count] = 0.0; dram->aGR[count] = 0.0;}
	for(int count = 0; count < delayH+2; count++) {dram->aHL[count] = 0.0; dram->aHR[count] = 0.0;}
	for(int count = 0; count < delayI+2; count++) {dram->aIL[count] = 0.0; dram->aIR[count] = 0.0;}
	for(int count = 0; count < delayJ+2; count++) {dram->aJL[count] = 0.0; dram->aJR[count] = 0.0;}
	for(int count = 0; count < delayK+2; count++) {dram->aKL[count] = 0.0; dram->aKR[count] = 0.0;}
	for(int count = 0; count < delayL+2; count++) {dram->aLL[count] = 0.0; dram->aLR[count] = 0.0;}
	for(int count = 0; count < delayM+2; count++) {dram->aML[count] = 0.0; dram->aMR[count] = 0.0;}
	for(int count = 0; count < delayN+2; count++) {dram->aNL[count] = 0.0; dram->aNR[count] = 0.0;}
	for(int count = 0; count < delayO+2; count++) {dram->aOL[count] = 0.0; dram->aOR[count] = 0.0;}
	for(int count = 0; count < delayP+2; count++) {dram->aPL[count] = 0.0; dram->aPR[count] = 0.0;}
	for(int count = 0; count < delayQ+2; count++) {dram->aQL[count] = 0.0; dram->aQR[count] = 0.0;}
	for(int count = 0; count < delayR+2; count++) {dram->aRL[count] = 0.0; dram->aRR[count] = 0.0;}
	for(int count = 0; count < delayS+2; count++) {dram->aSL[count] = 0.0; dram->aSR[count] = 0.0;}
	for(int count = 0; count < delayT+2; count++) {dram->aTL[count] = 0.0; dram->aTR[count] = 0.0;}
	for(int count = 0; count < delayU+2; count++) {dram->aUL[count] = 0.0; dram->aUR[count] = 0.0;}
	for(int count = 0; count < delayV+2; count++) {dram->aVL[count] = 0.0; dram->aVR[count] = 0.0;}
	for(int count = 0; count < delayW+2; count++) {dram->aWL[count] = 0.0; dram->aWR[count] = 0.0;}
	for(int count = 0; count < delayX+2; count++) {dram->aXL[count] = 0.0; dram->aXR[count] = 0.0;}
	for(int count = 0; count < delayY+2; count++) {dram->aYL[count] = 0.0; dram->aYR[count] = 0.0;}
	
	for(int count = 0; count < predelay+2; count++) {dram->aZL[count] = 0.0; dram->aZR[count] = 0.0;}
	for(int count = 0; count < vlfpredelay+2; count++) {dram->aVLFL[count] = 0.0; dram->aVLFR[count] = 0.0;}
	
	feedbackAL = 0.0;
	feedbackBL = 0.0;
	feedbackCL = 0.0;
	feedbackDL = 0.0;
	feedbackEL = 0.0;
	
	feedbackER = 0.0;
	feedbackJR = 0.0;
	feedbackOR = 0.0;
	feedbackTR = 0.0;
	feedbackYR = 0.0;
	
	countAL = 1;
	countBL = 1;
	countCL = 1;
	countDL = 1;	
	countEL = 1;
	countFL = 1;
	countGL = 1;
	countHL = 1;
	countIL = 1;
	countJL = 1;
	countKL = 1;
	countLL = 1;
	countML = 1;
	countNL = 1;
	countOL = 1;
	countPL = 1;
	countQL = 1;
	countRL = 1;
	countSL = 1;
	countTL = 1;
	countUL = 1;
	countVL = 1;
	countWL = 1;
	countXL = 1;
	countYL = 1;
	
	countAR = 1;
	countBR = 1;
	countCR = 1;
	countDR = 1;	
	countER = 1;
	countFR = 1;
	countGR = 1;
	countHR = 1;
	countIR = 1;
	countJR = 1;
	countKR = 1;
	countLR = 1;
	countMR = 1;
	countNR = 1;
	countOR = 1;
	countPR = 1;
	countQR = 1;
	countRR = 1;
	countSR = 1;
	countTR = 1;
	countUR = 1;
	countVR = 1;
	countWR = 1;
	countXR = 1;
	countYR = 1;
	
	countZ = 1;
	countVLF = 1;
		
	for (int x = 0; x < pear_total; x++) {dram->pearA[x] = 0.0; dram->pearB[x] = 0.0; dram->pearC[x] = 0.0; dram->pearD[x] = 0.0; dram->pearE[x] = 0.0; dram->pearF[x] = 0.0;}
	//from PearEQ
	
	vibratoL = vibAL = vibAR = vibBL = vibBR = 0.0;
	vibratoR = M_PI_4;
	
	subAL = subAR = subBL = subBR = subCL = subCR = 0.0;
	sbAL = sbAR = sbBL = sbBR = sbCL = sbCR = 0.0;
	//from SubTight
	
	for(int count = 0; count < dscBuf+2; count++) {
		dram->dBaL[count] = 0.0;
		dram->dBaR[count] = 0.0;
		dram->dBbL[count] = 0.0;
		dram->dBbR[count] = 0.0;
		dram->dBcL[count] = 0.0;
		dram->dBcR[count] = 0.0;
		dram->dBdL[count] = 0.0;
		dram->dBdR[count] = 0.0;
		dram->dBeL[count] = 0.0;
		dram->dBeR[count] = 0.0;
	}
	dBaPosL = 0.0;
	dBbPosL = 0.0;
	dBcPosL = 0.0;
	dBdPosL = 0.0;
	dBePosL = 0.0;
	dBaPosR = 0.0;
	dBbPosR = 0.0;
	dBcPosR = 0.0;
	dBdPosR = 0.0;
	dBePosR = 0.0;
	dBaXL = 1;
	dBbXL = 1;
	dBcXL = 1;	
	dBdXL = 1;	
	dBeXL = 1;	
	dBaXR = 1;
	dBbXR = 1;
	dBcXR = 1;	
	dBdXR = 1;	
	dBeXR = 1;	
	
	for (int x = 0; x < bez_total; x++) dram->bez[x] = 0.0;
	dram->bez[bez_cycle] = 1.0;

	fpdL = 1.0; while (fpdL < 16386) fpdL = rand()*UINT32_MAX;
	fpdR = 1.0; while (fpdR < 16386) fpdR = rand()*UINT32_MAX;
	return noErr;
}

};
