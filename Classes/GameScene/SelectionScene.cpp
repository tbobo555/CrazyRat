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
        std::string episodeButtonImagePrefix = "image/EpisodeButton_";
        std::string backButtonImage = "image/BackButton.png";
        std::string selectionTitleImage = "image/SelectionTitle.png";
        int currentEpisode = DB::EpisodeSetting::getInstance()->getCurrent();
        int maxEpisode = DB::EpisodeSetting::getInstance()->getMax();
        this->selectionBackground = new GameSprite::Background(backgroundImage);
        this->selectionBackground->setPosition(this->getBackgroundPosition());
        this->selectionBackButton = new GameSprite::BackButton(backButtonImage);
        this->selectionBackButton->setPosition(this->getBackButtonPosition());
        this->selectionTitle = new GameSprite::SelectionTitle(selectionTitleImage);
        this->selectionTitle->setPosition(this->getTitlePosition());
        this->addChild(this->selectionBackground, 0);
        this->addChild(this->selectionBackButton, 5);
        this->addChild(this->selectionTitle, 5);
        spriteManager->setWithKey("SelectionScene_Background", this->selectionBackground);
        spriteManager->setWithKey("SelectionScene_BackButton", this->selectionBackButton);
        spriteManager->setWithKey("SelectionScene_SelectionTitle", this->selectionTitle);
        for (int i = 0; i < maxEpisode; i++) {
            std::stringstream filePath;
            filePath << episodeButtonImagePrefix << i << ".png";
            GameSprite::EpisodeButton* episodeButton = new GameSprite::EpisodeButton(filePath.str(), i);
            if (currentEpisode < i) {
                episodeButton->locked();
            }
            this->episodeButtonVector.push_back(episodeButton);
            episodeButton->setPosition(this->getEpisodeButtonPosition(i));
            this->addChild(episodeButton, 1);
            std::stringstream key;
            key << "SelectionScene_EpisodeButton_" << i;
            spriteManager->setWithKey(key.str(), episodeButton);
        }
    }
    
    void SelectionScene::releaseScene()
    {
        this->removeAllChildren();
        auto spriteManager = Manager::SpriteManager::getInstance();
        spriteManager->releaseByKey("SelectionScene_Background");
        spriteManager->releaseByKey("SelectionScene_BackButton");
        spriteManager->releaseByKey("SelectionScene_SelectionTitle");
        int maxEpisode = DB::EpisodeSetting::getInstance()->getMax();
        for (int i = 0; i < maxEpisode; i++) {
            std::stringstream key;
            key << "SelectionScene_EpisodeButton_" << i;
            spriteManager->releaseByKey(key.str());
        }
    }
    
    Vec2 SelectionScene::getBackgroundPosition()
    {
        return this->center;
    }
    
    Vec2 SelectionScene::getTitlePosition()
    {
        return Vec2(this->center.x, this->visibleOrigin.y + 0.85 * this->visibleSize.height);
    }
    
    Vec2 SelectionScene::getBackButtonPosition()
    {
        float width = this->visibleSize.width;
        float height = this->visibleSize.height;
        return Vec2(this->visibleOrigin.x + (width - height / 12), this->visibleOrigin.y + height / 12);
    }
    
    Vec2 SelectionScene::getEpisodeButtonPosition(int episodeNumber)
    {
        float width = Director::getInstance()->getWinSize().width;
        float height = Director::getInstance()->getWinSize().height;
        std::vector<Vec2> episodeButtonPositionSet = {
            {Vec2(height / 10, 7 * height / 12)},
            {Vec2(this->center.x, 7 * height / 12)},
            {Vec2(width - height / 10, 7 * height / 12)},
            {Vec2(height / 10, 5 * height / 12)},
            {Vec2(this->center.x, 5 * height / 12)},
            {Vec2(width - height / 10, 5 * height / 12)},
        };
        
        return episodeButtonPositionSet[episodeNumber];
    }
}
