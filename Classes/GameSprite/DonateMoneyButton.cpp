#include "DonateMoneyButton.h"

namespace GameSprite
{
    DonateMoneyButton::DonateMoneyButton(std::string image, int money) : GameSprite::BaseSprite(image)
    {
        this->addEventListener();
        this->money = money;
    }
    
    void DonateMoneyButton::addEventListener()
    {
        auto listener = EventListenerTouchOneByOne::create();
        listener->setSwallowTouches(true);
        listener->onTouchBegan = DonateMoneyButton::onTouchBegan;
        listener->onTouchEnded = DonateMoneyButton::onTouchEnded;
        listener->onTouchMoved = DonateMoneyButton::onTouchMoved;
        listener->onTouchCancelled = DonateMoneyButton::onTouchCanceled;
        Director::getInstance()->getEventDispatcher()
        ->addEventListenerWithSceneGraphPriority(listener, this);
    }
    
    bool DonateMoneyButton::onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *event)
    {
        auto target = static_cast<Sprite*>(event->getCurrentTarget());
        Vec2 locationInNode = target->convertToNodeSpace(touch->getLocation());
        Size s = target->getContentSize();
        Rect rect = Rect(0, 0, s.width, s.height);
        if (rect.containsPoint(locationInNode)) {
            Manager::SoundsManager::getInstance()->playSound("audio/sounds/ButtonClick.caf");
            log("DonateMoneyButton began... x = %f, y = %f", locationInNode.x, locationInNode.y);
            target->setScale(0.95);
            return true;
        }
        return false;
    }
    
    void DonateMoneyButton::onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *event)
    {
        auto target = static_cast<Sprite*>(event->getCurrentTarget());
        Vec2 locationInNode = target->convertToNodeSpace(touch->getLocation());
        Size s = target->getContentSize();
        Rect rect = Rect(0, 0, s.width, s.height);
        if (rect.containsPoint(locationInNode)) {
            log("DonateButton ended... x = %f, y = %f", locationInNode.x, locationInNode.y);
            target->setScale(1.0);
            //sdkbox::IAP::purchase("donate2");
        } else {
            target->setScale(1.0);
        }
    }
    
    void DonateMoneyButton::onTouchMoved(cocos2d::Touch *touch, cocos2d::Event *event)
    {
        
    }
    
    void DonateMoneyButton::onTouchCanceled(cocos2d::Touch *touch, cocos2d::Event *event)
    {
        auto target = static_cast<Sprite*>(event->getCurrentTarget());
        target->setScale(1.0);
    }
}
