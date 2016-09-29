#ifndef _GameSprite_PlayInfiniteScene_H_
#define _GameSprite_PlayInfiniteScene_H_

#include "cocos2d.h"
#include "PlayBaseScene.h"
#include "Manager/SpriteManager.h"
#include "Manager/ScoresManager.h"
#include "Manager/MusicManager.h"
#include "Manager/SoundsManager.h"
#include "GameSprite/Background.h"
#include "GameSprite/Sweet.h"
#include "GameSprite/Pig.h"
#include "GameSprite/Cloud.h"
#include "GameSprite/Image.h"
#include "Lib/LevelDesigner.h"
#include "Db/NewHighScoreSetting.h"

USING_NS_CC;

namespace GameScene
{
    class PlayInfiniteScene : public PlayBaseScene
    {
    public:
        /**
         @brief 建構式
         */
        PlayInfiniteScene();
        
        /**
         @brief 初始化場景
         */
        void initScene();
        
        /**
         @brief 釋放場景所有的物件
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
        
        /**
         @brief 將遊戲的難度升級
         */
        void levelUp();
        
        /**
         @brief 依據玩家目前取得的分數來更新記分板上的星星狀態(亮或暗)
         */
        void updateScoreBarStar();
    private:
        // 是否暫停
        bool isPaused;
        
        // 甜點降落的速度
        float sweetRunSpeed;
        
        // 每秒產生幾個甜點
        float sweetPerSecond;
        
        // 產生單一甜點的秒數
        float addSweetTime;
        
        // 要加入甜點的路線
        int addSweetRoad;
        
        // 遊戲時間
        float playTime;
        
        // 目前遊戲難度
        int level;
        
        // 進入下一級前，目前累積的甜點數
        int levelUpSweetCounter;
        
        // 進入下一等級所需要的甜點數
        int levelUpSweetNumber;
        
        // 是否正在進行level up
        bool levelUpNow;
        
        // 難度提升的提示訊息
        Label* levelUpNotification;
        
        // 目前音樂播放的時間
        float musicTime;
        
        // 正在播放的音樂編號
        int playingMusicId;
        
        // 正在播放的音樂長度
        int playingMusicLength;
        
        // 音樂 Batty Mc Faddin 的長度
        int battyMcFaddinMusicLength;
        
        // 音樂 Merry Go 的長度
        int merryGoMusicLength;
        
        // 音樂 Royal Banana 的長度
        int royalBananaMusicLength;
        
        // 音樂 Run Amok 的長度
        int runAmokMusicLength;
        
        // 音樂 Wagon Wheel 的長度
        int wagonWheelMusicLength;
        
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
         @brief 播放背景音樂
          @param musicId 要播放的音樂編號
         */
        void playMusic(int muiscId);
        
        /**
         @brief 切換背景音樂
         @param delta 多久執行一次schedule
         */
        void switchMusic(float delta);
        
        /**
         @brief 取得記分板分數的座標位置
         @return 一個二維向量，代表分數的二維坐標
         */
        Vec2 getScoresPosition();
    };
}

#endif /* _GameSprite_PlayInfiniteScene_H_ */
