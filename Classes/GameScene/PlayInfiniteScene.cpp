#include "PlayInfiniteScene.h"
#include "Controller/GameController.h"

namespace GameScene
{
    PlayInfiniteScene::PlayInfiniteScene() : GameScene::PlayBaseScene()
    {
        this->level = 1;
        this->name = "PlayInfiniteScene";
    }
    
    void PlayInfiniteScene::initScene()
    {
        Manager::MusicManager::getInstance()->stopMusic();
        Manager::ScoresManager::getInstance()->initScores();
        this->spriteCache = SpriteFrameCache::getInstance();
        this->spriteCache->addSpriteFramesWithFile("image/Pig0Animation.plist");
        this->spriteCache->addSpriteFramesWithFile("image/Pig1Animation.plist");
        this->spriteCache->addSpriteFramesWithFile("image/Pig2Animation.plist");
        this->spriteCache->addSpriteFramesWithFile("image/MouthAnimation.plist");
        auto spriteManager = Manager::SpriteManager::getInstance();
        std::string backgroundImage = "image/PlayBackground.png";
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
        spriteManager->setWithKey("PlayInfiniteScene_Background", this->playBackground);
        
        this->prepareNumber = new GameSprite::Image("image/PrepareThree.png");
        spriteManager->setWithKey("PlayInfiniteScene_PrepareNumber", this->prepareNumber);
        this->prepareNumber->setPosition(this->center);
        this->addChild(this->prepareNumber, 1);
        this->prepareNumber->setVisible(false);
        
        float runningTime = 3;
        
        // 將各個路線的會用到的甜點物件初始化，每個路線都創造10個甜點。
        for (int i = 0; i < 10; i++) {
            std::vector<std::string> path = {"image/Sweet", "image/Cookie"};
            std::stringstream key;
            int sweetName = rand() % 2;
            int type = rand() % 10;
            int sweetId = i;
            key << path.at(sweetName) << type << ".png";
            this->road0SweetVector.push_back(new GameSprite::Sweet(key.str(), 0, sweetId, runningTime));
            this->road0SweetVector[sweetId]->setPosition(Vec2(-150, -200));
            this->addChild(this->road0SweetVector[sweetId], 3);
            this->road0AvailableIndex.push_back(sweetId);
            key.clear();
            key.str("");
            type = rand() % 10;
            sweetName = rand() % 2;
            key << path.at(sweetName) << type << ".png";
            this->road1SweetVector.push_back(new GameSprite::Sweet(key.str(), 1, sweetId, runningTime));
            this->road1SweetVector[sweetId]->setPosition(Vec2(-150, -200));
            this->addChild(this->road1SweetVector[sweetId], 3);
            this->road1AvailableIndex.push_back(sweetId);
            key.clear();
            key.str("");
            type = rand() % 10;
            sweetName = rand() % 2;
            key << path.at(sweetName) << type << ".png";
            this->road2SweetVector.push_back(new GameSprite::Sweet(key.str(), 2, sweetId, runningTime));
            this->road2SweetVector[sweetId]->setPosition(Vec2(-150, -200));
            this->addChild(this->road2SweetVector[sweetId], 3);
            this->road2AvailableIndex.push_back(sweetId);
        }

        this->ghost = new GameSprite::Image("image/Ghost.png");
        spriteManager->setWithKey("PlayInfiniteScene_Ghost", this->ghost);
        
        this->road0EatBlock = new GameSprite::Image("image/EatBlock.png");
        this->road0EatBlock->setPosition(this->getEatBlockPosition(0));
        this->road0EatBlock->setOpacity(150);
        this->addChild(this->road0EatBlock, 1);
        spriteManager->setWithKey("PlayInfiniteScene_Road0EatBlock", this->road0EatBlock);
        this->road1EatBlock = new GameSprite::Image("image/EatBlock.png");
        this->road1EatBlock->setPosition(this->getEatBlockPosition(1));
        this->road1EatBlock->setOpacity(150);
        this->addChild(this->road1EatBlock, 1);
        spriteManager->setWithKey("PlayInfiniteScene_Road1EatBlock", this->road1EatBlock);
        this->road2EatBlock = new GameSprite::Image("image/EatBlock.png");
        this->road2EatBlock->setPosition(this->getEatBlockPosition(2));
        this->road2EatBlock->setOpacity(150);
        this->addChild(this->road2EatBlock, 1);
        spriteManager->setWithKey("PlayInfiniteScene_Road2EatBlock", this->road2EatBlock);
        
        this->road0Pig = new Pig(pig0Image, 0, 0);
        this->road0Pig->setPosition(this->getPigPosition(0));
        this->road0Pig->recordPigPosition(this->road0Pig->getPosition());
        this->addChild(this->road0Pig, 2);
        spriteManager->setWithKey("PlayInfiniteScene_Road0Pig", this->road0Pig);
        this->road1Pig = new Pig(pig1Image, 1, 1);
        this->road1Pig->setPosition(this->getPigPosition(1));
        this->road1Pig->recordPigPosition(this->road1Pig->getPosition());
        this->addChild(this->road1Pig, 2);
        spriteManager->setWithKey("PlayInfiniteScene_Road1Pig", this->road1Pig);
        this->road2Pig = new Pig(pig2Image, 2, 2);
        this->road2Pig->setPosition(this->getPigPosition(2));
        this->road2Pig->recordPigPosition(this->road2Pig->getPosition());
        this->addChild(this->road2Pig, 2);
        spriteManager->setWithKey("PlayInfiniteScene_Road2Pig", this->road2Pig);
        
        this->road0Cloud = new Cloud(cloud0Image);
        this->road0Cloud->setPosition(this->getCloudPosition(0));
        this->addChild(this->road0Cloud, 20);
        spriteManager->setWithKey("PlayInfiniteScene_Road0Cloud", this->road0Cloud);
        this->road1Cloud = new Cloud(cloud1Image);
        this->road1Cloud->setPosition(this->getCloudPosition(1));
        this->addChild(this->road1Cloud, 20);
        spriteManager->setWithKey("PlayInfiniteScene_Road1Cloud", this->road1Cloud);
        this->road2Cloud = new Cloud(cloud2Image);
        this->road2Cloud->setPosition(this->getCloudPosition(2));
        this->addChild(this->road2Cloud, 20);
        spriteManager->setWithKey("PlayInfiniteScene_Road2Cloud", this->road2Cloud);
        
        this->scoreHalo = new GameSprite::Image(scoreHaloImage);
        this->scoreHalo->setPosition(this->getScoreHaloPosition());
        this->scoreHalo->setOpacity(0);
        spriteManager->setWithKey("PlayInfiniteScene_ScoreHalo", this->scoreHalo);
        this->addChild(this->scoreHalo, 21);
        
        this->scores = Manager::ScoresManager::getInstance()->getScoresLabel();
        this->scores->setPosition(this->getScoresPosition());
        this->scores->setColor(Color3B(255, 114, 18));
        this->addChild(this->scores, 23);
        
        this->levelUpNotification = Label::createWithTTF("Level 1", "fonts/KOMIKAX.ttf", 250);
        this->levelUpNotification->setPosition(Vec2(this->center.x, this->center.y + 150));
        this->levelUpNotification->setColor(Color3B(255, 53, 6));
        this->levelUpNotification->retain();
        this->addChild(this->levelUpNotification, 24);
        this->levelUpNotification->setOpacity(0);
    }
    
    void PlayInfiniteScene::releaseScene()
    {
        this->removeAllChildren();
        auto spriteManager = Manager::SpriteManager::getInstance();
        spriteManager->releaseByKey("PlayInfiniteScene_Background");
        spriteManager->releaseByKey("PlayInfiniteScene_PrepareNumber");
        spriteManager->releaseByKey("PlayInfiniteScene_Ghost");
        spriteManager->releaseByKey("PlayInfiniteScene_Road0Pig");
        spriteManager->releaseByKey("PlayInfiniteScene_Road1Pig");
        spriteManager->releaseByKey("PlayInfiniteScene_Road2Pig");
        spriteManager->releaseByKey("PlayInfiniteScene_Road0Cloud");
        spriteManager->releaseByKey("PlayInfiniteScene_Road1Cloud");
        spriteManager->releaseByKey("PlayInfiniteScene_Road2Cloud");
        spriteManager->releaseByKey("PlayInfiniteScene_Road0EatBlock");
        spriteManager->releaseByKey("PlayInfiniteScene_Road1EatBlock");
        spriteManager->releaseByKey("PlayInfiniteScene_Road2EatBlock");
        spriteManager->releaseByKey("PlayInfiniteScene_ScoreHalo");
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
        this->levelUpNotification->release();
    }
    
    void PlayInfiniteScene::addWinScene(){}
    
    void PlayInfiniteScene::addLoseScene()
    {
        auto controller = Controller::GameController::getInstance();
        this->deadExplode->release();
        this->deadPig->release();
        controller->addFinalScoreSceneToCurrentScene(this->scores->getString());
    }
    
    void PlayInfiniteScene::pauseScene()
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
    
    void PlayInfiniteScene::resumeScene()
    {
        this->isPaused = false;
        Manager::MusicManager::getInstance()->resumeMusic();
        for (const auto &child : this->getChildren()) {
            child->resume();
        }
    }
    
    void PlayInfiniteScene::play()
    {
        this->prepareTime = 4;
        this->addSweetRoad = -1;
        this->playTime = 0;
        this->sweetRunSpeed = 3.0f;
        this->sweetPerSecond = 1.6f;
        this->addSweetTime = 1 / this->sweetPerSecond;
        this->levelUpSweetNumber = 20;
        this->levelUpSweetCounter = 0;
        this->levelUpNow = false;
        schedule(CC_SCHEDULE_SELECTOR(PlayInfiniteScene::prepareUpdate), 1.f);
    }
    
    void PlayInfiniteScene::prepareUpdate(float delta)
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

    void PlayInfiniteScene::prepareDone()
    {
        unschedule(CC_SCHEDULE_SELECTOR(PlayInfiniteScene::prepareUpdate));
        this->prepareNumber->runAction(Sequence::create(FadeOut::create(1.5f),
                                                        CallFunc::create(CC_CALLBACK_0(PlayInfiniteScene::removePrepareNumber, this)),
                                                        NULL));
        log("Start!!");
        this->road0Pig->addEventListener();
        this->road1Pig->addEventListener();
        this->road2Pig->addEventListener();
        
        Manager::MusicManager::getInstance()->playMusic("audio/music/MerryGo(30s).caf");
        schedule(CC_SCHEDULE_SELECTOR(PlayInfiniteScene::gameUpdate), 0.1f);
        schedule(CC_SCHEDULE_SELECTOR(PlayInfiniteScene::road0Update), 0.1f);
        schedule(CC_SCHEDULE_SELECTOR(PlayInfiniteScene::road1Update), 0.1f);
        schedule(CC_SCHEDULE_SELECTOR(PlayInfiniteScene::road2Update), 0.1f);
        this->road0Pig->wink();
        this->road1Pig->wink();
        this->road2Pig->wink();
    }
    
    void PlayInfiniteScene::road0Update(float delta)
    {
        if (! this->isPaused) {
            // 判斷是否還有甜點需要落下
            if (this->addSweetRoad == 0) {
                this->addSweetRoad = -1;
                int availabelIndex = this->road0AvailableIndex.back();
                this->road0AvailableIndex.pop_back();
                this->road0RunningIndex.push(availabelIndex);
                auto sweet = this->road0SweetVector.at(availabelIndex);
                sweet->setPosition(this->getSweetPosition(0));
                sweet->run();
            }
        }
    }

    void PlayInfiniteScene::road1Update(float delta)
    {
        if (! this->isPaused) {
            // 判斷是否還有甜點需要落下
            if (this->addSweetRoad == 1) {
                this->addSweetRoad = -1;
                int availabelIndex = this->road1AvailableIndex.back();
                this->road1AvailableIndex.pop_back();
                this->road1RunningIndex.push(availabelIndex);
                auto sweet = this->road1SweetVector.at(availabelIndex);
                sweet->setPosition(this->getSweetPosition(1));
                sweet->run();
            }
        }
    }

    void PlayInfiniteScene::road2Update(float delta)
    {
        if (! this->isPaused) {
            // 判斷是否還有甜點需要落下
            if (this->addSweetRoad == 2) {
                this->addSweetRoad = -1;
                int availabelIndex = this->road2AvailableIndex.back();
                this->road2AvailableIndex.pop_back();
                this->road2RunningIndex.push(availabelIndex);
                auto sweet = this->road2SweetVector.at(availabelIndex);
                sweet->setPosition(this->getSweetPosition(2));
                sweet->run();
            }
        }
    }
    
    void PlayInfiniteScene::gameUpdate(float delta)
    {
        if (! this->isPaused) {
            if (! this->levelUpNow) {
                this->playTime += delta;
            }
            if (this->playTime > this->addSweetTime) {
                this->playTime = 0;
                this->addSweetRoad = rand() % 3;
                this->levelUpSweetCounter ++;
                if (this->levelUpSweetCounter >= this->levelUpSweetNumber) {
                    this->levelUpNow = true;
                    this->runAction(Sequence::create(
                                        DelayTime::create(this->sweetRunSpeed),
                                        CallFunc::create(CC_CALLBACK_0(PlayInfiniteScene::levelUp, this)),
                                        NULL)
                                    );
                }
            }
        }
        if (! this->isPaused) {
            // 有任何一隻豬的生命歸0，則遊戲結束，玩家闖關失敗
            if (this->road0Pig->hp <= 0 || this->road1Pig->hp <= 0 || this->road2Pig->hp <= 0) {
                Manager::MusicManager::getInstance()->stopMusic();
                unschedule(schedule_selector(PlayInfiniteScene::gameUpdate));
                unschedule(schedule_selector(PlayInfiniteScene::road0Update));
                unschedule(schedule_selector(PlayInfiniteScene::road1Update));
                unschedule(schedule_selector(PlayInfiniteScene::road2Update));
                int failRoadIndex = 0;
                if (this->road1Pig->hp <= 0) {
                    failRoadIndex = 1;
                } else if (this->road2Pig->hp <= 0) {
                    failRoadIndex = 2;
                }
                for (const auto &child : this->getChildren()) {
                    child->pause();
                }
                this->failRoadIndex = failRoadIndex;
                int highScore = DB::NewHighScoreSetting::getInstance()->getHighScore();
                int currentScore = atoi(this->scores->getString().c_str());
                if (highScore < currentScore) {
                    DB::NewHighScoreSetting::getInstance()->updateHighScore(currentScore);
                }
                this->showFailAnimation();
            }
        }
    }
    
    void PlayInfiniteScene::updateScoreBarStar()
    {
    }
    
    void PlayInfiniteScene::levelUp()
    {
        this->level ++;
        std::stringstream levelString;
        levelString << "Level " << this->level;
        this->levelUpNotification->setString(levelString.str());
        this->levelUpNotification->setOpacity(255);
        this->levelUpNotification->setScale(0.1f);
        this->levelUpNotification->runAction(Sequence::create(ScaleTo::create(0.3f, 1.f), FadeOut::create(0.3f) ,NULL));
        this->sweetRunSpeed = this->sweetRunSpeed - this->sweetRunSpeed / 10;
        this->sweetPerSecond = this->sweetRunSpeed + 0.3;
        this->addSweetTime = 1 / this->sweetPerSecond;
        this->levelUpSweetCounter = 0;
        this->levelUpSweetNumber += 5;
        for (int i = 0; i < 10; i++) {
            this->road0SweetVector[i]->setRunningTime(this->sweetRunSpeed);
            this->road1SweetVector[i]->setRunningTime(this->sweetRunSpeed);
            this->road2SweetVector[i]->setRunningTime(this->sweetRunSpeed);
        }
        this->levelUpNow = false;
    }
}
