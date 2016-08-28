#ifndef _GameSprite_StartButton_H_
#define _GameSprite_StartButton_H_

#include "BaseSprite.h"
#include "cocos2d.h"
#include "Manager/SoundsManager.h"

USING_NS_CC;

namespace GameSprite
{
    /**
     @brief 開始按鈕，按下進入章節選擇場景
     */
    class StartButton : public BaseSprite
    {
    public:
        /**
         @brief 建構式
         @param image 開始按鈕要使用的圖檔
         */
        StartButton(std::string image);
        
        /**
         @brief 加入事件監聽，物件會開始偵測觸控輸入
         */
        void addEventListener();
    private:
        /**
         @brief 偵測開始按鈕被按下的狀態，按鈕會變小
         @param touch 觸控區塊資訊
         @param event 事件監聽物件
         @return 一個布林變數，代表此狀態結束後是否要繼續監聽其他事件
         */
        static bool onTouchBegan(Touch *touch, Event *event);
        
        /**
         @brief 偵測開始按鈕點擊結束的狀態
         將場景切換至章節選擇
         @param touch 觸控區塊資訊
         @param event 事件監聽物件
         */
        static void onTouchEnded(Touch *touch, Event *event);
        
        /**
         @brief 偵測開始按鈕被拖曳的狀態，這裡不會執行任何動作
         @param touch 觸控區塊資訊
         @param event 事件監聽物件
         */
        static void onTouchMoved(Touch *touch, Event *event);
        
        /**
         @brief 偵測開始按鈕被拖曳的狀態，這裡不會執行任何動作
         @param touch 觸控區塊資訊
         @param event 事件監聽物件
         */
        static void onTouchCanceled(Touch *touch, Event *event);
    };
}

#endif /* defined(_GameSprite_StartButton_H_) */
