#include "ChallengeScene.h"


namespace GameScene
{
    ChallengeScene::ChallengeScene() : GameScene::BaseScene()
    {
        this->name = "ChallengeScene";
    }
    
    void ChallengeScene::initScene()
    {
        this->challengeBackground = new Background("image/ChallengeBackground.png");
        this->challengeBackground->setPosition(this->center);
        
        this->bossButton1 = new BossButton("image/Boss1Button.png");
        this->bossButton1->setPosition(this->getBossButtonPosition());
        
        this->addChild(this->challengeBackground, 0);
        this->addChild(this->bossButton1, 3);
        
        Manager::SpriteManager::getInstance()->setWithKey("ChallengeScene_Background", this->challengeBackground);
        Manager::SpriteManager::getInstance()->setWithKey("ChallengeScene_BossButton1", this->bossButton1);
    }
    
    void ChallengeScene::releaseScene()
    {
        this->removeAllChildren();
        auto spriteManager = Manager::SpriteManager::getInstance();
        spriteManager->releaseByKey("ChallengeScene_Background");
        spriteManager->releaseByKey("ChallengeScene_BossButton1");
    }
    
    Vec2 ChallengeScene::getBossButtonPosition()
    {
        return Vec2(this->center);
    }
}

