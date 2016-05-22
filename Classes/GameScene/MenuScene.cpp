#include "MenuScene.h"

namespace GameScene
{
    MenuScene::MenuScene() : GameScene::BaseScene()
    {
        this->name = "MenuScene";
    }
    
    void MenuScene::initScene()
    {
        auto spriteManager = Manager::SpriteManager::getInstance();
        this->settingButton = new SettingButton("image/SettingButton.png");
        this->settingButton->setPosition(this->getSettingButtonPosition());
        spriteManager->setWithKey("MenuScene_SettingButton", this->settingButton);
        
        this->settingBackground = new Background("image/SettingBackground.png");
        this->settingBackground->setPosition(this->getSettingBackgroundPosition());
        spriteManager->setWithKey("MenuScene_SettingBackground", this->settingBackground);
        
        this->settingBackButton = new SettingBackButton("image/CloseSettingButton.png");
        this->settingBackButton->setPosition(this->getSettingBackButtonPosition());
        spriteManager->setWithKey("MenuScene_SettingBackButton", this->settingBackButton);
        
        this->musicButton = new MusicButton("image/MusicOnButton.png");
        this->musicButton->setPosition(this->getMusicButtonPosition());
        spriteManager->setWithKey("MenuScene_MusicButton", this->musicButton);
        
        this->soundsButton = new SoundsButton("image/SoundsOnButton.png");
        this->soundsButton->setPosition(this->getSoundsButtonPosition());
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
    
    Vec2 MenuScene::getSettingBackgroundPosition()
    {
        return Vec2(this->center.x, this->center.y + this->visibleSize.height / 20);
    }
    
    Vec2 MenuScene::getMusicButtonPosition()
    {
        float width = this->settingBackground->getContentSize().width;
        float height = this->settingBackground->getContentSize().height;
        Vec2 center = Vec2(width / 2, height / 2);
        return Vec2(center.x - width / 4, center.y);
    }
    
    Vec2 MenuScene::getSoundsButtonPosition()
    {
        float width = this->settingBackground->getContentSize().width;
        float height = this->settingBackground->getContentSize().height;
        Vec2 center = Vec2(width / 2, height / 2);
        return Vec2(center.x + width / 4, center.y);
    }

    Vec2 MenuScene::getSettingBackButtonPosition()
    {
        return Vec2(this->settingBackground->getContentSize().width, this->settingBackground->getContentSize().height);

    }
    
    Vec2 MenuScene::getSettingButtonPosition()
    {
        return Vec2(this->visibleOrigin.x + this->visibleSize.height / 12, this->visibleOrigin.y + this->visibleSize.height / 12);
    }
}
