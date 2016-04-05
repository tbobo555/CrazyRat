#include "PauseScene.h"


namespace GameScene
{
    PauseScene::PauseScene() : GameScene::BaseScene()
    {
        this->name = "PauseScene";
    }
    
    void PauseScene::initScene()
    {
        auto imageConfig = ImageConfig::getInstance();
        auto spriteManager = Manager::SpriteManager::getInstance();
        std::string pauseButtonImage = "image/PauseButton.png";
        std::string pauseBackgroundImage = "image/SettingBackground.png";
        std::string musicButtonImage = "image/MusicOnButton.png";
        std::string soundsButtonImage = "image/SoundsOnButton.png";
        std::string backHomeButtonImage = "image/BackHomeButton.png";
        std::string retryButtonImage = "image/RetryButton.png";
        std::string pauseBackButtonImage = "image/BackButton.png";
        
        this->pauseBackground = new Background(pauseBackgroundImage);
        this->pauseBackground->setPosition(this->center);
        this->pauseBackground->setVisible(false);
        spriteManager->setWithKey("PauseScene_PauseBackground", this->pauseBackground);
        
        this->musicButton = new MusicButton(musicButtonImage);
        this->musicButton->setPosition(Vec2(355, 1315));
        this->musicButton->setVisible(false);
        spriteManager->setWithKey("PauseScene_MusicButton", this->musicButton);
        
        this->soundsButton = new SoundsButton(soundsButtonImage);
        this->soundsButton->setPosition(Vec2(355, 985));
        this->soundsButton->setVisible(false);
        spriteManager->setWithKey("PauseScene_SoundsButton", this->soundsButton);
        
        this->backHomeButton = new BackHomeButton(backHomeButtonImage);
        this->backHomeButton->setPosition(Vec2(730, 1315));
        this->backHomeButton->setVisible(false);
        spriteManager->setWithKey("PauseScene_BackHomeButton", this->backHomeButton);
        
        this->retryButton = new RetryButton(retryButtonImage);
        this->retryButton->setPosition(Vec2(730, 985));
        this->retryButton->setVisible(false);
        spriteManager->setWithKey("PauseScene_RetryButton", this->retryButton);
        
        this->pauseBackButton = new PauseBackButton(pauseBackButtonImage);
        this->pauseBackButton->setPosition(Vec2(this->leftTop.x + imageConfig->getImageSize("BackButton").width * 0.6, this->leftTop.y - imageConfig->getImageSize("BackButton").height * 0.6));
        this->pauseBackButton->setVisible(false);
        spriteManager->setWithKey("PauseScene_PauseBackButton", this->pauseBackButton);
        
        auto pauseButtonPosition = Vec2(this->leftBottom.x + imageConfig->getImageSize("PauseButton").width * 0.6, this->leftBottom.y + imageConfig->getImageSize("PauseButton").height * 0.6);
        this->pauseButton = new GameSprite::PauseButton(pauseButtonImage);
        this->pauseButton->setPosition(pauseButtonPosition);
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
}
