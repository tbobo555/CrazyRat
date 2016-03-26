#include "Rat.h"


namespace GameSprite
{
    Rat::Rat(std::string image, int pRatType) : GameSprite::BaseSprite(image)
    {
        this->addEventListener();
    }
    
    void Rat::addEventListener()
    {
        auto listener = EventListenerTouchOneByOne::create();
        listener->setSwallowTouches(true);
        listener->onTouchBegan = Rat::onTouchBegan;
        listener->onTouchEnded = Rat::onTouchEnded;
        listener->onTouchMoved = Rat::onTouchMoved;
        listener->onTouchCancelled = Rat::onTouchCanceled;
        Director::getInstance()->getEventDispatcher()
        ->addEventListenerWithSceneGraphPriority(listener, this);
    }
    
    bool Rat::onTouchBegan(Touch* touch, Event* event)
    {
        auto target = static_cast<Sprite*>(event->getCurrentTarget());
        Vec2 locationInNode = target->convertToNodeSpace(touch->getLocation());
        Size s = target->getContentSize();
        Rect rect = Rect(0, 0, s.width, s.height);
        if (rect.containsPoint(locationInNode)) {
            log("Rat began... x = %f, y = %f", locationInNode.x, locationInNode.y);
            target->setScale(1.2);
            return true;
        }
        return false;
    }
    
    void Rat::onTouchEnded(Touch* touch, Event* event)
    {
        auto target = static_cast<Sprite*>(event->getCurrentTarget());
        Vec2 locationInNode = target->convertToNodeSpace(touch->getLocation());
        Size s = target->getContentSize();
        Rect rect = Rect(0, 0, s.width, s.height);
        if (rect.containsPoint(locationInNode)) {
            log("Rat ended... x = %f, y = %f", locationInNode.x, locationInNode.y);
            target->setScale(1.0);
        } else {
            target->setScale(1.0);
        }
    }
    
    void Rat::onTouchMoved(Touch* touch, Event* event)
    {
        
    }
    
    void Rat::onTouchCanceled(Touch* touch, Event* event)
    {
        auto target = static_cast<Sprite*>(event->getCurrentTarget());
        target->setScale(1.0);
    }

}