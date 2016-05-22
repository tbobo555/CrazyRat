#include "StartScene.h"

namespace GameScene
{
    StartScene::StartScene() : GameScene::BaseScene()
    {
        this->name = "StartScene";
    }
    
    void StartScene::initScene()
    {
        auto spriteManager = Manager::SpriteManager::getInstance();
        std::string backgroundImage = "image/StartBackground.png";
        std::string startButtonImage = "image/StartButton.png";
        std::string startTitleImage = "image/StartTitle.png";
        this->startBackground = new GameSprite::Background(backgroundImage);
        this->startBackground->setPosition(this->center);
        this->startButton = new GameSprite::StartButton(startButtonImage);
        this->startButton->setPosition(this->getStartButtonPosition());
        this->startTitle = new GameSprite::StartTitle(startTitleImage);
        this->startTitle->setPosition(this->getStartTitlePosition());
        this->addChild(this->startBackground, 0);
        this->addChild(this->startButton, 1);
        this->addChild(this->startTitle, 1);
        spriteManager->setWithKey("StartScene_Background", this->startBackground);
        spriteManager->setWithKey("StartScene_StartButton", this->startButton);
        spriteManager->setWithKey("StartScene_StartTitle", this->startTitle);
    }
    
    void StartScene::releaseScene()
    {
        this->removeAllChildren();
        auto spriteManager = Manager::SpriteManager::getInstance();
        spriteManager->releaseByKey("StartScene_Background");
        spriteManager->releaseByKey("StartScene_StartButton");
        spriteManager->releaseByKey("StartScene_StartTitle");
    }
    
    Vec2 StartScene::getStartButtonPosition()
    {
        return Vec2(this->center.x, this->visibleOrigin.y + this->visibleSize.height / 4.0);
        //return Vec2(0, 0);
    }
    
    Vec2 StartScene::getStartTitlePosition()
    {
        return Vec2(this->center.x, this->visibleOrigin.y + this->visibleSize.height * 0.85);
    }
}
