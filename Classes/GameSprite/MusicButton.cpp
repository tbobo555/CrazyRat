#include "MusicButton.h"

namespace GameSprite {
    MusicButton::MusicButton() : BaseSprite::BaseSprite()
    {
        Size visibleSize = Director::getInstance()->getVisibleSize();
        Vec2 origin = Director::getInstance()->getVisibleOrigin();
        this->sprite->setTexture("image/MusicBtn.png");
        float x = origin.x + visibleSize.width / 2 - this->sprite->getContentSize().width * 0.6;
        float y = origin.y + visibleSize.height / 2;
        this->sprite->setPosition(Vec2(x, y));
        this->addEventListner();
    }
    
    void MusicButton::addEventListner()
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
        if (rect.containsPoint(locationInNode))
        {
            log("MusicButton began... x = %f, y = %f", locationInNode.x, locationInNode.y);
            target->setScale(1.2);
            return true;
        }
        return false;
    }
    
    void MusicButton::onTouchEnded(Touch* touch, Event* event)
    {
        auto target = static_cast<Sprite*>(event->getCurrentTarget());
        target->setScale(1.0);
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
