#include "SettingBackButton.h"

namespace GameSprite
{
    SettingBackButton::SettingBackButton(std::string image) : GameSprite::BaseSprite(image)
    {
        this->addEventListener();
    }
    
    void SettingBackButton::addEventListener()
    {
        auto listener = EventListenerTouchOneByOne::create();
        listener->setSwallowTouches(true);
        listener->onTouchBegan = SettingBackButton::onTouchBegan;
        listener->onTouchEnded = SettingBackButton::onTouchEnded;
        listener->onTouchMoved = SettingBackButton::onTouchMoved;
        listener->onTouchCancelled = SettingBackButton::onTouchCanceled;
        Director::getInstance()->getEventDispatcher()
        ->addEventListenerWithSceneGraphPriority(listener, this);
    }
    
    bool SettingBackButton::onTouchBegan(Touch* touch, Event* event)
    {
        auto target = static_cast<Sprite*>(event->getCurrentTarget());
        Vec2 locationInNode = target->convertToNodeSpace(touch->getLocation());
        Size s = target->getContentSize();
        Rect rect = Rect(0, 0, s.width, s.height);
        if (rect.containsPoint(locationInNode)) {
            Manager::SoundsManager::getInstance()->playSound("audio/sounds/ButtonClick.caf");
            log("SettingBackButton began... x = %f, y = %f", locationInNode.x, locationInNode.y);
            target->setScale(0.95);
            return true;
        }
        return false;
    }
    
    void SettingBackButton::onTouchEnded(Touch* touch, Event* event)
    {
        auto target = static_cast<Sprite*>(event->getCurrentTarget());
        Vec2 locationInNode = target->convertToNodeSpace(touch->getLocation());
        Size s = target->getContentSize();
        Rect rect = Rect(0, 0, s.width, s.height);
        if (rect.containsPoint(locationInNode)) {
            target->setScale(1.0);
            auto sceneManager = Manager::SceneManager::getInstance();
            auto spriteManager = Manager::SpriteManager::getInstance();
            auto scene = sceneManager->getCurrent();
            auto settingBackground = spriteManager->getByKey("MenuScene_SettingBackground");
            auto settingBackButton = spriteManager->getByKey("MenuScene_SettingBackButton");
            auto musicButton = spriteManager->getByKey("MenuScene_MusicButton");
            auto soundsButton = spriteManager->getByKey("MenuScene_SoundsButton");
            auto aboutButton = spriteManager->getByKey("MenuScene_AboutButton");
            auto donateButton = spriteManager->getByKey("MenuScene_DonateButton");
            auto settingMask = spriteManager->getByKey("MenuScene_SettingMask");
            auto donateTitle = spriteManager->getByKey("MenuScene_DonateTitle");
            auto donate2Button = spriteManager->getByKey("MenuScene_Donate2Button");
            auto donate5Button = spriteManager->getByKey("MenuScene_Donate5Button");
            auto donateBackButton = spriteManager->getByKey("MenuScene_DonateBackButton");
            settingBackground->GameScene::BaseScene::removeChild(soundsButton);
            settingBackground->GameScene::BaseScene::removeChild(musicButton);
            settingBackground->GameScene::BaseScene::removeChild(settingBackButton);
            settingBackground->GameScene::BaseScene::removeChild(aboutButton);
            settingBackground->GameScene::BaseScene::removeChild(donateButton);
            settingBackground->GameScene::BaseScene::removeChild(donateTitle);
            settingBackground->GameScene::BaseScene::removeChild(donate2Button);
            settingBackground->GameScene::BaseScene::removeChild(donate5Button);
            settingBackground->GameScene::BaseScene::removeChild(donateBackButton);
            scene->removeChild(settingBackground);
            scene->removeChild(settingMask);
        } else {
            target->setScale(1.0);
        }
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
