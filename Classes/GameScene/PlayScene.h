#ifndef _GameScene_PlayScene_H_
#define _GameScene_PlayScene_H_

#include "cocos2d.h"
#include "PlayBaseScene.h"
#include "Manager/SpriteManager.h"
#include "Manager/ScoresManager.h"
#include "Manager/MusicManager.h"
#include "Manager/SoundsManager.h"
#include "GameSprite/Background.h"
#include "GameSprite/ProgressBarUp.h"
#include "GameSprite/ProgressBarDown.h"
#include "GameSprite/Sweet.h"
#include "GameSprite/Pig.h"
#include "GameSprite/Cloud.h"
#include "GameSprite/Image.h"
#include "GameSprite/ScoreStar.h"
#include "Db/EpisodeSetting.h"
#include "Db/StageSetting.h"
#include "Db/StarSetting.h"
#include "Lib/LevelDesigner.h"

USING_NS_CC;

namespace GameScene
{
    /**
     @brief 遊戲場景，玩家開始遊玩關卡的場景
     */
    class PlayScene : public PlayBaseScene
    {
    public:
        /**
         @brief 建構式
         @param pEpisodeNumber 該遊戲場景的章節編號
         @param pStageNumber 該遊戲場景的關卡編號
         */
        PlayScene(int pEpisodeNumber, int pStageNumber);
        
        // 本關卡的章節編號
        int episodeNumber;
        
        // 本關卡的關卡編號
        int stageNumber;
        
        // 遊戲進度條，up代表填會隨進度滿容器的物件
        GameSprite::ProgressBarUp* progressBarUp;
        
        // 遊戲進度條，down代表進度條的容器
        GameSprite::ProgressBarDown* progressBarDown;
        
        // 進度條實體物件，用來呈現遊戲進度
        ProgressTimer* timeBar;
        
        // 遊戲計分版的右方星星，用來提示玩家目前得到幾顆星
        GameSprite::ScoreStar* scoreRightStar;
        
        // 遊戲計分版的左方星星，用來提示玩家目前得到幾顆星
        GameSprite::ScoreStar* scoreLeftStar;
        
        // 遊戲計分版的中間星星，用來提示玩家目前得到幾顆星
        GameSprite::ScoreStar* scoreMiddleStar;
        
        // 時間結束
        GameSprite::Image* timesUp;
        
        /**
         @brief 初始化場景
         */
        void initScene();
        
        /**
         @brief 釋放場景所有的物件
         */
        void releaseScene();
        
        /**
         @brief 開始遊戲迴圈，這這會新增一個schedule來更新遊戲畫面
         */
        void play();
        
        /**
         @brief 暫停遊戲，包含所有正在進行的schedule
         */
        void pauseScene();
        
        /**
         @brief 恢復遊戲，讓遊戲繼續進行
         */
        void resumeScene();
        
        /**
         @brief 加上失敗場景
         */
        void addLoseScene();
        
        /**
         @brief 加上勝利場景
         */
        void addWinScene();
        
        /**
         @brief 是否已暫停
         @return 暫停回傳true，否則回傳false
         */
        bool getIsPaused();
        
        /**
         @brief 玩家是否成功破關
         @return 破關回傳true，否則回傳false
         */
        bool getIsVictory();
        
        /**
         @brief 取得玩家破關所得到的星星數
         @return 玩家取得的星星數
         */
        bool getVictoryStar();
        
        /**
         @brief 玩家是否有在該關卡取得最新高分，這裡的分數是星星數
         @return 玩家有取得最新高分回傳true，否則回傳false
         */
        bool getIsNewHighScore();
        
        /**
         @brief 玩家是否已經有破過此關卡
         @return 有破過此關卡回傳true，否則回傳false
         */
        bool getAlreadyComplete();
        
        /**
         @brief 玩家原有分數和本次遊玩的分數差，這裡的分數是星星數
         玩家原本已在該關卡取得2顆星，本次取得3顆星，那麼差為1
         @return 舊分數和新分數的差
         */
        int getNewHighScoreDiff();
        
        /**
         @brief 依據玩家目前取得的分數來更新記分板上的星星狀態(亮或暗)
         */
        void updateScoreBarStar();
    private:
        // 遊戲結束時間
        float overGameTime;
        
        // 是否破關
        bool isVictory;
        
        // 是否重複破關
        bool alreadyComplete;
        
        // 先前破關所取得的星星數
        int alreadycompleteStar;
        
        // 是否取得最新高分
        bool isNewHighScore;
        
        // 新分數與舊分數的差
        int newHighScoreDiff;
        
        // 存放線路0會落下甜點的時間點
        std::vector<float> road0TimeConfig;
        
        // 存放線路1會落下甜點的時間點
        std::vector<float> road1TimeConfig;
        
        // 存放線路2會落下甜點的時間點
        std::vector<float> road2TimeConfig;

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
         @brief 初始化關卡參數設定
         */
        void initLevelSetting();
        
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
         @brief 計算玩家得到的分數可以獲得幾顆星星
         @return 玩家獲得的星星數
         */
        int calculateScores();

        /**
         @brief 顯示時間中止標示
         */
        void showTimesUp();
        
        /**
         @brief 取得進度條的座標位置
         @return 一個二維向量，代表進度條的二維坐標
         */
        Vec2 getProgressPosition();

        /**
         @brief 取得記分板星星的座標位置
         @param index 星星的索引，0代表左邊的星星，1是中間，2是右邊
         @return 一個二維向量，代表星星的二維坐標
         */
        Vec2 getScoreStarPosition(int index);
        
        /**
         @brief 取得時間終止標示的座標位置
         @return 一個二維向量，代表時間終止標示的二維坐標
         */
        Vec2 getTimesUpPosition();

        // 上一個甜點的路線
        int lastSweetRoad;

        /**
         @brief 檢查此時機點是否可以設置炸彈
         @param road 本次甜點出現的路線
         @return 是否要將甜點改為炸彈
         */
        bool checkBombTiming(int road);

    };
}


#endif /* _GameScene_PlayScene_H_ */
