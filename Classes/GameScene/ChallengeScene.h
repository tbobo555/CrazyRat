#ifndef _GameScene_ChallengeScene_H_
#define _GameScene_ChallengeScene_H_

#include "cocos2d.h"
#include "GameScene/BaseScene.h"
#include "GameSprite/Background.h"
#include "GameSprite/BossButton.h"
#include "GameSprite/BackButton.h"
#include "Manager/SpriteManager.h"

namespace GameScene
{
    class ChallengeScene : public BaseScene
    {
    public:
        /**
         @brief 建構式
         */
        ChallengeScene();
        
        // 是否已執行過魔王按鈕的動畫
        bool isShowBossButtonAnimation;
        
        /**
         @brief 場景初始化，將闖關場景會用到的資源載入
         */
        void initScene();
        
        /**
         @brief 釋放闖關場景的所有資源
         */
        void releaseScene();
        
        /**
         @brief 顯示魔王按鈕動畫
         */
        void showBossButtonAmimation();
        
        /**
         @brief 顯示魔王按鈕
         */
        void showBossButton();
    private:
        // 魔王按鈕動畫的飛行時間
        float bossButtonAnimationPeriod;
        
        // 闖關背景
        GameSprite::Background* challengeBackground;
        
        // 返回按鈕
        GameSprite::BackButton* backButton;
        
        // 第0關按鈕
        GameSprite::BossButton* bossButton0;
        
        // 第1關按鈕
        GameSprite::BossButton* bossButton1;
        
        // 第2關按鈕
        GameSprite::BossButton* bossButton2;
        
        // 第3關按鈕
        GameSprite::BossButton* bossButton3;
        
        // 第4關按鈕
        GameSprite::BossButton* bossButton4;
        
        // 第5關按鈕
        GameSprite::BossButton* bossButton5;
        
        // 第6關按鈕
        GameSprite::BossButton* bossButton6;
        
        // 第7關按鈕
        GameSprite::BossButton* bossButton7;
        
        /**
         @brief 取得闖關按鈕的座標位置
         @param index 按鈕編號
         @return 一個二維坐標
         */
        Vec2 getBossButtonPosition(int index);
        
        /**
         @brief 魔王0按鈕的特效
         */
        void runBossButton0();
        
        /**
         @brief 魔王1按鈕的特效
         */
        void runBossButton1();
        
        /**
         @brief 魔王2按鈕的特效
         */
        void runBossButton2();
        
        /**
         @brief 魔王3按鈕的特效
         */
        void runBossButton3();
        
        /**
         @brief 魔王4按鈕的特效
         */
        void runBossButton4();
        
        /**
         @brief 魔王5按鈕的特效
         */
        void runBossButton5();
        
        /**
         @brief 魔王6按鈕的特效
         */
        void runBossButton6();
        
        /**
         @brief 魔王7按鈕的特效
         */
        void runBossButton7();
        
        /**
         @brief 魔王按鈕特效執行結束
         */
        void bossButtonAnimationDone();
        
        /**
         @brief 取得返回按鈕的座標位置
         */
        Vec2 getBackButtonPosition();
    };
}

#endif /* _GameScene_ChallengeScene_H_ */
