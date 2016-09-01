#include "SettingButton.h"

namespace GameSprite
{    
    SettingButton::SettingButton(std::string image) : GameSprite::BaseSprite(image)
    {
        this->addEventListener();
    }
    
    void SettingButton::addEventListener()
    {
        auto listener = EventListenerTouchOneByOne::create();
        listener->setSwallowTouches(true);
        listener->onTouchBegan = SettingButton::onTouchBegan;
        listener->onTouchEnded = SettingButton::onTouchEnded;
        listener->onTouchMoved = SettingButton::onTouchMoved;
        listener->onTouchCancelled = SettingButton::onTouchCanceled;
        Director::getInstance()->getEventDispatcher()
        ->addEventListenerWithSceneGraphPriority(listener, this);
    }
    
    bool SettingButton::onTouchBegan(Touch* touch, Event* event)
    {
        auto target = static_cast<Sprite*>(event->getCurrentTarget());
        
        Vec2 locationInNode = target->convertToNodeSpace(touch->getLocation());
        Size s = target->getContentSize();
        Rect rect = Rect(0, 0, s.width, s.height);
        
        if (rect.containsPoint(locationInNode)) {
            Manager::SoundsManager::getInstance()->playSound("audio/sounds/ButtonClick.caf");
            log("SettingButton began... x = %f, y = %f", locationInNode.x, locationInNode.y);
            target->setScale(0.95);
            return true;
        }
        return false;

    }
    
    void SettingButton::onTouchEnded(Touch* touch, Event* event)
    {
        auto target = static_cast<Sprite*>(event->getCurrentTarget());
        Vec2 locationInNode = target->convertToNodeSpace(touch->getLocation());
        Size s = target->getContentSize();
        Rect rect = Rect(0, 0, s.width, s.height);
        if (rect.containsPoint(locationInNode)) {
            target->setScale(1.0);
            Manager::SceneManager* sceneManager = Manager::SceneManager::getInstance();
            Manager::SpriteManager* spriteManager = Manager::SpriteManager::getInstance();
            auto currentScene = sceneManager->getCurrent();
            auto settingBackground = spriteManager->getByKey("MenuScene_SettingBackground");
            auto settingBackButton = spriteManager->getByKey("MenuScene_SettingBackButton");
            auto musicButton = spriteManager->getByKey("MenuScene_MusicButton");
            auto soundsButton = spriteManager->getByKey("MenuScene_SoundsButton");
            auto aboutButton = spriteManager->getByKey("MenuScene_AboutButton");
            auto donateButton = spriteManager->getByKey("MenuScene_DonateButton");
            auto settingMask = spriteManager->getByKey("MenuScene_SettingMask");
            auto donateTitle = spriteManager->getByKey("MenuScene_DonateTitle");
            auto donate2Button = spriteManager->getByKey("MenuScene_Donate2Button");
            auto donate5Button = spriteManager->getByKey("MenuScene_Donate5Button");
            auto donateBackButton = spriteManager->getByKey("MenuScene_DonateBackButton");
            musicButton->setVisible(true);
            soundsButton->setVisible(true);
            aboutButton->setVisible(true);
            donateButton->setVisible(true);
            settingBackground->addChild(settingBackButton, 101, 2);
            settingBackground->addChild(musicButton, 101, 3);
            settingBackground->addChild(soundsButton, 101, 4);
            settingBackground->addChild(aboutButton, 101, 5);
            settingBackground->addChild(donateButton, 101, 6);
            settingBackground->addChild(donateTitle, 101, 7);
            settingBackground->addChild(donate2Button, 101, 8);
            settingBackground->addChild(donate5Button, 101, 9);
            settingBackground->addChild(donateBackButton, 101, 10);
            donateTitle->setVisible(false);
            donateTitle->setLocalZOrder(-99);
            donate2Button->setVisible(false);
            donate2Button->setLocalZOrder(-99);
            donate5Button->setVisible(false);
            donate5Button->setLocalZOrder(-99);
            donateBackButton->setVisible(false);
            donateBackButton->setLocalZOrder(-99);
            currentScene->addChild(settingBackground, 100, 1);
            currentScene->addChild(settingMask, 99);
        } else {
            target->setScale(1.0);
        }
    }
    
    void SettingButton::onTouchMoved(Touch* touch, Event* event)
    {
        
    }
    
    void SettingButton::onTouchCanceled(Touch* touch, Event* event)
    {
        auto target = static_cast<Sprite*>(event->getCurrentTarget());
        target->setScale(1.0);
    }

}
