#include "GameController.h"

namespace Controller
{
    GameController* GameController::instance = new GameController::GameController();
    
    GameController::GameController(){}
    
    GameController* GameController::getInstance()
    {
        return instance;
    }
    
    void GameController::loadMenuSceneResource()
    {
        auto menuScene = new MenuScene();
        menuScene->initScene();
        SceneManager::getInstance()->setWithKey("MenuScene", menuScene);
    }
    
    void GameController::releaseMenuSceneResource()
    {
        auto menuScene = SceneManager::getInstance()->getByKey("MenuScene");
        menuScene->releaseScene();
        SceneManager::getInstance()->releaseByKey("MenuScene");
    }

    void GameController::loadStartSceneResource()
    {
        StartScene *startScene = new StartScene();
        startScene->initScene();
        SceneManager::getInstance()->setWithKey("StartScene", startScene);
    }
    
    void GameController::releaseStartSceneResource()
    {
        auto startScene = SceneManager::getInstance()->getByKey("StartScene");
        startScene->releaseScene();
        SceneManager::getInstance()->releaseByKey("StartScene");
    }

    void GameController::loadSelectionSceneResource()
    {
        SelectionScene *selectionScene = new SelectionScene();
        selectionScene->initScene();
        SceneManager::getInstance()->setWithKey("SelectionScene", selectionScene);
    }
    
    void GameController::releaseSelectionSceneResource()
    {
        auto selectionScene = SceneManager::getInstance()->getByKey("SelectionScene");
        selectionScene->releaseScene();
        SceneManager::getInstance()->releaseByKey("SelectionScene");
    }
    
    void GameController::loadEpisodeSceneResource(int episodeNumber)
    {
        EpisodeScene *episodeScene = new EpisodeScene(episodeNumber);
        episodeScene->initScene();
        std::stringstream key;
        key << "EpisodeScene_" << episodeNumber;
        SceneManager::getInstance()->setWithKey(key.str(), episodeScene);
    }
    
    void GameController::releaseEpisodeSceneResource(int episodeNumber)
    {
        std::stringstream key;
        key << "EpisodeScene_" << episodeNumber;
        auto episodeScene = SceneManager::getInstance()->getByKey(key.str());
        episodeScene->releaseScene();
        SceneManager::getInstance()->releaseByKey(key.str());
    }
    
    void GameController::loadPlaySceneResource(int episodeNumber, int stageNumber)
    {
        PlayScene *playScene = new PlayScene(episodeNumber, stageNumber);
        playScene->initScene();
        std::stringstream key;
        key << "PlayScene_" << episodeNumber << "_" << stageNumber;
        SceneManager::getInstance()->setWithKey(key.str(), playScene);
    }
    
    void GameController::releasePlaySceneResource(int episodeNumber, int stageNumber)
    {
        std::stringstream key;
        key << "PlayScene_" << episodeNumber << "_" << stageNumber;
        auto playScene = SceneManager::getInstance()->getByKey(key.str());
        playScene->releaseScene();
        SceneManager::getInstance()->releaseByKey(key.str());
    }
    
    void GameController::loadPauseSceneResource()
    {
        PauseScene* pauseScene = new PauseScene();
        pauseScene->initScene();
        SceneManager::getInstance()->setWithKey("PauseScene", pauseScene);
    }
    
    void GameController::releasePauseSceneResource()
    {
        auto pauseScene = SceneManager::getInstance()->getByKey("PauseScene");
        pauseScene->releaseScene();
        SceneManager::getInstance()->releaseByKey("PauseScene");
    }
    
    void GameController::loadVictorySceneResource()
    {
        VictoryScene* victoryScene = new VictoryScene();
        victoryScene->initScene();
        SceneManager::getInstance()->setWithKey("VictoryScene", victoryScene);
    }
    
    void GameController::releaseVictorySceneResource()
    {
        auto victoryScene = SceneManager::getInstance()->getByKey("VictoryScene");
        victoryScene->releaseScene();
        SceneManager::getInstance()->releaseByKey("VictoryScene");
    }
    
    void GameController::loadLoseSceneResource()
    {
        LoseScene* loseScene = new LoseScene();
        loseScene->initScene();
        SceneManager::getInstance()->setWithKey("LoseScene", loseScene);
    }
    
    void GameController::releaseLoseSceneResource()
    {
        auto loseScene = SceneManager::getInstance()->getByKey("LoseScene");
        loseScene->releaseScene();
        SceneManager::getInstance()->releaseByKey("LoseScene");
    }
    
    void GameController::addMenuSceneToCurrentScene()
    {
        auto scene = SceneManager::getInstance()->getCurrent();
        auto settingButton = SpriteManager::getInstance()->getByKey("MenuScene_SettingButton");
        scene->addChild(settingButton, 1);
    }
    
    void GameController::removeMenuSceneFromCurrentScene()
    {
        auto scene = SceneManager::getInstance()->getCurrent();
        scene->removeChild(SpriteManager::getInstance()->getByKey("MenuScene_SettingButton"));
        scene->removeChild(SpriteManager::getInstance()->getByKey("MenuScene_SettingBackground"));
        scene->removeChild(SpriteManager::getInstance()->getByKey("MenuScene_SettingBackButton"));
        scene->removeChild(SpriteManager::getInstance()->getByKey("MenuScene_MusicButton"));
        scene->removeChild(SpriteManager::getInstance()->getByKey("MenuScene_SoundsButton"));
    }
    
    void GameController::addPauseSceneToCurrentScene()
    {
        auto scene = SceneManager::getInstance()->getCurrent();
        Manager::SpriteManager* spriteManager = Manager::SpriteManager::getInstance();
        auto pauseButton = spriteManager->getByKey("PauseScene_PauseButton");
        auto pauseBackground = spriteManager->getByKey("PauseScene_PauseBackground");
        auto pauseBackButton = spriteManager->getByKey("PauseScene_PauseBackButton");
        auto musicButton = spriteManager->getByKey("PauseScene_MusicButton");
        auto soundsButton = spriteManager->getByKey("PauseScene_SoundsButton");
        auto backHomeButton = spriteManager->getByKey("PauseScene_BackHomeButton");
        auto retryButton = spriteManager->getByKey("PauseScene_RetryButton");
        scene->addChild(pauseButton, 1);
        scene->addChild(pauseBackground, -100);
        scene->addChild(pauseBackButton, -100);
        scene->addChild(musicButton, -100);
        scene->addChild(soundsButton, -100);
        scene->addChild(backHomeButton, -100);
        scene->addChild(retryButton, -100);
    }
    
    void GameController::removePauseSceneFromCurrentScene()
    {
        auto scene = SceneManager::getInstance()->getCurrent();
        scene->removeChild(SpriteManager::getInstance()->getByKey("PauseScene_PauseButton"));
        scene->removeChild(SpriteManager::getInstance()->getByKey("PauseScene_PauseBackground"));
        scene->removeChild(SpriteManager::getInstance()->getByKey("PauseScene_PauseBackButton"));
        scene->removeChild(SpriteManager::getInstance()->getByKey("PauseScene_MusicButton"));
        scene->removeChild(SpriteManager::getInstance()->getByKey("PauseScene_SoundsButton"));
        scene->removeChild(SpriteManager::getInstance()->getByKey("PauseScene_BackHomeButton"));
        scene->removeChild(SpriteManager::getInstance()->getByKey("PauseScene_RetryButton"));
    }
    
    void GameController::addVictorySceneToCurrentScene()
    {
        auto scene = SceneManager::getInstance()->getCurrent();
        Manager::SpriteManager* spriteManager = Manager::SpriteManager::getInstance();
        auto victoryBackground = spriteManager->getByKey("VictoryScene_VictoryBackground");
        auto nextButton = spriteManager->getByKey("VictoryScene_NextButton");
        scene->addChild(victoryBackground, 200);
        scene->addChild(nextButton, 201);
    }
    
    void GameController::removeVictorySceneFromCurrentScene()
    {
        auto scene = SceneManager::getInstance()->getCurrent();
        scene->removeChild(SpriteManager::getInstance()->getByKey("VictoryScene_VictoryBackground"));
        scene->removeChild(SpriteManager::getInstance()->getByKey("VictoryScene_NextButton"));
    }
    
    void GameController::addLoseSceneToCurrentScene()
    {
        auto scene = SceneManager::getInstance()->getCurrent();
        Manager::SpriteManager* spriteManager = Manager::SpriteManager::getInstance();
        auto loseBackground = spriteManager->getByKey("LoseScene_LoseBackground");
        auto nextButton = spriteManager->getByKey("LoseScene_NextButton");
        scene->addChild(loseBackground, 200);
        scene->addChild(nextButton, 201);
    }
    
    void GameController::removeLoseSceneFromCurrentScene()
    {
        auto scene = SceneManager::getInstance()->getCurrent();
        scene->removeChild(SpriteManager::getInstance()->getByKey("LoseScene_LoseBackground"));
        scene->removeChild(SpriteManager::getInstance()->getByKey("LoseScene_NextButton"));
    }
    
    void GameController::runStartScene()
    {
        this->loadMenuSceneResource();
        this->loadStartSceneResource();
        this->loadSelectionSceneResource();
        StartScene *scene = static_cast<StartScene*>(
            SceneManager::getInstance()->getByKey("StartScene"));
        SceneManager::getInstance()->setCurrent(scene);
        this->addMenuSceneToCurrentScene();
        Director::getInstance()->runWithScene(scene);
    }
    
    void GameController::startSceneToSelectionScene()
    {
        SelectionScene *scene = static_cast<SelectionScene*>(
            SceneManager::getInstance()->getByKey("SelectionScene"));
        this->removeMenuSceneFromCurrentScene();
        SceneManager::getInstance()->setCurrent(scene);
        this->addMenuSceneToCurrentScene();
        Director::getInstance()->replaceScene(scene);
    }
    
    void GameController::selectionSceneToStartScene()
    {
        StartScene *scene = static_cast<StartScene*>(
            SceneManager::getInstance()->getByKey("StartScene"));
        this->removeMenuSceneFromCurrentScene();
        SceneManager::getInstance()->setCurrent(scene);
        this->addMenuSceneToCurrentScene();
        Director::getInstance()->replaceScene(scene);
    }
    
    void GameController::selectionSceneToEpisodeScene(int episodeNumber)
    {
        this->loadEpisodeSceneResource(episodeNumber);
        std::stringstream key;
        key << "EpisodeScene_" << episodeNumber;
        EpisodeScene *scene = static_cast<EpisodeScene*>(
             SceneManager::getInstance()->getByKey(key.str()));
        this->removeMenuSceneFromCurrentScene();
        SceneManager::getInstance()->setCurrent(scene);
        this->addMenuSceneToCurrentScene();
        Director::getInstance()->replaceScene(scene);
    }
    
    void GameController::EpisodeSceneToSelectionScene(int episodeNumber)
    {
        this->releaseEpisodeSceneResource(episodeNumber);
        SelectionScene *scene = static_cast<SelectionScene*>(
            SceneManager::getInstance()->getByKey("SelectionScene"));
        this->removeMenuSceneFromCurrentScene();
        SceneManager::getInstance()->setCurrent(scene);
        this->addMenuSceneToCurrentScene();
        Director::getInstance()->replaceScene(scene);
    }
    
    void GameController::EpisodeSceneToPlayScene(int episodeNumber, int stageNumber)
    {
        this->releaseStartSceneResource();
        this->releaseMenuSceneResource();
        this->releaseEpisodeSceneResource(episodeNumber);
        this->releaseSelectionSceneResource();
        this->loadPauseSceneResource();
        this->loadVictorySceneResource();
        this->loadLoseSceneResource();
        this->loadPlaySceneResource(episodeNumber, stageNumber);
        std::stringstream key;
        key << "PlayScene_" << episodeNumber << "_" << stageNumber;
        std::string a = key.str();
        PlayScene *scene = static_cast<PlayScene*>(
            SceneManager::getInstance()->getByKey(key.str()));
        SceneManager::getInstance()->setCurrent(scene);
        this->addPauseSceneToCurrentScene();
        Director::getInstance()->replaceScene(scene);
        scene->play();
    }
    
    void GameController::PlaySceneToEpisodeScene(int episodeNumber, int stageNumber)
    {
        int newEpisodeNumber = episodeNumber;
        auto current = static_cast<GameScene::PlayScene*>(SceneManager::getInstance()->getCurrent());
        if (current->getIsVictory()) {
            if (stageNumber == 4) {
                newEpisodeNumber++;
            }
            if (newEpisodeNumber > 5) {
                newEpisodeNumber = episodeNumber;
            }
        }
        this->removePauseSceneFromCurrentScene();
        this->removeLoseSceneFromCurrentScene();
        this->removeVictorySceneFromCurrentScene();
        this->releasePauseSceneResource();
        this->releaseVictorySceneResource();
        this->releaseLoseSceneResource();
        this->releasePlaySceneResource(episodeNumber, stageNumber);
        this->loadMenuSceneResource();
        this->loadStartSceneResource();
        this->loadSelectionSceneResource();
        this->loadEpisodeSceneResource(newEpisodeNumber);
        std::stringstream key;
        key << "EpisodeScene_" << newEpisodeNumber;
        EpisodeScene *scene = static_cast<EpisodeScene*>(SceneManager::getInstance()->getByKey(key.str()));
        SceneManager::getInstance()->setCurrent(scene);
        this->addMenuSceneToCurrentScene();
        Director::getInstance()->replaceScene(scene);
    }
    
    void GameController::RetryPlayScene(int episodeNumber, int stageNumber)
    {
        this->removePauseSceneFromCurrentScene();
        this->removeLoseSceneFromCurrentScene();
        this->removeVictorySceneFromCurrentScene();
        this->releasePauseSceneResource();
        this->releaseVictorySceneResource();
        this->releaseLoseSceneResource();
        this->releasePlaySceneResource(episodeNumber, stageNumber);
        this->loadPauseSceneResource();
        this->loadVictorySceneResource();
        this->loadLoseSceneResource();
        this->loadPlaySceneResource(episodeNumber, stageNumber);
        std::stringstream key;
        key << "PlayScene_" << episodeNumber << "_" << stageNumber;
        PlayScene *scene = static_cast<PlayScene*>(SceneManager::getInstance()->getByKey(key.str()));
        SceneManager::getInstance()->setCurrent(scene);
        this->addPauseSceneToCurrentScene();
        Director::getInstance()->replaceScene(scene);
        scene->play();
    }
}
