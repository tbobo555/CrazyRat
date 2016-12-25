#ifndef _GameScene_ChallengeScene_H_
#define _GameScene_ChallengeScene_H_

#include "cocos2d.h"
#include "GameScene/BaseScene.h"
#include "GameSprite/Background.h"
#include "GameSprite/BossButton.h"
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
        
        /**
         @brief 場景初始化，將闖關場景會用到的資源載入
         */
        void initScene();
        
        /**
         @brief 釋放闖關場景的所有資源
         */
        void releaseScene();
    private:
        // 闖關背景
        GameSprite::Background* challengeBackground;
        
        // 第一關按鈕
        GameSprite::BossButton* bossButton1;
        
        /**
         @brief 取得闖關按鈕的座標位置
         @return 一個二維坐標
         */
        Vec2 getBossButtonPosition();
    };
}

#endif /* _GameScene_ChallengeScene_H_ */
