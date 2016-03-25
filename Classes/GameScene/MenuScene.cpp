#include "MenuScene.h"

namespace GameScene
{
    MenuScene::MenuScene() : GameScene::BaseScene(){}
    
    void MenuScene::initScene()
    {
        auto spriteManager = Manager::SpriteManager::getInstance();
        this->settingButton = new SettingButton("image/SettingButton.png");
        this->settingButton->getCCSprite()->setPosition(this->getSettingButtonPosition());
        spriteManager->setWithKey("MenuScene_SettingButton", this->settingButton);
        
        this->settingBackground = new Background("image/SettingBackground.png");
        this->settingBackground->getCCSprite()->setPosition(this->center);
        spriteManager->setWithKey("MenuScene_SettingBackground", this->settingBackground);
        
        this->settingBackButton = new SettingBackButton("image/BackButton.png");
        this->settingBackButton->getCCSprite()->setPosition(this->getSettingBackButtonPosition());
        spriteManager->setWithKey("MenuScene_SettingBackButton", this->settingBackButton);
        
        this->musicButton = new MusicButton("image/MusicOnButton.png");
        this->musicButton->getCCSprite()->setPosition(this->getMusicButtonPosition());
        spriteManager->setWithKey("MenuScene_MusicButton", this->musicButton);
        
        this->soundsButton = new SoundsButton("image/SoundsOnButton.png");
        this->soundsButton->getCCSprite()->setPosition(this->getSoundsButtonPosition());
        spriteManager->setWithKey("MenuScene_SoundsButton", this->soundsButton);
    }
    
    void MenuScene::releaseScene()
    {
        auto spriteManager = Manager::SpriteManager::getInstance();
        spriteManager->releaseByKey("MenuScene_SettingButton");
        spriteManager->releaseByKey("MenuScene_SettingBackground");
        spriteManager->releaseByKey("MenuScene_SettingBackButton");
        spriteManager->releaseByKey("MenuScene_MusicButton");
        spriteManager->releaseByKey("MenuScene_SoundsButton");
    }
    
    Vec2 MenuScene::getMusicButtonPosition()
    {
        auto imageConfig = ImageConfig::getInstance();
        return Vec2(this->center.x - imageConfig->getImageSize("MusicOnButton").width * 0.6,
                    this->center.y);

    }
    
    Vec2 MenuScene::getSoundsButtonPosition()
    {
        auto imageConfig = ImageConfig::getInstance();
        return Vec2(this->center.x + imageConfig->getImageSize("SoundsOnButton").width * 0.6,
                    this->center.y);
    }

    Vec2 MenuScene::getSettingBackButtonPosition()
    {
        auto imageConfig = ImageConfig::getInstance();
        return Vec2(this->leftTop.x + imageConfig->getImageSize("BackButton").width * 0.6,
                    this->leftTop.y - imageConfig->getImageSize("BackButton").height * 0.6);

    }
    
    Vec2 MenuScene::getSettingButtonPosition()
    {
        auto imageConfig = ImageConfig::getInstance();
        return Vec2(this->leftBottom.x + imageConfig->getImageSize("SettingButton").width * 0.6,
                    this->leftBottom.y + imageConfig->getImageSize("SettingButton").height * 0.6);
    }
}
