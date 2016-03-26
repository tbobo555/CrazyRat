#include "GameController.h"


namespace Controller
{
    GameController* GameController::instance = new GameController::GameController();
    
    GameController::GameController(){}
    
    GameController* GameController::getInstance()
    {
        return instance;
    }
    
    void GameController::loadSettingMenuResource()
    {
        auto menuScene = new MenuScene();
        menuScene->initScene();
        SceneManager::getInstance()->setWithKey("MenuScene", menuScene);
    }
    
    void GameController::releaseSettingMenuResource()
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
    
    void GameController::addSettingMenuToCurrentScene()
    {
        auto scene = SceneManager::getInstance()->getCurrent();
        auto settingButton = SpriteManager::getInstance()->getByKey("MenuScene_SettingButton");
        scene->addChild(settingButton, 1);
    }
    
    void GameController::removeSettingMenuFromCurrentScene()
    {
        auto scene = SceneManager::getInstance()->getCurrent();
        scene->removeChild(SpriteManager::getInstance()->getByKey("MenuScene_SettingButton"));
        scene->removeChild(SpriteManager::getInstance()->getByKey("MenuScene_SettingBackground"));
        scene->removeChild(SpriteManager::getInstance()->getByKey("MenuScene_SettingBackButton"));
        scene->removeChild(SpriteManager::getInstance()->getByKey("MenuScene_MusicButton"));
        scene->removeChild(SpriteManager::getInstance()->getByKey("MenuScene_SoundsButton"));
    }
    
    void GameController::runStartScene()
    {
        StartScene *scene = static_cast<StartScene*>(
            SceneManager::getInstance()->getByKey("StartScene"));
        SceneManager::getInstance()->setCurrent(scene);
        this->addSettingMenuToCurrentScene();
        Director::getInstance()->runWithScene(scene);
    }
    
    void GameController::startSceneToSelectionScene()
    {
        SelectionScene *scene = static_cast<SelectionScene*>(
            SceneManager::getInstance()->getByKey("SelectionScene"));
        this->removeSettingMenuFromCurrentScene();
        SceneManager::getInstance()->setCurrent(scene);
        this->addSettingMenuToCurrentScene();
        Director::getInstance()->replaceScene(scene);
    }
    
    void GameController::selectionSceneToStartScene()
    {
        StartScene *scene = static_cast<StartScene*>(
            SceneManager::getInstance()->getByKey("StartScene"));
        this->removeSettingMenuFromCurrentScene();
        SceneManager::getInstance()->setCurrent(scene);
        this->addSettingMenuToCurrentScene();
        Director::getInstance()->replaceScene(scene);
    }
    
    void GameController::selectionSceneToMapScene(int mapNumber)
    {
        this->loadMapSceneResource(mapNumber);
        std::stringstream key;
        key << "MapScene_" << mapNumber;
        MapScene *scene = static_cast<MapScene*>(
             SceneManager::getInstance()->getByKey(key.str()));
        this->removeSettingMenuFromCurrentScene();
        SceneManager::getInstance()->setCurrent(scene);
        this->addSettingMenuToCurrentScene();
        Director::getInstance()->replaceScene(scene);
    }
    
    void GameController::MapSceneToSelectionScene(int mapNumber)
    {
        this->releaseMapSceneResource(mapNumber);
        SelectionScene *scene = static_cast<SelectionScene*>(
            SceneManager::getInstance()->getByKey("SelectionScene"));
        this->removeSettingMenuFromCurrentScene();
        SceneManager::getInstance()->setCurrent(scene);
        this->addSettingMenuToCurrentScene();
        Director::getInstance()->replaceScene(scene);

    }

}
