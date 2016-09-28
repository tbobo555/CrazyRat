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
        
        std::string playButtonImage = "image/PlayButton.png";
        std::string careerButtonImage = "image/CareerButton.png";
        std::string highScoresButtonImage = "image/HighScoresButton.png";
        std::string startTitleImage = "image/StartTitle.png";
        std::string movePig0Image = "image/StartSceneMovePig0.png";
        std::string movePig1Image = "image/StartSceneMovePig1.png";
        std::string highScoreMaskImage = "image/HighScoreRecordBackground.png";
        this->startBackground = new GameSprite::Background(backgroundImage);
        this->startBackground->setPosition(this->center);
        
        this->playButton = new GameSprite::PlayButton(playButtonImage);
        this->playButton->setPosition(this->getPlayButtonPosition());
        
        this->careerButton = new GameSprite::CareerButton(careerButtonImage);
        this->careerButton->setPosition(this->getCareerButtonPosition());
        
        this->highScoresButton = new GameSprite::HighScoresButton(highScoresButtonImage);
        this->highScoresButton->setPosition(this->getHighScoresButtonPosition());
        
        this->startTitle = new GameSprite::StartTitle(startTitleImage);
        this->startTitle->setPosition(this->getStartTitlePosition());
        this->movePig0 = new GameSprite::Image(movePig0Image);
        this->movePig0->setPosition(this->getMovePig0EndPosition());
        this->movePig1 = new GameSprite::Image(movePig1Image);
        this->movePig1->setPosition(this->getMovePig1EndPosition());
        
        this->highScoreMask = new GameSprite::HighScoreMask(highScoreMaskImage);
        this->highScoreMask->setPosition(this->center);
        
        int newHighScore = DB::NewHighScoreSetting::getInstance()->getHighScore();
        std::stringstream scoreKey;
        scoreKey << newHighScore;
        this->highScore = Label::createWithTTF(scoreKey.str(), "fonts/KOMIKAX.ttf", 170);
        this->highScore->setPosition(this->center);
        this->highScore->setColor(Color3B(249, 249, 21));
        this->highScore->retain();

        this->addChild(this->startBackground, 0);
        this->addChild(this->playButton, 3);
        this->addChild(this->careerButton, 3);
        this->addChild(this->highScoresButton, 3);
        this->addChild(this->startTitle, 3);
        this->addChild(this->movePig0, 2);
        this->addChild(this->movePig1, 1);
        this->addChild(this->highScoreMask, -2);
        this->addChild(this->highScore, -1);
        spriteManager->setWithKey("StartScene_Background", this->startBackground);
        spriteManager->setWithKey("StartScene_PlayButton", this->playButton);
        spriteManager->setWithKey("StartScene_CareerButton", this->careerButton);
        spriteManager->setWithKey("StartScene_HighScoresButton", this->highScoresButton);
        spriteManager->setWithKey("StartScene_StartTitle", this->startTitle);
        spriteManager->setWithKey("StartScene_MovePig0", this->movePig0);
        spriteManager->setWithKey("StartScene_MovePig1", this->movePig1);
        spriteManager->setWithKey("StartScene_HighScoreMask", this->highScoreMask);
        Manager::MusicManager::getInstance()->playMusic("audio/music/LivelyLumpsucker.caf");
    }
    
    void StartScene::releaseScene()
    {
        this->removeAllChildren();
        auto spriteManager = Manager::SpriteManager::getInstance();
        spriteManager->releaseByKey("StartScene_Background");
        spriteManager->releaseByKey("StartScene_PlayButton");
        spriteManager->releaseByKey("StartScene_CareerButton");
        spriteManager->releaseByKey("StartScene_HighScoresButton");
        spriteManager->releaseByKey("StartScene_StartTitle");
        spriteManager->releaseByKey("StartScene_MovePig0");
        spriteManager->releaseByKey("StartScene_MovePig1");
        spriteManager->releaseByKey("StartScene_HighScoreMask");
        this->highScore->release();
    }
    
    void StartScene::runAnimation()
    {
        Director::getInstance()->getEventDispatcher()->setEnabled(false);
        auto spriteManager = Manager::SpriteManager::getInstance();
        Vec2 titleEndPosition = this->getStartTitlePosition();
        Vec2 titleStartposition = Vec2(this->centerTop.x, this->centerTop.y + this->startTitle->getContentSize().height);
        this->startTitle->setPosition(titleStartposition);
        this->movePig0->setPosition(this->getMovePig0StartPosition());
        this->movePig1->setPosition(this->getMovePig1StartPosition());
        auto actionTo = MoveTo::create(0.3, titleEndPosition);
        auto actionBy0 = MoveBy::create(0.05, Vec2(0 , -50));
        auto actionBy1 = MoveBy::create(0.1, Vec2(0 , 100));
        auto actionBy2 = MoveBy::create(0.1, Vec2(0 , -100));
        auto actionBy3 = MoveBy::create(0.1, Vec2(0 , 100));
        auto actionBy4 = MoveBy::create(0.05, Vec2(0 , -50));
        spriteManager->getByKey("MenuScene_SettingButton")->setVisible(false);
        this->playButton->cocos2d::Node::setVisible(false);
        this->careerButton->cocos2d::Node::setVisible(false);
        this->highScoresButton->cocos2d::Node::setVisible(false);
        this->startTitle->runAction(Sequence::create(actionTo, actionBy0, actionBy1, actionBy2, actionBy3, actionBy4, DelayTime::create(0.1f),
                                                     CallFunc::create( CC_CALLBACK_0(StartScene::animationCallback, this)),nullptr));
        actionTo = MoveTo::create(0.5, this->getMovePig0EndPosition());
        this->movePig0->runAction(actionTo);
        actionTo = MoveTo::create(0.5, this->getMovePig1EndPosition());
        this->movePig1->runAction(actionTo);

    }
    
    void StartScene::animationCallback()
    {
        auto spriteManager = Manager::SpriteManager::getInstance();
        spriteManager->getByKey("MenuScene_SettingButton")->setVisible(true);
        this->playButton->cocos2d::Node::setVisible(true);
        this->careerButton->cocos2d::Node::setVisible(true);
        this->highScoresButton->cocos2d::Node::setVisible(true);
        Director::getInstance()->getEventDispatcher()->setEnabled(true);
    }
    
    void StartScene::showHighScore()
    {
        this->highScoreMask->setLocalZOrder(100);
        this->highScore->setLocalZOrder(101);
    }
    
    void StartScene::hideHighScore()
    {
        this->highScoreMask->setLocalZOrder(-2);
        this->highScore->setLocalZOrder(-1);
    }
    
    Vec2 StartScene::getPlayButtonPosition()
    {
        return Vec2(this->center.x + 10, this->visibleOrigin.y + this->visibleSize.height * 0.35);
    }
    
    Vec2 StartScene::getCareerButtonPosition()
    {
        return Vec2(this->center.x + 10 - 150, this->visibleOrigin.y + this->visibleSize.height * 0.35 - 225);
    }

    Vec2 StartScene::getHighScoresButtonPosition()
    {
        return Vec2(this->center.x + 10 + 150, this->visibleOrigin.y + this->visibleSize.height * 0.35 - 225);
    }
    
    Vec2 StartScene::getStartTitlePosition()
    {
        return Vec2(this->center.x, this->visibleOrigin.y + this->visibleSize.height * 0.83);
    }
    
    Vec2 StartScene::getMovePig0StartPosition()
    {
        return Vec2(this->visibleOrigin.x + this->visibleSize.width + this->getContentSize().width, 690);
    }
    
    Vec2 StartScene::getMovePig1StartPosition()
    {
        return Vec2(this->visibleOrigin.x + this->visibleSize.width + this->getContentSize().width, 810);
    }
    
    Vec2 StartScene::getMovePig0EndPosition()
    {
        return Vec2(950, 690);
    }
    
    Vec2 StartScene::getMovePig1EndPosition()
    {
        return Vec2(890, 810);
    }
}
