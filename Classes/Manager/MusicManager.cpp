#include "MusicManager.h"


namespace Manager
{
    MusicManager* MusicManager::instance = new MusicManager();
    
    MusicManager* MusicManager::getInstance()
    {
        return instance;
    }
    
    MusicManager::MusicManager(){}
    
    void MusicManager::playMusic(const char *fileName)
    {
        CocosDenshion::SimpleAudioEngine::getInstance()->stopBackgroundMusic();
        CocosDenshion::SimpleAudioEngine::getInstance()->playBackgroundMusic(fileName, true);
        if (DB::SwitchSetting::getInstance()->getMusicSwitch() == 0) {
            this->turnOffMusic();
        }
        this->musicName = fileName;
    }
    
    void MusicManager::playMusicNoLoop(const char *fileName)
    {
        CocosDenshion::SimpleAudioEngine::getInstance()->stopBackgroundMusic();
        CocosDenshion::SimpleAudioEngine::getInstance()->playBackgroundMusic(fileName, false);
        if (DB::SwitchSetting::getInstance()->getMusicSwitch() == 0) {
            this->turnOffMusic();
        }
        this->musicName = fileName;
    }
    
    void MusicManager::stopMusic()
    {
        CocosDenshion::SimpleAudioEngine::getInstance()->stopBackgroundMusic();
    }
    
    void MusicManager::pauseMusic()
    {
        CocosDenshion::SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
    }
    
    void MusicManager::resumeMusic()
    {
        CocosDenshion::SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
    }
    
    void MusicManager::turnOnMusic()
    {
        if (CocosDenshion::SimpleAudioEngine::getInstance()->getBackgroundMusicVolume() == 0) {
            DB::SwitchSetting::getInstance()->turnOnMusic();
            CocosDenshion::SimpleAudioEngine::getInstance()->setBackgroundMusicVolume(1);
        }
    }
    
    void MusicManager::turnOffMusic()
    {
        if (CocosDenshion::SimpleAudioEngine::getInstance()->getBackgroundMusicVolume() == 1) {
            DB::SwitchSetting::getInstance()->turnOffMusic();
            CocosDenshion::SimpleAudioEngine::getInstance()->setBackgroundMusicVolume(0);
        }
    }    
}
