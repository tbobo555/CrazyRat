#ifndef _GameSprite_StageButton_H_
#define _GameSprite_StageButton_H_

#include "BaseSprite.h"
#include "cocos2d.h"

USING_NS_CC;

namespace GameSprite
{
    /**
     @brief 關卡按鈕
     */
    class StageButton : public BaseSprite
    {
    public:
        /**
         @brief 建構式
         @param image 關卡按鈕要使用的圖檔
         @param pEpisodeNumber 該關卡按鈕的章節編號
         @param pStageNumber 關卡按鈕的關卡編號
         */
        StageButton(std::string image, int pEpisodeNumber, int pStageNumber);
        
        // 章節編號
        int episodeNumber;
        
        // 關卡編號
        int stageNumber;
        
        // 關卡是否被上鎖
        bool isLocked;
        
        /** 
         @brief 將關卡上鎖
         */
        void locked();
        
        /** 
         @brief 將關卡解鎖
         */
        void unlocked();
        
        /**
         @brief 加入事件監聽，物件會開始偵測觸控輸入
         */
        void addEventListener();
    private:
        /**
         @brief 偵測關卡按鈕被按下的狀態，按鈕會變小
         @param touch 觸控區塊資訊
         @param event 事件監聽物件
         @return 一個布林變數，代表此狀態結束後是否要繼續監聽其他事件
         */
        static bool onTouchBegan(Touch *touch, Event *event);
        
        /**
         @brief 偵測關卡按鈕點擊結束的狀態
         點擊後將畫面切換至該關卡的闖關畫面
         @param touch 觸控區塊資訊
         @param event 事件監聽物件
         */
        static void onTouchEnded(Touch *touch, Event *event);
        
        /**
         @brief 偵測關卡按鈕被拖曳的狀態，這裡不會執行任何動作
         @param touch 觸控區塊資訊
         @param event 事件監聽物件
         */
        static void onTouchMoved(Touch *touch, Event *event);
        
        /**
         @brief 偵測關卡按鈕被拖曳的狀態，這裡不會執行任何動作
         @param touch 觸控區塊資訊
         @param event 事件監聽物件
         */
        static void onTouchCanceled(Touch *touch, Event *event);
    };
}

#endif /* _GameSprite_StageButton_H_ */
