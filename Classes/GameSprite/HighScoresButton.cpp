#include "HighScoresButton.h"


namespace GameSprite
{
    HighScoresButton::HighScoresButton(std::string image) : GameSprite::BaseSprite(image)
    {
        this->addEventListener();
    }
    
    void HighScoresButton::addEventListener()
    {
        auto listener = EventListenerTouchOneByOne::create();
        listener->setSwallowTouches(true);
        listener->onTouchBegan = HighScoresButton::onTouchBegan;
        listener->onTouchEnded = HighScoresButton::onTouchEnded;
        listener->onTouchMoved = HighScoresButton::onTouchMoved;
        listener->onTouchCancelled = HighScoresButton::onTouchCanceled;
        Director::getInstance()->getEventDispatcher()
        ->addEventListenerWithSceneGraphPriority(listener, this);
    }
    
    bool HighScoresButton::onTouchBegan(Touch* touch, Event* event)
    {
        auto target = static_cast<Sprite*>(event->getCurrentTarget());
        Vec2 locationInNode = target->convertToNodeSpace(touch->getLocation());
        Size s = target->getContentSize();
        Rect rect = Rect(0, 0, s.width, s.height);
        
        if (rect.containsPoint(locationInNode)) {
            Manager::SoundsManager::getInstance()->playSound("audio/sounds/ButtonClick.caf");
            target->setScale(0.95);
            return true;
        }
        return false;
    }
    
    void HighScoresButton::onTouchEnded(Touch* touch, Event* event)
    {
        auto target = static_cast<Sprite*>(event->getCurrentTarget());
        Vec2 locationInNode = target->convertToNodeSpace(touch->getLocation());
        Size s = target->getContentSize();
        Rect rect = Rect(0, 0, s.width, s.height);
        if (rect.containsPoint(locationInNode)) {
            target->setScale(1.0);
        } else {
            target->setScale(1.0);
        }
    }
    
    void HighScoresButton::onTouchMoved(Touch* touch, Event* event)
    {
    }
    
    void HighScoresButton::onTouchCanceled(Touch* touch, Event* event)
    {
    }
    
}
