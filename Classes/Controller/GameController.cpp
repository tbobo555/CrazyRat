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
    
    void GameController::loadMapSceneResource(int mapNumber)
    {
        MapScene *mapScene = new MapScene(mapNumber);
        mapScene->initScene();
        std::stringstream key;
        key << "MapScene_" << mapNumber;
        SceneManager::getInstance()->setWithKey(key.str(), mapScene);
    }
    
    void GameController::releaseMapSceneResource(int mapNumber)
    {
        std::stringstream key;
        key << "MapScene_" << mapNumber;
        auto mapScene = SceneManager::getInstance()->getByKey(key.str());
        mapScene->releaseScene();
        SceneManager::getInstance()->releaseByKey(key.str());
    }
    
    void GameController::loadPlaySceneResource(int mapNumber, int stageNumber)
    {
        PlayScene *playScene = new PlayScene(mapNumber, stageNumber);
        playScene->initScene();
        std::stringstream key;
        key << "PlayScene_" << mapNumber << "_" << stageNumber;
        SceneManager::getInstance()->setWithKey(key.str(), playScene);
    }
    
    void GameController::releasePlaySceneResource(int mapNumber, int stageNumber)
    {
        std::stringstream key;
        key << "PlayScene_" << mapNumber << "_" << stageNumber;
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
    
    void GameController::selectionSceneToMapScene(int mapNumber)
    {
        this->loadMapSceneResource(mapNumber);
        std::stringstream key;
        key << "MapScene_" << mapNumber;
        MapScene *scene = static_cast<MapScene*>(
             SceneManager::getInstance()->getByKey(key.str()));
        this->removeMenuSceneFromCurrentScene();
        SceneManager::getInstance()->setCurrent(scene);
        this->addMenuSceneToCurrentScene();
        Director::getInstance()->replaceScene(scene);
    }
    
    void GameController::MapSceneToSelectionScene(int mapNumber)
    {
        this->releaseMapSceneResource(mapNumber);
        SelectionScene *scene = static_cast<SelectionScene*>(
            SceneManager::getInstance()->getByKey("SelectionScene"));
        this->removeMenuSceneFromCurrentScene();
        SceneManager::getInstance()->setCurrent(scene);
        this->addMenuSceneToCurrentScene();
        Director::getInstance()->replaceScene(scene);
    }
    
    void GameController::MapSceneToPlayScene(int mapNumber, int stageNumber)
    {
        this->releaseStartSceneResource();
        this->releaseMenuSceneResource();
        this->releaseMapSceneResource(mapNumber);
        this->releaseSelectionSceneResource();
        this->loadPauseSceneResource();
        this->loadVictorySceneResource();
        this->loadLoseSceneResource();
        this->loadPlaySceneResource(mapNumber, stageNumber);
        std::stringstream key;
        key << "PlayScene_" << mapNumber << "_" << stageNumber;
        PlayScene *scene = static_cast<PlayScene*>(
            SceneManager::getInstance()->getByKey(key.str()));
        SceneManager::getInstance()->setCurrent(scene);
        this->addPauseSceneToCurrentScene();
        Director::getInstance()->replaceScene(scene);
        scene->play();
    }
    
    void GameController::PlaySceneToMapScene(int mapNumber, int stageNumber)
    {
        int newMapNumber = mapNumber;
        auto current = static_cast<GameScene::PlayScene*>(SceneManager::getInstance()->getCurrent());
        if (current->getIsVictory()) {
            if (stageNumber == 4) {
                newMapNumber++;
            }
            if (newMapNumber > 5) {
                newMapNumber = mapNumber;
            }
        }
        this->removePauseSceneFromCurrentScene();
        this->removeLoseSceneFromCurrentScene();
        this->removeVictorySceneFromCurrentScene();
        this->releasePauseSceneResource();
        this->releaseVictorySceneResource();
        this->releaseLoseSceneResource();
        this->releasePlaySceneResource(mapNumber, stageNumber);
        this->loadMenuSceneResource();
        this->loadStartSceneResource();
        this->loadSelectionSceneResource();
        this->loadMapSceneResource(newMapNumber);
        std::stringstream key;
        key << "MapScene_" << newMapNumber;
        MapScene *scene = static_cast<MapScene*>(SceneManager::getInstance()->getByKey(key.str()));
        SceneManager::getInstance()->setCurrent(scene);
        this->addMenuSceneToCurrentScene();
        Director::getInstance()->replaceScene(scene);
    }
    
    void GameController::RetryPlayScene(int mapNumber, int stageNumber)
    {
        this->removePauseSceneFromCurrentScene();
        this->removeLoseSceneFromCurrentScene();
        this->removeVictorySceneFromCurrentScene();
        this->releasePauseSceneResource();
        this->releaseVictorySceneResource();
        this->releaseLoseSceneResource();
        this->releasePlaySceneResource(mapNumber, stageNumber);
        this->loadPauseSceneResource();
        this->loadVictorySceneResource();
        this->loadLoseSceneResource();
        this->loadPlaySceneResource(mapNumber, stageNumber);
        std::stringstream key;
        key << "PlayScene_" << mapNumber << "_" << stageNumber;
        PlayScene *scene = static_cast<PlayScene*>(SceneManager::getInstance()->getByKey(key.str()));
        SceneManager::getInstance()->setCurrent(scene);
        this->addPauseSceneToCurrentScene();
        Director::getInstance()->replaceScene(scene);
        scene->play();
    }
}
