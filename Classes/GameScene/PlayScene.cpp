#include "PlayScene.h"
#include <iostream>

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
        std::string timeBarDownImage = "image/TimeBarDown.png";
        std::string timeBarUpImage = "image/TimeBarUp.png";
        this->playBackground = new GameSprite::Background(backgroundImage);
        this->playBackground->setPosition(this->center);
        this->addChild(this->playBackground, 0);
        spriteManager->setWithKey("PlayScene_Background", this->playBackground);
        
        this->timeBarDown = new GameSprite::TimeBarDown(timeBarDownImage);
        this->timeBarDown->setPosition(Vec2(800, this->visibleOrigin.y + 70));
        this->addChild(timeBarDown, 1);
        
        this->timeBarUp = new GameSprite::TimeBarUp(timeBarUpImage);

        
        this->prepareLabel = Label::createWithTTF("3", "fonts/arial.ttf", 100);
        this->prepareLabel->setPosition(this->center);
        this->addChild(this->prepareLabel, 1);

        for (int i = 0; i < 10; i++) {
            int ratId = i;
            this->road0RatVector.push_back(new GameSprite::Rat("image/Rat.png", 0, 0, ratId));
            this->road0RatVector[ratId]->setPosition(Vec2(-150, -200));
            this->addChild(this->road0RatVector[ratId], 3);
            this->road0AvailableIndex.push_back(ratId);
        }
        
        for (int i = 0; i < 10; i++) {
            int ratId = i;
            this->road1RatVector.push_back(new GameSprite::Rat("image/Rat.png", 0, 1, ratId));
            this->road1RatVector[ratId]->setPosition(Vec2(-150, -200));
            this->addChild(this->road1RatVector[ratId], 3);
            this->road1AvailableIndex.push_back(ratId);
        }

        for (int i = 0; i < 10; i++) {
            int ratId = i;
            this->road2RatVector.push_back(new GameSprite::Rat("image/Rat.png", 0, 2, ratId));
            this->road2RatVector[ratId]->setPosition(Vec2(-150, -200));
            this->addChild(this->road2RatVector[ratId], 3);
            this->road2AvailableIndex.push_back(ratId);
        }
    }
    
    void PlayScene::releaseScene()
    {
        this->removeAllChildren();
        auto spriteManager = Manager::SpriteManager::getInstance();
        spriteManager->releaseByKey("PlayScene_Background");
    }
    
    void PlayScene::play()
    {
        this->prepareTime = 3;
        schedule(CC_SCHEDULE_SELECTOR(PlayScene::prepareUpdate), 1.f);
    }
    
    void PlayScene::prepareUpdate(float delta)
    {
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
        
        auto progressBar = ProgressTimer::create(this->timeBarUp);
        progressBar->setType(ProgressTimer::Type::BAR);
        progressBar->setMidpoint(Vec2(0,0));
        progressBar->setBarChangeRate(Vec2(1, 0));
        this->addChild(progressBar, 2);
        progressBar->setPosition(Vec2(800, this->visibleOrigin.y + 70));
        progressBar->runAction(ProgressTo::create(10.f, 100));
        
        schedule(CC_SCHEDULE_SELECTOR(PlayScene::gameUpdate), 0.1f);
        schedule(CC_SCHEDULE_SELECTOR(PlayScene::road0Update), 0.1f);
        schedule(CC_SCHEDULE_SELECTOR(PlayScene::road1Update), 0.1f);
        schedule(CC_SCHEDULE_SELECTOR(PlayScene::road2Update), 0.1f);
    }
    
    void PlayScene::road0Update(float delta)
    {
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
    
    void PlayScene::road1Update(float delta)
    {
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
    
    void PlayScene::road2Update(float delta)
    {
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
    
    void PlayScene::gameUpdate(float delta)
    {
        this->playTime += delta;
        if (this->playTime > 10.f) {
            unschedule(schedule_selector(PlayScene::gameUpdate));
            unschedule(schedule_selector(PlayScene::road0Update));
            unschedule(schedule_selector(PlayScene::road1Update));
            unschedule(schedule_selector(PlayScene::road2Update));
            log("End!");
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
