#include "DonateBackButton.h"

namespace GameSprite
{
    DonateBackButton::DonateBackButton(std::string image) : GameSprite::BaseSprite(image)
    {
        this->addEventListener();
    }
    
    void DonateBackButton::addEventListener()
    {
        auto listener = EventListenerTouchOneByOne::create();
        listener->setSwallowTouches(true);
        listener->onTouchBegan = DonateBackButton::onTouchBegan;
        listener->onTouchEnded = DonateBackButton::onTouchEnded;
        listener->onTouchMoved = DonateBackButton::onTouchMoved;
        listener->onTouchCancelled = DonateBackButton::onTouchCanceled;
        Director::getInstance()->getEventDispatcher()
        ->addEventListenerWithSceneGraphPriority(listener, this);
    }
    
    bool DonateBackButton::onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *event)
    {
        auto target = static_cast<Sprite*>(event->getCurrentTarget());
        Vec2 locationInNode = target->convertToNodeSpace(touch->getLocation());
        Size s = target->getContentSize();
        Rect rect = Rect(0, 0, s.width, s.height);
        if (rect.containsPoint(locationInNode)) {
            Manager::SoundsManager::getInstance()->playSound("audio/sounds/ButtonClick.caf");
            log("DonateBackButton began... x = %f, y = %f", locationInNode.x, locationInNode.y);
            target->setScale(0.95);
            return true;
        }
        return false;

    }
    
    void DonateBackButton::onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *event)
    {
        auto target = static_cast<Sprite*>(event->getCurrentTarget());
        Vec2 locationInNode = target->convertToNodeSpace(touch->getLocation());
        Size s = target->getContentSize();
        Rect rect = Rect(0, 0, s.width, s.height);
        if (rect.containsPoint(locationInNode)) {
            log("DonateBackButton ended... x = %f, y = %f", locationInNode.x, locationInNode.y);
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
            musicButton->setVisible(true);
            musicButton->setLocalZOrder(101);
            soundsButton->setVisible(true);
            soundsButton->setLocalZOrder(101);
            aboutButton->setVisible(true);
            aboutButton->setLocalZOrder(101);
            donateButton->setVisible(true);
            donateButton->setLocalZOrder(101);
            donateTitle->setVisible(false);
            donateTitle->setLocalZOrder(-99);
            donate2Button->setVisible(false);
            donate2Button->setLocalZOrder(-99);
            donate5Button->setVisible(false);
            donate5Button->setLocalZOrder(-99);
            donateBackButton->setVisible(false);
            donateBackButton->setLocalZOrder(-99);
        } else {
            target->setScale(1.0);
        }
    }
    
    void DonateBackButton::onTouchMoved(cocos2d::Touch *touch, cocos2d::Event *event)
    {
        
    }
    
    void DonateBackButton::onTouchCanceled(cocos2d::Touch *touch, cocos2d::Event *event)
    {
        auto target = static_cast<Sprite*>(event->getCurrentTarget());
        target->setScale(1.0);
    }
}
