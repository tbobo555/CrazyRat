#ifndef _GameSprite_NextButton_H_
#define _GameSprite_NextButton_H_

#include "cocos2d.h"
#include "BaseSprite.h"
#include "Manager/SoundsManager.h"

USING_NS_CC;

namespace GameSprite
{
    /**
     @brief 繼續按鈕
     */
    class NextButton : public BaseSprite
    {
    public:
        /**
         @brief 建構式
         @param image 繼續按鈕要使用的圖檔
         */
        NextButton(std::string image);

        /**
         @brief 將精靈加入事件監聽，精靈會開始偵測觸控輸入
         */
        void addEventListener();
    private:
        /**
         @brief 偵測繼續按鈕被按下的狀態，按鈕會變小
         @param touch 觸控區塊資訊
         @param event 事件監聽物件
         @return 一個布林變數，代表此狀態結束後是否要繼續監聽其他事件
         */
        static bool onTouchBegan(Touch *touch, Event *event);

        /**
         @brief 偵測繼續按鈕點擊結束的狀態
         會將場景切換至episode scene
         @param touch 觸控區塊資訊
         @param event 事件監聽物件
         */
        static void onTouchEnded(Touch *touch, Event *event);

        /**
         @brief 偵測繼續按鈕被拖曳的狀態，這裡不會執行任何動作
         @param touch 觸控區塊資訊
         @param event 事件監聽物件
         */
        static void onTouchMoved(Touch *touch, Event *event);

        /**
         @brief 偵測繼續按鈕被取消的狀態，這裡不會執行任何動作
         @param touch 觸控區塊資訊
         @param event 事件監聽物件
         */
        static void onTouchCanceled(Touch *touch, Event *event);
    };
}

#endif /* _GameSprite_NextButton_H_ */
