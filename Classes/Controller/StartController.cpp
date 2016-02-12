#include "StartController.h"

namespace Controller
{
    
    void Controller::StartController::run()
    {
        auto sceneManager = Manager::SceneManager::getInstance();
        auto spriteManager = Manager::SpriteManager::getInstance();
        auto director = Director::getInstance();
        GameSprite::StartBg *startBg = new GameSprite::StartBg();
        GameSprite::StartButton *startButton = new GameSprite::StartButton();
        GameSprite::SettingButton *settingButton = new GameSprite::SettingButton();
        GameSprite::SettingBg *settingBg = new GameSprite::SettingBg();
        GameSprite::SettingBackButton *settingBackButton = new GameSprite::SettingBackButton();
        GameSprite::MusicButton *musicButton = new GameSprite::MusicButton();
        GameSprite::SoundsButton *soundsButton = new GameSprite::SoundsButton();
        spriteManager->setWithKey("StartBg", startBg);
        spriteManager->setWithKey("StartButton", startButton);
        spriteManager->setWithKey("SettingButton", settingButton);
        spriteManager->setWithKey("SettingBg", settingBg);
        spriteManager->setWithKey("MusicButton", musicButton);
        spriteManager->setWithKey("SoundsButton", soundsButton);
        spriteManager->setWithKey("SettingBackButton", settingBackButton);
        GameScene::StartScene *startScene = new GameScene::StartScene();
        startScene->startBg = startBg;
        startScene->startButton = startButton;
        startScene->settingButton = settingButton;
        startScene->initScene();
        sceneManager->setCurrent(startScene);
        director->runWithScene(startScene->getCCScene());
    }
}
