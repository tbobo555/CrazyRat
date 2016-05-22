#include "LoseScene.h"

namespace GameScene
{
    LoseScene::LoseScene() : GameScene::BaseScene()
    {
        this->name = "LoseScene";
    }
    
    void LoseScene::initScene()
    {
        auto spriteManager = Manager::SpriteManager::getInstance();
        this->loseBackground = new GameSprite::Background("image/LoseBackground.png");
        this->loseBackground->setPosition(this->getBackgroundPosition());
        spriteManager->setWithKey("LoseScene_LoseBackground", this->loseBackground);
        this->nextButton = new GameSprite::NextButton("image/NextButton.png");
        this->nextButton->setPosition(this->getNextButtonPosition());
        spriteManager->setWithKey("LoseScene_NextButton", this->nextButton);
    }
    
    void LoseScene::releaseScene()
    {
        auto spriteManager = Manager::SpriteManager::getInstance();
        spriteManager->releaseByKey("LoseScene_LoseBackground");
        spriteManager->releaseByKey("LoseScene_NextButton");
    }
    
    Vec2 LoseScene::getBackgroundPosition()
    {
        return this->center;
    }
    
    Vec2 LoseScene::getNextButtonPosition()
    {
        return Vec2(this->center.x, this->center.y / 2);
    }

}
