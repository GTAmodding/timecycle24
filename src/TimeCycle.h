struct CTimeCycleBox
{
	CBox box;
	short farclp;
	uchar lodDistMult;
	int extraColor;
	float strength;
	float falloff;
};

class CTimeCycle
{
public:
	enum WeatherType {
		EXTRASUNNY_LA = 0,
		SUNNY_LA = 1,
		EXTRASUNNY_SMOG_LA = 2,
		SUNNY_SMOG_LA = 3,
	};
	static uchar m_nDirectionalMult[NUMHOURS][NUMWEATHERS];
	static uchar m_nWaterFogAlpha[NUMHOURS][NUMWEATHERS];
	static uchar m_nHighLightMinIntensity[NUMHOURS][NUMWEATHERS];
	static uchar m_fCloudAlpha[NUMHOURS][NUMWEATHERS];
	static uchar m_fPostFx2Alpha[NUMHOURS][NUMWEATHERS];
	static uchar m_fPostFx2Blue[NUMHOURS][NUMWEATHERS];
	static uchar m_fPostFx2Green[NUMHOURS][NUMWEATHERS];
	static uchar m_fPostFx2Red[NUMHOURS][NUMWEATHERS];
	static uchar m_fPostFx1Alpha[NUMHOURS][NUMWEATHERS];
	static uchar m_fPostFx1Blue[NUMHOURS][NUMWEATHERS];
	static uchar m_fPostFx1Green[NUMHOURS][NUMWEATHERS];
	static uchar m_fPostFx1Red[NUMHOURS][NUMWEATHERS];
	static uchar m_fWaterAlpha[NUMHOURS][NUMWEATHERS];
	static uchar m_fWaterBlue[NUMHOURS][NUMWEATHERS];
	static uchar m_fWaterGreen[NUMHOURS][NUMWEATHERS];
	static uchar m_fWaterRed[NUMHOURS][NUMWEATHERS];
	static uchar m_nFluffyCloudsBottomRed[NUMHOURS][NUMWEATHERS];
	static uchar m_nFluffyCloudsBottomGreen[NUMHOURS][NUMWEATHERS];
	static uchar m_nFluffyCloudsBottomBlue[NUMHOURS][NUMWEATHERS];
	static uchar m_nLowCloudsBlue[NUMHOURS][NUMWEATHERS];
	static uchar m_nLowCloudsGreen[NUMHOURS][NUMWEATHERS];
	static uchar m_nLowCloudsRed[NUMHOURS][NUMWEATHERS];
	static uchar m_fLightsOnGroundBrightness[NUMHOURS][NUMWEATHERS];
	static ushort m_fFogStart[NUMHOURS][NUMWEATHERS];
	static ushort m_fFarClip[NUMHOURS][NUMWEATHERS];
	static uchar m_nPoleShadowStrength[NUMHOURS][NUMWEATHERS];
	static uchar m_nLightShadowStrength[NUMHOURS][NUMWEATHERS];
	static uchar m_nShadowStrength[NUMHOURS][NUMWEATHERS];
	static uchar m_fSpriteBrightness[NUMHOURS][NUMWEATHERS];
	static uchar m_fSpriteSize[NUMHOURS][NUMWEATHERS];
	static uchar m_fSunSize[NUMHOURS][NUMWEATHERS];
	static uchar m_nSunCoronaBlue[NUMHOURS][NUMWEATHERS];
	static uchar m_nSunCoronaGreen[NUMHOURS][NUMWEATHERS];
	static uchar m_nSunCoronaRed[NUMHOURS][NUMWEATHERS];
	static uchar m_nSunCoreBlue[NUMHOURS][NUMWEATHERS];
	static uchar m_nSunCoreGreen[NUMHOURS][NUMWEATHERS];
	static uchar m_nSunCoreRed[NUMHOURS][NUMWEATHERS];
	static uchar m_nSkyBottomBlue[NUMHOURS][NUMWEATHERS];
	static uchar m_nSkyBottomGreen[NUMHOURS][NUMWEATHERS];
	static uchar m_nSkyBottomRed[NUMHOURS][NUMWEATHERS];
	static uchar m_nSkyTopBlue[NUMHOURS][NUMWEATHERS];
	static uchar m_nSkyTopGreen[NUMHOURS][NUMWEATHERS];
	static uchar m_nSkyTopRed[NUMHOURS][NUMWEATHERS];
	static uchar m_nAmbientBlue_Obj[NUMHOURS][NUMWEATHERS];
	static uchar m_nAmbientGreen_Obj[NUMHOURS][NUMWEATHERS];
	static uchar m_nAmbientRed_Obj[NUMHOURS][NUMWEATHERS];
	static uchar m_nAmbientBlue[NUMHOURS][NUMWEATHERS];
	static uchar m_nAmbientGreen[NUMHOURS][NUMWEATHERS];
	static uchar m_nAmbientRed[NUMHOURS][NUMWEATHERS];

	static float &m_BrightnessAddedToAmbientRed;
	static float &m_BrightnessAddedToAmbientGreen;
	static float &m_BrightnessAddedToAmbientBlue;

	static int &m_ExtraColourWeatherType;
	static int &m_ExtraColour;
	static int &m_bExtraColourOn;
	static float &m_ExtraColourInter;
	static CVector &m_vecDirnLightToSun;
	static int &m_FogReduction;
	static CVector *m_VectorToSun;	// [16]
	static float *m_fShadowFrontX;	// [16]
	static float *m_fShadowFrontY;	// [16]
	static float *m_fShadowSideX;	// [16]
	static float *m_fShadowSideY;	// [16]
	static float *m_fShadowDisplacementX;	// [16]
	static float *m_fShadowDisplacementY;	// [16]
	static int &m_CurrentStoredValue;
	static RwRGBA &m_BelowHorizonGrey;
#ifdef REPLACE
	static CColourSet m_CurrentColours;
	static CColourSet &m_CurrentColours_exe;
#else
	static CColourSet &m_CurrentColours;
#endif

	static void Initialise(bool unused);
	static void CalcColoursForPoint(float x, float y, float z, CColourSet *colorset);
	static void StartExtraColour(int extracolor, int keepInter);
	static void FindTimeCycleBox(float x, float y, float z, CTimeCycleBox **box, float *interp, bool checkLod, bool checkFar, CTimeCycleBox *exclude);
	static void SetConstantParametersForPostFX(void);
	static double FindFarClipForCoors(float x, float y, float z);
	static void Update(void);
};
