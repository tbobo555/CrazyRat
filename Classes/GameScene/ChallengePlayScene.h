#ifndef _GameScene_ChallengePlayScene_H_
#define _GameScene_ChallengePlayScene_H_

#include "cocos2d.h"
#include "BaseScene.h"
#include "GameSprite/Image.h"
#include "GameSprite/Boss.h"
#include "GameSprite/Background.h"
#include "PlayBaseScene.h"
#include "Manager/MusicManager.h"
#include "Manager/SoundsManager.h"
#include "GameSprite/NextButton.h"

namespace GameScene
{
    class ChallengePlayScene : public GameScene::PlayBaseScene
    {
    public:
        /**
         @brief 建構式
         */
        ChallengePlayScene();
        
        /**
         @brief 場景初始化，將開始場景會用到的資源載入
         */
        void initScene();
        
        /**
         @brief 釋放開始場景的所有資源
         */
        void releaseScene();
        
        /**
         @brief 暫停遊戲，包含所有正在進行的schedule
         */
        void pauseScene();
        
        /**
         @brief 恢復遊戲，讓遊戲繼續進行
         */
        void resumeScene();
        
        /**
         @brief 加上勝利場景
         */
        void addWinScene();
        
        /**
         @brief 加上失敗場景
         */
        void addLoseScene();
        
        /**
         @brief 開始遊戲迴圈，這這會新增一個schedule來更新遊戲畫面
         */
        void play();
    private:
        // 是否暫停
        bool isPaused;
        
        // 甜點降落的速度
        float sweetRunSpeed;
        
        // 每秒產生幾個甜點
        float sweetPerSecond;
     
        // 下一個要加入甜點的路線
        int nextSweetRoad;
        
        // 遊戲時間
        float playTime;
        
        // 上一個甜點的路線
        int lastSweetRoad;
        
        // 甜點在同一路線出現的次數
        int sweetInSameRoadTimes;

        /**
         @brief 更新倒數時間的schedule
         @param delta 多久執行一次schedule
         */
        void prepareUpdate(float delta);
        
        /**
         @brief 倒數計時結束，遊戲正式開始
         甜點開始從天空降下，豬開始眨眼，進度條開始動，遊戲迴圈開始進行
         */
        void prepareDone();
        
        /**
         @brief 遊戲主要迴圈的schedule，主要檢查遊戲是否結束和玩家的勝利與失敗
         @param delta 多久執行一次schedule
         */
        void gameUpdate(float delta);
        
        /**
         @brief 路線0用來降下甜點的shedule
         會取得目前路線0可用的甜點物件，並讓該甜點落下
         @param shedule多久執行一次的時間
         */
        void road0Update(float delta);
        
        /**
         @brief 路線1用來降下甜點的shedule
         會取得目前路線1可用的甜點物件，並讓該甜點落下
         @param shedule多久執行一次的時間
         */
        void road1Update(float delta);
        
        /**
         @brief 路線2用來降下甜點的shedule
         會取得目前路線2可用的甜點物件，並讓該甜點落下
         @param shedule多久執行一次的時間
         */
        void road2Update(float delta);

        /**
         @brief 檢查此時機點是否可以設置炸彈
         @param road 本次甜點出現的路線
         @return 是否要將甜點改為炸彈
         */
        bool checkBombTiming(int road);
    };
}


#endif /* _GameScene_ChallengePlayScene_H_ */
