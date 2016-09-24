#include "SettingButton.h"
#include "GameScene/MenuScene.h"

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
            auto sceneManager = Manager::SceneManager::getInstance();
            MenuScene* menuScene = static_cast<MenuScene*>(sceneManager->getByKey("MenuScene"));
            menuScene->openMenu();
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
