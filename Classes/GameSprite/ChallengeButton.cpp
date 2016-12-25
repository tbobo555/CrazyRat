#include "ChallengeButton.h"
#include "Controller/GameController.h"

namespace GameSprite
{
    ChallengeButton::ChallengeButton(std::string image) : GameSprite::BaseSprite(image)
    {
        this->addEventListener();
    }
    
    void ChallengeButton::addEventListener()
    {
        auto listener = EventListenerTouchOneByOne::create();
        listener->setSwallowTouches(true);
        listener->onTouchBegan = ChallengeButton::onTouchBegan;
        listener->onTouchEnded = ChallengeButton::onTouchEnded;
        listener->onTouchMoved = ChallengeButton::onTouchMoved;
        listener->onTouchCancelled = ChallengeButton::onTouchCanceled;
        Director::getInstance()->getEventDispatcher()
        ->addEventListenerWithSceneGraphPriority(listener, this);
    }
    
    bool ChallengeButton::onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *event)
    {
        auto target = static_cast<Sprite*>(event->getCurrentTarget());
        Vec2 locationInNode = target->convertToNodeSpace(touch->getLocation());
        Size s = target->getContentSize();
        Rect rect = Rect(0, 0, s.width, s.height);
        if (rect.containsPoint(locationInNode)) {
            target->setScale(0.95);
            return true;
        }
        return false;
        
    }
    
    void ChallengeButton::onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *event)
    {
        auto target = static_cast<Sprite*>(event->getCurrentTarget());
        Vec2 locationInNode = target->convertToNodeSpace(touch->getLocation());
        Size s = target->getContentSize();
        Rect rect = Rect(0, 0, s.width, s.height);
        if (rect.containsPoint(locationInNode)) {
            target->setScale(1.0);
            Controller::GameController::getInstance()->startSceneToChallengeScene();
        } else {
            target->setScale(1.0);
        }
    }
    
    void ChallengeButton::onTouchMoved(cocos2d::Touch *touch, cocos2d::Event *event)
    {
    }
    
    void ChallengeButton::onTouchCanceled(cocos2d::Touch *touch, cocos2d::Event *event)
    {
    }

}
