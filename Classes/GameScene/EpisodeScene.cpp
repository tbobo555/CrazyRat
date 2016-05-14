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
        this->episodeBackground->setPosition(this->center);
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
                this->getMasterPosition(currentStage, currentEpisode)
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
            if (this->episodeNumber == currentEpisode && i > currentStage) {
                stageButton->locked();
            } else if (
                this->episodeNumber < currentEpisode ||
                (this->episodeNumber == currentEpisode && i < currentStage)
            ) {
                int starNum = starOfStage.at(i);
                for (int j = 0; j < starNum; j++) {
                    auto star = new GameSprite::Star(starImage);
                    star->setPosition(this->getStarPosition(i, this->episodeNumber, j));
                    this->addChild(star, 3);
                    key << "EpisodeScene_Star_" << this->episodeNumber << "_" << i << "_" << j;
                    spriteManager->setWithKey(key.str(), star);
                    key.clear();
                    key.str("");
                }
            }
            this->stageButtonVector.push_back(stageButton);
            stageButton->setPosition(
                this->getStageButtonPosition(i, this->episodeNumber)
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
    
    Vec2 EpisodeScene::getStageButtonPosition(int stageNumber, int episodeNumber)
    {
        std::vector<std::vector<Vec2>> stageButtonPositionSet = {
            {
                {Vec2(165, 1100)},
                {Vec2(550, 1100)},
                {Vec2(930, 1100)},
                {Vec2(165, 650)},
                {Vec2(550, 650)},
            },
            {
                {Vec2(165, 1100)},
                {Vec2(550, 1100)},
                {Vec2(930, 1100)},
                {Vec2(165, 650)},
                {Vec2(550, 650)},
            },
            {
                {Vec2(165, 1100)},
                {Vec2(550, 1100)},
                {Vec2(930, 1100)},
                {Vec2(165, 650)},
                {Vec2(550, 650)},
            },
            {
                {Vec2(165, 1100)},
                {Vec2(550, 1100)},
                {Vec2(930, 1100)},
                {Vec2(165, 650)},
                {Vec2(550, 650)},
            },
            {
                {Vec2(165, 1100)},
                {Vec2(550, 1100)},
                {Vec2(930, 1100)},
                {Vec2(165, 650)},
                {Vec2(550, 650)},
            },
            {
                {Vec2(165, 1100)},
                {Vec2(550, 1100)},
                {Vec2(930, 1100)},
                {Vec2(165, 650)},
                {Vec2(550, 650)},
            }
        };
        return stageButtonPositionSet[episodeNumber][stageNumber];
    }
    
    Vec2 EpisodeScene::getMasterPosition(int currentStage, int currentEpisode)
    {
        Vec2 position = this->getStageButtonPosition(currentStage, currentEpisode);
        return Vec2(position.x, position.y + 100);
    }
    
    Vec2 EpisodeScene::getStarPosition(int stageNumber, int episodeNumber, int starNumber)
    {
        Vec2 position = this->getStageButtonPosition(stageNumber, episodeNumber);
        position.y += 50;
        switch (starNumber) {
            case 0:
                position.x -= 35;
                break;
            case 1:
                break;
            case 2:
                position.x += 35;
                break;
            default:
                break;
        }
        return position;
    }
    
    Vec2 EpisodeScene::getBackButtonPosition()
    {
        auto imageConfig = ImageConfig::getInstance();
        auto position = Vec2(
            this->rightBottom.x - imageConfig->getImageSize("BackButton").width * 0.6,
            this->rightBottom.y + imageConfig->getImageSize("BackButton").height * 0.6);
        return position;
    }

}
