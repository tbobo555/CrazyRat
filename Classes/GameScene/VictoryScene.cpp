#include "VictoryScene.h"

namespace GameScene
{
    VictoryScene::VictoryScene() : GameScene::BaseScene()
    {
        this->name = "VictoryScene";
    }
    
    void VictoryScene::initScene()
    {
        auto spriteManager = Manager::SpriteManager::getInstance();
        this->victoryBackground = new GameSprite::Background("image/SettingBackground.png");
        this->victoryBackground->setPosition(this->center);
        spriteManager->setWithKey("VictoryScene_VictoryBackground", this->victoryBackground);
        this->nextButton = new GameSprite::NextButton("image/NextButton.png");
        this->nextButton->setPosition(this->center);
        spriteManager->setWithKey("VictoryScene_NextButton", this->nextButton);
    }
    
    void VictoryScene::releaseScene()
    {
        auto spriteManager = Manager::SpriteManager::getInstance();
        spriteManager->releaseByKey("VictoryScene_VictoryBackground");
        spriteManager->releaseByKey("VictoryScene_NextButton");
    }
}
