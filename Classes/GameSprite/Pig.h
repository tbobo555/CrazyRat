#ifndef _GameSprite_Pig_H_
#define _GameSprite_Pig_H_

#include "cocos2d.h"
#include "BaseSprite.h"
#include "Mouth.h"
#include "Image.h"
#include "ScoreStar.h"
#include "Manager/SceneManager.h"
#include "Manager/ScoresManager.h"
#include "Manager/SpriteManager.h"
#include "Manager/SoundsManager.h"

namespace GameSprite
{
    /**
     @brief 豬
     */
    class Pig : public BaseSprite
    {
    public:
        /**
         @brief 建構式
         @param image 豬要套用的圖檔
         @param pRoadIndex 豬要在哪一個路線
         @param pigType 豬的類型
         */
        Pig(std::string image, int pRoadIndex, int pigType);

        /**
         @brief 解構式
         */
        ~Pig();

        // 豬被放置的路線
        int roadIndex;

        // 豬的類型
        int pigType;

        // 豬的生命值
        int hp;

        /**
         @brief 豬吃東西的動作
         @return 回傳吃東西的分數
         */
        int eat();

        /**
         @brief 豬受傷的動作，會讓hp減少
         @param byBomb 是否被炸彈所傷
         */
        void hurt(bool byBomb = false);

        /**
         @brief 豬眨眼的動作
         */
        void wink();
        
        /**
         @brief 紀錄豬的位置
         */
        void recordPigPosition(Vec2 position);

        /**
         @brief 將按鈕加入事件監聽，按鈕會開始偵測觸控輸入
         */
        void addEventListener();
    private:
        Vec2 originPosition;
        
        // 豬被甜點砸到的爆炸圖片
        Image* explode;
        
        // 得分特效 - Good
        Image* goodEffect;
        
        // 得分特效 - Great
        Image* greatEffect;

        // 得分特效 - Perfect
        Image* perfectEffect;

        // 豬的嘴巴圖片，吃東西時會顯示
        Mouth* mouth;

        /**
         @brief 隱藏豬的嘴巴
         */
        void hideMouth();

        /**
         @brief 顯示豬吃東西的動畫
         */
        void showEatAnimation();

        /**
         @brief 顯示豬被甜點砸到的動畫
         */
        void showExplode();
        
        /**
         @brief 顯示豬被炸彈砸到的動畫
         */
        void showBombExplode();

        /**
         @brief 隱藏豬被甜點砸到的動畫，這個方法會用shedule的方式來呼叫
         @param delta 時間常數，代表要多久執行一次
         */
        void hideExplode(float delta);
        
        /**
         @brief 顯示得分特效
         @param type 得分的種類[Good, Great, Perfect]
         */
        void showScoreEffect(int type);
        
        /**
         @brief 初始化得分特效的資訊
         */
        void initAllScoreEffect();
        
        /**
         @brief 重設豬的位置
         */
        void resetPigPosition();
        
        /**
         @brief 得分特效的座標位置
         */
        Vec2 getEffectPosition();

        /**
         @brief 偵測豬被按下的狀態，會顯示豬吃東西的動畫
         @param touch 觸控區塊資訊
         @param event 事件監聽物件
         @return 一個布林變數，代表此狀態結束後是否要繼續監聽其他事件
         */
        static bool onTouchBegan(Touch *touch, Event *event);

        /**
         @brief 偵測豬點擊結束的狀態，這裡不會執行任何動作
         @param touch 觸控區塊資訊
         @param event 事件監聽物件
         */
        static void onTouchEnded(Touch *touch, Event *event);

        /**
         @brief 偵測豬被拖曳的狀態，這裡不會執行任何動作
         @param touch 觸控區塊資訊
         @param event 事件監聽物件
         */
        static void onTouchMoved(Touch *touch, Event *event);

        /**
         @brief 偵測豬被取消的狀態，這裡不會執行任何動作
         @param touch 觸控區塊資訊
         @param event 事件監聽物件
         */
        static void onTouchCanceled(Touch *touch, Event *event);
    };
}


#endif /* _GameSprite_Pig_H_ */
