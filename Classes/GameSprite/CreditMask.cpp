#include "CreditMask.h"

namespace GameSprite
{
    CreditMask::CreditMask(std::string image) : GameSprite::BaseSprite(image)
    {
        this->addEventListener();
    }
    
    void CreditMask::addEventListener()
    {
        auto listener = EventListenerTouchOneByOne::create();
        listener->setSwallowTouches(true);
        listener->onTouchBegan = CreditMask::onTouchBegan;
        listener->onTouchEnded = CreditMask::onTouchEnded;
        listener->onTouchMoved = CreditMask::onTouchMoved;
        listener->onTouchCancelled = CreditMask::onTouchCanceled;
        Director::getInstance()->getEventDispatcher()
        ->addEventListenerWithSceneGraphPriority(listener, this);
    }
    
    bool CreditMask::onTouchBegan(Touch* touch, Event* event)
    {
        auto target = static_cast<Sprite*>(event->getCurrentTarget());
        Vec2 locationInNode = target->convertToNodeSpace(touch->getLocation());
        Size s = target->getContentSize();
        Rect rect = Rect(0, 0, s.width, s.height);
        if (rect.containsPoint(locationInNode)) {
            log("CreditMask began... x = %f, y = %f", locationInNode.x, locationInNode.y);
            return true;
        }
        return false;
    }
    
    void CreditMask::onTouchEnded(Touch* touch, Event* event)
    {
        auto target = static_cast<Sprite*>(event->getCurrentTarget());
        Vec2 locationInNode = target->convertToNodeSpace(touch->getLocation());
        Size s = target->getContentSize();
        Rect rect = Rect(0, 0, s.width, s.height);
        if (rect.containsPoint(locationInNode)) {
            log("CreditMask ended... x = %f, y = %f", locationInNode.x, locationInNode.y);
            target->setVisible(false);
            target->setLocalZOrder(-99);
        }
    }
    
    void CreditMask::onTouchMoved(Touch* touch, Event* event)
    {
    }
    
    void CreditMask::onTouchCanceled(Touch* touch, Event* event)
    {
    }

}
