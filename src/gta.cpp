#include "gta.h"
#include "MemoryMgr.h"

WRAPPER void CFileMgr::SetDir(const char *dir) { WRAPARG(dir); EAXJMP(0x5387D0); }
WRAPPER int CFileMgr::OpenFile(const char *path, const char *mode) { WRAPARG(path); WRAPARG(mode); EAXJMP(0x538900); }
WRAPPER void CFileMgr::CloseFile(int fd) { WRAPARG(fd); EAXJMP(0x5389D0); }

WRAPPER char *CFileLoader::LoadLine(int fd) { WRAPARG(fd); EAXJMP(0x536F80); }

void
CVector::Normalise(void)
{
	double dot, invlen;
	dot = this->x * this->x + this->y * this->y + this->z * this->z;
	if(dot > 0.0){
		invlen = 1.0 / sqrt(dot);
		this->x = invlen * this->x;
		this->y = invlen * this->y;
		this->z = invlen * this->z;
	}else
		this->x = 1.0f;
}

float &CTimer::ms_fTimeStep = *(float*)0xB7CB5C;

ushort &CClock::ms_nGameClockSeconds = *(ushort*)0xB70150;
uchar  &CClock::ms_nGameClockMinutes = *(uchar*)0xB70152;
uchar  &CClock::ms_nGameClockHours = *(uchar*)0xB70153;

short &CWeather::OldWeatherType = *(short*)0xC81320;
short &CWeather::NewWeatherType = *(short*)0xC8131C;
float &CWeather::InterpolationValue = *(float*)0xC8130C;
float &CWeather::UnderWaterness = *(float*)0xC8132C;
float &CWeather::InTunnelness = *(float*)0xC81334;
bool &CWeather::bScriptsForceRain = *(bool*)0xC812AC;

float &CCoronas::LightsMult = *(float*)0x8D4B5C;

WRAPPER bool CCullZones::PlayerNoRain(void) { EAXJMP(0x72DDC0); }
WRAPPER bool CCullZones::CamNoRain(void) { EAXJMP(0x72DDB0); }

bool &CCutsceneMgr::ms_running = *(bool*)0xB5F851;

WRAPPER void CShadows__CalcPedShadowValues(float x, float y, float z, float *sfx, float *sfy, float *ssx, float *ssy, float *sdx, float *sdy)
{ WRAPARG(x); WRAPARG(y); WRAPARG(z); WRAPARG(sfx); WRAPARG(sfy); WRAPARG(ssx); WRAPARG(ssy); WRAPARG(sdx); WRAPARG(sdy); EAXJMP(0x7076C0); }
