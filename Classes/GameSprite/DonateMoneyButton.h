#ifndef _GameSprite_DonateMoneyButton_H_
#define _GameSprite_DonateMoneyButton_H_

#include "cocos2d.h"
#include "BaseSprite.h"
#include "Manager/SoundsManager.h"

namespace GameSprite
{
    class DonateMoneyButton : public BaseSprite
    {
    public:
        /**
         @brief 建構式
         @param image 捐贈按鈕要使用的圖檔
         @param money 捐贈的金額
         */
        DonateMoneyButton(std::string image, int money);
        
        /**
         @brief 將精靈加入事件監聽，精靈會開始偵測觸控輸入
         */
        void addEventListener();
    private:
        // 捐贈金額
        int money;
        
        /**
         @brief 偵測捐贈按鈕被按下的狀態，按鈕會變小
         @param touch 觸控區塊資訊
         @param event 事件監聽物件
         @return 一個布林變數，代表此狀態結束後是否要繼續監聽其他事件
         */
        static bool onTouchBegan(Touch *touch, Event *event);
        
        /**
         @brief 偵測捐贈按鈕點擊結束的狀態
         會將場景切換至episode scene
         @param touch 觸控區塊資訊
         @param event 事件監聽物件
         */
        static void onTouchEnded(Touch *touch, Event *event);
        
        /**
         @brief 偵測捐贈按鈕被拖曳的狀態，這裡不會執行任何動作
         @param touch 觸控區塊資訊
         @param event 事件監聽物件
         */
        static void onTouchMoved(Touch *touch, Event *event);
        
        /**
         @brief 偵測捐贈按鈕被取消的狀態，這裡不會執行任何動作
         @param touch 觸控區塊資訊
         @param event 事件監聽物件
         */
        static void onTouchCanceled(Touch *touch, Event *event);
    };
}

#endif /* _GameSprite_DonateMoneyButton_H_ */
