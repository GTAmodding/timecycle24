#include "gta.h"

HMODULE dllModule;

uchar timecycleHours[25] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24 };
uchar timecycleHorizon[24] = { 30, 30, 30, 30, 30, 30, 30, 50, 52, 54, 56, 58, 60, 60, 60, 60, 60, 60, 60, 60, 50, 42, 35, 32 };

void __declspec(naked)
mod24(void)
{
	_asm{
		// leave next hour % NUMHOURS in ebp
		push	eax
		push	edx
		push	ecx

		mov	eax, ebp
		cdq
		mov	ecx,NUMHOURS
		idiv	ecx
		mov	ebp,edx

		pop	ecx
		pop	edx
		pop	eax
		push	0x56056F
		retn
	}
}

void __declspec(naked)
mod24_1(void)
{
	_asm{
		// save extra weather to stack, extra hour to eax
		cdq
		mov	ecx,NUMHOURS
		idiv	ecx	// eax = weather, edx = hour
		mov	ecx,eax
		add	ecx,EXTRASTART
		mov     [esp+10h],ecx
		mov	eax,edx

		push	0x5605F5
		retn
	}
}

void __declspec(naked)
mod24_2(void)
{
	_asm{
		// leave extra weather in ebx, extra hour in edi
		cdq
		mov	ecx,NUMHOURS
		idiv	ecx	// eax = weather, edx = hour
		mov	ebx,eax
		add	ebx,EXTRASTART
		mov	edi,ebx

		push	0x56116D
		retn
	}
}



void
patch(void)
{
	Patch<void*>(0x55F7C7, (void*)&CTimeCycle::m_nDirectionalMult);
	Patch<void*>(0x5BBFEC, (void*)&CTimeCycle::m_nDirectionalMult);
	Patch<void*>(0x55F7B8, (void*)&CTimeCycle::m_nWaterFogAlpha);
	Patch<void*>(0x5BBFC5, (void*)&CTimeCycle::m_nWaterFogAlpha);
	Patch<void*>(0x55F7A9, (void*)&CTimeCycle::m_nHighLightMinIntensity);
	Patch<void*>(0x5BBFBF, (void*)&CTimeCycle::m_nHighLightMinIntensity);
	Patch<void*>(0x55F793, (void*)&CTimeCycle::m_fCloudAlpha);
	Patch<void*>(0x5BBFB2, (void*)&CTimeCycle::m_fCloudAlpha);
	Patch<void*>(0x55F77D, (void*)&CTimeCycle::m_fPostFx2Alpha);
	Patch<void*>(0x560E4B, (void*)&CTimeCycle::m_fPostFx2Alpha);
	Patch<void*>(0x5BBF99, (void*)&CTimeCycle::m_fPostFx2Alpha);
	Patch<void*>(0x55F767, (void*)&CTimeCycle::m_fPostFx2Blue);
	Patch<void*>(0x560E2A, (void*)&CTimeCycle::m_fPostFx2Blue);
	Patch<void*>(0x5BBF73, (void*)&CTimeCycle::m_fPostFx2Blue);
	Patch<void*>(0x55F751, (void*)&CTimeCycle::m_fPostFx2Green);
	Patch<void*>(0x560E09, (void*)&CTimeCycle::m_fPostFx2Green);
	Patch<void*>(0x5BBF5F, (void*)&CTimeCycle::m_fPostFx2Green);
	Patch<void*>(0x55F73B, (void*)&CTimeCycle::m_fPostFx2Red);
	Patch<void*>(0x560DE3, (void*)&CTimeCycle::m_fPostFx2Red);
	Patch<void*>(0x5BBF4D, (void*)&CTimeCycle::m_fPostFx2Red);
	Patch<void*>(0x55F725, (void*)&CTimeCycle::m_fPostFx1Alpha);
	Patch<void*>(0x560DC2, (void*)&CTimeCycle::m_fPostFx1Alpha);
	Patch<void*>(0x5BBF87, (void*)&CTimeCycle::m_fPostFx1Alpha);
	Patch<void*>(0x55F70F, (void*)&CTimeCycle::m_fPostFx1Blue);
	Patch<void*>(0x560DA1, (void*)&CTimeCycle::m_fPostFx1Blue);
	Patch<void*>(0x5BBF3B, (void*)&CTimeCycle::m_fPostFx1Blue);
	Patch<void*>(0x55F6FC, (void*)&CTimeCycle::m_fPostFx1Green);
	Patch<void*>(0x560D86, (void*)&CTimeCycle::m_fPostFx1Green);
	Patch<void*>(0x5BBF29, (void*)&CTimeCycle::m_fPostFx1Green);
	Patch<void*>(0x55F6E9, (void*)&CTimeCycle::m_fPostFx1Red);
	Patch<void*>(0x560D66, (void*)&CTimeCycle::m_fPostFx1Red);
	Patch<void*>(0x5BBF17, (void*)&CTimeCycle::m_fPostFx1Red);
	Patch<void*>(0x55F6D6, (void*)&CTimeCycle::m_fWaterAlpha);
	Patch<void*>(0x560C46, (void*)&CTimeCycle::m_fWaterAlpha);
	Patch<void*>(0x5BBF08, (void*)&CTimeCycle::m_fWaterAlpha);
	Patch<void*>(0x55F6C3, (void*)&CTimeCycle::m_fWaterBlue);
	Patch<void*>(0x560C2B, (void*)&CTimeCycle::m_fWaterBlue);
	Patch<void*>(0x5BBEF9, (void*)&CTimeCycle::m_fWaterBlue);
	Patch<void*>(0x55F6B0, (void*)&CTimeCycle::m_fWaterGreen);
	Patch<void*>(0x560C10, (void*)&CTimeCycle::m_fWaterGreen);
	Patch<void*>(0x5BBEEA, (void*)&CTimeCycle::m_fWaterGreen);
	Patch<void*>(0x55F69C, (void*)&CTimeCycle::m_fWaterRed);
	Patch<void*>(0x560BF0, (void*)&CTimeCycle::m_fWaterRed);
	Patch<void*>(0x5BBEDB, (void*)&CTimeCycle::m_fWaterRed);
	Patch<void*>(0x55F690, (void*)&CTimeCycle::m_nFluffyCloudsBottomBlue);
	Patch<void*>(0x5BBECC, (void*)&CTimeCycle::m_nFluffyCloudsBottomBlue);
	Patch<void*>(0x55F683, (void*)&CTimeCycle::m_nFluffyCloudsBottomGreen);
	Patch<void*>(0x5BBEC6, (void*)&CTimeCycle::m_nFluffyCloudsBottomGreen);
	Patch<void*>(0x55F677, (void*)&CTimeCycle::m_nFluffyCloudsBottomRed);
	Patch<void*>(0x5BBEC0, (void*)&CTimeCycle::m_nFluffyCloudsBottomRed);
	Patch<void*>(0x55F66B, (void*)&CTimeCycle::m_nLowCloudsBlue);
	Patch<void*>(0x5BBEB6, (void*)&CTimeCycle::m_nLowCloudsBlue);
	Patch<void*>(0x55F65F, (void*)&CTimeCycle::m_nLowCloudsGreen);
	Patch<void*>(0x5BBEAC, (void*)&CTimeCycle::m_nLowCloudsGreen);
	Patch<void*>(0x55F653, (void*)&CTimeCycle::m_nLowCloudsRed);
	Patch<void*>(0x5BBEA2, (void*)&CTimeCycle::m_nLowCloudsRed);
	Patch<void*>(0x55F640, (void*)&CTimeCycle::m_fLightsOnGroundBrightness);
	Patch<void*>(0x5BBE98, (void*)&CTimeCycle::m_fLightsOnGroundBrightness);
	Patch<void*>(0x55F62E, (void*)&CTimeCycle::m_fFogStart);
	Patch<void*>(0x560D42, (void*)&CTimeCycle::m_fFogStart);
	Patch<void*>(0x5BBE7B, (void*)&CTimeCycle::m_fFogStart);
	Patch<void*>(0x55F61B, (void*)&CTimeCycle::m_fFarClip);
	Patch<void*>(0x560D0C, (void*)&CTimeCycle::m_fFarClip);
	Patch<void*>(0x5BBE65, (void*)&CTimeCycle::m_fFarClip);
	Patch<void*>(0x55F60F, (void*)&CTimeCycle::m_nPoleShadowStrength);
	Patch<void*>(0x5BBE52, (void*)&CTimeCycle::m_nPoleShadowStrength);
	Patch<void*>(0x55F603, (void*)&CTimeCycle::m_nLightShadowStrength);
	Patch<void*>(0x5BBE4C, (void*)&CTimeCycle::m_nLightShadowStrength);
	Patch<void*>(0x55F5F7, (void*)&CTimeCycle::m_nShadowStrength);
	Patch<void*>(0x5BBE3B, (void*)&CTimeCycle::m_nShadowStrength);
	Patch<void*>(0x55F5E4, (void*)&CTimeCycle::m_fSpriteBrightness);
	Patch<void*>(0x5BBE2E, (void*)&CTimeCycle::m_fSpriteBrightness);
	Patch<void*>(0x55F5D2, (void*)&CTimeCycle::m_fSpriteSize);
	Patch<void*>(0x5BBE19, (void*)&CTimeCycle::m_fSpriteSize);
	Patch<void*>(0x55F5C0, (void*)&CTimeCycle::m_fSunSize);
	Patch<void*>(0x5BBDFE, (void*)&CTimeCycle::m_fSunSize);
	Patch<void*>(0x55F5B5, (void*)&CTimeCycle::m_nSunCoronaBlue);
	Patch<void*>(0x5BBDE6, (void*)&CTimeCycle::m_nSunCoronaBlue);
	Patch<void*>(0x55F5A9, (void*)&CTimeCycle::m_nSunCoronaGreen);
	Patch<void*>(0x5BBDE0, (void*)&CTimeCycle::m_nSunCoronaGreen);
	Patch<void*>(0x55F59D, (void*)&CTimeCycle::m_nSunCoronaRed);
	Patch<void*>(0x5BBDDA, (void*)&CTimeCycle::m_nSunCoronaRed);
	Patch<void*>(0x55F591, (void*)&CTimeCycle::m_nSunCoreBlue);
	Patch<void*>(0x5BBDC7, (void*)&CTimeCycle::m_nSunCoreBlue);
	Patch<void*>(0x55F585, (void*)&CTimeCycle::m_nSunCoreGreen);
	Patch<void*>(0x5BBDBA, (void*)&CTimeCycle::m_nSunCoreGreen);
	Patch<void*>(0x55F579, (void*)&CTimeCycle::m_nSunCoreRed);
	Patch<void*>(0x5BBDAD, (void*)&CTimeCycle::m_nSunCoreRed);
	Patch<void*>(0x55F56D, (void*)&CTimeCycle::m_nSkyBottomBlue);
	Patch<void*>(0x560BCA, (void*)&CTimeCycle::m_nSkyBottomBlue);
	Patch<void*>(0x5BBDA0, (void*)&CTimeCycle::m_nSkyBottomBlue);
	Patch<void*>(0x55F561, (void*)&CTimeCycle::m_nSkyBottomGreen);
	Patch<void*>(0x560BA0, (void*)&CTimeCycle::m_nSkyBottomGreen);
	Patch<void*>(0x5BBD93, (void*)&CTimeCycle::m_nSkyBottomGreen);
	Patch<void*>(0x55F555, (void*)&CTimeCycle::m_nSkyBottomRed);
	Patch<void*>(0x560B6D, (void*)&CTimeCycle::m_nSkyBottomRed);
	Patch<void*>(0x5BBD86, (void*)&CTimeCycle::m_nSkyBottomRed);
	Patch<void*>(0x55F549, (void*)&CTimeCycle::m_nSkyTopBlue);
	Patch<void*>(0x560B47, (void*)&CTimeCycle::m_nSkyTopBlue);
	Patch<void*>(0x560FD8, (void*)&CTimeCycle::m_nSkyTopBlue);
	Patch<void*>(0x561197, (void*)&CTimeCycle::m_nSkyTopBlue);
	Patch<void*>(0x5BBD79, (void*)&CTimeCycle::m_nSkyTopBlue);
	Patch<void*>(0x55F53D, (void*)&CTimeCycle::m_nSkyTopGreen);
	Patch<void*>(0x560B19, (void*)&CTimeCycle::m_nSkyTopGreen);
	Patch<void*>(0x560FCE, (void*)&CTimeCycle::m_nSkyTopGreen);
	Patch<void*>(0x56118D, (void*)&CTimeCycle::m_nSkyTopGreen);
	Patch<void*>(0x5BBD6C, (void*)&CTimeCycle::m_nSkyTopGreen);
	Patch<void*>(0x55F531, (void*)&CTimeCycle::m_nSkyTopRed);
	Patch<void*>(0x560AEA, (void*)&CTimeCycle::m_nSkyTopRed);
	Patch<void*>(0x560FC4, (void*)&CTimeCycle::m_nSkyTopRed);
	Patch<void*>(0x561181, (void*)&CTimeCycle::m_nSkyTopRed);
	Patch<void*>(0x5BBD5F, (void*)&CTimeCycle::m_nSkyTopRed);
	Patch<void*>(0x55F51E, (void*)&CTimeCycle::m_nAmbientBlue_Obj);
	Patch<void*>(0x560CF0, (void*)&CTimeCycle::m_nAmbientBlue_Obj);
	Patch<void*>(0x5BBD52, (void*)&CTimeCycle::m_nAmbientBlue_Obj);
	Patch<void*>(0x55F50C, (void*)&CTimeCycle::m_nAmbientGreen_Obj);
	Patch<void*>(0x560CD5, (void*)&CTimeCycle::m_nAmbientGreen_Obj);
	Patch<void*>(0x5BBD45, (void*)&CTimeCycle::m_nAmbientGreen_Obj);
	Patch<void*>(0x55F4FA, (void*)&CTimeCycle::m_nAmbientRed_Obj);
	Patch<void*>(0x560CB5, (void*)&CTimeCycle::m_nAmbientRed_Obj);
	Patch<void*>(0x5BBD38, (void*)&CTimeCycle::m_nAmbientRed_Obj);
	Patch<void*>(0x55F4E8, (void*)&CTimeCycle::m_nAmbientBlue);
	Patch<void*>(0x560C9A, (void*)&CTimeCycle::m_nAmbientBlue);
	Patch<void*>(0x5BBD2B, (void*)&CTimeCycle::m_nAmbientBlue);
	Patch<void*>(0x55F4D6, (void*)&CTimeCycle::m_nAmbientGreen);
	Patch<void*>(0x560C7F, (void*)&CTimeCycle::m_nAmbientGreen);
	Patch<void*>(0x5BBD1E, (void*)&CTimeCycle::m_nAmbientGreen);
	Patch<void*>(0x55F4C5, (void*)&CTimeCycle::m_nAmbientRed);
	Patch<void*>(0x560C61, (void*)&CTimeCycle::m_nAmbientRed);
	Patch<void*>(0x5BBD11, (void*)&CTimeCycle::m_nAmbientRed);

	static char *timecycstr = "timecyc_24h.dat";
	Patch<char*>(0x5BBAD9 +1, timecycstr);
	Patch<int>(0x5BBB18 +1, NUMHOURS);

	Patch<uchar*>(0x560572, timecycleHours + 0x0);
	Patch<uchar*>(0x56051E, timecycleHours + 0x1);
	Patch<uchar*>(0x560579, timecycleHours + 0x1);
	Patch<uchar*>(0x560543, timecycleHours + 0x2);

	Patch<uchar*>(0x5613AD, timecycleHorizon);
	Patch<uchar*>(0x5613B8, timecycleHorizon);

	InjectHook(0x560562, mod24, PATCH_JUMP);
	InjectHook(0x5605DA, mod24_1, PATCH_JUMP);
	InjectHook(0x561158, mod24_2, PATCH_JUMP);
	InjectHook(0x55FEC0, CTimeCycle::StartExtraColour, PATCH_JUMP);

#ifdef REPLACE
	// replace functions!
	InjectHook(0x5BBAC0, CTimeCycle::Initialise, PATCH_JUMP);
	InjectHook(0x55F4B0, &CColourSet::ctor, PATCH_JUMP);
	InjectHook(0x55F870, &CColourSet::Interpolate, PATCH_JUMP);
	InjectHook(0x5603D0, CTimeCycle::CalcColoursForPoint, PATCH_JUMP);
	InjectHook(0x5616E0, CTimeCycle::FindFarClipForCoors, PATCH_JUMP);
	InjectHook(0x561760, CTimeCycle::Update, PATCH_JUMP);
#endif
}

BOOL WINAPI
DllMain(HINSTANCE hInst, DWORD reason, LPVOID)
{
	if(reason == DLL_PROCESS_ATTACH){
		// TODO: is this correct?
		if(*(DWORD*)DynBaseAddress(0x82457C) != 0x94BF &&
		   *(DWORD*)DynBaseAddress(0x8245BC) == 0x94BF)
			return FALSE;
		dllModule = hInst;
		patch();
	}
	return TRUE;
}
