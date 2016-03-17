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
        SpriteManager::getInstance()->setWithKey("SettingMenu_SettingBg", new SettingBg());
        SpriteManager::getInstance()->setWithKey(
            "SettingMenu_SettingBackButton", new SettingBackButton());
        SpriteManager::getInstance()->setWithKey("SettingMenu_MusicButton", new MusicButton());
        SpriteManager::getInstance()->setWithKey("SettingMenu_SoundsButton", new SoundsButton());
    }
    
    void GameController::loadStaticResourcesForStartScene()
    {
        StartScene *startScene = new StartScene();
        StartBg *startBg = new StartBg();
        StartButton *startButton = new StartButton();
        SceneManager::getInstance()->setWithKey("StartScene", startScene);
        SpriteManager::getInstance()->setWithKey("StartScene_StartBg", startBg);
        SpriteManager::getInstance()->setWithKey("StartScene_StartButton", startButton);
        startScene->startBg = startBg;
        startScene->startButton = startButton;
        startScene->initScene();
    }

    void GameController::loadStaticResourcesForSelectionScene()
    {
        SelectionScene *selectionScene = new SelectionScene();
        StartBg *startBg = new StartBg();
        MasterSprite *masterSprite = new MasterSprite();
        SceneManager::getInstance()->setWithKey("SelectionScene", selectionScene);
        for (int i = 0; i < 6; i++) {
            StageButton *stageButton = new StageButton();
            selectionScene->stageButtonVector.push_back(stageButton) ;
            std::stringstream key;
            key << "SelectionScene_StageButton" << i;
            SpriteManager::getInstance()->setWithKey(key.str(), stageButton);
        }
        
        for (int i = 0; i < 18; i++) {
            StarSprite *starSprite = new StarSprite();
            selectionScene->starSpriteVector.push_back(starSprite);
            std::stringstream key;
            key << "SelectionScene_StarSprite" << i;
            SpriteManager::getInstance()->setWithKey(key.str(), starSprite);
        }
        
        SpriteManager::getInstance()->setWithKey("SelectionScene_MasterSprite", masterSprite);
        SpriteManager::getInstance()->setWithKey("SelectionScene_StartBg", startBg);
        selectionScene->startBg = startBg;
        selectionScene->masterSprite = masterSprite;
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
        scene->getCCScene()->removeChild(SpriteManager::getInstance()->getByKey("SettingMenu_SettingBg")->getCCSprite());
        scene->getCCScene()->removeChild(SpriteManager::getInstance()->getByKey("SettingMenu_SettingBackButton")->getCCSprite());
        scene->getCCScene()->removeChild(SpriteManager::getInstance()->getByKey("SettingMenu_MusicButton")->getCCSprite());
        scene->getCCScene()->removeChild(SpriteManager::getInstance()->getByKey("SettingMenu_SoundsButton")->getCCSprite());
    }

}
