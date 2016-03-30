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
        auto imageConfig = ImageConfig::getInstance();
        auto spriteManager = Manager::SpriteManager::getInstance();
        std::string backgroundImage = "image/PlayBackground.png";
        std::string timeBarDownImage = "image/TimeBarDown.png";
        std::string timeBarUpImage = "image/TimeBarUp.png";
        std::string pauseButtonImage = "image/PauseButton.png";
        std::string pauseBackgroundImage = "image/SettingBackground.png";
        std::string musicButtonImage = "image/MusicOnButton.png";
        std::string soundsButtonImage = "image/SoundsOnButton.png";
        std::string backHomeButtonImage = "image/BackHomeButton.png";
        std::string retryButtonImage = "image/RetryButton.png";
        std::string pauseBackButtonImage = "image/BackButton.png";
        
        this->playBackground = new GameSprite::Background(backgroundImage);
        this->playBackground->setPosition(this->center);
        this->addChild(this->playBackground, 0);
        spriteManager->setWithKey("PlayScene_Background", this->playBackground);
        
        this->timeBarDown = new GameSprite::TimeBarDown(timeBarDownImage);
        this->timeBarDown->setPosition(Vec2(800, this->visibleOrigin.y + 70));
        this->addChild(timeBarDown, 1);
        spriteManager->setWithKey("PlayScene_TimeBarDown", this->timeBarDown);
        
        this->timeBarUp = new GameSprite::TimeBarUp(timeBarUpImage);
        spriteManager->setWithKey("PlayScene_TimeBarUp", this->timeBarUp);
        
        this->timeBar = ProgressTimer::create(this->timeBarUp);
        this->timeBar->setType(ProgressTimer::Type::BAR);
        this->timeBar->setMidpoint(Vec2(0,0));
        this->timeBar->setBarChangeRate(Vec2(1, 0));
        this->addChild(this->timeBar, 2);
        this->timeBar->retain();
        this->timeBar->setPosition(Vec2(800, this->visibleOrigin.y + 70));
        
        this->pauseBackground = new Background(pauseBackgroundImage);
        this->pauseBackground->setPosition(this->center);
        this->pauseBackground->setVisible(false);
        this->addChild(this->pauseBackground, -100);
        spriteManager->setWithKey("PlayScene_PauseBackground", this->pauseBackground);
        
        this->musicButton = new MusicButton(musicButtonImage);
        this->musicButton->setPosition(Vec2(355, 1315));
        this->musicButton->setVisible(false);
        this->addChild(this->musicButton, -100);
        spriteManager->setWithKey("PlayScene_MusicButton", this->musicButton);
        
        this->soundsButton = new SoundsButton(soundsButtonImage);
        this->soundsButton->setPosition(Vec2(355, 985));
        this->soundsButton->setVisible(false);
        this->addChild(this->soundsButton, -100);
        spriteManager->setWithKey("PlayScene_SoundsButton", this->soundsButton);
        
        this->backHomeButton = new BackHomeButton(backHomeButtonImage);
        this->backHomeButton->setPosition(Vec2(730, 1315));
        this->backHomeButton->setVisible(false);
        this->addChild(this->backHomeButton, -100);
        spriteManager->setWithKey("PlayScene_BackHomeButton", this->backHomeButton);

        this->retryButton = new RetryButton(retryButtonImage);
        this->retryButton->setPosition(Vec2(730, 985));
        this->retryButton->setVisible(false);
        this->addChild(this->retryButton, -100);
        spriteManager->setWithKey("PlayScene_RetryButton", this->retryButton);
        
        this->pauseBackButton = new PauseBackButton(pauseBackButtonImage);
        this->pauseBackButton->setPosition(Vec2(this->leftTop.x + imageConfig->getImageSize("BackButton").width * 0.6, this->leftTop.y - imageConfig->getImageSize("BackButton").height * 0.6));
        this->pauseBackButton->setVisible(false);
        this->addChild(this->pauseBackButton, 101);
        spriteManager->setWithKey("PlayScene_PauseBackButton", this->pauseBackButton);
        
        auto pauseButtonPosition = Vec2(this->leftBottom.x + imageConfig->getImageSize("PauseButton").width * 0.6, this->leftBottom.y + imageConfig->getImageSize("PauseButton").height * 0.6);
        this->pauseButton = new GameSprite::PauseButton(pauseButtonImage);
        this->pauseButton->setPosition(pauseButtonPosition);
        this->addChild(this->pauseButton, 1);
        spriteManager->setWithKey("PlayScene_PauseButton", this->pauseButton);
        
        this->prepareLabel = Label::createWithTTF("3", "fonts/arial.ttf", 100);
        this->prepareLabel->setPosition(this->center);
        this->prepareLabel->retain();
        this->addChild(this->prepareLabel, 1);

        for (int i = 0; i < 10; i++) {
            int ratId = i;
            this->road0RatVector.push_back(new GameSprite::Rat("image/Rat.png", 0, 0, ratId));
            this->road0RatVector[ratId]->setPosition(Vec2(-150, -200));
            this->addChild(this->road0RatVector[ratId], 3);
            this->road0AvailableIndex.push_back(ratId);
            this->road1RatVector.push_back(new GameSprite::Rat("image/Rat.png", 0, 1, ratId));
            this->road1RatVector[ratId]->setPosition(Vec2(-150, -200));
            this->addChild(this->road1RatVector[ratId], 3);
            this->road1AvailableIndex.push_back(ratId);
            this->road2RatVector.push_back(new GameSprite::Rat("image/Rat.png", 0, 2, ratId));
            this->road2RatVector[ratId]->setPosition(Vec2(-150, -200));
            this->addChild(this->road2RatVector[ratId], 3);
            this->road2AvailableIndex.push_back(ratId);
        }
    }
    
    bool PlayScene::getIsPaused()
    {
        return this->isPaused;
    }
    
    void PlayScene::releaseScene()
    {
        unscheduleAllCallbacks();
        unschedule(CC_SCHEDULE_SELECTOR(PlayScene::prepareUpdate));
        unschedule(CC_SCHEDULE_SELECTOR(PlayScene::gameUpdate));
        unschedule(CC_SCHEDULE_SELECTOR(PlayScene::road0Update));
        unschedule(CC_SCHEDULE_SELECTOR(PlayScene::road1Update));
        unschedule(CC_SCHEDULE_SELECTOR(PlayScene::road2Update));
        this->removeAllChildren();
        auto spriteManager = Manager::SpriteManager::getInstance();
        spriteManager->releaseByKey("PlayScene_Background");
        spriteManager->releaseByKey("PlayScene_TimeBarDown");
        spriteManager->releaseByKey("PlayScene_TimeBarUp");
        this->timeBar->release();
        spriteManager->releaseByKey("PlayScene_PauseBackground");
        spriteManager->releaseByKey("PlayScene_MusicButton");
        spriteManager->releaseByKey("PlayScene_SoundsButton");
        spriteManager->releaseByKey("PlayScene_BackHomeButton");
        spriteManager->releaseByKey("PlayScene_RetryButton");
        spriteManager->releaseByKey("PlayScene_PauseBackButton");
        spriteManager->releaseByKey("PlayScene_PauseButton");
        this->prepareLabel->release();
        for (int i = 0; i < 10; i++) {
            this->road0RatVector[i]->release();
            this->road1RatVector[i]->release();
            this->road2RatVector[i]->release();
        }
    }
    
    void PlayScene::play()
    {
        this->isPaused = false;
        this->prepareTime = 3;
        schedule(CC_SCHEDULE_SELECTOR(PlayScene::prepareUpdate), 1.f);
    }
    
    void PlayScene::pauseScene()
    {
        this->isPaused = true;
        for (const auto &child : this->getChildren()) {
            if (child->getName() != "MusicButton" && child->getName() != "SoundsButton" &&
                child->getName() != "PauseBackButton" && child->getName() != "BackHomeButton" &&
                child->getName() != "RetryButton") {
                child->pause();
            }
        }
    }
    
    void PlayScene::resumeScene()
    {
        this->isPaused = false;
        
        for (const auto &child : this->getChildren()) {
            child->resume();
        }
    }
    
    void PlayScene::prepareUpdate(float delta)
    {
        if (! this->isPaused) {
            if (this->prepareTime == 0) {
                this->prepareDone();
            } else {
                std::stringstream timeString;
                -- this->prepareTime;
                timeString << this->prepareTime;
                this->prepareLabel->setString(timeString.str());
                timeString.str("");
            }
        }
    }
    
    void PlayScene::prepareDone()
    {
        unschedule(CC_SCHEDULE_SELECTOR(PlayScene::prepareUpdate));
        this->removeChild(this->prepareLabel);
        log("Start!!");
        this->playTime = 0.f;
        this->road0CurrentIndex = 0;
        this->road1CurrentIndex = 0;
        this->road2CurrentIndex = 0;
        this->initConfig();
        this->timeBarUp->setVisible(true);
        this->timeBarUp->runProgress(10.f);
        this->timeBar->runAction(ProgressTo::create(10.f, 100));
        schedule(CC_SCHEDULE_SELECTOR(PlayScene::gameUpdate), 0.1f);
        schedule(CC_SCHEDULE_SELECTOR(PlayScene::road0Update), 0.1f);
        schedule(CC_SCHEDULE_SELECTOR(PlayScene::road1Update), 0.1f);
        schedule(CC_SCHEDULE_SELECTOR(PlayScene::road2Update), 0.1f);
    }
    
    void PlayScene::road0Update(float delta)
    {
        if (! this->isPaused) {
            if (this->road0CurrentIndex < this->road0TimeConfig.size()) {
                if (this->playTime >= this->road0TimeConfig.at(this->road0CurrentIndex)) {
                    ++this->road0CurrentIndex;
                    int availabelIndex = this->road0AvailableIndex.back();
                    this->road0AvailableIndex.pop_back();
                    auto rat = this->road0RatVector.at(availabelIndex);
                    rat->setPosition(Vec2(180, 1480));
                    rat->run();
                }
            }
        }
    }
    
    void PlayScene::road1Update(float delta)
    {
        if (! this->isPaused) {
            if (this->road1CurrentIndex < this->road1TimeConfig.size()) {
                if (this->playTime >= this->road1TimeConfig.at(this->road1CurrentIndex)) {
                    ++this->road1CurrentIndex;
                    int availabelIndex = this->road1AvailableIndex.back();
                    this->road1AvailableIndex.pop_back();
                    auto rat = this->road1RatVector.at(availabelIndex);
                    rat->setPosition(Vec2(540, 1480));
                    rat->run();
                }
            }
        }
    }
    
    void PlayScene::road2Update(float delta)
    {
        if (! this->isPaused) {
            if (this->road2CurrentIndex < this->road2TimeConfig.size()) {
                if (this->playTime >= this->road2TimeConfig.at(this->road2CurrentIndex)) {
                    ++this->road2CurrentIndex;
                    int availabelIndex = this->road2AvailableIndex.back();
                    this->road2AvailableIndex.pop_back();
                    auto rat = this->road2RatVector.at(availabelIndex);
                    rat->setPosition(Vec2(900, 1480));
                    rat->run();
                }
            }
        }
    }
    
    void PlayScene::gameUpdate(float delta)
    {
        if (! this->isPaused) {
            this->playTime += delta;
            if (this->playTime > 10.f) {
                unschedule(schedule_selector(PlayScene::gameUpdate));
                unschedule(schedule_selector(PlayScene::road0Update));
                unschedule(schedule_selector(PlayScene::road1Update));
                unschedule(schedule_selector(PlayScene::road2Update));
                log("End!");
            }
        }
    }
    
    void PlayScene::initConfig()
    {
        this->road0TimeConfig = {
            0.5f,
            0.8f,
            1.0f,
            1.3f,
            1.7f,
            2.2f,
            2.9f,
            3.3f,
            3.5f,
            4.0f,
            4.5f,
            5.1f,
            5.5f,
            6.4f,
            7.1f,
            7.7f,
            7.9f,
            8.5f,
            9.6f
        };
        this->road0TypeConfig = {0, 0};
        
        this->road1TimeConfig = {
            0.9f,
            1.8f,
            2.1f,
            2.5f,
            3.7f,
            4.0f,
            4.5f,
            4.9f,
            5.3f,
            5.5f,
            5.8f,
            6.1f,
            6.5f,
            6.7f,
            7.6f,
            8.1f,
            8.4f
        };
        this->road1TypeConfig = {0, 0};

        this->road2TimeConfig = {
            0.8f,
            1.5f,
            2.3f,
            2.9f,
            3.2f,
            3.6f,
            4.1f,
            4.6f,
            4.9f,
            5.3f,
            5.5f,
            6.0f,
            6.6f,
            7.0f,
            7.4f,
            7.8f,
            8.2f,
            8.9f,
            9.5f
        };
        this->road2TypeConfig = {0, 0};
    }
}
