#include "SettingBackButton.h"

namespace GameSprite
{
    const std::string SettingBackButton::originImage = "image/BackBtn.png";
    
    SettingBackButton::SettingBackButton() : BaseSprite(SettingBackButton::originImage)
    {
        Size visibleSize = Director::getInstance()->getVisibleSize();
        Vec2 origin = Director::getInstance()->getVisibleOrigin();
        float x = origin.x + this->sprite->getContentSize().width * 0.6;
        float y = origin.y + visibleSize.height - this->sprite->getContentSize().height * 0.6;
        this->sprite->setPosition(Vec2(x, y));
        this->addEventListner();
    }
    
    void SettingBackButton::addEventListner()
    {
        auto listener = EventListenerTouchOneByOne::create();
        listener->setSwallowTouches(true);
        listener->onTouchBegan = SettingBackButton::onTouchBegan;
        listener->onTouchEnded = SettingBackButton::onTouchEnded;
        listener->onTouchMoved = SettingBackButton::onTouchMoved;
        listener->onTouchCancelled = SettingBackButton::onTouchCanceled;
        Director::getInstance()->getEventDispatcher()
        ->addEventListenerWithSceneGraphPriority(listener, this->sprite);
    }
    
    bool SettingBackButton::onTouchBegan(Touch* touch, Event* event)
    {
        auto target = static_cast<Sprite*>(event->getCurrentTarget());
        Vec2 locationInNode = target->convertToNodeSpace(touch->getLocation());
        Size s = target->getContentSize();
        Rect rect = Rect(0, 0, s.width, s.height);
        if (rect.containsPoint(locationInNode)) {
            log("SettingBackButton began... x = %f, y = %f", locationInNode.x, locationInNode.y);
            target->setScale(1.2);
            return true;
        }
        return false;
    }
    
    void SettingBackButton::onTouchEnded(Touch* touch, Event* event)
    {
        auto target = static_cast<Sprite*>(event->getCurrentTarget());
        target->setScale(1.0);
        auto sceneManager = Manager::SceneManager::getInstance();
        auto spriteManager = Manager::SpriteManager::getInstance();
        auto scene = sceneManager->getCurrent()->getCCScene();
        auto settingBg = spriteManager->getByKey("SettingBg")->getCCSprite();
        auto settingBackButton = spriteManager->getByKey("SettingBackButton")->getCCSprite();
        auto musicButton = spriteManager->getByKey("MusicButton")->getCCSprite();
        auto soundsButton = spriteManager->getByKey("SoundsButton")->getCCSprite();
        scene->removeChild(soundsButton);
        scene->removeChild(musicButton);
        scene->removeChild(settingBackButton);
        scene->removeChild(settingBg);
    }
    
    void SettingBackButton::onTouchMoved(Touch* touch, Event* event)
    {
        
    }
    
    void SettingBackButton::onTouchCanceled(Touch* touch, Event* event)
    {
        auto target = static_cast<Sprite*>(event->getCurrentTarget());
        target->setScale(1.0);
    }
}
