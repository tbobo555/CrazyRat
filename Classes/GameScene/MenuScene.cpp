#include "MenuScene.h"

namespace GameScene
{
    MenuScene::MenuScene() : GameScene::BaseScene()
    {
        this->name = "MenuScene";
    }
    
    void MenuScene::initScene()
    {
        auto spriteManager = Manager::SpriteManager::getInstance();
        this->settingButton = new SettingButton("image/SettingButton.png");
        this->settingButton->setPosition(this->getSettingButtonPosition());
        spriteManager->setWithKey("MenuScene_SettingButton", this->settingButton);
        
        this->settingBackground = new Background("image/SettingBackground.png");
        this->settingBackground->setPosition(this->getSettingBackgroundPosition());
        spriteManager->setWithKey("MenuScene_SettingBackground", this->settingBackground);
        
        this->settingBackButton = new SettingBackButton("image/CloseSettingButton.png");
        this->settingBackButton->setPosition(this->getSettingBackButtonPosition());
        spriteManager->setWithKey("MenuScene_SettingBackButton", this->settingBackButton);
        
        this->musicButton = new MusicButton("image/MusicOnButton.png");
        this->musicButton->setPosition(this->getMusicButtonPosition());
        spriteManager->setWithKey("MenuScene_MusicButton", this->musicButton);
        
        this->soundsButton = new SoundsButton("image/SoundsOnButton.png");
        this->soundsButton->setPosition(this->getSoundsButtonPosition());
        spriteManager->setWithKey("MenuScene_SoundsButton", this->soundsButton);
        
        this->settingMask = new SettingMask("image/Mask.png");
        this->settingMask->setPosition(this->center);
        spriteManager->setWithKey("MenuScene_SettingMask", this->settingMask);
        
        this->aboutButton = new AboutButton("image/AboutButton.png");
        this->aboutButton->setPosition(this->getAboutButtonPosition());
        spriteManager->setWithKey("MenuScene_AboutButton", this->aboutButton);
        
        this->donateButton = new DonateButton("image/DonateButton.png");
        this->donateButton->setPosition(this->getDonateButtonPosition());
        spriteManager->setWithKey("MenuScene_DonateButton", this->donateButton);
        
        this->donateTitle = new GameSprite::Image("image/DonateTitle.png");
        this->donateTitle->setPosition(this->getDonateTitlePosition());
        spriteManager->setWithKey("MenuScene_DonateTitle", this->donateTitle);

        this->donate2MoneyButton = new DonateMoneyButton("image/Donate2Button.png", 2);
        this->donate2MoneyButton->setPosition(this->getDonate2ButtonPoition());
        spriteManager->setWithKey("MenuScene_Donate2Button", this->donate2MoneyButton);
        
        this->donate5MoneyButton = new DonateMoneyButton("image/Donate5Button.png", 5);
        this->donate5MoneyButton->setPosition(this->getDonate5ButtonPoition());
        spriteManager->setWithKey("MenuScene_Donate5Button", this->donate5MoneyButton);
        
        this->donateBackButton = new DonateBackButton("image/DonateBackButton.png");
        this->donateBackButton->setPosition(this->getDonateBackButtonPosition());
        spriteManager->setWithKey("MenuScene_DonateBackButton", this->donateBackButton);
        
        this->creditMask = new CreditMask("image/Credits.png");
        this->creditMask->setPosition(this->center);
        spriteManager->setWithKey("MenuScene_CreditMask", this->creditMask);
    }
    
    void MenuScene::releaseScene()
    {
        auto spriteManager = Manager::SpriteManager::getInstance();
        spriteManager->releaseByKey("MenuScene_SettingButton");
        spriteManager->releaseByKey("MenuScene_SettingBackground");
        spriteManager->releaseByKey("MenuScene_SettingBackButton");
        spriteManager->releaseByKey("MenuScene_MusicButton");
        spriteManager->releaseByKey("MenuScene_SoundsButton");
        spriteManager->releaseByKey("MenuScene_SettingMask");
        spriteManager->releaseByKey("MenuScene_AboutButton");
        spriteManager->releaseByKey("MenuScene_DonateButton");
        spriteManager->releaseByKey("MenuScene_DonateTitle");
        spriteManager->releaseByKey("MenuScene_Donate2Button");
        spriteManager->releaseByKey("MenuScene_Donate5Button");
        spriteManager->releaseByKey("MenuScene_DonateBackButton");
        spriteManager->releaseByKey("MenuScene_CreditMask");
    }
    
    void MenuScene::openMenu()
    {
        Manager::SceneManager* sceneManager = Manager::SceneManager::getInstance();
        auto currentScene = sceneManager->getCurrent();
        this->musicButton->setVisible(true);
        this->soundsButton->setVisible(true);
        this->aboutButton->setVisible(true);
        this->donateButton->setVisible(true);
        this->settingBackground->addChild(this->settingBackButton, 101, 2);
        this->settingBackground->addChild(this->musicButton, 101, 3);
        this->settingBackground->addChild(this->soundsButton, 101, 4);
        this->settingBackground->addChild(this->aboutButton, 101, 5);
        this->settingBackground->addChild(this->donateButton, 101, 6);
        this->settingBackground->addChild(this->donateTitle, 101, 7);
        this->settingBackground->addChild(this->donate2MoneyButton, 101, 8);
        this->settingBackground->addChild(this->donate5MoneyButton, 101, 9);
        this->settingBackground->addChild(this->donateBackButton, 101, 10);
        this->donateTitle->setVisible(false);
        this->donateTitle->setLocalZOrder(-99);
        this->donate2MoneyButton->setVisible(false);
        this->donate2MoneyButton->setLocalZOrder(-99);
        this->donate5MoneyButton->setVisible(false);
        this->donate5MoneyButton->setLocalZOrder(-99);
        this->donateBackButton->setVisible(false);
        this->donateBackButton->setLocalZOrder(-99);
        this->creditMask->setVisible(false);
        currentScene->addChild(this->settingBackground, 100, 1);
        currentScene->addChild(this->settingMask, 99);
        currentScene->addChild(this->creditMask, -99);
    }
    
    void MenuScene::closeMenu()
    {
        auto sceneManager = Manager::SceneManager::getInstance();
        auto scene = sceneManager->getCurrent();
        this->settingBackground->BaseScene::removeChild(this->soundsButton);
        this->settingBackground->BaseScene::removeChild(this->musicButton);
        this->settingBackground->BaseScene::removeChild(this->settingBackButton);
        this->settingBackground->BaseScene::removeChild(this->aboutButton);
        this->settingBackground->BaseScene::removeChild(this->donateButton);
        this->settingBackground->BaseScene::removeChild(this->donateTitle);
        this->settingBackground->BaseScene::removeChild(this->donate2MoneyButton);
        this->settingBackground->BaseScene::removeChild(this->donate5MoneyButton);
        this->settingBackground->BaseScene::removeChild(this->donateBackButton);
        scene->removeChild(this->settingBackground);
        scene->removeChild(this->settingMask);
        scene->removeChild(this->creditMask);
    }
    
    Vec2 MenuScene::getSettingBackgroundPosition()
    {
        return Vec2(this->center.x, this->center.y + this->visibleSize.height / 20);
    }
    
    Vec2 MenuScene::getMusicButtonPosition()
    {
        float width = this->settingBackground->getContentSize().width;
        float height = this->settingBackground->getContentSize().height;
        Vec2 center = Vec2(width / 2, height / 2);
        return Vec2(center.x - width / 4, center.y + width / 4);
    }
    
    Vec2 MenuScene::getSoundsButtonPosition()
    {
        float width = this->settingBackground->getContentSize().width;
        float height = this->settingBackground->getContentSize().height;
        Vec2 center = Vec2(width / 2, height / 2);
        return Vec2(center.x - width / 4, center.y - width / 4);
    }
    
    Vec2 MenuScene::getAboutButtonPosition()
    {
        float width = this->settingBackground->getContentSize().width;
        float height = this->settingBackground->getContentSize().height;
        Vec2 center = Vec2(width / 2, height / 2);
        return Vec2(center.x + width / 4, center.y + width / 4);
    }

    Vec2 MenuScene::getDonateButtonPosition()
    {
        float width = this->settingBackground->getContentSize().width;
        float height = this->settingBackground->getContentSize().height;
        Vec2 center = Vec2(width / 2, height / 2);
        return Vec2(center.x + width / 4, center.y - width / 4);
    }

    Vec2 MenuScene::getSettingBackButtonPosition()
    {
        return Vec2(this->settingBackground->getContentSize().width, this->settingBackground->getContentSize().height);
    }
    
    Vec2 MenuScene::getSettingButtonPosition()
    {
        return Vec2(this->visibleOrigin.x + this->visibleSize.height / 12, this->visibleOrigin.y + this->visibleSize.height / 12);
    }
    
    Vec2 MenuScene::getDonateTitlePosition()
    {
        float width = this->settingBackground->getContentSize().width;
        float height = this->settingBackground->getContentSize().height;
        Vec2 center = Vec2(width / 2, height / 2);
        return Vec2(center.x, center.y + width * 8.5 / 25);
    }
    
    Vec2 MenuScene::getDonate2ButtonPoition()
    {
        float width = this->settingBackground->getContentSize().width;
        float height = this->settingBackground->getContentSize().height;
        Vec2 center = Vec2(width / 2, height / 2);
        return Vec2(center.x, center.y + width * 1 / 8 - 10);
    }
    
    Vec2 MenuScene::getDonate5ButtonPoition()
    {
        float width = this->settingBackground->getContentSize().width;
        float height = this->settingBackground->getContentSize().height;
        Vec2 center = Vec2(width / 2, height / 2);
        return Vec2(center.x, center.y - width * 1 / 8 - 10);
    }
    
    Vec2 MenuScene::getDonateBackButtonPosition()
    {
        float width = this->settingBackground->getContentSize().width;
        float height = this->settingBackground->getContentSize().height;
        Vec2 center = Vec2(width / 2, height / 2);
        return Vec2(center.x, center.y - width * 9 / 25 );
    }
}
