#include "AboutButton.h"

namespace GameSprite
{
    AboutButton::AboutButton(std::string image) : GameSprite::BaseSprite(image)
    {
        this->addEventListener();
    }
    
    void AboutButton::addEventListener()
    {
        auto listener = EventListenerTouchOneByOne::create();
        listener->setSwallowTouches(true);
        listener->onTouchBegan = AboutButton::onTouchBegan;
        listener->onTouchEnded = AboutButton::onTouchEnded;
        listener->onTouchMoved = AboutButton::onTouchMoved;
        listener->onTouchCancelled = AboutButton::onTouchCanceled;
        Director::getInstance()->getEventDispatcher()
        ->addEventListenerWithSceneGraphPriority(listener, this);
    }
    
    bool AboutButton::onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *event)
    {
        auto target = static_cast<Sprite*>(event->getCurrentTarget());
        Vec2 locationInNode = target->convertToNodeSpace(touch->getLocation());
        Size s = target->getContentSize();
        Rect rect = Rect(0, 0, s.width, s.height);
        if (rect.containsPoint(locationInNode)) {
            Manager::SoundsManager::getInstance()->playSound("audio/sounds/ButtonClick.caf");
            log("AboutButton began... x = %f, y = %f", locationInNode.x, locationInNode.y);
            target->setScale(0.95);
            return true;
        }
        return false;
        
    }
    
    void AboutButton::onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *event)
    {
        auto target = static_cast<Sprite*>(event->getCurrentTarget());
        Vec2 locationInNode = target->convertToNodeSpace(touch->getLocation());
        Size s = target->getContentSize();
        Rect rect = Rect(0, 0, s.width, s.height);
        if (rect.containsPoint(locationInNode)) {
            log("AboutButton ended... x = %f, y = %f", locationInNode.x, locationInNode.y);
            target->setScale(1.0);
        } else {
            target->setScale(1.0);
        }
    }
    
    void AboutButton::onTouchMoved(cocos2d::Touch *touch, cocos2d::Event *event)
    {
        
    }
    
    void AboutButton::onTouchCanceled(cocos2d::Touch *touch, cocos2d::Event *event)
    {
        auto target = static_cast<Sprite*>(event->getCurrentTarget());
        target->setScale(1.0);
    }
}
