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
    
    void GameController::loadChallengeSceneResource()
    {
        ChallengeScene *challengeScene = new ChallengeScene();
        challengeScene->initScene();
        SceneManager::getInstance()->setWithKey("ChallengeScene", challengeScene);
    }
    
    void GameController::releaseChallengeSceneResource()
    {
        auto challengeScene = SceneManager::getInstance()->getByKey("ChallengeScene");
        challengeScene->releaseScene();
        SceneManager::getInstance()->releaseByKey("ChallengeScene");
    }
    
    void GameController::loadPlayInfiniteSceneResource()
    {
        PlayInfiniteScene *playInfiniteScene = new PlayInfiniteScene();
        playInfiniteScene->initScene();
        SceneManager::getInstance()->setWithKey("PlayInfiniteScene", playInfiniteScene);
    }
    
    void GameController::releasePlayInfiniteSceneResource()
    {
        auto playInfiniteScene = SceneManager::getInstance()->getByKey("PlayInfiniteScene");
        playInfiniteScene->releaseScene();
        SceneManager::getInstance()->releaseByKey("PlayInfiniteScene");
    }
    
    void GameController::loadChallengePlaySceneResource()
    {
        ChallengePlayScene *challengePlayScene = new ChallengePlayScene();
        challengePlayScene->initScene();
        SceneManager::getInstance()->setWithKey("ChallengePlayScene", challengePlayScene);
    }
    
    void GameController::releaseChallengePlaySceneResource()
    {
        auto challengePlayScene = SceneManager::getInstance()->getByKey("ChallengePlayScene");
        challengePlayScene->releaseScene();
        SceneManager::getInstance()->releaseByKey("ChallengePlayScene");
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
    
    void GameController::loadFinalScoreScene(std::string score)
    {
        FinalScoreScene* finalScoreScene = new FinalScoreScene(score);
        finalScoreScene->initScene();
        SceneManager::getInstance()->setWithKey("FinalScoreScene", finalScoreScene);
    }
    
    void GameController::releaseFinalScoreScene()
    {
        auto finalScoreScene = SceneManager::getInstance()->getByKey("FinalScoreScene");
        finalScoreScene->releaseScene();
        SceneManager::getInstance()->releaseByKey("FinalScoreScene");
    }
    
    void GameController::addMenuSceneToCurrentScene()
    {
        auto scene = SceneManager::getInstance()->getCurrent();
        // 僅放上settingButton，其餘的物件會在settingButton被點擊後加至目前的場景
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
        scene->removeChild(SpriteManager::getInstance()->getByKey("MenuScene_SettingMask"));
        scene->removeChild(SpriteManager::getInstance()->getByKey("MenuScene_CreditMask"));
    }
    
    void GameController::addPauseSceneToCurrentScene()
    {
        auto scene = SceneManager::getInstance()->getCurrent();
        // 與addMenuScene不同，此方法將所有相關物件加至目前的場景
        // 但是只顯示pauseButton，其餘物件會在pauseButton被點擊後顯示
        Manager::SpriteManager* spriteManager = Manager::SpriteManager::getInstance();
        auto pauseButton = spriteManager->getByKey("PauseScene_PauseButton");
        auto pauseBackground = spriteManager->getByKey("PauseScene_PauseBackground");
        auto pauseBackButton = spriteManager->getByKey("PauseScene_PauseBackButton");
        auto musicButton = spriteManager->getByKey("PauseScene_MusicButton");
        auto soundsButton = spriteManager->getByKey("PauseScene_SoundsButton");
        auto backHomeButton = spriteManager->getByKey("PauseScene_BackHomeButton");
        auto retryButton = spriteManager->getByKey("PauseScene_RetryButton");
        auto pauseMask = spriteManager->getByKey("PauseScene_PauseMask");
        scene->addChild(pauseButton, 20);
        scene->addChild(pauseBackground, -100);
        scene->addChild(pauseMask, -100);
        pauseBackground->addChild(pauseBackButton, -100);
        pauseBackground->addChild(musicButton, -100);
        pauseBackground->addChild(soundsButton, -100);
        pauseBackground->addChild(backHomeButton, -100);
        pauseBackground->addChild(retryButton, -100);
    }
    
    void GameController::removePauseSceneFromCurrentScene()
    {
        auto scene = SceneManager::getInstance()->getCurrent();
        Manager::SpriteManager* spriteManager = Manager::SpriteManager::getInstance();
        auto pauseBackground = spriteManager->getByKey("PauseScene_PauseBackground");
        scene->removeChild(SpriteManager::getInstance()->getByKey("PauseScene_PauseButton"));
        scene->removeChild(SpriteManager::getInstance()->getByKey("PauseScene_PauseBackground"));
        scene->removeChild(SpriteManager::getInstance()->getByKey("PauseScene_PauseMask"));
        pauseBackground->GameScene::BaseScene::removeChild(SpriteManager::getInstance()->getByKey("PauseScene_PauseBackButton"));
        pauseBackground->GameScene::BaseScene::removeChild(SpriteManager::getInstance()->getByKey("PauseScene_MusicButton"));
        pauseBackground->GameScene::BaseScene::removeChild(SpriteManager::getInstance()->getByKey("PauseScene_SoundsButton"));
        pauseBackground->GameScene::BaseScene::removeChild(SpriteManager::getInstance()->getByKey("PauseScene_BackHomeButton"));
        pauseBackground->GameScene::BaseScene::removeChild(SpriteManager::getInstance()->getByKey("PauseScene_RetryButton"));
    }
    
    void GameController::addFinalScoreSceneToCurrentScene(std::string score)
    {
        auto finalScoreScene = static_cast<FinalScoreScene*>(SceneManager::getInstance()->getByKey("FinalScoreScene"));
        auto scene = SceneManager::getInstance()->getCurrent();
        finalScoreScene->setScore(score);
        Manager::SpriteManager* spriteManager = Manager::SpriteManager::getInstance();
        auto finalScoreBackground = spriteManager->getByKey("FinalScoreScene_FinalScoreBackground");
        auto nextButton = spriteManager->getByKey("FinalScoreScene_NextButton");
        auto scoreLabel = finalScoreScene->getScoreLabel();
        scene->addChild(finalScoreBackground, 200);
        scene->addChild(nextButton, 201);
        scene->addChild(scoreLabel, 201);
        finalScoreScene->runAnimation();
    }
    
    void GameController::removeFinalScoreSceneFromCurrentScene()
    {
        auto scene = SceneManager::getInstance()->getCurrent();
        auto finalScoreScene = static_cast<FinalScoreScene*>(SceneManager::getInstance()->getByKey("FinalScoreScene"));
        scene->removeChild(SpriteManager::getInstance()->getByKey("FinalScoreScene_FinalScoreBackground"));
        scene->removeChild(SpriteManager::getInstance()->getByKey("FinalScoreScene_NextButton"));
        scene->removeChild(finalScoreScene->getScoreLabel());
    }
    
    void GameController::runStartScene()
    {
        this->loadMenuSceneResource();
        this->loadStartSceneResource();
        this->loadChallengeSceneResource();
        StartScene *scene = static_cast<StartScene*>(
            SceneManager::getInstance()->getByKey("StartScene"));
        SceneManager::getInstance()->setCurrent(scene);
        this->addMenuSceneToCurrentScene();
        Director::getInstance()->runWithScene(scene);
        scene->runAnimation();
    }

    void GameController::startSceneToPlayInfiniteScene()
    {
        this->releaseStartSceneResource();
        this->releaseChallengeSceneResource();
        this->releaseMenuSceneResource();
        // 將一些被cocos2d核心程式快取，殘留在記憶體沒有被釋放的物件做記憶體釋放
        Director::getInstance()->purgeCachedData();
        this->loadPauseSceneResource();
        this->loadFinalScoreScene("0");
        this->loadPlayInfiniteSceneResource();
        PlayInfiniteScene *scene = static_cast<PlayInfiniteScene*>(SceneManager::getInstance()->getByKey("PlayInfiniteScene"));
        SceneManager::getInstance()->setCurrent(scene);
        this->addPauseSceneToCurrentScene();
        Director::getInstance()->replaceScene(scene);
    }

    void GameController::retryPlayInfiniteScene()
    {
        this->removePauseSceneFromCurrentScene();
        this->releasePauseSceneResource();
        this->releaseFinalScoreScene();
        this->releasePlayInfiniteSceneResource();
        // 將一些被cocos2d核心程式快取，殘留在記憶體沒有被釋放的物件做記憶體釋放
        Director::getInstance()->purgeCachedData();
        this->loadPauseSceneResource();
        this->loadFinalScoreScene("0");
        this->loadPlayInfiniteSceneResource();
        PlayInfiniteScene *scene = static_cast<PlayInfiniteScene*>(SceneManager::getInstance()->getByKey("PlayInfiniteScene"));
        SceneManager::getInstance()->setCurrent(scene);
        this->addPauseSceneToCurrentScene();
        scene->hideTipBlock();
        Director::getInstance()->replaceScene(scene);
        scene->play();
    }
    
    void GameController::playInfiniteSceneToStartScene()
    {
        this->removePauseSceneFromCurrentScene();
        this->releasePauseSceneResource();
        this->releaseFinalScoreScene();
        this->releasePlayInfiniteSceneResource();
        // 將一些被cocos2d核心程式快取，殘留在記憶體沒有被釋放的物件做記憶體釋放
        Director::getInstance()->purgeCachedData();
        this->loadMenuSceneResource();
        this->loadStartSceneResource();
        this->loadChallengeSceneResource();
        StartScene* startScene = static_cast<StartScene*>(SceneManager::getInstance()->getByKey("StartScene"));
        SceneManager::getInstance()->setCurrent(startScene);
        this->addMenuSceneToCurrentScene();
        Director::getInstance()->replaceScene(startScene);
    }
    
    void GameController::startSceneToChallengeScene()
    {
        ChallengeScene *scene = static_cast<ChallengeScene*>(SceneManager::getInstance()->getByKey("ChallengeScene"));
        this->removeMenuSceneFromCurrentScene();
        SceneManager::getInstance()->setCurrent(scene);
        this->addMenuSceneToCurrentScene();
        Director::getInstance()->replaceScene(scene);
    }
    
    void GameController::challengeSceneToChallengePlayScene()
    {
        this->releaseStartSceneResource();
        this->releaseChallengeSceneResource();
        this->releaseMenuSceneResource();
        // 將一些被cocos2d核心程式快取，殘留在記憶體沒有被釋放的物件做記憶體釋放
        Director::getInstance()->purgeCachedData();
        this->loadPauseSceneResource();
        this->loadChallengePlaySceneResource();
        ChallengePlayScene *scene = static_cast<ChallengePlayScene*>(SceneManager::getInstance()->getByKey("ChallengePlayScene"));
        SceneManager::getInstance()->setCurrent(scene);
        this->addPauseSceneToCurrentScene();
        Director::getInstance()->replaceScene(scene);
        scene->play();
    }
    
    void GameController::retryChallengePlayScene()
    {
        this->removePauseSceneFromCurrentScene();
        this->releasePauseSceneResource();
        this->releaseChallengePlaySceneResource();
        // 將一些被cocos2d核心程式快取，殘留在記憶體沒有被釋放的物件做記憶體釋放
        Director::getInstance()->purgeCachedData();
        this->loadPauseSceneResource();
        this->loadChallengePlaySceneResource();
        ChallengePlayScene *scene = static_cast<ChallengePlayScene*>(SceneManager::getInstance()->getByKey("ChallengePlayScene"));
        SceneManager::getInstance()->setCurrent(scene);
        this->addPauseSceneToCurrentScene();
        Director::getInstance()->replaceScene(scene);
        scene->play();
    }
    
    void GameController::challengePlaySceneToChallengeScene()
    {
        this->removePauseSceneFromCurrentScene();
        this->releasePauseSceneResource();
        this->releaseChallengePlaySceneResource();
        // 將一些被cocos2d核心程式快取，殘留在記憶體沒有被釋放的物件做記憶體釋放
        Director::getInstance()->purgeCachedData();
        this->loadMenuSceneResource();
        this->loadStartSceneResource();
        this->loadChallengeSceneResource();
        ChallengeScene* challengeScene = static_cast<ChallengeScene*>(SceneManager::getInstance()->getByKey("ChallengeScene"));
        SceneManager::getInstance()->setCurrent(challengeScene);
        this->addMenuSceneToCurrentScene();
        Director::getInstance()->replaceScene(challengeScene);
    }

}
