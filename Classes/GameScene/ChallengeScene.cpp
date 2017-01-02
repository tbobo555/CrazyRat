#include "ChallengeScene.h"


namespace GameScene
{
    ChallengeScene::ChallengeScene() : GameScene::BaseScene()
    {
        this->name = "ChallengeScene";
        this->isShowBossButtonAnimation = false;
        this->bossButtonAnimationPeriod = 0.22f;
    }
    
    void ChallengeScene::initScene()
    {
        this->challengeBackground = new Background("image/ChallengeBackground.png");
        this->challengeBackground->setPosition(this->center);
        this->addChild(this->challengeBackground, 0);
        
        this->backButton = new BackButton("image/BackButton.png");
        this->backButton->setPosition(this->getBackButtonPosition());
        this->addChild(this->backButton, 5);
        
        this->bossButton0 = new BossButton("image/Boss0Button.png");
        this->bossButton0->setPosition(this->getBossButtonPosition(0));
        this->bossButton0->setVisible(false);
        this->addChild(this->bossButton0, 3);
        
        this->bossButton1 = new BossButton("image/Boss1Button.png");
        this->bossButton1->setPosition(this->getBossButtonPosition(1));
        this->bossButton1->setVisible(false);
        this->addChild(this->bossButton1, 3);

        this->bossButton2 = new BossButton("image/Boss2Button.png");
        this->bossButton2->setPosition(this->getBossButtonPosition(2));
        this->bossButton2->setVisible(false);
        this->addChild(this->bossButton2, 3);

        this->bossButton3 = new BossButton("image/Boss3Button.png");
        this->bossButton3->setPosition(this->getBossButtonPosition(3));
        this->bossButton3->setVisible(false);
        this->addChild(this->bossButton3, 3);
        
        this->bossButton4 = new BossButton("image/Boss4Button.png");
        this->bossButton4->setPosition(this->getBossButtonPosition(4));
        this->bossButton4->setVisible(false);
        this->addChild(this->bossButton4, 3);
        
        this->bossButton5 = new BossButton("image/Boss5Button.png");
        this->bossButton5->setPosition(this->getBossButtonPosition(5));
        this->bossButton5->setVisible(false);
        this->addChild(this->bossButton5, 3);

        this->bossButton6 = new BossButton("image/Boss6Button.png");
        this->bossButton6->setPosition(this->getBossButtonPosition(6));
        this->bossButton6->setVisible(false);
        this->addChild(this->bossButton6, 3);
        
        this->bossButton7 = new BossButton("image/Boss7Button.png");
        this->bossButton7->setPosition(this->getBossButtonPosition(7));
        this->bossButton7->setVisible(false);
        this->addChild(this->bossButton7, 3);
        
        this->highScoreButton = new GameSprite::HighScoreButton("image/HighScoreButton.png");
        this->highScoreButton->setPosition(this->getHighScoreButtonPosition());
        this->addChild(this->highScoreButton, 3);

        this->highScoreMask = new GameSprite::HighScoreMask("image/HighScoreRecordBackground.png");
        this->highScoreMask->setPosition(this->center);
        this->addChild(this->highScoreMask, -2);

        int newHighScore = DB::NewHighScoreSetting::getInstance()->getHighScore();
        std::stringstream scoreKey;
        scoreKey << newHighScore;
        this->highScore = Label::createWithTTF(scoreKey.str(), "fonts/KOMIKAX.ttf", 170);
        this->highScore->setPosition(this->center);
        this->highScore->setColor(Color3B(249, 249, 21));
        this->highScore->retain();
        this->addChild(this->highScore, -1);
        
        this->endlessButton = new GameSprite::EndlessButton("image/EndlessButton.png");
        this->endlessButton->setPosition(this->getEndlessButtonPosition());
        this->addChild(this->endlessButton, 3);
        
        Manager::SpriteManager::getInstance()->setWithKey("ChallengeScene_Background", this->challengeBackground);
        Manager::SpriteManager::getInstance()->setWithKey("ChallengeScene_BackButton", this->backButton);
        Manager::SpriteManager::getInstance()->setWithKey("ChallengeScene_BossButton0", this->bossButton0);
        Manager::SpriteManager::getInstance()->setWithKey("ChallengeScene_BossButton1", this->bossButton1);
        Manager::SpriteManager::getInstance()->setWithKey("ChallengeScene_BossButton2", this->bossButton2);
        Manager::SpriteManager::getInstance()->setWithKey("ChallengeScene_BossButton3", this->bossButton3);
        Manager::SpriteManager::getInstance()->setWithKey("ChallengeScene_BossButton4", this->bossButton4);
        Manager::SpriteManager::getInstance()->setWithKey("ChallengeScene_BossButton5", this->bossButton5);
        Manager::SpriteManager::getInstance()->setWithKey("ChallengeScene_BossButton6", this->bossButton6);
        Manager::SpriteManager::getInstance()->setWithKey("ChallengeScene_BossButton7", this->bossButton7);
        Manager::SpriteManager::getInstance()->setWithKey("ChallengeScene_HighScoreButton", this->highScoreButton);
        Manager::SpriteManager::getInstance()->setWithKey("ChallengeScene_HighScoreMask", this->highScoreMask);
        Manager::SpriteManager::getInstance()->setWithKey("ChallengeScene_EndlessButton", this->endlessButton);
    }
    
    void ChallengeScene::releaseScene()
    {
        this->removeAllChildren();
        auto spriteManager = Manager::SpriteManager::getInstance();
        spriteManager->releaseByKey("ChallengeScene_Background");
        spriteManager->releaseByKey("ChallengeScene_BackButton");
        spriteManager->releaseByKey("ChallengeScene_BossButton0");
        spriteManager->releaseByKey("ChallengeScene_BossButton1");
        spriteManager->releaseByKey("ChallengeScene_BossButton2");
        spriteManager->releaseByKey("ChallengeScene_BossButton3");
        spriteManager->releaseByKey("ChallengeScene_BossButton4");
        spriteManager->releaseByKey("ChallengeScene_BossButton5");
        spriteManager->releaseByKey("ChallengeScene_BossButton6");
        spriteManager->releaseByKey("ChallengeScene_BossButton7");
        spriteManager->releaseByKey("ChallengeScene_HighScoreButton");
        spriteManager->releaseByKey("ChallengeScene_HighScoreMask");
        spriteManager->releaseByKey("ChallengeScene_EndlessButton");
    }
    
    void ChallengeScene::showBossButton()
    {
        this->isShowBossButtonAnimation = true;
        this->bossButton0->cocos2d::Node::setVisible(true);
        this->bossButton1->cocos2d::Node::setVisible(true);
        this->bossButton2->cocos2d::Node::setVisible(true);
        this->bossButton3->cocos2d::Node::setVisible(true);
        this->bossButton4->cocos2d::Node::setVisible(true);
        this->bossButton5->cocos2d::Node::setVisible(true);
        this->bossButton6->cocos2d::Node::setVisible(true);
        this->bossButton7->cocos2d::Node::setVisible(true);
        this->endlessButton->cocos2d::Node::setVisible(true);
        this->highScoreButton->cocos2d::Node::setVisible(true);
    }
    
    void ChallengeScene::showHighScore()
    {
        this->highScoreMask->setLocalZOrder(100);
        this->highScore->setLocalZOrder(101);
    }
    
    void ChallengeScene::hideHighScore()
    {
        this->highScoreMask->setLocalZOrder(-2);
        this->highScore->setLocalZOrder(-1);
    }
    
    Vec2 ChallengeScene::getBossButtonPosition(int index)
    {
        switch(index) {
            case (0):
                return Vec2(140, 1385);
                break;
            case (1):
                return Vec2(406, 1385);
                break;
            case (2):
                return Vec2(672, 1385);
                break;
            case (3):
                return Vec2(938, 1385);
                break;
            case (4):
                return Vec2(140, 1000);
                break;
            case (5):
                return Vec2(406, 1000);
                break;
            case (6):
                return Vec2(672, 1000);
                break;
            case (7):
                return Vec2(938, 1000);
                break;
        }
        return Vec2(this->centerBottom);
    }
    
    void ChallengeScene::showBossButtonAmimation()
    {
        if (this->isShowBossButtonAnimation) {
            return;
        }
        Director::getInstance()->getEventDispatcher()->setEnabled(false);
        auto spriteManager = Manager::SpriteManager::getInstance();
        spriteManager->getByKey("MenuScene_SettingButton")->setVisible(false);
        this->backButton->setVisible(false);
        this->endlessButton->setVisible(false);
        this->highScoreButton->setVisible(false);
        this->isShowBossButtonAnimation = true;
        this->runAction(Sequence::create(
        CallFunc::create(CC_CALLBACK_0(ChallengeScene::runBossButton0, this)),
        DelayTime::create(this->bossButtonAnimationPeriod),
        CallFunc::create(CC_CALLBACK_0(ChallengeScene::runBossButton1, this)),
        DelayTime::create(this->bossButtonAnimationPeriod),
        CallFunc::create(CC_CALLBACK_0(ChallengeScene::runBossButton2, this)),
        DelayTime::create(this->bossButtonAnimationPeriod),
        CallFunc::create(CC_CALLBACK_0(ChallengeScene::runBossButton3, this)),
        DelayTime::create(this->bossButtonAnimationPeriod),
        CallFunc::create(CC_CALLBACK_0(ChallengeScene::runBossButton4, this)),
        DelayTime::create(this->bossButtonAnimationPeriod),
        CallFunc::create(CC_CALLBACK_0(ChallengeScene::runBossButton5, this)),
        DelayTime::create(this->bossButtonAnimationPeriod),
        CallFunc::create(CC_CALLBACK_0(ChallengeScene::runBossButton6, this)),
        DelayTime::create(this->bossButtonAnimationPeriod),
        CallFunc::create(CC_CALLBACK_0(ChallengeScene::runBossButton7, this)),
        DelayTime::create(0.6f),
        CallFunc::create(CC_CALLBACK_0(ChallengeScene::bossButtonAnimationDone, this)),
        NULL));
    }
    
    void ChallengeScene::runBossButton0()
    {
        this->bossButton0->setVisible(true);
        this->bossButton0->setPosition(this->centerBottom);
        this->bossButton0->runAction(MoveTo::create(this->bossButtonAnimationPeriod, this->getBossButtonPosition(0)));
    }
    
    void ChallengeScene::runBossButton1()
    {
        this->bossButton1->setVisible(true);
        this->bossButton1->setPosition(this->centerBottom);
        this->bossButton1->runAction(MoveTo::create(this->bossButtonAnimationPeriod, this->getBossButtonPosition(1)));
    }

    void ChallengeScene::runBossButton2()
    {
        this->bossButton2->setVisible(true);
        this->bossButton2->setPosition(this->centerBottom);
        this->bossButton2->runAction(MoveTo::create(this->bossButtonAnimationPeriod, this->getBossButtonPosition(2)));
    }
    
    void ChallengeScene::runBossButton3()
    {
        this->bossButton3->setVisible(true);
        this->bossButton3->setPosition(this->centerBottom);
        this->bossButton3->runAction(MoveTo::create(this->bossButtonAnimationPeriod, this->getBossButtonPosition(3)));
    }
    
    void ChallengeScene::runBossButton4()
    {
        this->bossButton4->setVisible(true);
        this->bossButton4->setPosition(this->centerBottom);
        this->bossButton4->runAction(MoveTo::create(this->bossButtonAnimationPeriod, this->getBossButtonPosition(4)));
    }
    
    void ChallengeScene::runBossButton5()
    {
        this->bossButton5->setVisible(true);
        this->bossButton5->setPosition(this->centerBottom);
        this->bossButton5->runAction(MoveTo::create(this->bossButtonAnimationPeriod, this->getBossButtonPosition(5)));
    }
    
    void ChallengeScene::runBossButton6()
    {
        this->bossButton6->setVisible(true);
        this->bossButton6->setPosition(this->centerBottom);
        this->bossButton6->runAction(MoveTo::create(this->bossButtonAnimationPeriod, this->getBossButtonPosition(6)));
    }
    
    void ChallengeScene::runBossButton7()
    {
        this->bossButton7->setVisible(true);
        this->bossButton7->setPosition(this->centerBottom);
        this->bossButton7->runAction(MoveTo::create(this->bossButtonAnimationPeriod, this->getBossButtonPosition(7)));
    }
    
    void ChallengeScene::bossButtonAnimationDone()
    {
        Director::getInstance()->getEventDispatcher()->setEnabled(true);
        auto spriteManager = Manager::SpriteManager::getInstance();
        spriteManager->getByKey("MenuScene_SettingButton")->setVisible(true);
        this->backButton->setVisible(true);
        this->endlessButton->setVisible(true);
        this->highScoreButton->setVisible(true);
    }
    
    Vec2 ChallengeScene::getBackButtonPosition()
    {
        float width = this->visibleSize.width;
        return Vec2(this->visibleOrigin.x + (width - 150), this->visibleOrigin.y + 150);
    }
    
    Vec2 ChallengeScene::getHighScoreButtonPosition()
    {
        return Vec2(672, 700);
    }
    
    Vec2 ChallengeScene::getEndlessButtonPosition()
    {
        return Vec2(406, 700);
    }
}
