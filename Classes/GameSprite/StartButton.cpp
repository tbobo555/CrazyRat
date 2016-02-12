#include "StartButton.h"

namespace GameSprite
{
    StartButton::StartButton() : GameSprite::BaseSprite()
    {
        Size visibleSize = Director::getInstance()->getVisibleSize();
        Vec2 origin = Director::getInstance()->getVisibleOrigin();
        this->sprite->setTexture("image/StartBtn.png");
        this->sprite->setPosition(
                                  Vec2(origin.x + visibleSize.width / 2.0,
                                       origin.y + visibleSize.height / 4.0
                                       )
                                  );
        this->addEventListner();
    }
    
    void StartButton::addEventListner()
    {
        auto listener = EventListenerTouchOneByOne::create();
        listener->setSwallowTouches(true);
        listener->onTouchBegan = StartButton::onTouchBegan;
        listener->onTouchEnded = StartButton::onTouchEnded;
        listener->onTouchMoved = StartButton::onTouchMoved;
        listener->onTouchCancelled = StartButton::onTouchCanceled;
        Director::getInstance()->getEventDispatcher()
        ->addEventListenerWithSceneGraphPriority(listener, this->sprite);
    }
    
    bool StartButton::onTouchBegan(Touch* touch, Event* event)
    {
        auto target = static_cast<Sprite*>(event->getCurrentTarget());
        Vec2 locationInNode = target->convertToNodeSpace(touch->getLocation());
        Size s = target->getContentSize();
        Rect rect = Rect(0, 0, s.width, s.height);
        
        if (rect.containsPoint(locationInNode))
        {
            log("StartButton began... x = %f, y = %f", locationInNode.x, locationInNode.y);
            target->setScale(1.2);
            return true;
        }
        return false;
    }
    
    void StartButton::onTouchEnded(Touch* touch, Event* event)
    {
        auto target = static_cast<Sprite*>(event->getCurrentTarget());
        target->setScale(1.0);
    }
    
    void StartButton::onTouchMoved(Touch* touch, Event* event)
    {
    }

    void StartButton::onTouchCanceled(Touch* touch, Event* event)
    {
        auto target = static_cast<Sprite*>(event->getCurrentTarget());
        target->setScale(1.0);
    }
    
}
