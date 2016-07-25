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
        std::string startTitleImage = "image/StartTitle.png";
        std::string movePig0Image = "image/StartSceneMovePig0.png";
        std::string movePig1Image = "image/StartSceneMovePig1.png";
        this->startBackground = new GameSprite::Background(backgroundImage);
        this->startBackground->setPosition(this->center);
        this->startButton = new GameSprite::StartButton(startButtonImage);
        this->startButton->setPosition(this->getStartButtonPosition());
        this->startTitle = new GameSprite::StartTitle(startTitleImage);
        this->startTitle->setPosition(this->getStartTitlePosition());
        this->movePig0 = new GameSprite::Image(movePig0Image);
        this->movePig0->setPosition(this->getMovePig0EndPosition());
        this->movePig1 = new GameSprite::Image(movePig1Image);
        this->movePig1->setPosition(this->getMovePig1EndPosition());
        this->addChild(this->startBackground, 0);
        this->addChild(this->startButton, 3);
        this->addChild(this->startTitle, 3);
        this->addChild(this->movePig0, 2);
        this->addChild(this->movePig1, 1);
        spriteManager->setWithKey("StartScene_Background", this->startBackground);
        spriteManager->setWithKey("StartScene_StartButton", this->startButton);
        spriteManager->setWithKey("StartScene_StartTitle", this->startTitle);
        spriteManager->setWithKey("StartScene_MovePig0", this->movePig0);
        spriteManager->setWithKey("StartScene_MovePig1", this->movePig1);
    }
    
    void StartScene::releaseScene()
    {
        this->removeAllChildren();
        auto spriteManager = Manager::SpriteManager::getInstance();
        spriteManager->releaseByKey("StartScene_Background");
        spriteManager->releaseByKey("StartScene_StartButton");
        spriteManager->releaseByKey("StartScene_StartTitle");
        spriteManager->releaseByKey("StartScene_MovePig0");
        spriteManager->releaseByKey("StartScene_MovePig1");

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
        this->startButton->cocos2d::Node::setVisible(false);
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
        this->startButton->cocos2d::Node::setVisible(true);
        Director::getInstance()->getEventDispatcher()->setEnabled(true);
    }
    
    Vec2 StartScene::getStartButtonPosition()
    {
        return Vec2(this->center.x, this->visibleOrigin.y + this->visibleSize.height / 4.0);
    }
    
    Vec2 StartScene::getStartTitlePosition()
    {
        return Vec2(this->center.x, this->visibleOrigin.y + this->visibleSize.height * 0.85);
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
