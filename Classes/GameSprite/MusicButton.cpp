#include "MusicButton.h"

namespace GameSprite
{
    MusicButton::MusicButton(std::string image) : GameSprite::BaseSprite(image)
    {
        this->addEventListener();
    }
    
    void MusicButton::addEventListener()
    {
        auto listener = EventListenerTouchOneByOne::create();
        listener->setSwallowTouches(true);
        listener->onTouchBegan = MusicButton::onTouchBegan;
        listener->onTouchEnded = MusicButton::onTouchEnded;
        listener->onTouchMoved = MusicButton::onTouchMoved;
        listener->onTouchCancelled = MusicButton::onTouchCanceled;
        Director::getInstance()->getEventDispatcher()
        ->addEventListenerWithSceneGraphPriority(listener, this->sprite);
    }

    bool MusicButton::onTouchBegan(Touch* touch, Event* event)
    {
        auto target = static_cast<Sprite*>(event->getCurrentTarget());
        Vec2 locationInNode = target->convertToNodeSpace(touch->getLocation());
        Size s = target->getContentSize();
        Rect rect = Rect(0, 0, s.width, s.height);
        if (rect.containsPoint(locationInNode)) {
            log("MusicButton began... x = %f, y = %f", locationInNode.x, locationInNode.y);
            target->setScale(1.2);
            return true;
        }
        return false;
    }
    
    void MusicButton::onTouchEnded(Touch* touch, Event* event)
    {
        auto target = static_cast<Sprite*>(event->getCurrentTarget());
        Vec2 locationInNode = target->convertToNodeSpace(touch->getLocation());
        Size s = target->getContentSize();
        Rect rect = Rect(0, 0, s.width, s.height);
        if (rect.containsPoint(locationInNode)) {
            log("MusicButton ended... x = %f, y = %f", locationInNode.x, locationInNode.y);
            target->setScale(1.0);
        } else {
            target->setScale(1.0);
        }
    }

    void MusicButton::onTouchMoved(Touch* touch, Event* event)
    {
        
    }

    void MusicButton::onTouchCanceled(Touch* touch, Event* event)
    {
        auto target = static_cast<Sprite*>(event->getCurrentTarget());
        target->setScale(1.0);
    }

}
