#include "SettingButton.h"

namespace GameSprite
{
    const std::string SettingButton::originImage = "image/SettingBtn.png";
    
    SettingButton::SettingButton() : BaseSprite(SettingButton::originImage)
    {
        //Size visibleSize = Director::getInstance()->getVisibleSize();
        Vec2 origin = Director::getInstance()->getVisibleOrigin();

        this->sprite->setPosition(Vec2(
                                       origin.x + this->sprite->getContentSize().width * 0.6,
                                       origin.y + this->sprite->getContentSize().height * 0.6));
        this->addEventListner();
        
    }
    
    void SettingButton::addEventListner()
    {
        auto listener = EventListenerTouchOneByOne::create();
        listener->setSwallowTouches(true);
        listener->onTouchBegan = SettingButton::onTouchBegan;
        listener->onTouchEnded = SettingButton::onTouchEnded;
        listener->onTouchMoved = SettingButton::onTouchMoved;
        listener->onTouchCancelled = SettingButton::onTouchCanceled;
        Director::getInstance()->getEventDispatcher()
        ->addEventListenerWithSceneGraphPriority(listener, this->sprite);
    }
    
    bool SettingButton::onTouchBegan(Touch* touch, Event* event)
    {
        auto target = static_cast<Sprite*>(event->getCurrentTarget());
        
        Vec2 locationInNode = target->convertToNodeSpace(touch->getLocation());
        Size s = target->getContentSize();
        Rect rect = Rect(0, 0, s.width, s.height);
        
        if (rect.containsPoint(locationInNode)) {
            log("SettingButton began... x = %f, y = %f", locationInNode.x, locationInNode.y);
            target->setScale(1.2);
            return true;
        }
        return false;

    }
    
    void SettingButton::onTouchEnded(Touch* touch, Event* event)
    {
        auto target = static_cast<Sprite*>(event->getCurrentTarget());
        target->setScale(1.0);
        Manager::SceneManager* sceneManager = Manager::SceneManager::getInstance();
        Manager::SpriteManager* spriteManager = Manager::SpriteManager::getInstance();
        auto currentScene = sceneManager->getCurrent()->getCCScene();
        auto settingBg = spriteManager->getByKey("SettingBg")->getCCSprite();
        auto settingBackButton = spriteManager->getByKey("SettingBackButton")->getCCSprite();
        auto musicButton = spriteManager->getByKey("MusicButton")->getCCSprite();
        auto soundsButton = spriteManager->getByKey("SoundsButton")->getCCSprite();
        currentScene->addChild(settingBg, 100, 1);
        currentScene->addChild(settingBackButton, 101, 2);
        currentScene->addChild(musicButton, 101, 3);
        currentScene->addChild(soundsButton, 101, 4);
    }
    
    void SettingButton::onTouchMoved(Touch* touch, Event* event)
    {
        
    }
    
    void SettingButton::onTouchCanceled(Touch* touch, Event* event)
    {
        auto target = static_cast<Sprite*>(event->getCurrentTarget());
        target->setScale(1.0);
    }

}
