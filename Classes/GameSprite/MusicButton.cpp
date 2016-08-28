#include "MusicButton.h"

namespace GameSprite
{
    MusicButton::MusicButton(std::string image) : GameSprite::BaseSprite(image)
    {
        this->setName("MusicButton");
        this->addEventListener();
        this->isOpen = DB::SwitchSetting::getInstance()->getMusicSwitch();
        if (this->isOpen == false) {
            this->turnOff();
        } else {
            this->turnOn();
        }
    }
    
    void MusicButton::addEventListener()
    {
        auto listener = EventListenerTouchOneByOne::create();
        listener->setSwallowTouches(true);
        listener->onTouchBegan = MusicButton::onTouchBegan;
        listener->onTouchEnded = MusicButton::onTouchEnded;
        listener->onTouchMoved = MusicButton::onTouchMoved;
        listener->onTouchCancelled = MusicButton::onTouchCanceled;
        Director::getInstance()->getEventDispatcher()
        ->addEventListenerWithSceneGraphPriority(listener, this);
    }
    
    void MusicButton::turnOn()
    {
        Manager::MusicManager::getInstance()->turnOnMusic();
        TextureCreator* textureCreator = TextureCreator::getInstance();
        std::string musicOnButtonImage = "image/MusicOnButton.png";
        Texture2D* onTexutre =
        textureCreator->getAutoSizeTexture2d(musicOnButtonImage);
        this->setTexture(onTexutre);
        this->isOpen = true;
        CCLOG("MusicButton On");
    }
    
    void MusicButton::turnOff()
    {
        Manager::MusicManager::getInstance()->turnOffMusic();
        TextureCreator* textureCreator = TextureCreator::getInstance();
        std::string musicOffButtonImage = "image/MusicOffButton.png";
        Texture2D* offTexutre =
        textureCreator->getAutoSizeTexture2d(musicOffButtonImage);
        this->setTexture(offTexutre);
        this->isOpen = false;
        CCLOG("MusicButton Off");
    }

    bool MusicButton::onTouchBegan(Touch* touch, Event* event)
    {
        auto target = static_cast<Sprite*>(event->getCurrentTarget());
        Vec2 locationInNode = target->convertToNodeSpace(touch->getLocation());
        Size s = target->getContentSize();
        Rect rect = Rect(0, 0, s.width, s.height);

        if (rect.containsPoint(locationInNode)) {
            Manager::SoundsManager::getInstance()->playSound("audio/sounds/ButtonClick.caf");
            log("MusicButton began... x = %f, y = %f", locationInNode.x, locationInNode.y);
            target->setScale(0.95);
            return true;
        }
        return false;
    }
    
    void MusicButton::onTouchEnded(Touch* touch, Event* event)
    {
        auto target = static_cast<MusicButton*>(event->getCurrentTarget());
        Vec2 locationInNode = target->convertToNodeSpace(touch->getLocation());
        Size s = target->getContentSize();
        Rect rect = Rect(0, 0, s.width, s.height);
        if (rect.containsPoint(locationInNode)) {
            log("MusicButton ended... x = %f, y = %f", locationInNode.x, locationInNode.y);
            int musicSwitch = target->isOpen;
            if (musicSwitch == false) {
                target->turnOn();
            } else {
                target->turnOff();
            }
            target->setScale(1.0);
        } else {
            target->setScale(1.0);
        }
    }

    void MusicButton::onTouchMoved(Touch* touch, Event* event)
    {
        
    }

    void MusicButton::onTouchCanceled(Touch* touch, Event* event)
    {
        auto target = static_cast<Sprite*>(event->getCurrentTarget());
        target->setScale(1.0);
    }

}
