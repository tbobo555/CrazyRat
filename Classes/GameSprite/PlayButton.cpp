#include "PlayButton.h"
#include "Controller/GameController.h"

namespace GameSprite
{
    PlayButton::PlayButton(std::string image) : GameSprite::BaseSprite(image)
    {
        this->addEventListener();
    }
    
    void PlayButton::addEventListener()
    {
        auto listener = EventListenerTouchOneByOne::create();
        listener->setSwallowTouches(true);
        listener->onTouchBegan = PlayButton::onTouchBegan;
        listener->onTouchEnded = PlayButton::onTouchEnded;
        listener->onTouchMoved = PlayButton::onTouchMoved;
        listener->onTouchCancelled = PlayButton::onTouchCanceled;
        Director::getInstance()->getEventDispatcher()
        ->addEventListenerWithSceneGraphPriority(listener, this);
    }
    
    bool PlayButton::onTouchBegan(Touch* touch, Event* event)
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
    
    void PlayButton::onTouchEnded(Touch* touch, Event* event)
    {
        auto target = static_cast<Sprite*>(event->getCurrentTarget());
        Vec2 locationInNode = target->convertToNodeSpace(touch->getLocation());
        Size s = target->getContentSize();
        Rect rect = Rect(0, 0, s.width, s.height);
        if (rect.containsPoint(locationInNode)) {
            target->setScale(1.0);
            Controller::GameController::getInstance()->startSceneToPlayInfiniteScene();
        } else {
            target->setScale(1.0);
        }
    }
    
    void PlayButton::onTouchMoved(Touch* touch, Event* event)
    {
    }
    
    void PlayButton::onTouchCanceled(Touch* touch, Event* event)
    {
    }

}
