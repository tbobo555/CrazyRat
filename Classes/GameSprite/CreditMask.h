#ifndef _GameSprite_CreditMask_H_
#define _GameSprite_CreditMask_H_

#include "cocos2d.h"
#include "BaseSprite.h"

USING_NS_CC;

namespace GameSprite
{
    class CreditMask : public BaseSprite
    {
    public:
        /**
         @brief 建構式
         */
        CreditMask(std::string image);
        
        /**
         @brief 將遮罩加入事件監聽，會開始偵測觸控輸入
         */
        void addEventListener();
    private:
        /**
         @brief 偵測遮罩被按下的狀態，這裡不會執行任何動作，但仍會偵測點擊狀態
         @param touch 觸控區塊資訊
         @param event 事件監聽物件
         @return 一個布林變數，代表此狀態結束後是否要繼續監聽其他事件
         */
        static bool onTouchBegan(Touch *touch, Event *event);
        
        /**
         @brief 偵測遮罩點擊結束的狀態
         會將設定選單的畫面關閉
         @param touch 觸控區塊資訊
         @param event 事件監聽物件
         */
        static void onTouchEnded(Touch *touch, Event *event);
        
        /**
         @brief 偵測遮罩被拖曳的狀態，這裡不會執行任何動作
         @param touch 觸控區塊資訊
         @param event 事件監聽物件
         */
        static void onTouchMoved(Touch *touch, Event *event);
        
        /**
         @brief 偵測遮罩被取消的狀態，這裡不會執行任何動作
         @param touch 觸控區塊資訊
         @param event 事件監聽物件
         */
        static void onTouchCanceled(Touch *touch, Event *event);
    };
}

#endif /* _GameSprite_CreditMask_H_ */
