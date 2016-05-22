#include "PauseScene.h"


namespace GameScene
{
    PauseScene::PauseScene() : GameScene::BaseScene()
    {
        this->name = "PauseScene";
    }
    
    void PauseScene::initScene()
    {
        auto spriteManager = Manager::SpriteManager::getInstance();
        std::string pauseButtonImage = "image/PauseButton.png";
        std::string pauseBackgroundImage = "image/SettingBackground.png";
        std::string musicButtonImage = "image/MusicOnButton.png";
        std::string soundsButtonImage = "image/SoundsOnButton.png";
        std::string backHomeButtonImage = "image/BackHomeButton.png";
        std::string retryButtonImage = "image/RetryButton.png";
        std::string pauseBackButtonImage = "image/CloseSettingButton.png";
        
        this->pauseBackground = new Background(pauseBackgroundImage);
        this->pauseBackground->setPosition(this->getPauseBackgroundPosition());
        this->pauseBackground->setVisible(false);
        spriteManager->setWithKey("PauseScene_PauseBackground", this->pauseBackground);
        
        this->musicButton = new MusicButton(musicButtonImage);
        this->musicButton->setPosition(this->getMusicButtonPosition());
        this->musicButton->setVisible(false);
        spriteManager->setWithKey("PauseScene_MusicButton", this->musicButton);
        
        this->soundsButton = new SoundsButton(soundsButtonImage);
        this->soundsButton->setPosition(this->getSoundsButtonPosition());
        this->soundsButton->setVisible(false);
        spriteManager->setWithKey("PauseScene_SoundsButton", this->soundsButton);
        
        this->backHomeButton = new BackHomeButton(backHomeButtonImage);
        this->backHomeButton->setPosition(this->getBackHomeButtonPosition());
        this->backHomeButton->setVisible(false);
        spriteManager->setWithKey("PauseScene_BackHomeButton", this->backHomeButton);
        
        this->retryButton = new RetryButton(retryButtonImage);
        this->retryButton->setPosition(this->getRetryButtonPosition());
        this->retryButton->setVisible(false);
        spriteManager->setWithKey("PauseScene_RetryButton", this->retryButton);
        
        this->pauseBackButton = new PauseBackButton(pauseBackButtonImage);
        this->pauseBackButton->setPosition(this->getPauseBackButtonPosition());
        this->pauseBackButton->setVisible(false);
        spriteManager->setWithKey("PauseScene_PauseBackButton", this->pauseBackButton);
        
        this->pauseButton = new GameSprite::PauseButton(pauseButtonImage);
        this->pauseButton->setPosition(this->getPauseButtonPosition());
        spriteManager->setWithKey("PauseScene_PauseButton", this->pauseButton);
    }
    
    void PauseScene::releaseScene()
    {
        auto spriteManager = Manager::SpriteManager::getInstance();
        spriteManager->releaseByKey("PauseScene_PauseBackground");
        spriteManager->releaseByKey("PauseScene_MusicButton");
        spriteManager->releaseByKey("PauseScene_SoundsButton");
        spriteManager->releaseByKey("PauseScene_BackHomeButton");
        spriteManager->releaseByKey("PauseScene_RetryButton");
        spriteManager->releaseByKey("PauseScene_PauseBackButton");
        spriteManager->releaseByKey("PauseScene_PauseButton");
    }
    
    Vec2 PauseScene::getPauseButtonPosition()
    {
        return Vec2(this->visibleOrigin.x + this->visibleSize.width / 11,
                    this->visibleOrigin.y + this->visibleSize.height - this->visibleSize.width /11);
    }
    
    Vec2 PauseScene::getPauseBackgroundPosition()
    {
        return Vec2(this->center.x, this->center.y + this->visibleSize.height / 20);
    }
    
    Vec2 PauseScene::getPauseBackButtonPosition()
    {
        float width = this->pauseBackground->getContentSize().width;
        float height = this->pauseBackground->getContentSize().height;
        return Vec2(width, height);
    }
    
    Vec2 PauseScene::getMusicButtonPosition()
    {
        float width = this->pauseBackground->getContentSize().width;
        float height = this->pauseBackground->getContentSize().height;
        Vec2 center = Vec2(width / 2, height / 2);
        return Vec2(center.x - width /4, center.y + width /4);
    }
    
    Vec2 PauseScene::getSoundsButtonPosition()
    {
        float width = this->pauseBackground->getContentSize().width;
        float height = this->pauseBackground->getContentSize().height;
        Vec2 center = Vec2(width / 2, height / 2);
        return Vec2(center.x - width /4, center.y - width /4);
    }
    
    Vec2 PauseScene::getBackHomeButtonPosition()
    {
        float width = this->pauseBackground->getContentSize().width;
        float height = this->pauseBackground->getContentSize().height;
        Vec2 center = Vec2(width / 2, height / 2);
        return Vec2(center.x + width /4, center.y + width /4);
    }
    
    Vec2 PauseScene::getRetryButtonPosition()
    {
        float width = this->pauseBackground->getContentSize().width;
        float height = this->pauseBackground->getContentSize().height;
        Vec2 center = Vec2(width / 2, height / 2);
        return Vec2(center.x + width /4, center.y - width /4);
    }
}
