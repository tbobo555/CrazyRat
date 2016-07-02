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
        this->victoryBackground = new GameSprite::Background("image/VictoryBackground.png");
        this->victoryBackground->setPosition(this->getBackgroundPosition());
        spriteManager->setWithKey("VictoryScene_VictoryBackground", this->victoryBackground);
        this->nextButton = new GameSprite::NextButton("image/NextButton.png");
        this->nextButton->setPosition(this->getNextButtonPosition());
        spriteManager->setWithKey("VictoryScene_NextButton", this->nextButton);
        this->starLeft = new GameSprite::Star("image/StarLeft.png");
        this->starLeft->setPosition(this->getStarPosition(0));
        spriteManager->setWithKey("VictoryScene_StarLeft", this->starLeft);
        this->starMiddle = new GameSprite::Star("image/StarMiddle.png");
        this->starMiddle->setPosition(this->getStarPosition(1));
        spriteManager->setWithKey("VictoryScene_StarMiddle", this->starMiddle);
        this->starRight = new GameSprite::Star("image/StarRight.png");
        this->starRight->setPosition(this->getStarPosition(2));
        spriteManager->setWithKey("VictoryScene_StarRight", this->starRight);
    }
    
    void VictoryScene::releaseScene()
    {
        auto spriteManager = Manager::SpriteManager::getInstance();
        spriteManager->releaseByKey("VictoryScene_VictoryBackground");
        spriteManager->releaseByKey("VictoryScene_NextButton");
        spriteManager->releaseByKey("VictoryScene_StarLeft");
        spriteManager->releaseByKey("VictoryScene_StarMiddle");
        spriteManager->releaseByKey("VictoryScene_StarRight");
    }
    
    void VictoryScene::runAnimation()
    {
        Director::getInstance()->getEventDispatcher()->setEnabled(false);
        this->nextButton->setVisible(false);
        this->starRight->setPosition(this->leftBottom);
        this->starMiddle->setPosition(this->leftBottom);
        this->starLeft->setPosition(this->leftBottom);
        
        auto actionTo = MoveTo::create(0.3, this->getStarPosition(0));
        this->starRight->runAction(actionTo);
        
        actionTo = MoveTo::create(0.3, this->getStarPosition(1));
        this->starMiddle->runAction(Sequence::create(DelayTime::create(0.15f), actionTo, NULL));
        
        actionTo = MoveTo::create(0.3, this->getStarPosition(2));
        this->starLeft->runAction(Sequence::create(DelayTime::create(0.3f), actionTo, CallFunc::create(CC_CALLBACK_0(VictoryScene::animationCallback, this)), NULL));
    }
    
    void VictoryScene::animationCallback()
    {
        Director::getInstance()->getEventDispatcher()->setEnabled(true);
        this->nextButton->setVisible(true);
    }
    
    Vec2 VictoryScene::getBackgroundPosition()
    {
        return this->center;
    }
    
    Vec2 VictoryScene::getNextButtonPosition()
    {
        return Vec2(this->center.x, this->center.y / 2);
    }
    
    Vec2 VictoryScene::getStarPosition(int position)
    {
        std::vector<Vec2> starPositionset = {
            Vec2(this->center.x - 360, this->center.y),
            Vec2(this->center.x, 1100),
            Vec2(this->center.x + 360, this->center.y)
        };
        return starPositionset.at(position);
    }

}
