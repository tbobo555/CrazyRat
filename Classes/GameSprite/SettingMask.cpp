#include "SettingMask.h"

namespace GameSprite
{
    SettingMask::SettingMask(std::string image) : GameSprite::BaseSprite(image)
    {
        this->addEventListener();
    }
    
    void SettingMask::addEventListener()
    {
        auto listener = EventListenerTouchOneByOne::create();
        listener->setSwallowTouches(true);
        listener->onTouchBegan = SettingMask::onTouchBegan;
        listener->onTouchEnded = SettingMask::onTouchEnded;
        listener->onTouchMoved = SettingMask::onTouchMoved;
        listener->onTouchCancelled = SettingMask::onTouchCanceled;
        Director::getInstance()->getEventDispatcher()
        ->addEventListenerWithSceneGraphPriority(listener, this);
    }
    
    bool SettingMask::onTouchBegan(Touch* touch, Event* event)
    {
        auto target = static_cast<Sprite*>(event->getCurrentTarget());
        Vec2 locationInNode = target->convertToNodeSpace(touch->getLocation());
        Size s = target->getContentSize();
        Rect rect = Rect(0, 0, s.width, s.height);
        if (rect.containsPoint(locationInNode)) {
            log("SettingMask began... x = %f, y = %f", locationInNode.x, locationInNode.y);
            return true;
        }
        return false;
    }
    
    void SettingMask::onTouchEnded(Touch* touch, Event* event)
    {
        auto target = static_cast<Sprite*>(event->getCurrentTarget());
        Vec2 locationInNode = target->convertToNodeSpace(touch->getLocation());
        Size s = target->getContentSize();
        Rect rect = Rect(0, 0, s.width, s.height);
        auto settingBackground = Manager::SpriteManager::getInstance()->getByKey("MenuScene_SettingBackground");
        Size settingBackgroundSize = settingBackground->getContentSize();
        Rect settingBackgroundRect = Rect(settingBackground->getPositionX() - settingBackgroundSize.width / 2,
                                          settingBackground->getPositionY() - settingBackgroundSize.height / 2,
                                          settingBackgroundSize.width,
                                          settingBackgroundSize.height);
        auto settingBackButton = Manager::SpriteManager::getInstance()->getByKey("MenuScene_SettingBackButton");
        Size settingBackButtonSize = settingBackButton->getContentSize();
        Rect settingBackButtonRect = Rect(
        (settingBackground->getPositionX() + settingBackgroundSize.width / 2) - settingBackButtonSize.width / 2,
        (settingBackground->getPositionY() + settingBackgroundSize.height / 2) - settingBackButtonSize.height / 2,
        settingBackButtonSize.width, settingBackButtonSize.height);
        if (!settingBackButtonRect.containsPoint(locationInNode) &&
            !settingBackgroundRect.containsPoint(locationInNode) &&
            rect.containsPoint(locationInNode)) {
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
        }
    }
    
    void SettingMask::onTouchMoved(Touch* touch, Event* event)
    {
    }
    
    void SettingMask::onTouchCanceled(Touch* touch, Event* event)
    {
    }

}