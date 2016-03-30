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
        this->startBackground = new GameSprite::Background(backgroundImage);
        this->startBackground->setPosition(this->center);
        this->startButton = new GameSprite::StartButton(startButtonImage);
        this->startButton->setPosition(this->getStartButtonPosition());
        this->addChild(this->startBackground, 0);
        this->addChild(this->startButton, 1);
        spriteManager->setWithKey("StartScene_Background", this->startBackground);
        spriteManager->setWithKey("StartScene_StartButton", this->startButton);
    }
    
    void StartScene::releaseScene()
    {
        this->removeAllChildren();
        auto spriteManager = Manager::SpriteManager::getInstance();
        spriteManager->releaseByKey("StartScene_Background");
        spriteManager->releaseByKey("StartScene_StartButton");
    }
    
    Vec2 StartScene::getStartButtonPosition()
    {
        return Vec2(this->center.x, this->visibleOrigin.y + this->visibleSize.height / 4.0);
    }
}
