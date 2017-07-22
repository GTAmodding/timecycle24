#include "gta.h"

uchar CTimeCycle::m_nDirectionalMult[NUMHOURS][NUMWEATHERS];
uchar CTimeCycle::m_nWaterFogAlpha[NUMHOURS][NUMWEATHERS];
uchar CTimeCycle::m_nHighLightMinIntensity[NUMHOURS][NUMWEATHERS];
uchar CTimeCycle::m_fCloudAlpha[NUMHOURS][NUMWEATHERS];
uchar CTimeCycle::m_fPostFx2Alpha[NUMHOURS][NUMWEATHERS];
uchar CTimeCycle::m_fPostFx2Blue[NUMHOURS][NUMWEATHERS];
uchar CTimeCycle::m_fPostFx2Green[NUMHOURS][NUMWEATHERS];
uchar CTimeCycle::m_fPostFx2Red[NUMHOURS][NUMWEATHERS];
uchar CTimeCycle::m_fPostFx1Alpha[NUMHOURS][NUMWEATHERS];
uchar CTimeCycle::m_fPostFx1Blue[NUMHOURS][NUMWEATHERS];
uchar CTimeCycle::m_fPostFx1Green[NUMHOURS][NUMWEATHERS];
uchar CTimeCycle::m_fPostFx1Red[NUMHOURS][NUMWEATHERS];
uchar CTimeCycle::m_fWaterAlpha[NUMHOURS][NUMWEATHERS];
uchar CTimeCycle::m_fWaterBlue[NUMHOURS][NUMWEATHERS];
uchar CTimeCycle::m_fWaterGreen[NUMHOURS][NUMWEATHERS];
uchar CTimeCycle::m_fWaterRed[NUMHOURS][NUMWEATHERS];
uchar CTimeCycle::m_nFluffyCloudsBottomRed[NUMHOURS][NUMWEATHERS];
uchar CTimeCycle::m_nFluffyCloudsBottomGreen[NUMHOURS][NUMWEATHERS];
uchar CTimeCycle::m_nFluffyCloudsBottomBlue[NUMHOURS][NUMWEATHERS];
uchar CTimeCycle::m_nLowCloudsBlue[NUMHOURS][NUMWEATHERS];
uchar CTimeCycle::m_nLowCloudsGreen[NUMHOURS][NUMWEATHERS];
uchar CTimeCycle::m_nLowCloudsRed[NUMHOURS][NUMWEATHERS];
uchar CTimeCycle::m_fLightsOnGroundBrightness[NUMHOURS][NUMWEATHERS];
ushort CTimeCycle::m_fFogStart[NUMHOURS][NUMWEATHERS];
ushort CTimeCycle::m_fFarClip[NUMHOURS][NUMWEATHERS];
uchar CTimeCycle::m_nPoleShadowStrength[NUMHOURS][NUMWEATHERS];
uchar CTimeCycle::m_nLightShadowStrength[NUMHOURS][NUMWEATHERS];
uchar CTimeCycle::m_nShadowStrength[NUMHOURS][NUMWEATHERS];
uchar CTimeCycle::m_fSpriteBrightness[NUMHOURS][NUMWEATHERS];
uchar CTimeCycle::m_fSpriteSize[NUMHOURS][NUMWEATHERS];
uchar CTimeCycle::m_fSunSize[NUMHOURS][NUMWEATHERS];
uchar CTimeCycle::m_nSunCoronaBlue[NUMHOURS][NUMWEATHERS];
uchar CTimeCycle::m_nSunCoronaGreen[NUMHOURS][NUMWEATHERS];
uchar CTimeCycle::m_nSunCoronaRed[NUMHOURS][NUMWEATHERS];
uchar CTimeCycle::m_nSunCoreBlue[NUMHOURS][NUMWEATHERS];
uchar CTimeCycle::m_nSunCoreGreen[NUMHOURS][NUMWEATHERS];
uchar CTimeCycle::m_nSunCoreRed[NUMHOURS][NUMWEATHERS];
uchar CTimeCycle::m_nSkyBottomBlue[NUMHOURS][NUMWEATHERS];
uchar CTimeCycle::m_nSkyBottomGreen[NUMHOURS][NUMWEATHERS];
uchar CTimeCycle::m_nSkyBottomRed[NUMHOURS][NUMWEATHERS];
uchar CTimeCycle::m_nSkyTopBlue[NUMHOURS][NUMWEATHERS];
uchar CTimeCycle::m_nSkyTopGreen[NUMHOURS][NUMWEATHERS];
uchar CTimeCycle::m_nSkyTopRed[NUMHOURS][NUMWEATHERS];
uchar CTimeCycle::m_nAmbientBlue_Obj[NUMHOURS][NUMWEATHERS];
uchar CTimeCycle::m_nAmbientGreen_Obj[NUMHOURS][NUMWEATHERS];
uchar CTimeCycle::m_nAmbientRed_Obj[NUMHOURS][NUMWEATHERS];
uchar CTimeCycle::m_nAmbientBlue[NUMHOURS][NUMWEATHERS];
uchar CTimeCycle::m_nAmbientGreen[NUMHOURS][NUMWEATHERS];
uchar CTimeCycle::m_nAmbientRed[NUMHOURS][NUMWEATHERS];

float &CTimeCycle::m_BrightnessAddedToAmbientRed = *(float*)0xB79E38;
float &CTimeCycle::m_BrightnessAddedToAmbientGreen = *(float*)0xB79E34;
float &CTimeCycle::m_BrightnessAddedToAmbientBlue = *(float*)0xB79E30;

int &CTimeCycle::m_ExtraColourWeatherType = *(int*)0xB79E40;
int &CTimeCycle::m_ExtraColour = *(int*)0xB79E44;
int &CTimeCycle::m_bExtraColourOn = *(int*)0xB7C484;
float &CTimeCycle::m_ExtraColourInter = *(float*)0xB79E3C;
CVector &CTimeCycle::m_vecDirnLightToSun = *(CVector*)0xB7CB14;
int &CTimeCycle::m_FogReduction = *(int*)0xB79E48;
CVector *CTimeCycle::m_VectorToSun = (CVector*)0xB7CA50;
float *CTimeCycle::m_fShadowFrontX = (float*)0xB79F90;
float *CTimeCycle::m_fShadowFrontY = (float*)0xB79F50;
float *CTimeCycle::m_fShadowSideX = (float*)0xB79F10;
float *CTimeCycle::m_fShadowSideY = (float*)0xB79ED0;
float *CTimeCycle::m_fShadowDisplacementX = (float*)0xB79E90;
float *CTimeCycle::m_fShadowDisplacementY = (float*)0xB79E50;
int &CTimeCycle::m_CurrentStoredValue = *(int*)0xB79FD0;
RwRGBA &CTimeCycle::m_BelowHorizonGrey = *(RwRGBA*)0xB7CB10;
CColourSet &CTimeCycle::m_CurrentColours = *(CColourSet*)0xB7C4A0;

WRAPPER void CTimeCycle::SetConstantParametersForPostFX(void) { EAXJMP(0x560210); }

void
CTimeCycle::StartExtraColour(int extracolor, int keepInter)
{
	CTimeCycle::m_ExtraColourWeatherType = extracolor / NUMHOURS + EXTRASTART;
	CTimeCycle::m_ExtraColour = extracolor % NUMHOURS;
	CTimeCycle::m_bExtraColourOn = 1;
	CTimeCycle::m_ExtraColourInter = 0.0f;
	if(!keepInter)
		CTimeCycle::m_ExtraColourInter = 1.0f;
}

void
CTimeCycle::Initialise(bool unused)
{
	int fd;
	int w, h;
	char *line;

	int ambr, ambg, ambb;
	int ambobjr, ambobjg, ambobjb;
	int dirr, dirg, dirb;
	int skytopr, skytopg, skytopb;
	int skybotr, skybotg, skybotb;
	int suncorer, suncoreg, suncoreb;
	int suncoronar, suncoronag, suncoronab;
	float sunsz, sprsz, sprbght;
	int shdw, lightshd, poleshd;
	float farclp, fogst, lightonground;
	int lowcloudr, lowcloudg, lowcloudb;
	int bottomcloudr, bottomcloudg, bottomcloudb;
	float waterr, waterg, waterb, watera;
	float postfx1a, postfx1r, postfx1g, postfx1b;
	float postfx2a, postfx2r, postfx2g, postfx2b;
	float cloudalpha;
	int radlimit;
	int waterfogalpha;
	float dirMult;

	CFileMgr::SetDir("DATA");
	fd = CFileMgr::OpenFile("TIMECYC_24H.DAT", "rb");
	CFileMgr::SetDir("");

	for(w = 0; w < NUMWEATHERS; w++)
		for(h = 0; h < NUMHOURS; h++){
			while(line = CFileLoader::LoadLine(fd), line)
				if(line[0] != '/' && line[0] != '\0')
					break;
			sscanf(line, "%d %d %d" " %d %d %d" " %d %d %d" " %d %d %d" " %d %d %d" " %d %d %d" " %d %d %d"
				" %f %f %f"
				" %d %d %d"
				" %f %f %f"
				" %d %d %d" " %d %d %d"
				" %f %f %f %f"
				"  %f %f %f %f"
				"  %f %f %f %f"
				" %f %d %d %f",
				&ambr, &ambg, &ambb,
				&ambobjr, &ambobjg, &ambobjb,
				&dirr, &dirg, &dirb,
				&skytopr, &skytopg, &skytopb,
				&skybotr, &skybotg, &skybotb,
				&suncorer, &suncoreg, &suncoreb,
				&suncoronar, &suncoronag, &suncoronab,
				&sunsz, &sprsz, &sprbght,
				&shdw, &lightshd, &poleshd,
				&farclp, &fogst, &lightonground,
				&lowcloudr, &lowcloudg, &lowcloudb,
				&bottomcloudr, &bottomcloudg, &bottomcloudb,
				&waterr, &waterg, &waterb, &watera,
				&postfx1a, &postfx1r, &postfx1g, &postfx1b,
				&postfx2a, &postfx2r, &postfx2g, &postfx2b,
				&cloudalpha,
				&radlimit,
				&waterfogalpha,
				&dirMult);
			m_nAmbientRed[h][w] = ambr;
			m_nAmbientGreen[h][w] = ambg;
			m_nAmbientBlue[h][w] = ambb;
			m_nAmbientRed_Obj[h][w] = ambobjr;
			m_nAmbientGreen_Obj[h][w] = ambobjg;
			m_nAmbientBlue_Obj[h][w] = ambobjb;
			m_nSkyTopRed[h][w] = skytopr;
			m_nSkyTopGreen[h][w] = skytopg;
			m_nSkyTopBlue[h][w] = skytopb;
			m_nSkyBottomRed[h][w] = skybotr;
			m_nSkyBottomGreen[h][w] = skybotg;
			m_nSkyBottomBlue[h][w] = skybotb;
			m_nSunCoreRed[h][w] = suncorer;
			m_nSunCoreGreen[h][w] = suncoreg;
			m_nSunCoreBlue[h][w] = suncoreb;
			m_nSunCoronaRed[h][w] = suncoronar;
			m_nSunCoronaGreen[h][w] = suncoronag;
			m_nSunCoronaBlue[h][w] = suncoronab;
			m_fSunSize[h][w] = sunsz*10.0f + 0.5f;
			m_fSpriteSize[h][w] = sprsz*10.0f + 0.5f;
			m_fSpriteBrightness[h][w] = sprbght*10.0f + 0.5f;
			m_nShadowStrength[h][w] = shdw;
			m_nLightShadowStrength[h][w] = lightshd;
			m_nPoleShadowStrength[h][w] = poleshd;
			m_fFarClip[h][w] = farclp;
			m_fFogStart[h][w] = fogst;
			m_fLightsOnGroundBrightness[h][w] = lightonground*10.0f + 0.5f;
			m_nLowCloudsRed[h][w] = lowcloudr;
			m_nLowCloudsGreen[h][w] = lowcloudg;
			m_nLowCloudsBlue[h][w] = lowcloudb;
			m_nFluffyCloudsBottomRed[h][w] = bottomcloudr;
			m_nFluffyCloudsBottomGreen[h][w] = bottomcloudg;
			m_nFluffyCloudsBottomBlue[h][w] = bottomcloudb;
			m_fWaterRed[h][w] = waterr;
			m_fWaterGreen[h][w] = waterg;
			m_fWaterBlue[h][w] = waterb;
			m_fWaterAlpha[h][w] = watera;
			m_fPostFx1Red[h][w] = postfx1r;
			m_fPostFx1Green[h][w] = postfx1g;
			m_fPostFx1Blue[h][w] = postfx1b;
			m_fPostFx2Red[h][w] = postfx2r;
			m_fPostFx2Green[h][w] = postfx2g;
			m_fPostFx2Blue[h][w] = postfx2b;
			m_fPostFx1Alpha[h][w] = postfx1a + postfx1a;
			m_fPostFx2Alpha[h][w] = postfx2a + postfx2a;
			m_fCloudAlpha[h][w] = cloudalpha;
			m_nHighLightMinIntensity[h][w] = radlimit;
			m_nWaterFogAlpha[h][w] = waterfogalpha;
			m_nDirectionalMult[h][w] = dirMult*100.0f;
		}
	CFileMgr::CloseFile(fd);
	float c = cos(0.7853981852531433);
	m_vecDirnLightToSun.x = cos(-2.356194496154785) * c;
	m_vecDirnLightToSun.y = sin(-2.356194496154785) * c;
	m_vecDirnLightToSun.z = sin(0.7853981852531433);
	m_vecDirnLightToSun.Normalise();
	m_FogReduction = 0;
	m_bExtraColourOn = 0;
}

WRAPPER void CTimeCycle::FindTimeCycleBox(float x, float y, float z, CTimeCycleBox **box, float *interp, bool checkLod, bool checkFar, CTimeCycleBox *exclude)
{ WRAPARG(x); WRAPARG(y); WRAPARG(z); WRAPARG(box); WRAPARG(interp); WRAPARG(checkLod); WRAPARG(checkFar); WRAPARG(exclude); EAXJMP(0x55FFD0); }

static uchar timecycleHours[25] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24 };
static uchar timecycleHorizon[24] = { 30, 30, 30, 30, 30, 30, 30, 50, 52, 54, 56, 58, 60, 60, 60, 60, 60, 60, 60, 60, 50, 42, 35, 32 };
int &tunnelWeather = *(int*)0x8CDEE0;

void
CTimeCycle::CalcColoursForPoint(float x, float y, float z, CColourSet *colorset)
{
	CTimeCycleBox *lodBox, *farBox1, *farBox2, *weatherBox, *tmpBox;
	float lodBoxInterp, farBox1Interp, farBox2Interp, weatherBoxInterp, tmpInterp;
	float time;
	int curHourSel, nextHourSel;
	int curHour, nextHour;
	float timeInterp, invTimeInterp, weatherInterp, invWeatherInterp;
	int boxWeather, boxHour;
	float lightMult;
	float sunAngle;
	CVector *vec;
	float inc;
	float camZ;
	float horiz;
	float brightness;
	float max, f;

	FindTimeCycleBox(x, y, z, &lodBox, &lodBoxInterp, true, false, NULL);
	FindTimeCycleBox(x, y, z, &farBox1, &farBox1Interp, false, true, NULL);
	if(farBox1){
		CTimeCycle::FindTimeCycleBox(x, y, z, &farBox2, &farBox2Interp, false, true, farBox1);
		if(farBox2)
		if(farBox2->box.max.x - farBox2->box.min.x > farBox1->box.max.x - farBox1->box.min.x){
			tmpBox = farBox1;
			farBox1 = farBox2;
			farBox2 = tmpBox;
			tmpInterp = farBox2Interp;
			farBox2Interp = farBox1Interp;
			farBox1Interp = tmpInterp;
		}
	}else
		farBox2 = NULL;
	FindTimeCycleBox(x, y, z, &weatherBox, &weatherBoxInterp, false, false, NULL);

	time = CClock::ms_nGameClockMinutes / 60.0f
	     + CClock::ms_nGameClockSeconds / 3600.0f
	     + CClock::ms_nGameClockHours;
	if(time >= 23.999f)
		time = 23.999f;

	for(curHourSel = 0; time >= timecycleHours[curHourSel+1]; curHourSel++);
	nextHourSel = (curHourSel + 1) % NUMHOURS;
	curHour = timecycleHours[curHourSel];
	nextHour = timecycleHours[curHourSel+1];
	timeInterp = (time - curHour) / (float)(nextHour - curHour);
	invTimeInterp = 1.0f - timeInterp;
	weatherInterp = CWeather::InterpolationValue;
	invWeatherInterp = 1.0f - weatherInterp;
	if(weatherBox){
		boxWeather = (weatherBox->extraColor / NUMHOURS) + 21;
		boxHour = weatherBox->extraColor % 8;
	}
	CColourSet curold(curHour, CWeather::OldWeatherType);
	CColourSet nextold(nextHour, CWeather::OldWeatherType);
	CColourSet curnew(curHour, CWeather::NewWeatherType);
	CColourSet nextnew(nextHour, CWeather::NewWeatherType);

	if(*(CMatrix**)(0xB6F028 + 0x14))	// TheCamera coords
		camZ = (*(CMatrix**)(0xB6F028 + 0x14))->matrix.pos.z;
	else
		camZ = ((CVector*)(0xB6F028 + 0x4))->z;
	f = (camZ-20.0)/200.0;
	if(f < 0.0) f = 0.0;
	if(f > 1.0) f = 1.0;
	if(CWeather::OldWeatherType == EXTRASUNNY_SMOG_LA){
		CColourSet set1(curHourSel, EXTRASUNNY_LA);
		curold.Interpolate(&curold, &set1, 1.0-f, f, false);
		CColourSet set2(nextHourSel, EXTRASUNNY_LA);
		nextold.Interpolate(&nextold, &set2, 1.0-f, f, false);
	}else if(CWeather::OldWeatherType == SUNNY_SMOG_LA){
		CColourSet set1(curHourSel, SUNNY_LA);
		curold.Interpolate(&curold, &set1, 1.0-f, f, false);
		CColourSet set2(nextHourSel, SUNNY_LA);
		nextold.Interpolate(&nextold, &set2, 1.0-f, f, false);
	}
	if(CWeather::NewWeatherType == EXTRASUNNY_SMOG_LA){
		CColourSet set1(curHourSel, EXTRASUNNY_LA);
		curnew.Interpolate(&curnew, &set1, 1.0-f, f, false);
		CColourSet set2(nextHourSel, EXTRASUNNY_LA);
		nextnew.Interpolate(&nextnew, &set2, 1.0-f, f, false);
	}else if(CWeather::NewWeatherType == SUNNY_SMOG_LA){
		CColourSet set1(curHourSel, SUNNY_LA);
		curnew.Interpolate(&curnew, &set1, 1.0-f, f, false);
		CColourSet set2(nextHourSel, SUNNY_LA);
		nextnew.Interpolate(&nextnew, &set2, 1.0-f, f, false);
	}

	CColourSet oldInterp, newInterp;
	oldInterp.Interpolate(&curold, &nextold, invTimeInterp, timeInterp, false);
	newInterp.Interpolate(&curnew, &nextnew, invTimeInterp, timeInterp, false);
	colorset->Interpolate(&oldInterp, &newInterp, invWeatherInterp, weatherInterp, false);

	lightMult = (1.0f / CCoronas::LightsMult + 3.0f) * 0.25f;
	colorset->skytopr *= lightMult;
	colorset->skytopg *= lightMult;
	colorset->skytopb *= lightMult;
	colorset->skybotr *= lightMult;
	colorset->skybotg *= lightMult;
	colorset->skybotb *= lightMult;
	if(colorset->skytopr > 0xFF) colorset->skytopr = 0xFF;
	if(colorset->skytopg > 0xFF) colorset->skytopg = 0xFF;
	if(colorset->skytopb > 0xFF) colorset->skytopb = 0xFF;
	if(colorset->skybotr > 0xFF) colorset->skybotr = 0xFF;
	if(colorset->skybotg > 0xFF) colorset->skybotg = 0xFF;
	if(colorset->skybotb > 0xFF) colorset->skybotb = 0xFF;

	if(m_FogReduction)
		colorset->farclp = colorset->farclp > m_FogReduction*10.15625 ? colorset->farclp : m_FogReduction*10.15625;

	m_CurrentStoredValue = (m_CurrentStoredValue + 1) & 0xF;
	vec = &m_VectorToSun[m_CurrentStoredValue];
	sunAngle = (CClock::ms_nGameClockMinutes + 60 * CClock::ms_nGameClockHours + CClock::ms_nGameClockSeconds/60.0f) * 0.0043633231;
	vec->x = 0.7 + sin(sunAngle);
	vec->y = -0.7;
	vec->z = 0.2 - cos(sunAngle);
	vec->Normalise();

	if(weatherBox && weatherBox->extraColor >= 0){
		float boxf = weatherBoxInterp * weatherBox->strength;
		float invboxf = 1.0 - boxf;

		colorset->skytopr = colorset->skytopr*invboxf + m_nSkyTopRed[boxHour][boxWeather]*boxf;
		colorset->skytopg = colorset->skytopg*invboxf + m_nSkyTopGreen[boxHour][boxWeather]*boxf;
		colorset->skytopb = colorset->skytopg*invboxf + m_nSkyTopBlue[boxHour][boxWeather]*boxf;

		colorset->skybotr = colorset->skybotr*invboxf + m_nSkyBottomRed[boxHour][boxWeather]*boxf;
		colorset->skybotg = colorset->skybotg*invboxf + m_nSkyBottomGreen[boxHour][boxWeather]*boxf;
		colorset->skybotb = colorset->skybotb*invboxf + m_nSkyBottomBlue[boxHour][boxWeather]*boxf;

		colorset->waterr = colorset->waterr*invboxf + m_fWaterRed[boxHour][boxWeather]*boxf;
		colorset->waterg = colorset->waterg*invboxf + m_fWaterGreen[boxHour][boxWeather]*boxf;
		colorset->waterb = colorset->waterb*invboxf + m_fWaterBlue[boxHour][boxWeather]*boxf;
		colorset->watera = colorset->watera*invboxf + m_fWaterAlpha[boxHour][boxWeather]*boxf;

		colorset->ambr = colorset->ambr*invboxf + m_nAmbientRed[boxHour][boxWeather]*boxf;
		colorset->ambg = colorset->ambg*invboxf + m_nAmbientGreen[boxHour][boxWeather]*boxf;
		colorset->ambb = colorset->ambb*invboxf + m_nAmbientBlue[boxHour][boxWeather]*boxf;

		colorset->ambobjr = colorset->ambobjr*invboxf + m_nAmbientRed_Obj[boxHour][boxWeather]*boxf;
		colorset->ambobjg = colorset->ambobjg*invboxf + m_nAmbientGreen_Obj[boxHour][boxWeather]*boxf;
		colorset->ambobjb = colorset->ambobjb*invboxf + m_nAmbientBlue_Obj[boxHour][boxWeather]*boxf;

		if(m_fFarClip[boxHour][boxWeather] < colorset->farclp)
			colorset->farclp = colorset->farclp*invboxf + m_fFarClip[boxHour][boxWeather]*boxf;

		colorset->fogst = colorset->fogst*invboxf + m_fFogStart[boxHour][boxWeather]*boxf;

		colorset->postfx1r = colorset->postfx1r*invboxf + m_fPostFx1Red[boxHour][boxWeather]*boxf;
		colorset->postfx1g = colorset->postfx1g*invboxf + m_fPostFx1Green[boxHour][boxWeather]*boxf;
		colorset->postfx1b = colorset->postfx1b*invboxf + m_fPostFx1Blue[boxHour][boxWeather]*boxf;
		colorset->postfx1a = colorset->postfx1a*invboxf + m_fPostFx1Alpha[boxHour][boxWeather]*boxf;

		colorset->postfx2r = colorset->postfx2r*invboxf + m_fPostFx2Red[boxHour][boxWeather]*boxf;
		colorset->postfx2g = colorset->postfx2g*invboxf + m_fPostFx2Green[boxHour][boxWeather]*boxf;
		colorset->postfx2b = colorset->postfx2b*invboxf + m_fPostFx2Blue[boxHour][boxWeather]*boxf;
		colorset->postfx2a = colorset->postfx2a*invboxf + m_fPostFx2Alpha[boxHour][boxWeather]*boxf;
	}

	if(lodBox)
		colorset->lodDistMult = colorset->lodDistMult*(1.0f-lodBoxInterp) + lodBox->lodDistMult/32.0f*lodBoxInterp;

	if(farBox1 && farBox1->farclp < colorset->farclp)
		colorset->farclp = colorset->farclp*(1.0f-farBox1Interp) + farBox1->farclp*farBox1Interp;
	if(farBox2 && farBox2->farclp < colorset->farclp)
		colorset->farclp = colorset->farclp*(1.0f-farBox2Interp) + farBox2->farclp*farBox2Interp;

	inc = CTimer::ms_fTimeStep/120.0f;
	if(m_bExtraColourOn){
		m_ExtraColourInter += inc;
		if(m_ExtraColourInter > 1.0f)
			m_ExtraColourInter = 1.0f;
	}else{
		m_ExtraColourInter -= inc;
		if(m_ExtraColourInter < 0.0f)
			m_ExtraColourInter = 0.0f;
	}
	if(m_ExtraColourInter > 0.0f){
		CColourSet extraset(m_ExtraColour, m_ExtraColourWeatherType);
		colorset->Interpolate(colorset, &extraset, 1.0f-m_ExtraColourInter, m_ExtraColourInter, 
			m_nSkyTopRed[m_ExtraColour][m_ExtraColourWeatherType] == 0 && 
			m_nSkyTopGreen[m_ExtraColour][m_ExtraColourWeatherType] == 0 && 
			m_nSkyTopBlue[m_ExtraColour][m_ExtraColourWeatherType] == 0);
	}

	if(CWeather::UnderWaterness > 0.0f){
		CColourSet curuwset(curHourSel, 20);
		CColourSet nextuwset(nextHourSel, 20);
		CColourSet tmpset;
		tmpset.Interpolate(&curuwset, &nextuwset, invTimeInterp, timeInterp, false);
		colorset->Interpolate(colorset, &tmpset, 1.0f-CWeather::UnderWaterness, CWeather::UnderWaterness, false);
	}

	if(CWeather::InTunnelness > 0.0f){
		CColourSet tunnelset(tunnelWeather % NUMHOURS, tunnelWeather / NUMHOURS + EXTRASTART);
		colorset->Interpolate(colorset, &tunnelset, 1.0f-CWeather::InTunnelness, CWeather::InTunnelness, 
			m_nSkyTopRed[m_ExtraColour][m_ExtraColourWeatherType] == 0 && 
			m_nSkyTopGreen[m_ExtraColour][m_ExtraColourWeatherType] == 0 && 
			m_nSkyTopBlue[m_ExtraColour][m_ExtraColourWeatherType] == 0);
	}

	colorset->ambr /= 255;
	colorset->ambg /= 255;
	colorset->ambb /= 255;
	colorset->ambobjr /= 255;
	colorset->ambobjg /= 255;
	colorset->ambobjb /= 255;

	CShadows__CalcPedShadowValues(
		m_VectorToSun[m_CurrentStoredValue].x,
		m_VectorToSun[m_CurrentStoredValue].y,
		m_VectorToSun[m_CurrentStoredValue].z,
		&m_fShadowFrontX[m_CurrentStoredValue],
		&m_fShadowFrontY[m_CurrentStoredValue],
		&m_fShadowSideX[m_CurrentStoredValue],
		&m_fShadowSideY[m_CurrentStoredValue],
		&m_fShadowDisplacementX[m_CurrentStoredValue],
		&m_fShadowDisplacementY[m_CurrentStoredValue]);

	if(((CMatrix*)(0xB6F028 + 0x974))->matrix.up.z < -0.9
		|| !CWeather::bScriptsForceRain
		&& (CCullZones::PlayerNoRain() || CCullZones::CamNoRain() || CCutsceneMgr::ms_running)){
		m_FogReduction++;
		if(m_FogReduction > 64)
			m_FogReduction = 64;
	}else{
		m_FogReduction--;
		if(m_FogReduction < 0)
			m_FogReduction = 0;
	}

	if(camZ > 200.0f){
		if(camZ <= 500.0f)
			colorset->farclp = colorset->farclp*(1.0f - (camZ-200.0f)/300.0f) + 1000.0f*(camZ-200.0f)/300.0f;
		else if(colorset->farclp >= 1000.0f)
			colorset->farclp = 1000.0f;
	}

	horiz = timecycleHorizon[curHourSel]*invTimeInterp + timecycleHorizon[nextHourSel]*timeInterp;
	m_BelowHorizonGrey.red = m_CurrentColours.skybotr*CWeather::UnderWaterness + horiz*(1.0f - CWeather::UnderWaterness);
	m_BelowHorizonGrey.green = m_CurrentColours.skybotg*CWeather::UnderWaterness + horiz*(1.0f - CWeather::UnderWaterness);
	m_BelowHorizonGrey.blue = m_CurrentColours.skybotb*CWeather::UnderWaterness + horiz*(1.0f - CWeather::UnderWaterness);

	colorset->ambBeforeBrightnessr = colorset->ambr;
	colorset->ambBeforeBrightnessg = colorset->ambg;
	colorset->ambBeforeBrightnessb = colorset->ambb;
	brightness = *(int*)(0xBA6748 + 0x3C);
	if(brightness >= 256.0f){
		f = (brightness - 256.0)/128.0 + 1.0;
		max = colorset->ambr;
		if(colorset->ambg > max)
			max = colorset->ambg;
		if(colorset->ambb > max)
			max = colorset->ambb;
		max = max*f - max;
		colorset->ambr += max;
		colorset->ambg += max;
		colorset->ambb += max;
	}else{
		f = brightness/256.0f * 0.8 + 0.2;
		colorset->ambr *= f;
		colorset->ambg *= f;
		colorset->ambb *= f;
	}

	if(f > 1.0){
		float r, g, b;
		f = (f-1.0f)*0.06;
		max = colorset->ambr;
		if(colorset->ambg > max)
			max = colorset->ambg;
		if(colorset->ambb > max)
			max = colorset->ambb;
		r = colorset->ambr;
		g = colorset->ambg;
		b = colorset->ambb;
		if(max == 0.0){
			colorset->ambr = 0.001;
			colorset->ambg = 0.001;
			colorset->ambb = 0.001;
		}
		if(f > max){
			f /= max;
			colorset->ambr *= f;
			colorset->ambg *= f;
			colorset->ambb *= f;
		}
		m_BrightnessAddedToAmbientRed = colorset->ambr - r;
		m_BrightnessAddedToAmbientGreen = colorset->ambg - g;
		m_BrightnessAddedToAmbientBlue = colorset->ambb - b;
	}

	f = 0.0;
	if(x < -3000.0)
		f = -(x + 3000.0);
	else if(x > 3000.0)
		f = x - 3000.0;
	if(y < -3000.0)
		f += -(y + 3000.0);
	else if(y > 3000.0)
		f += y - 3000.0;
	if(f >= 1000.0)
		colorset->lodDistMult *= 2.0;
	else if(f > 0.0)
		colorset->lodDistMult = (f/1000.0 + 1.0) * colorset->lodDistMult;

	SetConstantParametersForPostFX();
}
