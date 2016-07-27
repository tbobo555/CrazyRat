#ifndef _GameScene_PlayScene_H_
#define _GameScene_PlayScene_H_

#include <queue>
#include "cocos2d.h"
#include "BaseScene.h"
#include "Manager/SpriteManager.h"
#include "Manager/ScoresManager.h"
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


USING_NS_CC;

namespace GameScene
{
    /**
     @brief 遊戲場景，玩家開始遊玩關卡的場景
     */
    class PlayScene : public BaseScene
    {
    public:
        
        /**
         @brief 建構式
         @param pEpisodeNumber 該遊戲場景的章節編號
         @param pStageNumber 該遊戲場景的關卡編號
         */
        PlayScene(int pEpisodeNumber, int pStageNumber);
        
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
        
        // 本關卡的章節編號
        int episodeNumber;
        
        // 本關卡的關卡編號
        int stageNumber;
        
        // 背景物件
        GameSprite::Background* playBackground;
        
        // 遊戲進度條，up代表填會隨進度滿容器的物件
        GameSprite::ProgressBarUp* progressBarUp;
        
        // 遊戲進度條，down代表進度條的容器
        GameSprite::ProgressBarDown* progressBarDown;
        
        // 進度條實體物件，用來呈現遊戲進度
        ProgressTimer* timeBar;
        
        // 白豬
        GameSprite::Pig* road0Pig;
        
        // 紅豬
        GameSprite::Pig* road1Pig;
        
        // 粉紅豬
        GameSprite::Pig* road2Pig;
        
        // 路線0的雲
        GameSprite::Cloud* road0Cloud;
        
        // 路線1的雲
        GameSprite::Cloud* road1Cloud;
        
        // 路線2的雲
        GameSprite::Cloud* road2Cloud;
        
        // 遊戲記分板的光暈，會在玩家獲得分數時顯示
        GameSprite::Image* scoreHalo;
        
        // 遊戲計分版的右方星星，用來提示玩家目前得到幾顆星
        GameSprite::ScoreStar* scoreRightStar;
        
        // 遊戲計分版的左方星星，用來提示玩家目前得到幾顆星
        GameSprite::ScoreStar* scoreLeftStar;
        
        // 遊戲計分版的中間星星，用來提示玩家目前得到幾顆星
        GameSprite::ScoreStar* scoreMiddleStar;
        
        // 遊戲計分版的分數，不同的分數可以得到不同的星星
        Label* scores;
        
        // 路線0的甜點物件
        std::vector<GameSprite::Sweet*> road0SweetVector;
        
        // 路線1的甜點物件
        std::vector<GameSprite::Sweet*> road1SweetVector;
        
        // 路線2的甜點物件
        std::vector<GameSprite::Sweet*> road2SweetVector;
        
        // 取得路線0可以被使用的甜點物件索引
        std::vector<int> road0AvailableIndex;
        
        // 取得路線1可以被使用的甜點物件索引
        std::vector<int> road1AvailableIndex;
        
        // 取得路線2可以被使用的甜點物件索引
        std::vector<int> road2AvailableIndex;
        
        // 取得路線0目前正在被使用的甜點索引
        std::queue<int> road0RunningIndex;
        
        // 取得路線1目前正在被使用的甜點索引
        std::queue<int> road1RunningIndex;
        
        // 取得路線2目前正在被使用的甜點索引
        std::queue<int> road2RunningIndex;
        
        /** 
         @brief 取得指定路線最靠近豬的甜點索引
         @param road 路線編號
         @return 甜點索引
         */
        int getNearestSweetIndex(int road);
        
        /**
         @brief 取得指定路線最靠近豬的甜點物件
         @param road 路線編號
         @return 甜點物件
         */
        GameSprite::Sweet* getNearestSweet(int road);
    private:
        // 存放sprite sheet的快取物件
        SpriteFrameCache* spriteCache;
        
        // 遊戲結束時間
        float overGameTime;
        
        // 是否破關
        bool isVictory;
        
        // 是否暫停
        bool isPaused;
        
        // 是否重複破關
        bool alreadyComplete;
        
        // 先前破關所取得的星星數
        int alreadycompleteStar;
        
        // 是否取得最新高分
        bool isNewHighScore;
        
        // 新分數與舊分數的差
        int newHighScoreDiff;
        
        // 遊戲開始的倒數時間
        int prepareTime;
        
        // 倒數時間的實體物件
        GameSprite::Image* prepareNumber;
        
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
        void initConfig();
        
        // 遊戲已經開始的時間
        float playTime;
        
        /**
         @brief 遊戲主要迴圈的schedule，主要檢查遊戲是否結束和玩家的勝利與失敗
         @param delta 多久執行一次schedule
         */
        void gameUpdate(float delta);
        
        /**
         @brief 計算玩家得到的分數可以獲得幾顆星星
         @return 玩家獲得的星星數
         */
        int calculateScores();
        
        // 路線0會使用到的甜點的最大數量，此變數尚未使用
        int road0MaxSpriteNumber;
        
        // 路線1會使用到的甜點的最大數量，此變數尚未使用
        int road1MaxSpriteNumber;
        
        // 路線2會使用到的甜點的最大數量，此變數尚未使用
        int road2MaxSpriteNumber;
        
        // 路線0目前的甜點索引，此索引代表已經落下的甜點數量
        int road0CurrentIndex;
        
        // 路線1目前的甜點索引，此索引代表已經落下的甜點數量
        int road1CurrentIndex;
        
        // 路線2目前的甜點索引，此索引代表已經落下的甜點數量
        int road2CurrentIndex;
        
        // 存放線路0會落下甜點的時間點
        std::vector<float> road0TimeConfig;
        
        // 存放線路1會落下甜點的時間點
        std::vector<float> road1TimeConfig;
        
        // 存放線路2會落下甜點的時間點
        std::vector<float> road2TimeConfig;
        
        // 路線0每一個落下甜點的類型
        std::vector<int> road0TypeConfig;
        
        // 路線1每一個落下甜點的類型
        std::vector<int> road1TypeConfig;
        
        // 路線2每一個落下甜點的類型
        std::vector<int> road2TypeConfig;
        
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
         @brief 取得背景圖的座標位置
         @return 一個二維向量，代表背景圖的二維坐標
         */
        Vec2 getBackgroundPosition();
        
        /**
         @brief 取得指定路線上的豬的座標位置
         @param roadNumber 路線編號
         @return 一個二維向量，代表豬的二維坐標
         */
        Vec2 getPigPosition(int roadNumber);
        
        /**
         @brief 取得指定路線上的雲的座標位置
         @param roadNumber 路線編號
         @return 一個二維向量，代表雲的二維坐標
         */
        Vec2 getCloudPosition(int roadNumber);
        
        /**
         @brief 取得進度條的座標位置
         @return 一個二維向量，代表進度條的二維坐標
         */
        Vec2 getProgressPosition();
        
        /**
         @brief 取得指定路線上的甜點的座標位置
         @param roadNumber 路線編號
         @return 一個二維向量，代表甜點的二維坐標
         */
        Vec2 getSweetPosition(int roadNumber);
        
        /**
         @brief 取得記分板光暈的座標位置
         @return 一個二維向量，代表光暈的二維坐標
         */
        Vec2 getScoreHaloPosition();
        
        /**
         @brief 取得記分板星星的座標位置
         @param index 星星的索引，0代表左邊的星星，1是中間，2是右邊
         @return 一個二維向量，代表星星的二維坐標
         */
        Vec2 getScoreStarPosition(int index);
        
        /**
         @brief 取得記分板分數的座標位置
         @return 一個二維向量，代表分數的二維坐標
         */
        Vec2 getScoresPosition();
        
        /**
         @brief 將Prepare Number從場景中移除
         */
        void removePrepareNumber();
    };
}


#endif /* _GameScene_PlayScene_H_ */
