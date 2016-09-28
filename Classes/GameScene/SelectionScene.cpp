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
        std::string rainbowImage = "image/SelectionSceneRainbow.png";
        std::string moveCloud0Image = "image/SelectionSceneMoveCloud0.png";
        std::string moveCloud1Image = "image/SelectionSceneMoveCloud1.png";
        std::string moveCloud2Image = "image/SelectionSceneMoveCloud2.png";
        std::string moveCloud3Image = "image/SelectionSceneMoveCloud3.png";
        std::string moveCloud4Image = "image/SelectionSceneMoveCloud4.png";
        
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
        this->rainbow = new GameSprite::Image(rainbowImage);
        this->rainbow->setPosition(this->getRainbowPosition());
        this->addChild(this->rainbow, 2);
        this->moveCloud0 = new GameSprite::Image(moveCloud0Image);
        this->moveCloud0->setPosition(this->getMoveCloudPosition(0));
        this->addChild(this->moveCloud0, 1);
        this->moveCloud1 = new GameSprite::Image(moveCloud1Image);
        this->moveCloud1->setPosition(this->getMoveCloudPosition(1));
        this->addChild(this->moveCloud1, 1);
        this->moveCloud2 = new GameSprite::Image(moveCloud2Image);
        this->moveCloud2->setPosition(this->getMoveCloudPosition(2));
        this->addChild(this->moveCloud2, 1);
        this->moveCloud3 = new GameSprite::Image(moveCloud3Image);
        this->moveCloud3->setPosition(this->getMoveCloudPosition(3));
        this->addChild(this->moveCloud3, 1);
        this->moveCloud4 = new GameSprite::Image(moveCloud4Image);
        this->moveCloud4->setPosition(this->getMoveCloudPosition(4));
        this->addChild(this->moveCloud4, 1);
        spriteManager->setWithKey("SelectionScene_Background", this->selectionBackground);
        spriteManager->setWithKey("SelectionScene_BackButton", this->selectionBackButton);
        spriteManager->setWithKey("SelectionScene_SelectionTitle", this->selectionTitle);
        spriteManager->setWithKey("SelectionScene_Rainbow", this->rainbow);
        spriteManager->setWithKey("SelectionScene_MoveCloud0", this->moveCloud0);
        spriteManager->setWithKey("SelectionScene_MoveCloud1", this->moveCloud1);
        spriteManager->setWithKey("SelectionScene_MoveCloud2", this->moveCloud2);
        spriteManager->setWithKey("SelectionScene_MoveCloud3", this->moveCloud3);
        spriteManager->setWithKey("SelectionScene_MoveCloud4", this->moveCloud4);
        for (int i = 0; i < maxEpisode; i++) {
            std::stringstream filePath;
            filePath << episodeButtonImagePrefix << i << ".png";
            GameSprite::EpisodeButton* episodeButton = new GameSprite::EpisodeButton(filePath.str(), i);
            if (currentEpisode < i) {
                episodeButton->locked();
            }
            this->episodeButtonVector.push_back(episodeButton);
            episodeButton->setPosition(this->getEpisodeButtonPosition(i));
            this->addChild(episodeButton, 4);
            std::stringstream key;
            key << "SelectionScene_EpisodeButton_" << i;
            spriteManager->setWithKey(key.str(), episodeButton);
        }
        
        this->unlockedMask = new GameSprite::UnlockedMask("image/Mask.png");
        spriteManager->setWithKey("SelectionScene_UnlockedMask", this->unlockedMask);
        this->unlockedMask->setPosition(Vec2(this->center));
        this->addChild(this->unlockedMask, -100);
        
        this->chapterUnlocked = new GameSprite::Image("image/Chapter1Unlocked.png");
        spriteManager->setWithKey("SelectionScene_ChapterUnlocked", this->chapterUnlocked);
        this->chapterUnlocked->setPosition(this->centerTop);
        this->addChild(this->chapterUnlocked, -100);

    }
    
    void SelectionScene::releaseScene()
    {
        this->removeAllChildren();
        auto spriteManager = Manager::SpriteManager::getInstance();
        spriteManager->releaseByKey("SelectionScene_Background");
        spriteManager->releaseByKey("SelectionScene_BackButton");
        spriteManager->releaseByKey("SelectionScene_SelectionTitle");
        spriteManager->releaseByKey("SelectionScene_Rainbow");
        spriteManager->releaseByKey("SelectionScene_MoveCloud0");
        spriteManager->releaseByKey("SelectionScene_MoveCloud1");
        spriteManager->releaseByKey("SelectionScene_MoveCloud2");
        spriteManager->releaseByKey("SelectionScene_MoveCloud3");
        spriteManager->releaseByKey("SelectionScene_MoveCloud4");
        int maxEpisode = DB::EpisodeSetting::getInstance()->getMax();
        for (int i = 0; i < maxEpisode; i++) {
            std::stringstream key;
            key << "SelectionScene_EpisodeButton_" << i;
            spriteManager->releaseByKey(key.str());
        }
        spriteManager->releaseByKey("SelectionScene_UnlockedMask");
        spriteManager->releaseByKey("SelectionScene_ChapterUnlocked");

    }
    
    void SelectionScene::runConstantAnimation()
    {
        this->moveCloud0->setPosition(this->getMoveCloudPosition(0));
        this->moveCloud1->setPosition(this->getMoveCloudPosition(1));
        this->moveCloud2->setPosition(this->getMoveCloudPosition(2));
        this->moveCloud3->setPosition(this->getMoveCloudPosition(3));
        this->moveCloud4->setPosition(this->getMoveCloudPosition(4));
        auto move100 = MoveBy::create(15.f, Vec2(100, 0));
        auto moveNegative100 = MoveBy::create(15.f, Vec2(-100, 0));
        auto move150 = MoveBy::create(15.f, Vec2(150, 0));
        auto moveNegative150 = MoveBy::create(15.f, Vec2(-150, 0));
        auto repeat100 = RepeatForever::create(
                         Sequence::create(move100, move100->reverse(), moveNegative100, moveNegative100->reverse(), nullptr));
        auto repeat150 = RepeatForever::create(
                         Sequence::create(move150, move150->reverse(), moveNegative150, moveNegative150->reverse(), nullptr));
        this->moveCloud0->runAction(repeat150->clone());
        this->moveCloud1->runAction(repeat100->clone());
        this->moveCloud2->runAction(repeat100->clone());
        this->moveCloud3->runAction(repeat100->clone());
        this->moveCloud4->runAction(repeat150->clone());
    }
    
    void SelectionScene::runUnlockedEpisodeAnimation(int unlockedEpisodeNumber)
    {
        Director::getInstance()->getEventDispatcher()->setEnabled(false);
        std::stringstream key;
        key << "image/Chapter" << unlockedEpisodeNumber << "Unlocked.png";
        TextureCreator* textureCreator = TextureCreator::getInstance();
        Texture2D* unclockedTexutre = textureCreator->getAutoSizeTexture2d(key.str());
        this->chapterUnlocked->setTexture(unclockedTexutre);
        this->chapterUnlocked->setPosition(this->centerTop);
        this->unlockedMask->setLocalZOrder(100);
        this->chapterUnlocked->setLocalZOrder(101);
        this->chapterUnlocked->runAction(Sequence::create(
                                                        MoveTo::create(0.6f, this->center),
                                                        CallFunc::create(CC_CALLBACK_0(SelectionScene::setUnlockedMaskClickable, this)),
                                                        NULL));
    }
    
    void SelectionScene::removeUnlockedSprite()
    {
        this->chapterUnlocked->setLocalZOrder(-100);
        this->unlockedMask->setLocalZOrder(-100);
    }
    
    void SelectionScene::setUnlockedMaskClickable()
    {
        Director::getInstance()->getEventDispatcher()->setEnabled(true);
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
        return Vec2(this->visibleOrigin.x + (width - 150), this->visibleOrigin.y + 150);
    }
    
    Vec2 SelectionScene::getEpisodeButtonPosition(int episodeNumber)
    {
        std::vector<Vec2> episodeButtonPositionSet = {
            {Vec2(280, 900)},
            {Vec2(800, 900)}
        };
        
        return episodeButtonPositionSet[episodeNumber];
    }
    
    Vec2 SelectionScene::getRainbowPosition()
    {
        return Vec2(540, 1920 - 640);
    }
    
    Vec2 SelectionScene::getMoveCloudPosition(int index)
    {
        Vec2 result;
        switch (index) {
            case 0:
                result = Vec2(270, 1920 - 230);
                break;
            case 1:
                result = Vec2(70, 1920 - 375);
                break;
            case 2:
                result = Vec2(370, 1920 - 670);
                break;
            case 3 :
                result = Vec2(820, 1920 - 640);
                break;
            case 4 :
                result = Vec2(960, 1920 - 340);
                break;
            default :
                result = Vec2(270, 1920 - 230);
                break;
        }
        return result;
    }
}
