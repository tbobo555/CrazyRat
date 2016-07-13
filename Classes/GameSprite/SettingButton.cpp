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
            log("SettingButton began... x = %f, y = %f", locationInNode.x, locationInNode.y);
            target->setScale(0.9);
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
            settingBackground->addChild(settingBackButton, 101, 2);
            settingBackground->addChild(musicButton, 101, 3);
            settingBackground->addChild(soundsButton, 101, 4);
            currentScene->addChild(settingBackground, 100, 1);
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
