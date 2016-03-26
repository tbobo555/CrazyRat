#include "Rat.h"


namespace GameSprite
{
    Rat::Rat(std::string image, int pRatType) : GameSprite::BaseSprite(image)
    {
        this->addEventListener();
    }
    
    void Rat::hit()
    {
        this->release();
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
        auto target = static_cast<Rat*>(event->getCurrentTarget());
        Vec2 locationInNode = target->convertToNodeSpace(touch->getLocation());
        Size s = target->getContentSize();
        Rect rect = Rect(0, 0, s.width, s.height);
        if (rect.containsPoint(locationInNode)) {
            log("Rat began... x = %f, y = %f", locationInNode.x, locationInNode.y);
            target->hit();
            return true;
        }
        return false;
    }

    void Rat::onTouchEnded(Touch* touch, Event* event){}

    void Rat::onTouchMoved(Touch* touch, Event* event){}

    void Rat::onTouchCanceled(Touch* touch, Event* event){}

}
