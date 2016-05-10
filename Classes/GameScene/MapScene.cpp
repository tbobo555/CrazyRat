#include "MapScene.h"


namespace GameScene
{
    MapScene::MapScene(int pMapNumber) : GameScene::BaseScene()
    {
        this->name = "MapScene";
        this->mapMumber = pMapNumber;
    }
    
    void MapScene::initScene()
    {
        auto spriteManager = Manager::SpriteManager::getInstance();
        std::string backgroundImagePrefix = "image/EpisodeBackground_";
        std::string stageButtonImagePrefix = "image/StageButton_";
        std::string backButtonImage = "image/BackButton.png";
        std::string starImage = "image/Star.png";
        std::string masterImage = "image/Master.png";
        int currentMap = DB::CommonSetting::currentMap;
        int currentStage = DB::CommonSetting::currentStage;
        std::vector<int> starOfStage = DB::CommonSetting::starOfStage.at(this->mapMumber);
        std::stringstream backgroundPath;
        backgroundPath << backgroundImagePrefix << this->mapMumber << ".png";
        this->mapBackground = new GameSprite::Background(backgroundPath.str());
        this->mapBackButton = new GameSprite::BackButton(backButtonImage);
        this->mapBackground->setPosition(this->center);
        this->mapBackButton->setPosition(this->getBackButtonPosition());
        this->addChild(this->mapBackground, 0);
        this->addChild(this->mapBackButton, 1);
        std::stringstream key;
        key << "MapScene_Background_" << this->mapMumber;
        spriteManager->setWithKey(key.str(), this->mapBackground);
        key.clear();
        key.str("");
        key << "MapScene_BackButton_" << this->mapMumber;
        spriteManager->setWithKey(key.str(), this->mapBackButton);
        key.clear();
        key.str("");
        if (this->mapMumber == currentMap) {
            this->master = new GameSprite::Master(masterImage);
            this->master->setPosition(
                this->getMasterPosition(currentStage, currentMap)
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
            auto stageButton = new GameSprite::StageButton(stagePath.str(), this->mapMumber, i);
            if (this->mapMumber == currentMap && i > currentStage) {
                stageButton->locked();
            } else if (
                this->mapMumber < currentMap ||
                (this->mapMumber == currentMap && i < currentStage)
            ) {
                int starNum = starOfStage.at(i);
                for (int j = 0; j < starNum; j++) {
                    auto star = new GameSprite::Star(starImage);
                    star->setPosition(this->getStarPosition(i, this->mapMumber, j));
                    this->addChild(star, 3);
                    key << "MapScene_Star_" << this->mapMumber << "_" << i << "_" << j;
                    spriteManager->setWithKey(key.str(), star);
                    key.clear();
                    key.str("");
                }
            }
            this->stageButtonVector.push_back(stageButton);
            stageButton->setPosition(
                this->getStageButtonPosition(i, this->mapMumber)
            );
            this->addChild(stageButton, 2);
            key << "MapScene_Stage_" << this->mapMumber << "_" << i;
            spriteManager->setWithKey(key.str(), stageButton);
        }
    }
    
    void MapScene::releaseScene()
    {
        this->removeAllChildren();
        auto spriteManager = Manager::SpriteManager::getInstance();
        int currentMap = DB::CommonSetting::currentMap;
        int currentStage = DB::CommonSetting::currentStage;
        std::vector<int> starOfStage = DB::CommonSetting::starOfStage.at(this->mapMumber);
        std::stringstream key;
        key << "MapScene_Background_" << this->mapMumber;
        spriteManager->releaseByKey(key.str());
        key.clear();
        key.str("");
        key << "MapScene_BackButton_" << this->mapMumber;
        spriteManager->releaseByKey(key.str());
        key.clear();
        key.str("");
        if (this->mapMumber == currentMap) {
            spriteManager->releaseByKey("Master");
        }
        int maxStage = DB::CommonSetting::maxStage;
        for (int i = 0; i < maxStage; i++) {
            key.clear();
            key.str("");
            if (this->mapMumber < currentMap || (this->mapMumber == currentMap && i < currentStage)) {
                int starNum = starOfStage.at(i);
                for (int j = 0; j < starNum; j++) {
                    key << "MapScene_Star_" << this->mapMumber << "_" << i << "_" << j;
                    spriteManager->releaseByKey(key.str());
                    key.clear();
                    key.str("");
                }
            }
            key << "MapScene_Stage_" << this->mapMumber << "_" << i;
            spriteManager->releaseByKey(key.str());
        }
    }
    
    Vec2 MapScene::getStageButtonPosition(int stageNumber, int mapNumber)
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
        return stageButtonPositionSet[mapNumber][stageNumber];
    }
    
    Vec2 MapScene::getMasterPosition(int currentStage, int currentMap)
    {
        Vec2 position = this->getStageButtonPosition(currentStage, currentMap);
        return Vec2(position.x, position.y + 100);
    }
    
    Vec2 MapScene::getStarPosition(int stageNumber, int mapNumber, int starNumber)
    {
        Vec2 position = this->getStageButtonPosition(stageNumber, mapNumber);
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
    
    Vec2 MapScene::getBackButtonPosition()
    {
        auto imageConfig = ImageConfig::getInstance();
        auto position = Vec2(
            this->rightBottom.x - imageConfig->getImageSize("BackButton").width * 0.6,
            this->rightBottom.y + imageConfig->getImageSize("BackButton").height * 0.6);
        return position;
    }

}
