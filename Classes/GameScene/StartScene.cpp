#include "StartScene.h"

namespace GameScene
{
    StartScene::StartScene() : GameScene::BaseScene()
    {
    }
    
    void StartScene::initScene()
    {
        this->scene->addChild(this->startBackground->getCCSprite(), 0);
        this->scene->addChild(this->startButton->getCCSprite(), 1);
    }
    
}
