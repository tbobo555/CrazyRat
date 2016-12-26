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
         @param image 初始化的圖檔
         */
        Boss(std::string image);
        
        /**
         @brief 解構式
         */
        ~Boss();
        
        // 魔王的生命值
        int life;
        
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
         @param index 圖檔在快取中的參數
         */
        void setHurtImage(int index);
    private:
        // 被豬攻擊的爆炸圖片
        GameSprite::Image* explode;

        /**
         @brief 隱藏被豬攻擊的動畫
         @param delta 時間常數，代表要多久執行一次
         */
        void hideExplode(float delta);

        /**
         @brief 顯示被豬攻擊的特效
         */
        void showExplode();
    };
}

#endif /* _GameSprite_Boss_H_ */
