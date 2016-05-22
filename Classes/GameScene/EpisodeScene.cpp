#include "EpisodeScene.h"


namespace GameScene
{
    EpisodeScene::EpisodeScene(int pEpisodeNumber) : GameScene::BaseScene()
    {
        this->name = "EpisodeScene";
        this->episodeNumber = pEpisodeNumber;
    }
    
    void EpisodeScene::initScene()
    {
        auto spriteManager = Manager::SpriteManager::getInstance();
        std::string backgroundImagePrefix = "image/EpisodeBackground_";
        std::string stageButtonImagePrefix = "image/StageButton_";
        std::string backButtonImage = "image/BackButton.png";
        std::string starImage = "image/Star.png";
        std::string masterImage = "image/Master.png";
        int currentEpisode = DB::CommonSetting::currentEpisode;
        int currentStage = DB::CommonSetting::currentStage;
        std::vector<int> starOfStage = DB::CommonSetting::starOfStage.at(this->episodeNumber);
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
        if (this->episodeNumber == currentEpisode) {
            this->master = new GameSprite::Master(masterImage);
            this->master->setPosition(
                this->getMasterPosition(currentStage)
            );
            this->addChild(this->master, 4);
            spriteManager->setWithKey("Master", this->master);
        }
        int maxStage = DB::CommonSetting::maxStage;
        for (int i = 0; i < maxStage; i++) {
            key.clear();
            key.str("");
            std::stringstream stagePath;
            stagePath << stageButtonImagePrefix << i << ".png";            
            auto stageButton = new GameSprite::StageButton(stagePath.str(), this->episodeNumber, i);
            this->stageButtonVector.push_back(stageButton);
            if (this->episodeNumber == currentEpisode && i > currentStage) {
                stageButton->locked();
            } else if (
                this->episodeNumber < currentEpisode ||
                (this->episodeNumber == currentEpisode && i < currentStage)
            ) {
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
        int currentEpisode = DB::CommonSetting::currentEpisode;
        int currentStage = DB::CommonSetting::currentStage;
        std::vector<int> starOfStage = DB::CommonSetting::starOfStage.at(this->episodeNumber);
        std::stringstream key;
        key << "EpisodeScene_Background_" << this->episodeNumber;
        spriteManager->releaseByKey(key.str());
        key.clear();
        key.str("");
        key << "EpisodeScene_BackButton_" << this->episodeNumber;
        spriteManager->releaseByKey(key.str());
        key.clear();
        key.str("");
        if (this->episodeNumber == currentEpisode) {
            spriteManager->releaseByKey("Master");
        }
        int maxStage = DB::CommonSetting::maxStage;
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
                Vec2(this->center.x, 0.75 * height - 5.4 * width),
                Vec2(this->center.x + width / 5.4, 0.75 * height - width / 5.4),
                Vec2(this->center.x + 2 * width / 5.4, 0.75 * height - width / 5.4),
                
                Vec2(this->center.x - 2 * width / 5.4, 0.75 * height - 2 * width / 5.4),
                Vec2(this->center.x - width / 5.4, 0.75 * height - 2 * width / 5.4),
                Vec2(this->center.x, 0.75 * height - 2 * 5.4 * width),
                Vec2(this->center.x + width / 5.4, 0.75 * height - 2 * width / 5.4),
                Vec2(this->center.x + 2 * width / 5.4, 0.75 * height - 2 * width / 5.4),
            }
        };
        return stageButtonPositionSet[stageNumber];
    }
    
    Vec2 EpisodeScene::getMasterPosition(int currentStage)
    {
        Vec2 position = this->getStageButtonPosition(currentStage);
        return Vec2(position.x, position.y + 100);
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
        float height = this->visibleSize.height;
        return Vec2(this->visibleOrigin.x + (width - height / 12), this->visibleOrigin.y + height / 12);
    }
    
    Vec2 EpisodeScene::getBackgroundPosition()
    {
        return this->center;
    }

}
