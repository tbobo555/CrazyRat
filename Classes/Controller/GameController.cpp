#include "GameController.h"


namespace Controller
{
    
    GameController* GameController::instance = new GameController::GameController();
    
    GameController::GameController(){}
    
    GameController* GameController::getInstance()
    {
        return instance;
    }
    
    void GameController::runStartScene()
    {
        StartScene *scene = static_cast<StartScene*>(
            SceneManager::getInstance()->getByKey("StartScene"));
        
        SceneManager::getInstance()->setCurrent(scene);
        this->setSettingMenuToCurrentScene();
        Director::getInstance()->runWithScene(scene->getCCScene());
    }
    
    void GameController::startSceneToSelectionScene()
    {
        StartScene *scene = static_cast<StartScene*>(
            SceneManager::getInstance()->getByKey("SelectionScene"));
        this->releaseSettingMenuFromCurrentScene();
        SceneManager::getInstance()->setCurrent(scene);
        this->setSettingMenuToCurrentScene();
        Director::getInstance()->pushScene(scene->getCCScene());
    }
    
    void GameController::loadStaticResourcesForSettingMenu()
    {
        SpriteManager::getInstance()->setWithKey("SettingMenu_SettingButton", new SettingButton());
        SpriteManager::getInstance()->setWithKey("SettingMenu_SettingBackground", new SettingBackground());
        SpriteManager::getInstance()->setWithKey(
            "SettingMenu_SettingBackButton", new SettingBackButton());
        SpriteManager::getInstance()->setWithKey("SettingMenu_MusicButton", new MusicButton());
        SpriteManager::getInstance()->setWithKey("SettingMenu_SoundsButton", new SoundsButton());
    }
    
    void GameController::loadStaticResourcesForStartScene()
    {
        StartScene *startScene = new StartScene();
        StartBackground *startBackground = new StartBackground();
        StartButton *startButton = new StartButton();
        SceneManager::getInstance()->setWithKey("StartScene", startScene);
        SpriteManager::getInstance()->setWithKey("StartScene_StartBackground", startBackground);
        SpriteManager::getInstance()->setWithKey("StartScene_StartButton", startButton);
        startScene->startBackground = startBackground;
        startScene->startButton = startButton;
        startScene->initScene();
    }

    void GameController::loadStaticResourcesForSelectionScene()
    {
        SelectionScene *selectionScene = new SelectionScene();
        SelectionBackground *selectionBackground = new SelectionBackground();
        Master *master = new Master();
        SceneManager::getInstance()->setWithKey("SelectionScene", selectionScene);
        for (int i = 1; i <= 6; i++) {
            StageButton *stageButton = new StageButton();
            selectionScene->stageButtonVector.push_back(stageButton) ;
            std::stringstream key;
            key << "SelectionScene_StageButton_" << i;
            SpriteManager::getInstance()->setWithKey(key.str(), stageButton);
        }
        
        for (int i = 1; i <= 18; i++) {
            Star *star = new Star();
            selectionScene->starVector.push_back(star);
            std::stringstream key;
            key << "SelectionScene_Star_" << i;
            SpriteManager::getInstance()->setWithKey(key.str(), star);
        }
        
        SpriteManager::getInstance()->setWithKey("SelectionScene_Master", master);
        SpriteManager::getInstance()->setWithKey("SelectionScene_SelectionBackground", selectionBackground);
        selectionScene->selectionBackground = selectionBackground;
        selectionScene->master = master;
        selectionScene->initScene();
    }
    
    void GameController::setSettingMenuToCurrentScene()
    {
        auto scene = SceneManager::getInstance()->getCurrent();
        auto settingButton = SpriteManager::getInstance()->getByKey("SettingMenu_SettingButton");
        scene->getCCScene()->addChild(settingButton->getCCSprite(), 1);
    }
    
    void GameController::releaseSettingMenuFromCurrentScene()
    {
        auto scene = SceneManager::getInstance()->getCurrent();
        scene->getCCScene()->removeChild(SpriteManager::getInstance()->getByKey("SettingMenu_SettingButton")->getCCSprite());
        scene->getCCScene()->removeChild(SpriteManager::getInstance()->getByKey("SettingMenu_SettingBackground")->getCCSprite());
        scene->getCCScene()->removeChild(SpriteManager::getInstance()->getByKey("SettingMenu_SettingBackButton")->getCCSprite());
        scene->getCCScene()->removeChild(SpriteManager::getInstance()->getByKey("SettingMenu_MusicButton")->getCCSprite());
        scene->getCCScene()->removeChild(SpriteManager::getInstance()->getByKey("SettingMenu_SoundsButton")->getCCSprite());
    }

}
