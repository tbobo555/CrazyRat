#include "BossButton.h"
#include "Controller/GameController.h"

namespace GameSprite
{
    BossButton::BossButton(std::string image) : GameSprite::BaseSprite(image)
    {
        this->addEventListener();
    }
    
    void BossButton::addEventListener()
    {
        auto listener = EventListenerTouchOneByOne::create();
        listener->setSwallowTouches(true);
        listener->onTouchBegan = BossButton::onTouchBegan;
        listener->onTouchEnded = BossButton::onTouchEnded;
        listener->onTouchMoved = BossButton::onTouchMoved;
        listener->onTouchCancelled = BossButton::onTouchCanceled;
        Director::getInstance()->getEventDispatcher()
        ->addEventListenerWithSceneGraphPriority(listener, this);
    }
    
    bool BossButton::onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *event)
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
    
    void BossButton::onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *event)
    {
        auto target = static_cast<Sprite*>(event->getCurrentTarget());
        Vec2 locationInNode = target->convertToNodeSpace(touch->getLocation());
        Size s = target->getContentSize();
        Rect rect = Rect(0, 0, s.width, s.height);
        if (rect.containsPoint(locationInNode)) {
            target->setScale(1.0);
            Controller::GameController::getInstance()->challengeSceneToChallengePlayScene();
        } else {
            target->setScale(1.0);
        }
    }
    
    void BossButton::onTouchMoved(cocos2d::Touch *touch, cocos2d::Event *event)
    {
    }
    
    void BossButton::onTouchCanceled(cocos2d::Touch *touch, cocos2d::Event *event)
    {
    }
    
}
