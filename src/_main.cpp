#include "mod_utils.hpp"
#include "hooks.hpp"
using namespace cocos2d;
using namespace cocos2d::extension;
using namespace gd;
using namespace std;

#include "SimpleIni.h"

inline void(__thiscall* GameManager_update)(GameManager*, float);
void __fastcall GameManager_update_H(GameManager* self, void*, float dt) {
    GameManager_update(self, dt);
    CCTexture2D::setDefaultAlphaPixelFormat(CCTexture2DPixelFormat::kCCTexture2DPixelFormat_RGBA8888);
}

DWORD WINAPI PROCESS_ATTACH(void* hModule) {
    MH_SafeInitialize();
    HOOK(base + 0xce440, GameManager_update);
    CCTexture2D::setDefaultAlphaPixelFormat(CCTexture2DPixelFormat::kCCTexture2DPixelFormat_RGBA8888);
    return 0;
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved) {
    if (ul_reason_for_call == DLL_PROCESS_ATTACH)
        CreateThread(0, 0, PROCESS_ATTACH, hModule, 0, 0);
    return TRUE;
}
