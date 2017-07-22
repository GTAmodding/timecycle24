#include "gta.h"

void
CColourSet::ctor(int h, int w)
{
	this->ambr = CTimeCycle::m_nAmbientRed[h][w];
	this->ambg = CTimeCycle::m_nAmbientGreen[h][w];
	this->ambb = CTimeCycle::m_nAmbientBlue[h][w];
	this->ambobjr = CTimeCycle::m_nAmbientRed_Obj[h][w];
	this->ambobjg = CTimeCycle::m_nAmbientGreen_Obj[h][w];
	this->ambobjb = CTimeCycle::m_nAmbientBlue_Obj[h][w];
	this->skytopr = CTimeCycle::m_nSkyTopRed[h][w];
	this->skytopg = CTimeCycle::m_nSkyTopGreen[h][w];
	this->skytopb = CTimeCycle::m_nSkyTopBlue[h][w];
	this->skybotr = CTimeCycle::m_nSkyBottomRed[h][w];
	this->skybotg = CTimeCycle::m_nSkyBottomGreen[h][w];
	this->skybotb = CTimeCycle::m_nSkyBottomBlue[h][w];
	this->suncorer = CTimeCycle::m_nSunCoreRed[h][w];
	this->suncoreg = CTimeCycle::m_nSunCoreGreen[h][w];
	this->suncoreb = CTimeCycle::m_nSunCoreBlue[h][w];
	this->suncoronar = CTimeCycle::m_nSunCoronaRed[h][w];
	this->suncoronag = CTimeCycle::m_nSunCoronaGreen[h][w];
	this->suncoronab = CTimeCycle::m_nSunCoronaBlue[h][w];
	this->sunsz = CTimeCycle::m_fSunSize[h][w];
	this->sprsz = CTimeCycle::m_fSpriteSize[h][w];
	this->sprbght = CTimeCycle::m_fSpriteBrightness[h][w];
	this->shd = CTimeCycle::m_nShadowStrength[h][w];
	this->lightshd = CTimeCycle::m_nLightShadowStrength[h][w];
	this->poleshd = CTimeCycle::m_nPoleShadowStrength[h][w];
	this->farclp = CTimeCycle::m_fFarClip[h][w];
	this->fogst = CTimeCycle::m_fFogStart[h][w];
	this->lightonground = CTimeCycle::m_fLightsOnGroundBrightness[h][w];
	this->lowcloudr = CTimeCycle::m_nLowCloudsRed[h][w];
	this->lowcloudg = CTimeCycle::m_nLowCloudsGreen[h][w];
	this->lowcloudb = CTimeCycle::m_nLowCloudsBlue[h][w];
	this->fluffycloudr = CTimeCycle::m_nFluffyCloudsBottomRed[h][w];
	this->fluffycloudg = CTimeCycle::m_nFluffyCloudsBottomGreen[h][w];
	this->fluffycloudb = CTimeCycle::m_nFluffyCloudsBottomBlue[h][w];
	this->waterr = CTimeCycle::m_fWaterRed[h][w];
	this->waterg = CTimeCycle::m_fWaterGreen[h][w];
	this->waterb = CTimeCycle::m_fWaterBlue[h][w];
	this->watera = CTimeCycle::m_fWaterAlpha[h][w];
	this->postfx1r = CTimeCycle::m_fPostFx1Red[h][w];
	this->postfx1g = CTimeCycle::m_fPostFx1Green[h][w];
	this->postfx1b = CTimeCycle::m_fPostFx1Blue[h][w];
	this->postfx1a = CTimeCycle::m_fPostFx1Alpha[h][w];
	this->postfx2r = CTimeCycle::m_fPostFx2Red[h][w];
	this->postfx2g = CTimeCycle::m_fPostFx2Green[h][w];
	this->postfx2b = CTimeCycle::m_fPostFx2Blue[h][w];
	this->postfx2a = CTimeCycle::m_fPostFx2Alpha[h][w];
	this->cloudalpha = CTimeCycle::m_fCloudAlpha[h][w];
	this->intensityLimit = CTimeCycle::m_nHighLightMinIntensity[h][w];
	this->waterfogalpha = CTimeCycle::m_nWaterFogAlpha[h][w];
	this->lodDistMult = 1.0f;
	this->directionalmult = CTimeCycle::m_nDirectionalMult[h][w] / 100.0f;
}

void
CColourSet::Interpolate(CColourSet *a, CColourSet *b, float fa, float fb, bool ignoreSky)
{
	if(!ignoreSky){
		this->skytopr = a->skytopr * fa + b->skytopr * fb;
		this->skytopg = a->skytopg * fa + b->skytopg * fb;
		this->skytopb = a->skytopb * fa + b->skytopb * fb;
		this->skybotr = a->skybotr * fa + b->skybotr * fb;
		this->skybotg = a->skybotg * fa + b->skybotg * fb;
		this->skybotb = a->skybotb * fa + b->skybotb * fb;
		this->suncorer = a->suncorer * fa + b->suncorer * fb;
		this->suncoreg = a->suncoreg * fa + b->suncoreg * fb;
		this->suncoreb = a->suncoreb * fa + b->suncoreb * fb;
		this->suncoronar = a->suncoronar * fa + b->suncoronar * fb;
		this->suncoronag = a->suncoronag * fa + b->suncoronag * fb;
		this->suncoronab = a->suncoronab * fa + b->suncoronab * fb;
		this->sunsz = fa * a->sunsz + fb * b->sunsz;
		this->lowcloudr = a->lowcloudr * fa + b->lowcloudr * fb;
		this->lowcloudg = a->lowcloudg * fa + b->lowcloudg * fb;
		this->lowcloudb = a->lowcloudb * fa + b->lowcloudb * fb;
		this->fluffycloudr = a->fluffycloudr * fa + b->fluffycloudr * fb;
		this->fluffycloudg = a->fluffycloudg * fa + b->fluffycloudg * fb;
		this->fluffycloudb = a->fluffycloudb * fa + b->fluffycloudb * fb;
	}
	this->ambr = fa * a->ambr + fb * b->ambr;
	this->ambg = fa * a->ambg + fb * b->ambg;
	this->ambb = fa * a->ambb + fb * b->ambb;
	this->ambobjr = fa * a->ambobjr + fb * b->ambobjr;
	this->ambobjg = fa * a->ambobjg + fb * b->ambobjg;
	this->ambobjb = fa * a->ambobjb + fb * b->ambobjb;
	this->sprsz = fa * a->sprsz + fb * b->sprsz;
	this->sprbght = fa * a->sprbght + fb * b->sprbght;
	this->shd = a->shd * fa + b->shd * fb;
	this->lightshd = a->lightshd * fa + b->lightshd * fb;
	this->poleshd = a->poleshd * fa + b->poleshd * fb;
	this->farclp = fa * a->farclp + fb * b->farclp;
	this->fogst = fa * a->fogst + fb * b->fogst;
	this->postfx1r = fa * a->postfx1r + fb * b->postfx1r;
	this->postfx1g = fa * a->postfx1g + fb * b->postfx1g;
	this->postfx1b = fa * a->postfx1b + fb * b->postfx1b;
	this->postfx1a = fa * a->postfx1a + fb * b->postfx1a;
	this->postfx2r = fa * a->postfx2r + fb * b->postfx2r;
	this->postfx2g = fa * a->postfx2g + fb * b->postfx2g;
	this->postfx2b = fa * a->postfx2b + fb * b->postfx2b;
	this->postfx2a = fa * a->postfx2a + fb * b->postfx2a;
	this->lightonground = fa * a->lightonground + fb * b->lightonground;
	this->cloudalpha = fa * a->cloudalpha + fb * b->cloudalpha;
	this->intensityLimit = a->intensityLimit * fa + b->intensityLimit * fb;
	this->waterfogalpha = a->waterfogalpha * fa + b->waterfogalpha * fb;
	this->directionalmult = fa * a->directionalmult + fb * b->directionalmult;
	this->lodDistMult = fa * a->lodDistMult + fb * b->lodDistMult;
	this->waterr = fa * a->waterr + fb * b->waterr;
	this->waterg = fa * a->waterg + fb * b->waterg;
	this->waterb = fa * a->waterb + fb * b->waterb;
	this->watera = fa * a->watera + fb * b->watera;
}
