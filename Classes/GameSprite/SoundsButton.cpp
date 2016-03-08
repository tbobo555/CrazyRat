#include "SoundsButton.h"

namespace GameSprite {
    const std::string SoundsButton::originImage = "image/SoundsBtn.png";
    
    SoundsButton::SoundsButton() : BaseSprite::BaseSprite(SoundsButton::originImage)
    {
        Size visibleSize = Director::getInstance()->getVisibleSize();
        Vec2 origin = Director::getInstance()->getVisibleOrigin();
        float x = origin.x + visibleSize.width / 2 + this->sprite->getContentSize().width * 0.6;
        float y = origin.y + visibleSize.height / 2;
        this->sprite->setPosition(Vec2(x, y));
        this->addEventListner();
    }
    
    void SoundsButton::addEventListner()
    {
        auto listener = EventListenerTouchOneByOne::create();
        listener->setSwallowTouches(true);
        listener->onTouchBegan = SoundsButton::onTouchBegan;
        listener->onTouchEnded = SoundsButton::onTouchEnded;
        listener->onTouchMoved = SoundsButton::onTouchMoved;
        listener->onTouchCancelled = SoundsButton::onTouchCanceled;
        Director::getInstance()->getEventDispatcher()
        ->addEventListenerWithSceneGraphPriority(listener, this->sprite);
    }
    
    bool SoundsButton::onTouchBegan(Touch* touch, Event* event)
    {
        auto target = static_cast<Sprite*>(event->getCurrentTarget());
        Vec2 locationInNode = target->convertToNodeSpace(touch->getLocation());
        Size s = target->getContentSize();
        Rect rect = Rect(0, 0, s.width, s.height);
        if (rect.containsPoint(locationInNode)) {
            log("SoundsButton began... x = %f, y = %f", locationInNode.x, locationInNode.y);
            target->setScale(1.2);
            return true;
        }
        return false;
    }
    
    void SoundsButton::onTouchEnded(Touch* touch, Event* event)
    {
        auto target = static_cast<Sprite*>(event->getCurrentTarget());
        target->setScale(1.0);
    }
    
    void SoundsButton::onTouchMoved(Touch* touch, Event* event)
    {
        
    }
    
    void SoundsButton::onTouchCanceled(Touch* touch, Event* event)
    {
        auto target = static_cast<Sprite*>(event->getCurrentTarget());
        target->setScale(1.0);
    }
    
}
