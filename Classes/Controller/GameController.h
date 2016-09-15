#ifndef _Controller_GameController_H_
#define _Controller_GameController_H_

#include "cocos2d.h"
#include "GameSprite/SettingButton.h"
#include "GameSprite/SettingBackButton.h"
#include "GameSprite/Background.h"
#include "GameSprite/MusicButton.h"
#include "GameSprite/SoundsButton.h"
#include "GameScene/StartScene.h"
#include "GameScene/SelectionScene.h"
#include "GameScene/EpisodeScene.h"
#include "GameScene/MenuScene.h"
#include "GameScene/PlayScene.h"
#include "GameScene/PauseScene.h"
#include "GameScene/VictoryScene.h"
#include "GameScene/LoseScene.h"
#include "GameScene/PlayInfiniteScene.h"
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
         @brief 載入SelectionScene需要使用的資源到記憶體
         */
        void loadSelectionSceneResource();
        
        /**
         @brief 釋放SelectionScene有用到的所有資源
         */
        void releaseSelectionSceneResource();
        
        /**
         @brief 載入EpisodeScene需要使用的資源到記憶體
         @param episodeNumber 要載入的章節編號
         */
        void loadEpisodeSceneResource(int episodeNumber);
        
        /**
         @brief 釋放EpisodeScene有用到的所有資源
         @param episodeNumber 要被釋放資源的章節編號
         */
        void releaseEpisodeSceneResource(int episodeNumber);
        
        /**
         @brief 載入PlayScene需要使用的資源到記憶體
         @param episodeNumber 章節編號
         @param stageNumber 關卡編號
         */
        void loadPlaySceneResource(int episodeNumber, int stageNumber);
        
        /**
         @brief 釋放PlayScene有用到的所有資源
         @param episodeNumber 章節編號
         @param stageNumber 關卡編號
         */
        void releasePlaySceneResource(int episodeNumber, int stageNumber);
        
        
        void loadPlayInfiniteSceneResource();
        
        void releasePlayInfiniteSceneResource();
        
        /**
         @brief 載入PauseScene需要使用的資源到記憶體
         */
        void loadPauseSceneResource();
        
        /**
         @brief 釋放PauseScene有用到的所有資源
         */
        void releasePauseSceneResource();
        
        /**
         @brief 載入VictoryScene需要使用的資源到記憶體
         */
        void loadVictorySceneResource();
        
        /**
         @brief 釋放VictoryScene有用到的所有資源
         */
        void releaseVictorySceneResource();
        
        /**
         @brief 載入LoseScene需要使用的資源到記憶體
         */
        void loadLoseSceneResource();
        
        /**
         @brief 釋放LoseScene有用到的所有資源
         */
        void releaseLoseSceneResource();
        
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
         @brief 將VictoryScene放到目前的場景
         @param newScores 勝利場景的分數(星星數)
         */
        void addVictorySceneToCurrentScene(int newScores);
        
        /**
         @brief 將VictoryScene從目前的場景中移除
         */
        void removeVictorySceneFromCurrentScene();
        
        /**
         @brief 將LoseScene放到目前的場景
         */
        void addLoseSceneToCurrentScene();
        
        /**
         @brief 將LoseScene從目前的場景中移除
         */
        void removeLoseSceneFromCurrentScene();
        
        /**
         @brief 顯示StartScene，此方法在App開啟時會被呼叫
         */
        void runStartScene();
        
        /**
         @brief 畫面從StartScene切換為SelectionScene
         */
        void startSceneToSelectionScene();
        
        /**
         @brief 畫面從SelectionScene切換為StartScene
         */
        void selectionSceneToStartScene();
        
        /**
         @brief 畫面從SelectionScene切換為EpisodeScene
         @param episodeNumber 章節編號
         */
        void selectionSceneToEpisodeScene(int episodeNumber);
        
        /**
         @brief 畫面從EpisodeScene切換為SelectionScene
         此方法會將EpisodeScene有用到的資源做釋放
         @param episodeNumber 章節編號
         */
        void EpisodeSceneToSelectionScene(int episodeNumber);
        
        /**
         @brief 畫面從EpisodeScene切換為PlayScene
         此方法會釋放StartScene, SelectionScene, EpisodeScene, MenuScene的資源
         @param episodeNumber 章節編號
         @param stageNumber 關卡編號
         */
        void EpisodeSceneToPlayScene(int episodeNumber, int stageNumber);
        
        /**
         @brief 重新載入PlayScene
         @param episodeNumber 章節編號
         @param stageNumber 關卡編號
         */
        void RetryPlayScene(int episodeNumber, int stageNumber);
        
        /**
         @brief 畫面從PlayScene切換為EpisodeScene
         此方法會釋放PlayScene的資源
         @param episodeNumber 章節編號
         @param stageNumber 關卡編號
         */
        void PlaySceneToEpisodeScene(int episodeNumber, int stageNumber);
        
        /**
         @brief 畫面從PlayScene切換至EpisodeScene，只有在解鎖新關卡時會呼叫此方法，此方法會釋放PlayScene的資源
         @param episodeNumber 章節編號
         @param stageNumber 關卡編號
         @param unlockedEpisodeNumber 新解鎖的章節編號
         */
        void PlaySceneToSelectionScene(int episodeNumber, int stageNumber, int unlockedEpisodeNumber);
        
        /**
         @brief 畫面從StartScene切換為PlayInfiniteScene
         */
        void startSceneToPlayInfiniteScene();
        
        /**
         @brief 重新載入PlayInfiniteScene
         @param episodeNumber 章節編號
         @param stageNumber 關卡編號
         */
        void retryPlayInfiniteScene();
        
        /**
         @brief 畫面從PlayInfiniteScene切換為StartScene
         */
        void playInfiniteSceneToStartScene();
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
