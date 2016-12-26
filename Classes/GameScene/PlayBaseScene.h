#ifndef _GameScene_PlayBaseScene_H_
#define _GameScene_PlayBaseScene_H_

#include <deque>
#include "cocos2d.h"
#include "Manager/SpriteManager.h"
#include "Manager/ScoresManager.h"
#include "Manager/MusicManager.h"
#include "Manager/SoundsManager.h"
#include "GameScene/BaseScene.h"
#include "GameSprite/Background.h"
#include "GameSprite/Sweet.h"
#include "GameSprite/Pig.h"
#include "GameSprite/Cloud.h"
#include "GameSprite/Image.h"
#include "GameSprite/Boss.h"

USING_NS_CC;

namespace GameScene
{
    class PlayBaseScene : public GameScene::BaseScene
    {
    public:
        /**
         @brief 建構式
         */
        PlayBaseScene();
        
        // 背景物件
        GameSprite::Background* playBackground;
        
        // 豬陣亡的爆破圖片
        GameSprite::Image* deadExplode;
        
        // 鬼魂
        GameSprite::Image* ghost;
        
        // 陣亡的豬的圖片
        GameSprite::Image* deadPig;
        
        // 路線0可以吃甜點的提示區塊
        GameSprite::Image* road0EatBlock;
        
        // 路線1可以吃甜點的提示區塊
        GameSprite::Image* road1EatBlock;
        
        // 路線2可以吃甜點的提示區塊
        GameSprite::Image* road2EatBlock;
        
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
        std::deque<int> road0RunningIndex;
        
        // 取得路線1目前正在被使用的甜點索引
        std::deque<int> road1RunningIndex;
        
        // 取得路線2目前正在被使用的甜點索引
        std::deque<int> road2RunningIndex;
        
        // 失敗路線的索引
        int failRoadIndex;
        
        /**
         @brief 初始化場景
         */
        virtual void initScene();
        
        /**
         @brief 釋放場景
         */
        virtual void releaseScene();
        
        /**
         @brief 開始遊戲迴圈，這這會新增一個schedule來更新遊戲畫面
         */
        virtual void play();
        
        /**
         @brief 暫停遊戲，包含所有正在進行的schedule
         */
        virtual void pauseScene();
        
        /**
         @brief 恢復遊戲，讓遊戲繼續進行
         */
        virtual void resumeScene();
        
        /**
         @brief 加上失敗場景
         */
        virtual void addLoseScene();
        
        /**
         @brief 加上勝利場景
         */
        virtual void addWinScene();
        
        /**
         @brief 依據玩家目前取得的分數來更新記分板上的星星狀態(亮或暗)
         */
        virtual void updateScoreBarStar();
        
        /**
         @brief 取得指定路線最靠近豬的甜點索引
         @param road 路線編號
         @return 甜點索引
         */
        int  getNearestSweetIndex(int road);
                
        /**
         @brief 取得指定路線最靠近豬的甜點物件
         @param road 路線編號
         @return 甜點物件
         */
        GameSprite::Sweet* getNearestSweet(int road);
        
        // 魔王圖片
        GameSprite::Boss* boss;
        
        // 白霧遮罩
        GameSprite::Image* whiteMask;
        
        /**
         @brief 魔王被擊中
         */
        void bossHurted();
        
        /**
         @brief 魔王被擊中後的回覆
         */
        void resetBossMotion();
        
        /**
         @brief 將魔王設置為未擊中
         */
        void setBossNotHurt();
        
        /**
         @brief 在魔王被擊中後，重置攻擊路線
         */
        int resetBossRoad;

        /**
         @brief 魔王是否被攻擊
         */
        bool bossIsHurting;
        
        bool bossIsDead;
        
        void showBossDeadAnimation();
        
        void removeBoss();
    protected:
        // 存放sprite sheet的快取物件
        SpriteFrameCache* spriteCache;
        
        // 是否暫停
        bool isPaused;
        
        // 遊戲開始的倒數時間
        int prepareTime;
        
        // 產生單一甜點的秒數
        float addSweetTime;
        
        // 要加入甜點的路線
        int addSweetRoad;

        // 倒數時間的實體物件
        GameSprite::Image* prepareNumber;
        
        // 遊戲已經開始的時間
        float playTime;
        
        // 路線0目前的甜點索引，此索引代表已經落下的甜點數量
        int road0CurrentIndex;
        
        // 路線1目前的甜點索引，此索引代表已經落下的甜點數量
        int road1CurrentIndex;
        
        // 路線2目前的甜點索引，此索引代表已經落下的甜點數量
        int road2CurrentIndex;
        
        /**
         @brief 遊戲主要迴圈的schedule，主要檢查遊戲是否結束和玩家的勝利與失敗
         @param delta 多久執行一次schedule
         */
        virtual void gameUpdate();
        
        /**
         @brief 路線0用來降下甜點的shedule
         會取得目前路線0可用的甜點物件，並讓該甜點落下
         @param shedule多久執行一次的時間
         */
        virtual void road0Update(float delta);
        
        /**
         @brief 路線1用來降下甜點的shedule
         會取得目前路線1可用的甜點物件，並讓該甜點落下
         @param shedule多久執行一次的時間
         */
        virtual void road1Update(float delta);
        
        /**
         @brief 路線2用來降下甜點的shedule
         會取得目前路線2可用的甜點物件，並讓該甜點落下
         @param shedule多久執行一次的時間
         */
        virtual void road2Update(float delta);
        
        /**
         @brief 更新倒數時間的schedule
         @param delta 多久執行一次schedule
         */
        virtual void prepareUpdate(float delta);
        
        /**
         @brief 倒數計時結束，遊戲正式開始
         甜點開始從天空降下，豬開始眨眼，進度條開始動，遊戲迴圈開始進行
         */
        virtual void prepareDone();
        
        /**
         @brief 將Prepare Number從場景中移除
         */
        void removePrepareNumber();

        /**
         @brief 更換陣亡爆炸的圖片
         */
        void changeDeadExplode();
        
        /**
         @brief 顯示陣亡豬的圖檔
         */
        void showDeadPig();
        
        /**
         @brief 顯示豬的鬼混
         */
        void showGhost();
        
        /**
         @brief 取得失敗豬的物件
         @brief 豬的實體物件
         */
        GameSprite::Pig* getFailedPig();
        
        /**
         @brief 取得失敗豬的圖片路徑
         @return 圖檔路徑
         */
        std::string getDeadPigImagePath();
        
        /**
         @brief 顯示失敗動畫
         @param failRoadIndex 造成遊戲失敗的路線索引
         */
        void showFailAnimation();
        
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
         @brief 取得指定路徑上的吃東西區塊的座標位置
         @param roadNumber 路線編號
         @return 一個二維向量，代表區塊的二維坐標
         */
        Vec2 getEatBlockPosition(int roadNumber);
        
        /**
         @brief 取得指定路線上的雲的座標位置
         @param roadNumber 路線編號
         @return 一個二維向量，代表雲的二維坐標
         */
        Vec2 getCloudPosition(int roadNumber);
        
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
         @brief 取得記分板分數的座標位置
         @return 一個二維向量，代表分數的二維坐標
         */
        Vec2 getScoresPosition();
    };
}

#endif /* _GameScene_PlayBaseScene_H_ */
