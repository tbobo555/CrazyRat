#include "DonateButton.h"

namespace GameSprite
{
    DonateButton::DonateButton(std::string image) : GameSprite::BaseSprite(image)
    {
        this->addEventListener();
    }
    
    void DonateButton::addEventListener()
    {
        auto listener = EventListenerTouchOneByOne::create();
        listener->setSwallowTouches(true);
        listener->onTouchBegan = DonateButton::onTouchBegan;
        listener->onTouchEnded = DonateButton::onTouchEnded;
        listener->onTouchMoved = DonateButton::onTouchMoved;
        listener->onTouchCancelled = DonateButton::onTouchCanceled;
        Director::getInstance()->getEventDispatcher()
        ->addEventListenerWithSceneGraphPriority(listener, this);
    }
    
    bool DonateButton::onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *event)
    {
        auto target = static_cast<Sprite*>(event->getCurrentTarget());
        Vec2 locationInNode = target->convertToNodeSpace(touch->getLocation());
        Size s = target->getContentSize();
        Rect rect = Rect(0, 0, s.width, s.height);
        if (rect.containsPoint(locationInNode)) {
            Manager::SoundsManager::getInstance()->playSound("audio/sounds/ButtonClick.caf");
            log("DonateButton began... x = %f, y = %f", locationInNode.x, locationInNode.y);
            target->setScale(0.95);
            return true;
        }
        return false;
    }
    
    void DonateButton::onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *event)
    {
        auto target = static_cast<Sprite*>(event->getCurrentTarget());
        Vec2 locationInNode = target->convertToNodeSpace(touch->getLocation());
        Size s = target->getContentSize();
        Rect rect = Rect(0, 0, s.width, s.height);
        if (rect.containsPoint(locationInNode)) {
            log("DonateButton ended... x = %f, y = %f", locationInNode.x, locationInNode.y);
            target->setScale(1.0);
            Manager::SpriteManager* spriteManager = Manager::SpriteManager::getInstance();
            auto musicButton = spriteManager->getByKey("MenuScene_MusicButton");
            auto soundsButton = spriteManager->getByKey("MenuScene_SoundsButton");
            auto aboutButton = spriteManager->getByKey("MenuScene_AboutButton");
            auto donateButton = spriteManager->getByKey("MenuScene_DonateButton");
            auto donateTitle = spriteManager->getByKey("MenuScene_DonateTitle");
            auto donate2Button = spriteManager->getByKey("MenuScene_Donate2Button");
            auto donate5Button = spriteManager->getByKey("MenuScene_Donate5Button");
            auto donateBackButton = spriteManager->getByKey("MenuScene_DonateBackButton");
            musicButton->setVisible(false);
            musicButton->setLocalZOrder(-99);
            soundsButton->setVisible(false);
            soundsButton->setLocalZOrder(-99);
            aboutButton->setVisible(false);
            aboutButton->setLocalZOrder(-99);
            donateButton->setVisible(false);
            donateButton->setLocalZOrder(-99);
            donateTitle->setVisible(true);
            donateTitle->setLocalZOrder(101);
            donate2Button->setVisible(true);
            donate2Button->setLocalZOrder(101);
            donate5Button->setVisible(true);
            donate5Button->setLocalZOrder(101);
            donateBackButton->setVisible(true);
            donateBackButton->setLocalZOrder(101);
            auto donate2 = static_cast<DonateMoneyButton*>(Manager::SpriteManager::getInstance()->getByKey("MenuScene_Donate2Button"));
            auto donate5 = static_cast<DonateMoneyButton*>(Manager::SpriteManager::getInstance()->getByKey("MenuScene_Donate5Button"));
            donate2->setMoneyTextWithLocalCurrency();
            donate5->setMoneyTextWithLocalCurrency();
        } else {
            target->setScale(1.0);
        }
    }
    
    void DonateButton::onTouchMoved(cocos2d::Touch *touch, cocos2d::Event *event)
    {
        
    }
    
    void DonateButton::onTouchCanceled(cocos2d::Touch *touch, cocos2d::Event *event)
    {
        auto target = static_cast<Sprite*>(event->getCurrentTarget());
        target->setScale(1.0);
    }
}
