#include "SelectionScene.h"

namespace GameScene
{
    SelectionScene::SelectionScene() : GameScene::BaseScene()
    {
        this->name = "SelectionScene";
    }
    
    void SelectionScene::initScene()
    {
        auto spriteManager = Manager::SpriteManager::getInstance();
        std::string backgroundImage = "image/SelectionBackground.png";
        std::string mapButtonImagePrefix = "image/EpisodeButton_";
        std::string backButtonImage = "image/BackButton.png";
        int currentMap = DB::CommonSetting::currentMap;
        int maxMap = DB::CommonSetting::maxEpisode;
        this->selectionBackground = new GameSprite::Background(backgroundImage);
        this->selectionBackground->setPosition(this->center);
        this->selectionBackButton = new GameSprite::BackButton(backButtonImage);
        this->selectionBackButton->setPosition(this->getBackButtonPosition());
        this->addChild(this->selectionBackground, 0);
        this->addChild(this->selectionBackButton, 5);
        spriteManager->setWithKey("SelectionScene_Background", this->selectionBackground);
        spriteManager->setWithKey("SelectionScene_BackButton", this->selectionBackButton);
        for (int i = 0; i < maxMap; i++) {
            std::stringstream filePath;
            filePath << mapButtonImagePrefix << i << ".png";
            GameSprite::MapButton* mapButton = new GameSprite::MapButton(filePath.str(), i);
            if (currentMap < i) {
                mapButton->locked();
            }
            this->mapButtonVector.push_back(mapButton);
            mapButton->setPosition(this->getMapButtonPosition(i));
            this->addChild(mapButton, 1);
            std::stringstream key;
            key << "SelectionScene_MapButton_" << i;
            spriteManager->setWithKey(key.str(), mapButton);
        }
    }
    
    void SelectionScene::releaseScene()
    {
        this->removeAllChildren();
        auto spriteManager = Manager::SpriteManager::getInstance();
        spriteManager->releaseByKey("SelectionScene_Background");
        spriteManager->releaseByKey("SelectionScene_BackButton");
        int maxMap = DB::CommonSetting::maxEpisode;
        for (int i = 0; i < maxMap; i++) {
            std::stringstream key;
            key << "SelectionScene_MapButton_" << i;
            spriteManager->releaseByKey(key.str());
        }
    }
    
    Vec2 SelectionScene::getBackButtonPosition()
    {
        auto imageConfig = ImageConfig::getInstance();
        auto position = Vec2(
        this->rightBottom.x - imageConfig->getImageSize("BackButton").width * 0.6,
        this->rightBottom.y + imageConfig->getImageSize("BackButton").height * 0.6);
        log("x %f", this->rightBottom.x);
        log("y %f", this->rightBottom.y);
        return position;
    }
    
    Vec2 SelectionScene::getMapButtonPosition(int mapNumber)
    {
        std::vector<Vec2> mapButtonPositionSet = {
            {Vec2(165, 1100)},
            {Vec2(550, 1100)},
            {Vec2(930, 1100)},
            {Vec2(165, 650)},
            {Vec2(550, 650)},
            {Vec2(930, 650)},
        };
        
        return mapButtonPositionSet[mapNumber];
    }
}
