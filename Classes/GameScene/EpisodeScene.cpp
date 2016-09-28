#include "EpisodeScene.h"


namespace GameScene
{
    EpisodeScene::EpisodeScene(int pEpisodeNumber) : GameScene::BaseScene()
    {
        this->name = "EpisodeScene";
        this->episodeNumber = pEpisodeNumber;
        this->isNewHighScore = false;
        this->newHighScoreDiff = 0;
        this->newHighScoreStage = -1;
    }
    
    void EpisodeScene::initScene()
    {
        auto spriteManager = Manager::SpriteManager::getInstance();
        std::string backgroundImagePrefix = "image/EpisodeBackground_";
        std::string stageButtonImagePrefix = "image/StageButton_";
        std::string backButtonImage = "image/BackButton.png";
        std::string starImage = "image/Star.png";

        // 取得玩家目前破到第幾章的第幾小關
        // ex: 玩家破到第二章的第三關
        int currentEpisode = DB::EpisodeSetting::getInstance()->getCurrent();
        int currentStage = DB::StageSetting::getInstance()->getCurrent();

        std::vector<int> starOfStage = {0};
        try {
            // 取得玩家選擇的這個章節各關卡的星星數
            starOfStage = DB::StarSetting::getInstance()->getAllStarNumber().at(this->episodeNumber);
        } catch (std::out_of_range ex) {
            
        }

        // 載入並設置背景與返回按鈕
        std::stringstream backgroundPath;
        backgroundPath << backgroundImagePrefix << this->episodeNumber << ".png";
        this->episodeBackground = new GameSprite::Background(backgroundPath.str());
        this->episodeBackButton = new GameSprite::BackButton(backButtonImage);
        this->episodeBackground->setPosition(this->getBackgroundPosition());
        this->episodeBackButton->setPosition(this->getBackButtonPosition());
        this->addChild(this->episodeBackground, 0);
        this->addChild(this->episodeBackButton, 1);
        std::stringstream key;
        key << "EpisodeScene_Background_" << this->episodeNumber;
        spriteManager->setWithKey(key.str(), this->episodeBackground);
        key.clear();
        key.str("");
        key << "EpisodeScene_BackButton_" << this->episodeNumber;
        spriteManager->setWithKey(key.str(), this->episodeBackButton);
        key.clear();
        key.str("");

        // 取得最多的章節數，還有每一章節最多的關卡數
        int maxStage = DB::StageSetting::getInstance()->getMax();
        int maxEpisode = DB::EpisodeSetting::getInstance()->getMax();

        // 創造和配置關卡按鈕
        for (int i = 0; i < maxStage; i++) {
            key.clear();
            key.str("");
            std::stringstream stagePath;
            stagePath << stageButtonImagePrefix << i << ".png";
            // 創建一個關卡按鈕並存到stageButtonVector裡
            auto stageButton = new GameSprite::StageButton(stagePath.str(), this->episodeNumber, i);
            this->stageButtonVector.push_back(stageButton);

            // 當此章節為玩家最新破關的章節，且關卡大於最新破關的關卡，就將關卡按鈕鎖住
            if (this->episodeNumber == currentEpisode && i > currentStage) {
                stageButton->locked();
            // 當章節小於最新破關的章節 或是 章節為最新破關章節但關卡小於最新破關的關卡，就配置該關卡的星星
            } else if (
                this->episodeNumber < currentEpisode ||
                (this->episodeNumber == currentEpisode && i < currentStage)
            ) {
                int starNum = starOfStage.at(i);
                for (int j = 0; j < starNum; j++) {
                    auto star = new GameSprite::Star(starImage);
                    star->setPosition(this->getStarPosition(i, j));
                    stageButton->addChild(star, 4);
                    key << "EpisodeScene_Star_" << this->episodeNumber << "_" << i << "_" << j;
                    spriteManager->setWithKey(key.str(), star);
                    key.clear();
                    key.str("");
                }
            // 當關卡與章節是最後一關時，配置該關卡的星星
            } else if (this->episodeNumber == maxEpisode - 1 && currentStage == maxStage - 1 && i == currentStage) {
                try {
                    int starNum = starOfStage.at(i);
                    for (int j = 0; j < starNum; j++) {
                        auto star = new GameSprite::Star(starImage);
                        star->setPosition(this->getStarPosition(i, j));
                        stageButton->addChild(star, 3);
                        key << "EpisodeScene_Star_" << this->episodeNumber << "_" << i << "_" << j;
                        spriteManager->setWithKey(key.str(), star);
                        key.clear();
                        key.str("");
                    }
                } catch (std::out_of_range ex) {
                    CCLOG("Not complete all level.");
                }

            }
            stageButton->setPosition(
                this->getStageButtonPosition(i)
            );
            this->addChild(stageButton, 2);
            key << "EpisodeScene_Stage_" << this->episodeNumber << "_" << i;
            spriteManager->setWithKey(key.str(), stageButton);
        }
    }
    
    void EpisodeScene::releaseScene()
    {
        this->removeAllChildren();
        auto spriteManager = Manager::SpriteManager::getInstance();
        int currentEpisode = DB::EpisodeSetting::getInstance()->getCurrent();
        int currentStage = DB::StageSetting::getInstance()->getCurrent();
        std::vector<int> starOfStage = {0};
        try {
            starOfStage = DB::StarSetting::getInstance()->getAllStarNumber().at(this->episodeNumber);
        } catch (std::out_of_range ex) {
            
        }
        std::stringstream key;
        key << "EpisodeScene_Background_" << this->episodeNumber;
        spriteManager->releaseByKey(key.str());
        key.clear();
        key.str("");
        key << "EpisodeScene_BackButton_" << this->episodeNumber;
        spriteManager->releaseByKey(key.str());
        key.clear();
        key.str("");
        int maxStage = DB::StageSetting::getInstance()->getMax();
        for (int i = 0; i < maxStage; i++) {
            key.clear();
            key.str("");
            if (this->episodeNumber < currentEpisode || (this->episodeNumber == currentEpisode && i < currentStage)) {
                int starNum = starOfStage.at(i);
                for (int j = 0; j < starNum; j++) {
                    key << "EpisodeScene_Star_" << this->episodeNumber << "_" << i << "_" << j;
                    spriteManager->releaseByKey(key.str());
                    key.clear();
                    key.str("");
                }
            }
            key << "EpisodeScene_Stage_" << this->episodeNumber << "_" << i;
            spriteManager->releaseByKey(key.str());
        }
    }
    
    void EpisodeScene::runStarAnimation()
    {
        // 當玩家獲得最新高分時，會播放星星動畫
        if (this->isNewHighScore && this->newHighScoreStage != -1) {
            Director::getInstance()->getEventDispatcher()->setEnabled(false);
            int starNum = DB::StarSetting::getInstance()->getStarNumber(this->episodeNumber, this->newHighScoreStage);
            auto spriteManager = Manager::SpriteManager::getInstance();
            int firstIndex = starNum - newHighScoreDiff;
            Vec2 buttonPosition = this->getStageButtonPosition(this->newHighScoreStage);
            spriteManager->getByKey("MenuScene_SettingButton")->setVisible(false);
            this->episodeBackButton->cocos2d::Node::setVisible(false);
            CCLOG("newHighScoreDiff : %i", newHighScoreDiff);
            CCLOG("starNum : %i", starNum);
            for (int i = firstIndex; i < starNum; i++) {
                std::stringstream key;
                key << "EpisodeScene_Star_" << this->episodeNumber << "_" << this->newHighScoreStage << "_" << i;
                auto star = spriteManager->getByKey(key.str());
                star->setScale(3.0f);
                star->setPosition(Vec2(this->centerBottom.x - buttonPosition.x, this->centerBottom.y - buttonPosition.y));
                star->runAction(RotateBy::create(0.3f, 1080));
                star->runAction(ScaleTo::create(0.3f, 1.0f));
                star->runAction(MoveTo::create(0.3f, this->getStarPosition(this->newHighScoreStage, i)));
            }
            Manager::SoundsManager::getInstance()->playSound("audio/sounds/ShowSmallStar.caf");
            this->episodeBackground->runAction(Sequence::create(DelayTime::create(1.0f),
                                                         CallFunc::create(CC_CALLBACK_0(EpisodeScene::animationCallback, this)),nullptr));

        }
    }
    
    void EpisodeScene::animationCallback()
    {
        Director::getInstance()->getEventDispatcher()->setEnabled(true);
        auto spriteManager = Manager::SpriteManager::getInstance();
        spriteManager->getByKey("MenuScene_SettingButton")->setVisible(true);
        this->episodeBackButton->cocos2d::Node::setVisible(true);
    }

    
    Vec2 EpisodeScene::getStageButtonPosition(int stageNumber)
    {
        float width = Director::getInstance()->getWinSize().width;
        float height = Director::getInstance()->getWinSize().height;
        std::vector<Vec2> stageButtonPositionSet = {
            {
                Vec2(this->center.x - 2 * width / 5.4, 0.75 * height),
                Vec2(this->center.x - width / 5.4, 0.75 * height),
                Vec2(this->center.x, 0.75 * height),
                Vec2(this->center.x + width / 5.4, 0.75 * height),
                Vec2(this->center.x + 2 * width / 5.4, 0.75 * height),
                
                Vec2(this->center.x - 2 * width / 5.4, 0.75 * height - width / 5.4),
                Vec2(this->center.x - width / 5.4, 0.75 * height - width / 5.4),
                Vec2(this->center.x, 0.75 * height - width / 5.4),
                Vec2(this->center.x + width / 5.4, 0.75 * height - width / 5.4),
                Vec2(this->center.x + 2 * width / 5.4, 0.75 * height - width / 5.4),
                
                Vec2(this->center.x - 2 * width / 5.4, 0.75 * height - 2 * width / 5.4),
                Vec2(this->center.x - width / 5.4, 0.75 * height - 2 * width / 5.4),
                Vec2(this->center.x, 0.75 * height - 2 * width / 5.4),
                Vec2(this->center.x + width / 5.4, 0.75 * height - 2 * width / 5.4),
                Vec2(this->center.x + 2 * width / 5.4, 0.75 * height - 2 * width / 5.4),
                
                Vec2(this->center.x - 2 * width / 5.4, 0.75 * height - 3 * width / 5.4),
                Vec2(this->center.x - width / 5.4, 0.75 * height - 3 * width / 5.4),
                Vec2(this->center.x, 0.75 * height - 3 * width / 5.4),
                Vec2(this->center.x + width / 5.4, 0.75 * height - 3 * width / 5.4),
                Vec2(this->center.x + 2 * width / 5.4, 0.75 * height - 3 * width / 5.4),

            }
        };
        return stageButtonPositionSet[stageNumber];
    }
    
    Vec2 EpisodeScene::getStarPosition(int stageNumber, int starNumber)
    {
        Vec2 position = this->getStageButtonPosition(stageNumber);
        GameSprite::StageButton* stageButton = this->stageButtonVector.at(0);
        float width = stageButton->getContentSize().width;
        float height = stageButton->getContentSize().height;
        Vec2 center = Vec2(width / 2, height / 2);
        Vec2 result = Vec2(0, 0);
        switch (starNumber) {
            case 0:
                result = Vec2(center.x - width / 3, height / 16);
                break;
            case 1:
                result = Vec2(center.x, height / 8);
                break;
            case 2:
                result = Vec2(center.x + width / 3, height / 16);
                break;
            default:
                break;
        }
        return result;
    }
    
    Vec2 EpisodeScene::getBackButtonPosition()
    {
        float width = this->visibleSize.width;
        return Vec2(this->visibleOrigin.x + (width - 150), this->visibleOrigin.y + 150);
    }
    
    Vec2 EpisodeScene::getBackgroundPosition()
    {
        return this->center;
    }

}
