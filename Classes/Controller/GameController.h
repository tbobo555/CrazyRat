#ifndef _Controller_GameController_H_
#define _Controller_GameController_H_

#include "cocos2d.h"
#include "GameSprite/SettingButton.h"
#include "GameSprite/SettingBackButton.h"
#include "GameSprite/Background.h"
#include "GameSprite/MusicButton.h"
#include "GameSprite/SoundsButton.h"
#include "GameScene/StartScene.h"
#include "GameScene/ChallengeScene.h"
#include "GameScene/MenuScene.h"
#include "GameScene/PauseScene.h"
#include "GameScene/FinalScoreScene.h"
#include "GameScene/PlayInfiniteScene.h"
#include "GameScene/ChallengePlayScene.h"
#include "Manager/SceneManager.h"
#include "Manager/SpriteManager.h"

using namespace GameSprite;
using namespace Manager;
using namespace DB;
USING_NS_CC;

namespace Controller
{
    /**
     @brief 遊戲控制器
     主要用來控制遊戲流程與資源的載入與釋放
     */
    class GameController
    {
    public:
        /**
         @brief 取得遊戲控制者的實體物件
         */
        static GameController* getInstance();
        
        /**
         @breif 載入MenuScene需要使用的資源到記憶體
         */
        void loadMenuSceneResource();
        
        /**
         @brief 釋放MenuScene有用到的所有資源
         */
        void releaseMenuSceneResource();
        
        /**
         @brief 載入StartScene需要使用的資源到記憶體
         */
        void loadStartSceneResource();
        
        /**
         @brief 釋放StartScene有用到的所有資源
         */
        void releaseStartSceneResource();
        
        /**
         @brief 載入ChallengeScene需要使用的資源到記憶體
         */
        void loadChallengeSceneResource();
        
        /**
         @brief 釋放ChallengeScene有用到的所有資源
         */
        void releaseChallengeSceneResource();
      
        /**
         @brief 載入PlayInfiniteScene需要使用的資源到記憶體
         */
        void loadPlayInfiniteSceneResource();
        
        /**
         @brief 釋放PlayInfiniteScene有用到的所有資源
         */
        void releasePlayInfiniteSceneResource();
        
        /**
         @brief 載入ChallengePlayScene需要使用的資源到記憶體
         */
        void loadChallengePlaySceneResource();
        
        /**
         @brief 釋放ChallengePlayScene有用到的所有資源
         */
        void releaseChallengePlaySceneResource();
        
        /**
         @brief 載入PauseScene需要使用的資源到記憶體
         */
        void loadPauseSceneResource();
        
        /**
         @brief 釋放PauseScene有用到的所有資源
         */
        void releasePauseSceneResource();
        
        /**
         @brief 載入FinalScoreScene需要使用的資源到記憶體
         @param score 在場景要顯示的分數
         */
        void loadFinalScoreScene(std::string score);
        
        /**
         @brief 釋放FinalScoreScene有用到的所有資源
         */
        void releaseFinalScoreScene();
        
        /**
         @brief 將MenuScene放到目前的場景
         */
        void addMenuSceneToCurrentScene();
        
        /**
         @brief 將MenuScene從目前的場景中移除
         */
        void removeMenuSceneFromCurrentScene();
        
        /**
         @brief 將PauseScene放到目前的場景
         */
        void addPauseSceneToCurrentScene();
        
        /**
         @brief 將PauseScene從目前的場景中移除
         */
        void removePauseSceneFromCurrentScene();
      
        /**
         @brief 將FinalScoreScene放到目前的場景
         @param score 要顯示的分數
         */
        void addFinalScoreSceneToCurrentScene(std::string score);
        
        /**
         @brief 將FinalScoreScene從目前的場景中移除
         */
        void removeFinalScoreSceneFromCurrentScene();
        
        /**
         @brief 顯示StartScene，此方法在App開啟時會被呼叫
         */
        void runStartScene();
        
        /**
         @brief 畫面從StartScene切換為PlayInfiniteScene
         */
        void startSceneToPlayInfiniteScene();
        
        /**
         @brief 重新載入PlayInfiniteScene
         */
        void retryPlayInfiniteScene();
        
        /**
         @brief 畫面從PlayInfiniteScene切換為StartScene
         */
        void playInfiniteSceneToStartScene();
        
        /**
         @brief 畫面從StartScene切換為ChallengeScene
         */
        void startSceneToChallengeScene();
        
        /**
         @brief 畫面從ChallengeScene切換為StartScene
         */
        void challengeSceneToStartScene();
        
        /**
         @brief 畫面從ChallengeScene切換為ChallengePlayScene
         */
        void challengeSceneToChallengePlayScene();
        
        /**
         @brief 畫面從ChallengePlayScene切換為ChallengeScene
         */
        void challengePlaySceneToChallengeScene();
        
        /**
         @brief 重新載入ChallengePlayScene
         */
        void retryChallengePlayScene();
        
    private:
        /**
         @brief 建構式
         */
        GameController();
        
        // 靜態實例
        static GameController* instance;
    };
}


#endif /* _Controller_GameController_H_ */
