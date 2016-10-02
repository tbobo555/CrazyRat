#include "OkButton.h"
#include "GameScene/PlayBaseScene.h"

namespace GameSprite
{
    OkButton::OkButton(std::string image) : GameSprite::BaseSprite(image)
    {
        this->addEventListener();
    }
    
    void OkButton::addEventListener()
    {
        auto listener = EventListenerTouchOneByOne::create();
        listener->setSwallowTouches(true);
        listener->onTouchBegan = OkButton::onTouchBegan;
        listener->onTouchEnded = OkButton::onTouchEnded;
        listener->onTouchMoved = OkButton::onTouchMoved;
        listener->onTouchCancelled = OkButton::onTouchCanceled;
        Director::getInstance()->getEventDispatcher()
        ->addEventListenerWithSceneGraphPriority(listener, this);
    }
    
    bool OkButton::onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *event)
    {
        auto target = static_cast<Sprite*>(event->getCurrentTarget());
        Vec2 locationInNode = target->convertToNodeSpace(touch->getLocation());
        Size s = target->getContentSize();
        Rect rect = Rect(0, 0, s.width, s.height);
        if (rect.containsPoint(locationInNode)) {
            Manager::SoundsManager::getInstance()->playSound("audio/sounds/ButtonClick.caf");
            log("OkButton began... x = %f, y = %f", locationInNode.x, locationInNode.y);
            target->setScale(0.95);
            return true;
        }
        return false;
        
    }
    
    void OkButton::onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *event)
    {
        auto target = static_cast<Sprite*>(event->getCurrentTarget());
        Vec2 locationInNode = target->convertToNodeSpace(touch->getLocation());
        Size s = target->getContentSize();
        Rect rect = Rect(0, 0, s.width, s.height);
        if (rect.containsPoint(locationInNode)) {
            log("OkButton ended... x = %f, y = %f", locationInNode.x, locationInNode.y);
            target->setScale(1.0);
            auto currentScene = static_cast<PlayBaseScene*>(Manager::SceneManager::getInstance()->getCurrent());
            currentScene->play();
        } else {
            target->setScale(1.0);
        }
    }
    
    void OkButton::onTouchMoved(cocos2d::Touch *touch, cocos2d::Event *event)
    {
    }
    
    void OkButton::onTouchCanceled(cocos2d::Touch *touch, cocos2d::Event *event)
    {
    }

}
