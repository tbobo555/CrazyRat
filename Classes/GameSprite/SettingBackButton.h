#ifndef _GameSprite_SettingBackButton_H_
#define _GameSprite_SettingBackButton_H_

#include "BaseSprite.h"
#include "cocos2d.h"
#include "Manager/SceneManager.h"
#include "Manager/SpriteManager.h"
#include "Manager/SoundsManager.h"

USING_NS_CC;

namespace GameSprite
{
    /**
     @brief 設定返回按鈕
     */
    class SettingBackButton : public BaseSprite
    {
    public:
        /**
         @brief 建構式
         @param 按鈕所需要的圖檔
         */
        SettingBackButton(std::string image);
        
        /**
         @brief 將按鈕加入事件監聽，按鈕會開始偵測觸控輸入
         */
        void addEventListener();
    private:
        /**
         @brief 偵測設定返回按鈕被按下的狀態，按鈕會變小
         @param touch 觸控區塊資訊
         @param event 事件監聽物件
         @return 一個布林變數，代表此狀態結束後是否要繼續監聽其他事件
         */
        static bool onTouchBegan(Touch *touch, Event *event);
        
        /**
         @brief 偵測設定返回按鈕點擊結束的狀態
         會將設定選單的畫面關閉
         @param touch 觸控區塊資訊
         @param event 事件監聽物件
         */
        static void onTouchEnded(Touch *touch, Event *event);
        
        /**
         @brief 偵測設定返回按鈕被拖曳的狀態，這裡不會執行任何動作
         @param touch 觸控區塊資訊
         @param event 事件監聽物件
         */
        static void onTouchMoved(Touch *touch, Event *event);
        
        /**
         @brief 偵測設定返回按鈕被取消的狀態，這裡不會執行任何動作
         @param touch 觸控區塊資訊
         @param event 事件監聽物件
         */
        static void onTouchCanceled(Touch *touch, Event *event);
    };
}

#endif /* defined(_GameSprite_SettingBackButton_H_) */
