#include "ChallengePlayScene.h"

namespace GameScene
{
    ChallengePlayScene::ChallengePlayScene() : PlayBaseScene()
    {
        this->name = "ChallengePlayScene";
    }
    
    void ChallengePlayScene::initScene()
    {
        Manager::MusicManager::getInstance()->stopMusic();
        Manager::ScoresManager::getInstance()->initScores();
        this->spriteCache = SpriteFrameCache::getInstance();
        this->spriteCache->addSpriteFramesWithFile("image/Pig0Animation.plist");
        this->spriteCache->addSpriteFramesWithFile("image/Pig1Animation.plist");
        this->spriteCache->addSpriteFramesWithFile("image/Pig2Animation.plist");
        this->spriteCache->addSpriteFramesWithFile("image/MouthAnimation.plist");
        this->spriteCache->addSpriteFramesWithFile("image/Boss01Animation.plist");
        auto spriteManager = Manager::SpriteManager::getInstance();
        std::stringstream backgroundKey;
        backgroundKey << "image/PlayBackground_" << 0 << ".png";
        std::string backgroundImage = backgroundKey.str();
        std::string pauseButtonImage = "image/PauseButton.png";
        std::string pauseBackgroundImage = "image/SettingBackground.png";
        std::string musicButtonImage = "image/MusicOnButton.png";
        std::string soundsButtonImage = "image/SoundsOnButton.png";
        std::string backHomeButtonImage = "image/BackHomeButton.png";
        std::string retryButtonImage = "image/RetryButton.png";
        std::string pauseBackButtonImage = "image/BackButton.png";
        std::string whiteMaskImage = "image/WhiteMask.png";
        std::string pig0Image = "Pig0Animation_0.png";
        std::string pig1Image = "Pig1Animation_0.png";
        std::string pig2Image = "Pig2Animation_0.png";
        std::string bossImage = "Boss01Animation_0.png";
        
        this->playBackground = new GameSprite::Background(backgroundImage);
        this->playBackground->setPosition(this->getBackgroundPosition());
        this->addChild(this->playBackground, 0);
        this->playBackground->setName("PlayBackground");
        spriteManager->setWithKey("ChallengePlayScene_Background", this->playBackground);
        
        this->prepareNumber = new GameSprite::Image("image/PrepareThree.png");
        spriteManager->setWithKey("ChallengePlayScene_PrepareNumber", this->prepareNumber);
        this->prepareNumber->setPosition(this->center);
        this->addChild(this->prepareNumber, 1);
        this->prepareNumber->setVisible(false);
        
        this->boss = new GameSprite::Boss(bossImage);
        this->boss->setPosition(this->getCloudPosition(1));
        this->addChild(this->boss, 5);
        spriteManager->setWithKey("ChallengePlayScene_Boss", this->boss);
        
        this->whiteMask = new GameSprite::Image(whiteMaskImage);
        this->whiteMask->setPosition(this->center);
        this->addChild(this->whiteMask, 4);
        this->whiteMask->setVisible(false);
        spriteManager->setWithKey("ChallengePlayScene_WhiteMask", this->whiteMask);
        
        float runningTime = 2.5;
        
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
        spriteManager->setWithKey("ChallengePlayScene_Ghost", this->ghost);
        
        this->road0EatBlock = new GameSprite::Image("image/EatBlock.png");
        this->road0EatBlock->setPosition(this->getEatBlockPosition(0));
        this->road0EatBlock->setOpacity(150);
        this->addChild(this->road0EatBlock, 1);
        spriteManager->setWithKey("ChallengePlayScene_Road0EatBlock", this->road0EatBlock);
        this->road1EatBlock = new GameSprite::Image("image/EatBlock.png");
        this->road1EatBlock->setPosition(this->getEatBlockPosition(1));
        this->road1EatBlock->setOpacity(150);
        this->addChild(this->road1EatBlock, 1);
        spriteManager->setWithKey("ChallengePlayScene_Road1EatBlock", this->road1EatBlock);
        this->road2EatBlock = new GameSprite::Image("image/EatBlock.png");
        this->road2EatBlock->setPosition(this->getEatBlockPosition(2));
        this->road2EatBlock->setOpacity(150);
        this->addChild(this->road2EatBlock, 1);
        spriteManager->setWithKey("ChallengePlayScene_Road2EatBlock", this->road2EatBlock);
        
        this->road0Pig = new Pig(pig0Image, 0, 0);
        this->road0Pig->setPosition(this->getPigPosition(0));
        this->road0Pig->recordPigPosition(this->road0Pig->getPosition());
        this->addChild(this->road0Pig, 2);
        spriteManager->setWithKey("ChallengePlayScene_Road0Pig", this->road0Pig);
        this->road1Pig = new Pig(pig1Image, 1, 1);
        this->road1Pig->setPosition(this->getPigPosition(1));
        this->road1Pig->recordPigPosition(this->road1Pig->getPosition());
        this->addChild(this->road1Pig, 2);
        spriteManager->setWithKey("ChallengePlayScene_Road1Pig", this->road1Pig);
        this->road2Pig = new Pig(pig2Image, 2, 2);
        this->road2Pig->setPosition(this->getPigPosition(2));
        this->road2Pig->recordPigPosition(this->road2Pig->getPosition());
        this->addChild(this->road2Pig, 2);
        spriteManager->setWithKey("ChallengePlayScene_Road2Pig", this->road2Pig);
    }
    
    void ChallengePlayScene::releaseScene()
    {
        this->removeAllChildren();
        auto spriteManager = Manager::SpriteManager::getInstance();
        spriteManager->releaseByKey("ChallengePlayScene_Background");
        spriteManager->releaseByKey("ChallengePlayScene_PrepareNumber");
        spriteManager->releaseByKey("ChallengePlayScene_Ghost");
        spriteManager->releaseByKey("ChallengePlayScene_Road0Pig");
        spriteManager->releaseByKey("ChallengePlayScene_Road1Pig");
        spriteManager->releaseByKey("ChallengePlayScene_Road2Pig");
        spriteManager->releaseByKey("ChallengePlayScene_Boss");
        spriteManager->releaseByKey("ChallengePlayScene_Road0EatBlock");
        spriteManager->releaseByKey("ChallengePlayScene_Road1EatBlock");
        spriteManager->releaseByKey("ChallengePlayScene_Road2EatBlock");
        spriteManager->releaseByKey("ChallengePlayScene_WhiteMask");
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
        this->spriteCache->removeSpriteFramesFromFile("image/Bosso1Animation.plist");
    }
    
    void ChallengePlayScene::pauseScene()
    {
        Manager::MusicManager::getInstance()->pauseMusic();
        this->isPaused = true;
        // 將該場景中所有的子物件取出，除了暫停場景裡的物件，其他的都進行並暫停
        for (const auto &child : this->getChildren()) {
            if (child->getName() != "MusicButton" && child->getName() != "SoundsButton" &&
                child->getName() != "PauseBackButton" && child->getName() != "BackHomeButton" &&
                child->getName() != "RetryButton" && child->getName() != "PauseMask" &&
                child->getName() != "PauseBackground" && child->getName() != "PlayBackground") {
                child->pause();
            }
        }
    }
    
    void ChallengePlayScene::resumeScene()
    {
        this->isPaused = false;
        Manager::MusicManager::getInstance()->resumeMusic();
        for (const auto &child : this->getChildren()) {
            child->resume();
        }
    }
    
    void ChallengePlayScene::addWinScene()
    {
        log("Win");
    }
    
    void ChallengePlayScene::addLoseScene(){}

    void ChallengePlayScene::play()
    {
        this->isPaused= false;
        this->prepareTime = 4;
        this->addSweetRoad = -1;
        this->nextSweetRoad = -1;
        this->playTime = 0;
        this->sweetRunSpeed = 2.5f;
        this->sweetPerSecond = 2.0f;
        this->addSweetTime = 1 / this->sweetPerSecond;
        this->lastSweetRoad = -1;
        this->sweetInSameRoadTimes = -1;
        this->bossIsDead = false;
        this->bossIsHurting = false;
        
        schedule(CC_SCHEDULE_SELECTOR(ChallengePlayScene::prepareUpdate), 1.f);
    }

    
    void ChallengePlayScene::prepareUpdate(float delta)
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

    
    void ChallengePlayScene::prepareDone()
    {
        unschedule(CC_SCHEDULE_SELECTOR(ChallengePlayScene::prepareUpdate));
        this->prepareNumber->runAction(Sequence::create(FadeOut::create(1.5f),
                                    CallFunc::create(CC_CALLBACK_0(ChallengePlayScene::removePrepareNumber, this)),NULL));
        log("Start!!");
        this->road0Pig->addEventListener();
        this->road1Pig->addEventListener();
        this->road2Pig->addEventListener();
        
        schedule(CC_SCHEDULE_SELECTOR(ChallengePlayScene::gameUpdate), 0.1f);
        schedule(CC_SCHEDULE_SELECTOR(ChallengePlayScene::road0Update), 0.1f);
        schedule(CC_SCHEDULE_SELECTOR(ChallengePlayScene::road1Update), 0.1f);
        schedule(CC_SCHEDULE_SELECTOR(ChallengePlayScene::road2Update), 0.1f);
        this->road0Pig->wink();
        this->road1Pig->wink();
        this->road2Pig->wink();
    }

    
    void ChallengePlayScene::road0Update(float delta)
    {
        if (! this->isPaused) {
            // 判斷是否還有甜點需要落下
            if (this->addSweetRoad == 0) {
                this->addSweetRoad = -1;
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
    
    void ChallengePlayScene::road1Update(float delta)
    {
        if (! this->isPaused) {
            // 判斷是否還有甜點需要落下
            if (this->addSweetRoad == 1) {
                this->addSweetRoad = -1;
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
    
    void ChallengePlayScene::road2Update(float delta)
    {
        if (! this->isPaused) {
            // 判斷是否還有甜點需要落下
            if (this->addSweetRoad == 2) {
                this->addSweetRoad = -1;
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
    
    void ChallengePlayScene::gameUpdate(float delta)
    {
        if (! this->isPaused) {
            if (! this->bossIsHurting) {
                this->playTime += delta;
                if (this->playTime > this->addSweetTime) {
                    this->playTime = 0;
                    int road = rand() % 3;
                    if (road == this->lastSweetRoad) {
                        this->sweetInSameRoadTimes ++;
                    }
                    if (this->sweetInSameRoadTimes >= 3) {
                        road = (road + 1) % 3;
                        this->sweetInSameRoadTimes = 0;
                    }
                    if (this->addSweetRoad != road) {
                        this->boss->runAction(MoveTo::create(this->addSweetTime, this->getCloudPosition(road)));
                    }
                    this->addSweetRoad = this->nextSweetRoad;
                    this->nextSweetRoad = road;
                }
            }
        }
        
        if (! this->isPaused) {
            if (this->boss->life <= 0) {
                this->bossIsDead = true;
                this->boss->dead();
                unschedule(schedule_selector(ChallengePlayScene::gameUpdate));
                unschedule(schedule_selector(ChallengePlayScene::road0Update));
                unschedule(schedule_selector(ChallengePlayScene::road1Update));
                unschedule(schedule_selector(ChallengePlayScene::road2Update));
                for (const auto &child : this->getChildren()) {
                    if (child->getName() != "PauseBackground" && child->getName() != "PlayBackground") {
                        child->pause();
                    }
                }
                this->showBossDeadAnimation();
            }
        }
        
        if (! this->isPaused) {
            // 有任何一隻豬的生命歸0，則遊戲結束，玩家闖關失敗
            if (this->road0Pig->hp <= 0 || this->road1Pig->hp <= 0 || this->road2Pig->hp <= 0) {
                unschedule(schedule_selector(ChallengePlayScene::gameUpdate));
                unschedule(schedule_selector(ChallengePlayScene::road0Update));
                unschedule(schedule_selector(ChallengePlayScene::road1Update));
                unschedule(schedule_selector(ChallengePlayScene::road2Update));
                int failRoadIndex = 0;
                if (this->road1Pig->hp <= 0) {
                    failRoadIndex = 1;
                } else if (this->road2Pig->hp <= 0) {
                    failRoadIndex = 2;
                }
                for (const auto &child : this->getChildren()) {
                    if (child->getName() != "PauseBackground" && child->getName() != "PlayBackground") {
                        child->pause();
                    }
                }
                this->failRoadIndex = failRoadIndex;
                this->showFailAnimation();
            }
        }
    }

    bool ChallengePlayScene::checkBombTiming(int road)
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
