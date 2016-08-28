#include "SoundsManager.h"


namespace Manager
{
    SoundsManager* SoundsManager::instance = new SoundsManager();
    
    SoundsManager* SoundsManager::getInstance()
    {
        return instance;
    }
    
    SoundsManager::SoundsManager(){}
    
    
    void SoundsManager::playSound(const char *fileName)
    {
        if (DB::SwitchSetting::getInstance()->getSoundsSwitch() == 1) {
            CocosDenshion::SimpleAudioEngine::getInstance()->playEffect(fileName, false);
        }
    }
}
