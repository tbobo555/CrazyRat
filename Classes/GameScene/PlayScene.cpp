#include "PlayScene.h"
#include "Controller/GameController.h"

namespace GameScene
{
    PlayScene::PlayScene(int pMapNumber, int pStageNumber) : GameScene::BaseScene()
    {
        this->name = "PlayScene";
        this->mapNumber = pMapNumber;
        this->stageNumber = pStageNumber;
        this->isVictory = false;
    }
    
    void PlayScene::initScene()
    {
        auto spriteManager = Manager::SpriteManager::getInstance();
        std::string backgroundImage = "image/PlayBackground.png";
        std::string progressBarDownImage = "image/ProgressBarDown.png";
        std::string progressBarUpImage = "image/ProgressBarUp.png";
        std::string pauseButtonImage = "image/PauseButton.png";
        std::string pauseBackgroundImage = "image/SettingBackground.png";
        std::string musicButtonImage = "image/MusicOnButton.png";
        std::string soundsButtonImage = "image/SoundsOnButton.png";
        std::string backHomeButtonImage = "image/BackHomeButton.png";
        std::string retryButtonImage = "image/RetryButton.png";
        std::string pauseBackButtonImage = "image/BackButton.png";
        std::string pig0Image = "image/Pig0.png";
        std::string pig1Image = "image/Pig1.png";
        std::string pig2Image = "image/Pig2.png";
        
        this->playBackground = new GameSprite::Background(backgroundImage);
        this->playBackground->setPosition(this->center);
        this->addChild(this->playBackground, 0);
        spriteManager->setWithKey("PlayScene_Background", this->playBackground);
        
        this->progressBarDown = new GameSprite::ProgressBarDown(progressBarDownImage);
        this->progressBarDown->setPosition(Vec2(800, this->visibleOrigin.y + 70));
        this->addChild(progressBarDown, 1);
        spriteManager->setWithKey("PlayScene_ProgressBarDown", this->progressBarDown);
        
        this->progressBarUp = new GameSprite::ProgressBarUp(progressBarUpImage);
        spriteManager->setWithKey("PlayScene_ProgressBarUp", this->progressBarUp);
        
        this->timeBar = ProgressTimer::create(this->progressBarUp);
        this->timeBar->setType(ProgressTimer::Type::BAR);
        this->timeBar->setMidpoint(Vec2(0,0));
        this->timeBar->setBarChangeRate(Vec2(1, 0));
        this->addChild(this->timeBar, 2);
        this->timeBar->retain();
        this->timeBar->setPosition(Vec2(800, this->visibleOrigin.y + 70));
        
        this->prepareLabel = Label::createWithTTF("3", "fonts/arial.ttf", 100);
        this->prepareLabel->setPosition(this->center);
        this->prepareLabel->retain();
        this->addChild(this->prepareLabel, 1);

        for (int i = 0; i < 10; i++) {
            std::string path = "image/Sweet";
            std::stringstream key;
            int type = rand() % 3;
            int sweetId = i;
            key << path << type << ".png";
            this->road0SweetVector.push_back(new GameSprite::Sweet(key.str(), 0, sweetId));
            this->road0SweetVector[sweetId]->setPosition(Vec2(-150, -200));
            this->addChild(this->road0SweetVector[sweetId], 3);
            this->road0AvailableIndex.push_back(sweetId);
            key.clear();
            key.str("");
            type = rand() % 3;
            key << path << type << ".png";
            this->road1SweetVector.push_back(new GameSprite::Sweet(key.str(), 1, sweetId));
            this->road1SweetVector[sweetId]->setPosition(Vec2(-150, -200));
            this->addChild(this->road1SweetVector[sweetId], 3);
            this->road1AvailableIndex.push_back(sweetId);
            key.clear();
            key.str("");
            type = rand() % 3;
            key << path << type << ".png";
            this->road2SweetVector.push_back(new GameSprite::Sweet(key.str(), 2, sweetId));
            this->road2SweetVector[sweetId]->setPosition(Vec2(-150, -200));
            this->addChild(this->road2SweetVector[sweetId], 3);
            this->road2AvailableIndex.push_back(sweetId);
        }
        
        this->road0Pig = new Pig(pig0Image, 0);
        this->road0Pig->setPosition(Vec2(180, 480));
        this->addChild(this->road0Pig, 2);
        spriteManager->setWithKey("PlayScene_Road0Pig", this->road0Pig);
        this->road1Pig = new Pig(pig1Image, 1);
        this->road1Pig->setPosition(Vec2(540, 480));
        this->addChild(this->road1Pig, 2);
        spriteManager->setWithKey("PlayScene_Road1Pig", this->road1Pig);
        this->road2Pig = new Pig(pig2Image, 2);
        this->road2Pig->setPosition(Vec2(900, 480));
        this->addChild(this->road2Pig, 2);
        spriteManager->setWithKey("PlayScene_Road2Pig", this->road2Pig);
    }
    
    bool PlayScene::getIsPaused()
    {
        return this->isPaused;
    }
    
    bool PlayScene::getIsVictory()
    {
        return this->isVictory;
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
        spriteManager->releaseByKey("PlayScene_ProgressBarDown");
        spriteManager->releaseByKey("PlayScene_ProgressBarUp");
        this->timeBar->release();
        this->prepareLabel->release();
        spriteManager->releaseByKey("PlayScene_Road0Pig");
        spriteManager->releaseByKey("PlayScene_Road1Pig");
        spriteManager->releaseByKey("PlayScene_Road2Pig");
        for (int i = 0; i < 10; i++) {
            this->road0SweetVector[i]->release();
            this->road1SweetVector[i]->release();
            this->road2SweetVector[i]->release();
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
        this->progressBarUp->setVisible(true);
        this->progressBarUp->runProgress(10.f);
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
                    this->road0RunningIndex.push(availabelIndex);
                    auto sweet = this->road0SweetVector.at(availabelIndex);
                    sweet->setPosition(Vec2(180, 1480));
                    sweet->run();
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
                    this->road1RunningIndex.push(availabelIndex);
                    auto sweet = this->road1SweetVector.at(availabelIndex);
                    sweet->setPosition(Vec2(540, 1480));
                    sweet->run();
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
                    this->road2RunningIndex.push(availabelIndex);
                    auto sweet = this->road2SweetVector.at(availabelIndex);
                    sweet->setPosition(Vec2(900, 1480));
                    sweet->run();
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
                for (const auto &child : this->getChildren()) {
                    child->pause();
                }
                log("Victory!");
                this->isVictory = true;
                auto controller = Controller::GameController::getInstance();
                controller->addVictorySceneToCurrentScene();
            }
            if (this->road0Pig->hp <= 0 || this->road1Pig->hp <= 0 || this->road2Pig->hp <= 0) {
                unschedule(schedule_selector(PlayScene::gameUpdate));
                unschedule(schedule_selector(PlayScene::road0Update));
                unschedule(schedule_selector(PlayScene::road1Update));
                unschedule(schedule_selector(PlayScene::road2Update));
                for (const auto &child : this->getChildren()) {
                    child->pause();
                }
                log("Lose!");
                this->isVictory = false;
                auto controller = Controller::GameController::getInstance();
                controller->addLoseSceneToCurrentScene();
            }
        }
    }
    
    GameSprite::Sweet* PlayScene::getNearestSweet(int road)
    {
        if (road == 0 && ! this->road0RunningIndex.empty()) {
            return this->road0SweetVector.at(this->road0RunningIndex.front());
        } else if (road == 1 && ! this->road2RunningIndex.empty()) {
            return this->road1SweetVector.at(this->road1RunningIndex.front());
        } else if (road == 2 && ! this->road2RunningIndex.empty()) {
            return this->road2SweetVector.at(this->road2RunningIndex.front());
        } else {
            return nullptr;
        }
    }
    
    int PlayScene::getNearestSweetIndex(int road)
    {
        if (road == 0 && ! this->road0RunningIndex.empty()) {
            return this->road0RunningIndex.front();
        } else if (road == 1 && ! this->road2RunningIndex.empty()) {
            return this->road1RunningIndex.front();
        } else if (road == 2 && ! this->road2RunningIndex.empty()) {
            return this->road2RunningIndex.front();
        } else {
            return -1;
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
    }
}
