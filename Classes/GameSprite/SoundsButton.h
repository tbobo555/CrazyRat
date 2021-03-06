#ifndef _GameSprite_SoundsButton_H_
#define _GameSprite_SoundsButton_H_

#include "BaseSprite.h"
#include "cocos2d.h"
#include "Db/SwitchSetting.h"
#include "Manager/SoundsManager.h"

USING_NS_CC;

namespace GameSprite
{
    /**
     @brief 音效開關按鈕
     */
    class SoundsButton : public BaseSprite
    {
    public:
        /**
         @brief 建構式
         @param image 音效開關要使用的圖檔
         */
        SoundsButton(std::string image);
        
        /**
         @brief 將開關加入事件監聽，音效開關按鈕會開始偵測觸控輸入
         */
        void addEventListener();
        
        // 開關是否被打開
        bool isOpen;
        
        /**
         @brief 將音效關閉
         */
        void turnOff();
        
        /**
         @brief 將音效打開
         */
        void turnOn();
    private:
        /**
         @brief 偵測音效開關按鈕被按下的狀態，按鈕會變小
         @param touch 觸控區塊資訊
         @param event 事件監聽物件
         @return 一個布林變數，代表此狀態結束後是否要繼續監聽其他事件
         */
        static bool onTouchBegan(Touch *touch, Event *event);
        
        /**
         @brief 偵測音效開關按鈕點擊結束的狀態
         音效按鈕會切換圖片並關閉或打開音效
         @param touch 觸控區塊資訊
         @param event 事件監聽物件
         */
        static void onTouchEnded(Touch *touch, Event *event);
        
        /**
         @brief 偵測音效開關按鈕被拖曳的狀態，這裡不會執行任何動作
         @param touch 觸控區塊資訊
         @param event 事件監聽物件
         */
        static void onTouchMoved(Touch *touch, Event *event);
        
        /**
         @brief 偵測音效開關按鈕被取消的狀態，這裡不會執行任何動作
         @param touch 觸控區塊資訊
         @param event 事件監聽物件
         */
        static void onTouchCanceled(Touch *touch, Event *event);
    };
}

#endif /* defined(_GameSprite_SoundsButton_H_) */
