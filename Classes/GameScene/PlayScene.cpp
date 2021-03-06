#include "PlayScene.h"
#include "Controller/GameController.h"

namespace GameScene
{
    PlayScene::PlayScene(int pEpisodeNumber, int pStageNumber) : GameScene::PlayBaseScene()
    {
        this->name = "PlayScene";
        this->episodeNumber = pEpisodeNumber;
        this->stageNumber = pStageNumber;
        this->isVictory = false;
        this->overGameTime = LevelDeisgner::getInstance()->loadGameOverTimeSetting(this->episodeNumber, this->stageNumber);
        this->alreadycompleteStar = 0;
        this->alreadyComplete = false;
        this->isNewHighScore = false;
        this->newHighScoreDiff = 0;
        this->failRoadIndex = 0;
        
        // 取得目前關卡在DB中已獲得的星星數，如果不是0代表玩家已破過該關卡，此次為重新挑戰。
        int starResult = DB::StarSetting::getInstance()->getStarNumber(this->episodeNumber, this->stageNumber);
        CCLOG("Star Result %d, %d, %d",this->episodeNumber, this->stageNumber, starResult);
        if (starResult != 0) {
            this->alreadyComplete = true;
            this->alreadycompleteStar = starResult;
        }
    }
    
    void PlayScene::initScene()
    {
        Manager::MusicManager::getInstance()->stopMusic();
        Manager::ScoresManager::getInstance()->initScores();
        this->spriteCache = SpriteFrameCache::getInstance();
        this->spriteCache->addSpriteFramesWithFile("image/Pig0Animation.plist");
        this->spriteCache->addSpriteFramesWithFile("image/Pig1Animation.plist");
        this->spriteCache->addSpriteFramesWithFile("image/Pig2Animation.plist");
        this->spriteCache->addSpriteFramesWithFile("image/MouthAnimation.plist");
        auto spriteManager = Manager::SpriteManager::getInstance();
        std::vector<int> backgroundNumberVector = {
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
            2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
            3, 3, 3, 3, 3,
            4, 4, 4, 4, 4,
            5,
            6};
        int randomBackgroundId = backgroundNumberVector.at(rand() % 42);
        std::stringstream backgroundKey;
        backgroundKey << "image/PlayBackground_" << randomBackgroundId << ".png";
        std::string backgroundImage = backgroundKey.str();
        std::string progressBarDownImage = "image/ProgressBarDown.png";
        std::string progressBarUpImage = "image/ProgressBarUp.png";
        std::string pauseButtonImage = "image/PauseButton.png";
        std::string pauseBackgroundImage = "image/SettingBackground.png";
        std::string musicButtonImage = "image/MusicOnButton.png";
        std::string soundsButtonImage = "image/SoundsOnButton.png";
        std::string backHomeButtonImage = "image/BackHomeButton.png";
        std::string retryButtonImage = "image/RetryButton.png";
        std::string pauseBackButtonImage = "image/BackButton.png";
        std::string pig0Image = "Pig0Animation_0.png";
        std::string pig1Image = "Pig1Animation_0.png";
        std::string pig2Image = "Pig2Animation_0.png";
        std::string cloud0Image = "image/Cloud0.png";
        std::string cloud1Image = "image/Cloud1.png";
        std::string cloud2Image = "image/Cloud2.png";
        std::string scoreHaloImage = "image/ScoreHalo.png";
        
        this->playBackground = new GameSprite::Background(backgroundImage);
        this->playBackground->setPosition(this->getBackgroundPosition());
        this->addChild(this->playBackground, 0);
        spriteManager->setWithKey("PlayScene_Background", this->playBackground);
        
        this->progressBarDown = new GameSprite::ProgressBarDown(progressBarDownImage);
        this->progressBarDown->setPosition(this->getProgressPosition());
        this->addChild(progressBarDown, 6);
        spriteManager->setWithKey("PlayScene_ProgressBarDown", this->progressBarDown);
        
        this->progressBarUp = new GameSprite::ProgressBarUp(progressBarUpImage);
        spriteManager->setWithKey("PlayScene_ProgressBarUp", this->progressBarUp);
        
        this->timeBar = ProgressTimer::create(this->progressBarUp);
        this->timeBar->setType(ProgressTimer::Type::BAR);
        this->timeBar->setMidpoint(Vec2(0,0));
        this->timeBar->setBarChangeRate(Vec2(1, 0));
        this->addChild(this->timeBar, 7);
        this->timeBar->retain();
        this->timeBar->setPosition(this->getProgressPosition());
        
        this->prepareNumber = new GameSprite::Image("image/PrepareThree.png");
        spriteManager->setWithKey("PlayScene_ProgressNumber", this->prepareNumber);
        this->prepareNumber->setPosition(this->center);
        this->addChild(this->prepareNumber, 1);
        this->prepareNumber->setVisible(false);
        float runningTime = LevelDeisgner::getInstance()->loadSweetSpeedSetting(this->episodeNumber, this->stageNumber);
        // 將各個路線的會用到的甜點物件初始化，每個路線都創造10個甜點。
        for (int i = 0; i < 10; i++) {
            std::string path = "image/Sweet";
            if (this->episodeNumber == 1) {
                path = "image/Cookie";
            }
            std::stringstream key;
            int type = rand() % 10;
            int sweetId = i;
            key << path << type << ".png";
            this->road0SweetVector.push_back(new GameSprite::Sweet(key.str(), 0, sweetId, runningTime));
            this->road0SweetVector[sweetId]->setPosition(Vec2(-150, -200));
            this->addChild(this->road0SweetVector[sweetId], 3);
            this->road0AvailableIndex.push_back(sweetId);
            key.clear();
            key.str("");
            type = rand() % 10;
            key << path << type << ".png";
            this->road1SweetVector.push_back(new GameSprite::Sweet(key.str(), 1, sweetId, runningTime));
            this->road1SweetVector[sweetId]->setPosition(Vec2(-150, -200));
            this->addChild(this->road1SweetVector[sweetId], 3);
            this->road1AvailableIndex.push_back(sweetId);
            key.clear();
            key.str("");
            type = rand() % 10;
            key << path << type << ".png";
            this->road2SweetVector.push_back(new GameSprite::Sweet(key.str(), 2, sweetId, runningTime));
            this->road2SweetVector[sweetId]->setPosition(Vec2(-150, -200));
            this->addChild(this->road2SweetVector[sweetId], 3);
            this->road2AvailableIndex.push_back(sweetId);
        }
        
        this->ghost = new GameSprite::Image("image/Ghost.png");
        spriteManager->setWithKey("PlayScene_Ghost", this->ghost);
        
        this->road0EatBlock = new GameSprite::Image("image/EatBlock.png");
        this->road0EatBlock->setPosition(this->getEatBlockPosition(0));
        this->road0EatBlock->setOpacity(150);
        this->addChild(this->road0EatBlock, 1);
        spriteManager->setWithKey("PlayScene_Road0EatBlock", this->road0EatBlock);
        this->road1EatBlock = new GameSprite::Image("image/EatBlock.png");
        this->road1EatBlock->setPosition(this->getEatBlockPosition(1));
        this->road1EatBlock->setOpacity(150);
        this->addChild(this->road1EatBlock, 1);
        spriteManager->setWithKey("PlayScene_Road1EatBlock", this->road1EatBlock);
        this->road2EatBlock = new GameSprite::Image("image/EatBlock.png");
        this->road2EatBlock->setPosition(this->getEatBlockPosition(2));
        this->road2EatBlock->setOpacity(150);
        this->addChild(this->road2EatBlock, 1);
        spriteManager->setWithKey("PlayScene_Road2EatBlock", this->road2EatBlock);
        
        this->road0Pig = new Pig(pig0Image, 0, 0);
        this->road0Pig->setPosition(this->getPigPosition(0));
        this->road0Pig->recordPigPosition(this->road0Pig->getPosition());
        this->addChild(this->road0Pig, 2);
        spriteManager->setWithKey("PlayScene_Road0Pig", this->road0Pig);
        this->road1Pig = new Pig(pig1Image, 1, 1);
        this->road1Pig->setPosition(this->getPigPosition(1));
        this->road1Pig->recordPigPosition(this->road1Pig->getPosition());
        this->addChild(this->road1Pig, 2);
        spriteManager->setWithKey("PlayScene_Road1Pig", this->road1Pig);
        this->road2Pig = new Pig(pig2Image, 2, 2);
        this->road2Pig->setPosition(this->getPigPosition(2));
        this->road2Pig->recordPigPosition(this->road2Pig->getPosition());
        this->addChild(this->road2Pig, 2);
        spriteManager->setWithKey("PlayScene_Road2Pig", this->road2Pig);
        
        this->road0Cloud = new Cloud(cloud0Image);
        this->road0Cloud->setPosition(this->getCloudPosition(0));
        this->addChild(this->road0Cloud, 5);
        spriteManager->setWithKey("PlayScene_Road0Cloud", this->road0Cloud);
        this->road1Cloud = new Cloud(cloud1Image);
        this->road1Cloud->setPosition(this->getCloudPosition(1));
        this->addChild(this->road1Cloud, 5);
        spriteManager->setWithKey("PlayScene_Road1Cloud", this->road1Cloud);
        this->road2Cloud = new Cloud(cloud2Image);
        this->road2Cloud->setPosition(this->getCloudPosition(2));
        this->addChild(this->road2Cloud, 5);
        spriteManager->setWithKey("PlayScene_Road2Cloud", this->road2Cloud);
        
        this->scoreHalo = new GameSprite::Image(scoreHaloImage);
        this->scoreHalo->setPosition(this->getScoreHaloPosition());
        this->scoreHalo->setOpacity(0);
        spriteManager->setWithKey("PlayScene_ScoreHalo", this->scoreHalo);
        this->addChild(this->scoreHalo, 21);
        
        this->scoreRightStar = new GameSprite::ScoreStar();
        this->scoreRightStar->setPosition(this->getScoreStarPosition(2));
        spriteManager->setWithKey("PlayScene_ScoreRightStar", this->scoreRightStar);
        this->addChild(this->scoreRightStar, 22);
        
        this->scoreLeftStar = new GameSprite::ScoreStar();
        this->scoreLeftStar->setPosition(this->getScoreStarPosition(0));
        spriteManager->setWithKey("PlayScene_ScoreLeftStar", this->scoreLeftStar);
        this->addChild(this->scoreLeftStar, 22);
        
        this->scoreMiddleStar = new GameSprite::ScoreStar();
        this->scoreMiddleStar->setPosition(this->getScoreStarPosition(1));
        spriteManager->setWithKey("PlayScene_ScoreMiddleStar", this->scoreMiddleStar);
        this->addChild(this->scoreMiddleStar, 22);
        
        this->scores = Manager::ScoresManager::getInstance()->getScoresLabel();
        this->scores->setPosition(this->getScoresPosition());
        this->scores->setColor(Color3B(255, 114, 18));
        this->addChild(this->scores, 23);
        
        this->timesUp = new GameSprite::Image("image/TimesUp.png");
        this->timesUp->setPosition(this->getTimesUpPosition());
        spriteManager->setWithKey("PlayScene_TimesUp", this->timesUp);
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
        spriteManager->releaseByKey("PlayScene_ProgressNumber");
        spriteManager->releaseByKey("PlayScene_Ghost");
        spriteManager->releaseByKey("PlayScene_Road0Pig");
        spriteManager->releaseByKey("PlayScene_Road1Pig");
        spriteManager->releaseByKey("PlayScene_Road2Pig");
        spriteManager->releaseByKey("PlayScene_Road0Cloud");
        spriteManager->releaseByKey("PlayScene_Road1Cloud");
        spriteManager->releaseByKey("PlayScene_Road2Cloud");
        
        spriteManager->releaseByKey("PlayScene_Road0EatBlock");
        spriteManager->releaseByKey("PlayScene_Road1EatBlock");
        spriteManager->releaseByKey("PlayScene_Road2EatBlock");
        
        spriteManager->releaseByKey("PlayScene_ScoreHalo");
        spriteManager->releaseByKey("PlayScene_ScoreRightStar");
        spriteManager->releaseByKey("PlayScene_ScoreLeftStar");
        spriteManager->releaseByKey("PlayScene_ScoreMiddleStar");
        spriteManager->releaseByKey("PlayScene_TimesUp");
        Manager::ScoresManager::getInstance()->releaseScores();
        
        for (int i = 0; i < 10; i++) {
            this->road0SweetVector[i]->release();
            this->road1SweetVector[i]->release();
            this->road2SweetVector[i]->release();
        }
        this->spriteCache->removeSpriteFramesFromFile("image/Pig0Animation.plist");
        this->spriteCache->removeSpriteFramesFromFile("image/Pig1Animation.plist");
        this->spriteCache->removeSpriteFramesFromFile("image/Pig2Animation.plist");
        this->spriteCache->removeSpriteFramesFromFile("image/MouthAnimation.plist");
    }
    
    bool PlayScene::getIsPaused()
    {
        return this->isPaused;
    }
    
    bool PlayScene::getIsVictory()
    {
        return this->isVictory;
    }
    
    bool PlayScene::getIsNewHighScore()
    {
        return this->isNewHighScore;
    }
    
    int PlayScene::getNewHighScoreDiff()
    {
        return this->newHighScoreDiff;
    }
    
    bool PlayScene::getAlreadyComplete()
    {
        return this->alreadyComplete;
    }
    
    void PlayScene::play()
    {
        this->isPaused = false;
        this->prepareTime = 4;
        this->lastSweetRoad = -1;
        
        schedule(CC_SCHEDULE_SELECTOR(PlayScene::prepareUpdate), 1.f);
    }
    
    void PlayScene::addWinScene()
    {
        int newScore = this->calculateScores();
        Controller::GameController::getInstance()->addVictorySceneToCurrentScene(newScore);
        Manager::SoundsManager::getInstance()->playSound("audio/sounds/Victory.caf");
    }
    
    void PlayScene::addLoseScene()
    {
        auto controller = Controller::GameController::getInstance();
        this->deadExplode->release();
        this->deadPig->release();
        controller->addLoseSceneToCurrentScene();
        Manager::SoundsManager::getInstance()->playSound("audio/sounds/Lose.caf");
    }
    
    void PlayScene::pauseScene()
    {
        Manager::MusicManager::getInstance()->pauseMusic();
        this->isPaused = true;
        // 將該場景中所有的子物件取出，除了暫停場景裡的物件，其他的都進行並暫停
        for (const auto &child : this->getChildren()) {
            if (child->getName() != "MusicButton" && child->getName() != "SoundsButton" &&
                child->getName() != "PauseBackButton" && child->getName() != "BackHomeButton" &&
                child->getName() != "RetryButton" && child->getName() != "PauseMask" &&
                child->getName() != "PauseBackground") {
                child->pause();
            }
        }
    }
    
    void PlayScene::resumeScene()
    {
        this->isPaused = false;
        Manager::MusicManager::getInstance()->resumeMusic();
        for (const auto &child : this->getChildren()) {
            child->resume();
        }
    }
    
    void PlayScene::prepareUpdate(float delta)
    {
        // 更新倒數計時
        if (! this->isPaused) {
            if (this->prepareTime == 0) {
                this->prepareDone();
            } else {
                std::string imagePath;
                -- this->prepareTime;
                switch (this->prepareTime) {
                    case 3:
                        Manager::SoundsManager::getInstance()->playSound("audio/sounds/Timer321.caf");
                        this->prepareNumber->setVisible(true);
                        return;
                        break;
                    case 2 :
                        imagePath = "image/PrepareTwo.png";
                        Manager::SoundsManager::getInstance()->playSound("audio/sounds/Timer321.caf");
                        break;
                    case 1 :
                        imagePath = "image/PrepareOne.png";
                        Manager::SoundsManager::getInstance()->playSound("audio/sounds/Timer321.caf");
                        break;
                    case 0 :
                        imagePath = "image/PrepareGo.png";
                        Manager::SoundsManager::getInstance()->playSound("audio/sounds/TimerGo.caf");
                    break;
                }
                auto texture = TextureCreator::getInstance()->getAutoSizeTexture2d(imagePath);
                this->prepareNumber->setTexture(texture);
            }
        }
    }
    
    void PlayScene::prepareDone()
    {
        unschedule(CC_SCHEDULE_SELECTOR(PlayScene::prepareUpdate));
        this->prepareNumber->runAction(Sequence::create(FadeOut::create(1.5f),
                                                        CallFunc::create(CC_CALLBACK_0(PlayScene::removePrepareNumber, this)),
                                                        NULL));
        log("Start!!");
        this->road0Pig->addEventListener();
        this->road1Pig->addEventListener();
        this->road2Pig->addEventListener();
        this->playTime = 0.f;
        this->road0CurrentIndex = 0;
        this->road1CurrentIndex = 0;
        this->road2CurrentIndex = 0;
        this->initLevelSetting();
        
        
        std::vector<std::string> musicMap = {"BattyMcFaddin", "MerryGo", "RoyalBanana", "RunAmok", "WagonWheel"};
        int randMusicId = rand() % 5;
        if (this->overGameTime == 30) {
            Manager::MusicManager::getInstance()->playMusicNoLoop("audio/music/MerryGo(30s).mp3");
        } else {
            std::stringstream musicName;
            int musicLength = (int)this->overGameTime;
            musicName << "audio/music/" << musicMap.at(randMusicId) << "(" <<  musicLength << "s).mp3";
            Manager::MusicManager::getInstance()->playMusicNoLoop(musicName.str().c_str());
            CCLOG("Play Game Music : %s", musicName.str().c_str());
        }
        this->progressBarUp->setVisible(true);
        this->timeBar->runAction(ProgressTo::create(this->overGameTime, 100));
        schedule(CC_SCHEDULE_SELECTOR(PlayScene::gameUpdate), 0.1f);
        schedule(CC_SCHEDULE_SELECTOR(PlayScene::road0Update), 0.1f);
        schedule(CC_SCHEDULE_SELECTOR(PlayScene::road1Update), 0.1f);
        schedule(CC_SCHEDULE_SELECTOR(PlayScene::road2Update), 0.1f);
        this->road0Pig->wink();
        this->road1Pig->wink();
        this->road2Pig->wink();
    }

    void PlayScene::gameUpdate(float delta)
    {
        if (! this->isPaused) {
            this->playTime += delta;
            // 時間結束玩家尚未lose，代表玩家獲勝
            if (this->playTime > this->overGameTime) {
                unschedule(schedule_selector(PlayScene::gameUpdate));
                unschedule(schedule_selector(PlayScene::road0Update));
                unschedule(schedule_selector(PlayScene::road1Update));
                unschedule(schedule_selector(PlayScene::road2Update));
                for (const auto &child : this->getChildren()) {
                    child->pause();
                }
                log("Victory!");
                this->isVictory = true;
                // 取得最多章節數與每章節最多的關卡數，-1主要目的是該變數要用來當作索引判斷
                int maxStage = DB::StageSetting::getInstance()->getMax() - 1;
                int maxEpisode = DB::EpisodeSetting::getInstance()->getMax() - 1;
                int newStage;
                int newEpisode;
                int newScore = this->calculateScores();
                
                // 如果該關卡已經被破過了(玩家不是第一次破此關卡)
                if (this->alreadyComplete == true) {
                    int oldScore = DB::StarSetting::getInstance()->getStarNumber(this->episodeNumber, this->stageNumber);
                    if (oldScore < newScore) {
                        this->isNewHighScore = true;
                        this->newHighScoreDiff = newScore - oldScore;
                        DB::StarSetting::getInstance()->updateStar(this->episodeNumber, this->stageNumber, newScore);
                    }
                    this->showTimesUp();
                    return;
                    // 如果該關卡是最後一章節的最後一關
                } else if (this->episodeNumber == maxEpisode && this->stageNumber == maxStage) {
                    DB::StarSetting::getInstance()->insertStar(this->episodeNumber, this->stageNumber, newScore);
                    this->isNewHighScore = true;
                    this->newHighScoreDiff = newScore;
                    this->showTimesUp();
                    return;
                    // 如果該關卡是第一章的第一關
                } else if (this->episodeNumber == 0 && this->stageNumber == 0) {
                    this->isNewHighScore = true;
                    this->newHighScoreDiff = newScore;
                    newStage = this->stageNumber + 1;
                    newEpisode = this->episodeNumber;
                    DB::StarSetting::getInstance()->updateStar(this->episodeNumber, this->stageNumber, newScore);
                    DB::StageSetting::getInstance()->updateCurrent(newStage);
                    DB::EpisodeSetting::getInstance()->updateCurrent(newEpisode);
                    this->showTimesUp();
                    return;
                    // 如果該關卡是某章節的最後一關
                } else if (this->stageNumber == maxStage) {
                    this->isNewHighScore = false;
                    this->newHighScoreDiff = 0;
                    newStage = 0;
                    newEpisode = this->episodeNumber + 1;
                    // 非以上條件時
                } else {
                    this->isNewHighScore = true;
                    this->newHighScoreDiff = newScore;
                    newStage = this->stageNumber + 1;
                    newEpisode = this->episodeNumber;
                }
                DB::StarSetting::getInstance()->insertStar(this->episodeNumber, this->stageNumber, newScore);
                DB::StageSetting::getInstance()->updateCurrent(newStage);
                DB::EpisodeSetting::getInstance()->updateCurrent(newEpisode);
                this->showTimesUp();
                return;
            }
            // 有任何一隻豬的生命歸0，則遊戲結束，玩家闖關失敗
            if (this->road0Pig->hp <= 0 || this->road1Pig->hp <= 0 || this->road2Pig->hp <= 0) {
                Manager::MusicManager::getInstance()->stopMusic();
                unschedule(schedule_selector(PlayScene::gameUpdate));
                unschedule(schedule_selector(PlayScene::road0Update));
                unschedule(schedule_selector(PlayScene::road1Update));
                unschedule(schedule_selector(PlayScene::road2Update));
                int failRoadIndex = 0;
                if (this->road1Pig->hp <= 0) {
                    failRoadIndex = 1;
                } else if (this->road2Pig->hp <= 0) {
                    failRoadIndex = 2;
                }
                for (const auto &child : this->getChildren()) {
                    child->pause();
                }
                log("Lose!");
                this->isVictory = false;
                this->failRoadIndex = failRoadIndex;
                this->showFailAnimation();
            }
        }
    }
    
    void PlayScene::road0Update(float delta)
    {
        if (! this->isPaused) {
            // 判斷是否還有甜點需要落下
            if (this->road0CurrentIndex < this->road0TimeConfig.size()) {
                // 判斷該時間點是否有甜點需要落下
                if (this->playTime >= this->road0TimeConfig.at(this->road0CurrentIndex)) {
                    ++this->road0CurrentIndex;
                    int availabelIndex = this->road0AvailableIndex.back();
                    this->road0AvailableIndex.pop_back();
                    this->road0RunningIndex.push_back(availabelIndex);
                    auto sweet = this->road0SweetVector.at(availabelIndex);
                    if (this->checkBombTiming(0)) {
                        sweet->setBomb();
                    }
                    this->lastSweetRoad = 0;
                    sweet->setPosition(this->getSweetPosition(0));
                    sweet->run();
                }
            }
        }
    }
    
    void PlayScene::road1Update(float delta)
    {
        if (! this->isPaused) {
            // 判斷是否還有甜點需要落下
            if (this->road1CurrentIndex < this->road1TimeConfig.size()) {
                // 判斷該時間點是否有甜點需要落下
                if (this->playTime >= this->road1TimeConfig.at(this->road1CurrentIndex)) {
                    ++this->road1CurrentIndex;
                    int availabelIndex = this->road1AvailableIndex.back();
                    this->road1AvailableIndex.pop_back();
                    this->road1RunningIndex.push_back(availabelIndex);
                    auto sweet = this->road1SweetVector.at(availabelIndex);
                    if (this->checkBombTiming(1)) {
                        sweet->setBomb();
                    }
                    this->lastSweetRoad = 1;
                    sweet->setPosition(this->getSweetPosition(1));
                    sweet->run();
                }
            }
        }
    }
    
    void PlayScene::road2Update(float delta)
    {
        if (! this->isPaused) {
            // 判斷是否還有甜點需要落下
            if (this->road2CurrentIndex < this->road2TimeConfig.size()) {
                // 判斷該時間點是否有甜點需要落下
                if (this->playTime >= this->road2TimeConfig.at(this->road2CurrentIndex)) {
                    ++this->road2CurrentIndex;
                    int availabelIndex = this->road2AvailableIndex.back();
                    this->road2AvailableIndex.pop_back();
                    this->road2RunningIndex.push_back(availabelIndex);
                    auto sweet = this->road2SweetVector.at(availabelIndex);
                    if (this->checkBombTiming(2)) {
                        sweet->setBomb();
                    }
                    this->lastSweetRoad = 2;
                    sweet->setPosition(this->getSweetPosition(2));
                    sweet->run();
                }
            }
        }
    }
    
    void PlayScene::updateScoreBarStar()
    {
        int starNumber = this->calculateScores();
        if (starNumber == 1 && this->scoreLeftStar->isLight == false) {
            this->scoreLeftStar->setLight();
        }
        if (starNumber == 2 && this->scoreMiddleStar->isLight == false) {
            this->scoreMiddleStar->setLight();
        }
        if (starNumber == 3 && this->scoreRightStar->isLight == false) {
            this->scoreRightStar->setLight();
        }
    }
    
    int PlayScene::calculateScores()
    {
        int totalScores = Manager::ScoresManager::getInstance()->getScores();
        std::vector<int> starForScoresSet = LevelDeisgner::getInstance()->loadStarAndScoresSetting(this->episodeNumber, this->stageNumber);
        
        if (totalScores >= starForScoresSet.at(0) && totalScores < starForScoresSet.at(1)) {
            return 1;
        }
        if (totalScores >= starForScoresSet.at(1) && totalScores < starForScoresSet.at(2)) {
            return 2;
        }
        if (totalScores >= starForScoresSet.at(2)) {
            return 3;
        }
        return 0;
    }
    
    void PlayScene::showTimesUp()
    {
        this->timesUp->setScale(0.1f);
        this->addChild(this->timesUp, 100);
        this->timesUp->runAction(Sequence::create(ScaleTo::create(0.3f, 1.f),
                                                  DelayTime::create(0.8f),
                                                  FadeOut::create(0.5f),
                                                  DelayTime::create(0.5f),
                                                  CallFunc::create(CC_CALLBACK_0(PlayScene::addWinScene, this)),
                                                  NULL));
        Manager::SoundsManager::getInstance()->playSound("audio/sounds/TimesUp.caf");
    }
    
    void PlayScene::initLevelSetting()
    {
        this->road0TimeConfig = LevelDeisgner::getInstance()->loadSweetTimingSetting(this->episodeNumber, this->stageNumber, 0);
        this->road1TimeConfig = LevelDeisgner::getInstance()->loadSweetTimingSetting(this->episodeNumber, this->stageNumber, 1);
        this->road2TimeConfig = LevelDeisgner::getInstance()->loadSweetTimingSetting(this->episodeNumber, this->stageNumber, 2);
    }
    
    Vec2 PlayScene::getProgressPosition()
    {
        return Vec2(480, this->visibleOrigin.y + this->visibleSize.height - this->visibleSize.width / 11);
    }
    
    
    Vec2 PlayScene::getScoreStarPosition(int index)
    {
        int x = 0;
        switch (index) {
            case 0:
                x = 865;
                break;
            case 1:
                x = 925;
                break;
            case 2:
                x = 985;
                break;
            default:
                break;
        }
        
        return Vec2(x, this->visibleOrigin.y + this->visibleSize.height - this->visibleSize.width / 11 + 40);
    }
    
    Vec2 PlayScene::getTimesUpPosition()
    {
        return Vec2(this->center.x, this->center.y + 100);
    }

    bool PlayScene::checkBombTiming(int road)
    {
        if (this->lastSweetRoad == road) {
            return false;
        } else {
            int bombRandom = rand() % 7;
            if (bombRandom == 4) {
                return true;
            }
        }
        return false;
    }
}
