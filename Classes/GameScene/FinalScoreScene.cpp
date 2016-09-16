#include "FinalScoreScene.h"


namespace GameScene
{
    FinalScoreScene::FinalScoreScene(std::string score) : BaseScene()
    {
        this->score = score;
        this->name = "FinalScoreScene";
    }
    
    void FinalScoreScene::initScene()
    {
        this->background = new GameSprite::Background("image/FinalScoreBackground.png");
        this->background->setPosition(this->getBackgroundPosition());
        Manager::SpriteManager::getInstance()->setWithKey("FinalScoreScene_FinalScoreBackground", this->background);
        
        this->nextButton = new GameSprite::NextButton("image/NextButton.png");
        this->nextButton->setPosition(this->getNextButtonPosition());
        Manager::SpriteManager::getInstance()->setWithKey("FinalScoreScene_NextButton", this->nextButton);
        
        std::stringstream scoreString;
        scoreString << this->score;
        this->scoreLabel = Label::createWithTTF(scoreString.str(), "fonts/KOMIKAX.ttf", 170);
        this->scoreLabel->setPosition(this->getScorePosition());
        this->scoreLabel->setColor(Color3B(249, 249, 21));
        this->scoreLabel->retain();
    }
    
    void FinalScoreScene::releaseScene()
    {
        Manager::SpriteManager::getInstance()->releaseByKey("FinalScoreScene_FinalScoreBackground");
        Manager::SpriteManager::getInstance()->releaseByKey("FinalScoreScene_NextButton");
        this->scoreLabel->release();
    }
    
    Label* FinalScoreScene::getScoreLabel()
    {
        return this->scoreLabel;
    }
    
    void FinalScoreScene::runAnimation()
    {
        Director::getInstance()->getEventDispatcher()->setEnabled(false);
        this->nextButton->setVisible(false);
        auto fadeIn = FadeIn::create(1.f);
        this->scoreLabel->setOpacity(0);
        this->scoreLabel->runAction(Sequence::create(fadeIn, CallFunc::create(CC_CALLBACK_0(FinalScoreScene::showNextButton, this)), NULL));
    }
    
    void FinalScoreScene::showNextButton()
    {
        Director::getInstance()->getEventDispatcher()->setEnabled(true);
        this->nextButton->setVisible(true);
    }
    
    void FinalScoreScene::setScore(std::string score)
    {
        this->score = score;
        this->scoreLabel->setString(score);
    }
    
    Vec2 FinalScoreScene::getScorePosition()
    {
        return this->center;
    }
    
    Vec2 FinalScoreScene::getBackgroundPosition()
    {
        return this->center;
    }
    
    Vec2 FinalScoreScene::getNextButtonPosition()
    {
        return Vec2(this->center.x, this->center.y / 2);
    }
}
