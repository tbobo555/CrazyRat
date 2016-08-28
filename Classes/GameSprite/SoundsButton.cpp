#include "SoundsButton.h"

namespace GameSprite
{
    SoundsButton::SoundsButton(std::string image) : GameSprite::BaseSprite(image)
    {
        this->setName("SoundsButton");
        this->addEventListener();
        this->isOpen = DB::SwitchSetting::getInstance()->getSoundsSwitch();
        if (this->isOpen == false) {
            this->turnOff();
        } else {
            this->turnOn();
        }
    }
    
    void SoundsButton::addEventListener()
    {
        auto listener = EventListenerTouchOneByOne::create();
        listener->setSwallowTouches(true);
        listener->onTouchBegan = SoundsButton::onTouchBegan;
        listener->onTouchEnded = SoundsButton::onTouchEnded;
        listener->onTouchMoved = SoundsButton::onTouchMoved;
        listener->onTouchCancelled = SoundsButton::onTouchCanceled;
        Director::getInstance()->getEventDispatcher()
        ->addEventListenerWithSceneGraphPriority(listener, this);
    }
    
    void SoundsButton::turnOn()
    {
        DB::SwitchSetting::getInstance()->turnOnSounds();
        TextureCreator* textureCreator = TextureCreator::getInstance();
        std::string soundsOnButtonImage = "image/SoundsOnButton.png";
        Texture2D* onTexutre =
        textureCreator->getAutoSizeTexture2d(soundsOnButtonImage);
        this->setTexture(onTexutre);
        this->isOpen = true;
        CCLOG("SoundsButton On");
    }
    
    void SoundsButton::turnOff()
    {
        DB::SwitchSetting::getInstance()->turnOffSounds();
        TextureCreator* textureCreator = TextureCreator::getInstance();
        std::string soundsOffButtonImage = "image/SoundsOffButton.png";
        Texture2D* offTexutre =
        textureCreator->getAutoSizeTexture2d(soundsOffButtonImage);
        this->setTexture(offTexutre);
        this->isOpen = false;
        CCLOG("SoundsButton Off");
    }
    
    bool SoundsButton::onTouchBegan(Touch* touch, Event* event)
    {
        auto target = static_cast<Sprite*>(event->getCurrentTarget());
        Vec2 locationInNode = target->convertToNodeSpace(touch->getLocation());
        Size s = target->getContentSize();
        Rect rect = Rect(0, 0, s.width, s.height);
        if (rect.containsPoint(locationInNode)) {
            log("SoundsButton began... x = %f, y = %f", locationInNode.x, locationInNode.y);
            target->setScale(0.95);
            return true;
        }
        return false;
    }
    
    void SoundsButton::onTouchEnded(Touch* touch, Event* event)
    {
        auto target = static_cast<SoundsButton*>(event->getCurrentTarget());
        Vec2 locationInNode = target->convertToNodeSpace(touch->getLocation());
        Size s = target->getContentSize();
        Rect rect = Rect(0, 0, s.width, s.height);
        if (rect.containsPoint(locationInNode)) {
            log("SoundsButton ended... x = %f, y = %f", locationInNode.x, locationInNode.y);
            target->setScale(1.0);
            int soundsSwitch = target->isOpen;
            if (soundsSwitch == false) {
                target->turnOn();
                Manager::SoundsManager::getInstance()->playSound("audio/sounds/ButtonClick.caf");
            } else {
                target->turnOff();
            }
        } else {
            target->setScale(1.0);
        }
    }
    
    void SoundsButton::onTouchMoved(Touch* touch, Event* event)
    {
        
    }
    
    void SoundsButton::onTouchCanceled(Touch* touch, Event* event)
    {
        auto target = static_cast<Sprite*>(event->getCurrentTarget());
        target->setScale(1.0);
    }
    
}
