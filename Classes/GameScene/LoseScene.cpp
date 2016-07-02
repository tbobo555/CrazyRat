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
        this->loseTitle = new GameSprite::Image("image/LoseTitle.png");
        this->loseTitle->setPosition(this->getLoseTitlePosition());
        spriteManager->setWithKey("LoseScene_LoseTitle", this->loseTitle);

    }
    
    void LoseScene::releaseScene()
    {
        auto spriteManager = Manager::SpriteManager::getInstance();
        spriteManager->releaseByKey("LoseScene_LoseBackground");
        spriteManager->releaseByKey("LoseScene_NextButton");
        spriteManager->releaseByKey("LoseScene_LoseTitle");
    }
    
    void LoseScene::runAnimation()
    {
        Director::getInstance()->getEventDispatcher()->setEnabled(false);
        this->nextButton->setVisible(false);
        auto fadeIn = FadeIn::create(1.f);
        this->loseTitle->setOpacity(0);
        this->loseTitle->runAction(Sequence::create(fadeIn, CallFunc::create(CC_CALLBACK_0(LoseScene::animationCallback, this)), NULL));
    }
    
    void LoseScene::animationCallback()
    {
        Director::getInstance()->getEventDispatcher()->setEnabled(true);
        this->nextButton->setVisible(true);
    }
    
    Vec2 LoseScene::getBackgroundPosition()
    {
        return this->center;
    }
    
    Vec2 LoseScene::getNextButtonPosition()
    {
        return Vec2(this->center.x, this->center.y / 2);
    }
    
    Vec2 LoseScene::getLoseTitlePosition()
    {
        return Vec2(556, 1920 - 572);
    }

}
