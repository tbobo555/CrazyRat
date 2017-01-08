#ifndef _GameSprite_Boss_H_
#define _GameSprite_Boss_H_

#include "cocos2d.h"
#include "BaseSprite.h"
#include "GameSprite/Image.h"
#include "Lib/TextureCreator.h"
#include "Manager/SceneManager.h"

USING_NS_CC;


namespace GameSprite
{
    class Boss : public BaseSprite
    {
    public:
        /**
         @brief 建構式
         @param type 魔王類型
         */
        Boss(int type);
        
        /**
         @brief 解構式
         */
        ~Boss();
        
        // 魔王的生命值
        int life;
        
        // 是否正在進行攻擊
        bool isAttacking;
        
        /**
         @brief 魔王被攻擊所觸發的方法
         */
        void hurt();
        
        /**
         @brief 魔王陣亡所觸發的方法
         */
        void dead();
        
        /**
         @brief 從快取設置魔王的受傷圖檔
         */
        void setHurtImage();
        
        /**
         @brief 從快取設置魔王的陣亡圖檔
         */
        void setDeadImage();
        
        /**
         @brief 攻擊完畢
         */
        void attackDone();
        
        /**
         @brief 攻擊路線0
         */
        void attackRoad0();
        
        /**
         @brief 攻擊路線1
         */
        void attackRoad1();
        
        /**
         @brief 攻擊路線2
         */
        void attackRoad2();
        
        /**
         @brief 攻擊模式1
         */
        void attackMode1();
        
        /**
         @brief 開始魔王基本動畫
         */
        void startBaseMotion();
        
        /**
         @brief 自動轉向
         */
        void autoSkewAdjust();
    private:
        // 被豬攻擊的爆炸圖片
        GameSprite::Image* explode;
        
        // 魔王的類型
        int type;
        
        // 下一個移動目標
        Vec2 nextTargetPosition;
        
        /**
         @brief 設置移動目標為線路0
         */
        void setMoveTarget0();
        
        /**
         @brief 設置移動目標為線路1
         */
        void setMoveTarget1();
        
        /**
         @brief 設置移動目標為線路2
         */
        void setMoveTarget2();
        
        /**
         @brief 隱藏被豬攻擊的動畫
         @param delta 時間常數，代表要多久執行一次
         */
        void hideExplode(float delta);

        /**
         @brief 顯示被豬攻擊的特效
         */
        void showExplode();
        
        /**
         @brief 取得魔王動態圖檔路徑
         @param 圖檔動作參數
         @return 圖檔路徑
         */
        std::string getBossImagePath(int index);
    };
}

#endif /* _GameSprite_Boss_H_ */
