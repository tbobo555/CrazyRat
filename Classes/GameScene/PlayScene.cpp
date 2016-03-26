#include "PlayScene.h"


namespace GameScene
{
    PlayScene::PlayScene(int pMapNumber, int pStageNumber) : GameScene::BaseScene()
    {
        this->name = "PlayScene";
        this->mapNumber = pMapNumber;
        this->stageNumber = pStageNumber;
    }
    
    void PlayScene::initScene()
    {
        auto spriteManager = Manager::SpriteManager::getInstance();
        std::string backgroundImage = "image/PlayBackground.png";
        this->playBackground = new GameSprite::Background(backgroundImage);
        this->playBackground->setPosition(this->center);
        this->addChild(this->playBackground, 0);
        spriteManager->setWithKey("PlayScene_Background", this->playBackground);
        
        this->prepareLabel = Label::createWithTTF("3", "fonts/arial.ttf", 100);
        this->prepareLabel->setPosition(this->center);
        this->addChild(this->prepareLabel);
    }
    
    void PlayScene::releaseScene()
    {
        this->removeAllChildren();
        auto spriteManager = Manager::SpriteManager::getInstance();
        spriteManager->releaseByKey("PlayScene_Background");
    }
    
    void PlayScene::run()
    {
        this->prepareCountdown();
    }
    
    void PlayScene::prepareCountdown()
    {
        this->prepareTime = 3;
        auto defaultScheduler = Director::getInstance()->getScheduler();
        this->prepareScheduler = new (std::nothrow) Scheduler();
        defaultScheduler->scheduleUpdate(this->prepareScheduler, 0, false);
        
        
        this->prepareScheduler->schedule([&](float dt)
                         {
                             if (this->prepareTime == 0) {
                                 this->prepareScheduler->unschedule("CountDown", this);
                                 this->start();
                             } else {
                                 std::stringstream timeString;
                                 -- this->prepareTime;
                                 timeString << this->prepareTime;
                                 this->prepareLabel->setString(timeString.str());
                                 timeString.str("");
                             }  
                         }, this, 1.0f, CC_REPEAT_FOREVER, 0.0f, false, "CountDown");
    }
    
    void PlayScene::start()
    {
        //this->prepareScheduler->release();
        this->removeChild(this->prepareLabel);
        log("Start!!");
    }
    void PlayScene::update(float delta)
    {
        
    }
    
}