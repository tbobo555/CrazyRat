#include "EndlessButton.h"
#include "Controller/GameController.h"

namespace GameSprite
{
    EndlessButton::EndlessButton(std::string image) : GameSprite::BaseSprite(image)
    {
        this->addEventListener();
    }
    
    void EndlessButton::addEventListener()
    {
        auto listener = EventListenerTouchOneByOne::create();
        listener->setSwallowTouches(true);
        listener->onTouchBegan = EndlessButton::onTouchBegan;
        listener->onTouchEnded = EndlessButton::onTouchEnded;
        listener->onTouchMoved = EndlessButton::onTouchMoved;
        listener->onTouchCancelled = EndlessButton::onTouchCanceled;
        Director::getInstance()->getEventDispatcher()
        ->addEventListenerWithSceneGraphPriority(listener, this);
    }
    
    bool EndlessButton::onTouchBegan(Touch* touch, Event* event)
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
    
    void EndlessButton::onTouchEnded(Touch* touch, Event* event)
    {
        auto target = static_cast<Sprite*>(event->getCurrentTarget());
        Vec2 locationInNode = target->convertToNodeSpace(touch->getLocation());
        Size s = target->getContentSize();
        Rect rect = Rect(0, 0, s.width, s.height);
        if (rect.containsPoint(locationInNode)) {
            target->setScale(1.0);
            Controller::GameController::getInstance()->challengeSceneToPlayInfiniteScene();
        } else {
            target->setScale(1.0);
        }
    }
    
    void EndlessButton::onTouchMoved(Touch* touch, Event* event)
    {
    }
    
    void EndlessButton::onTouchCanceled(Touch* touch, Event* event)
    {
    }
    
}
