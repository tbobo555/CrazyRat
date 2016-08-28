#ifndef _GameSprite_EpisodeButton_H_
#define _GameSprite_EpisodeButton_H_

#include "cocos2d.h"
#include "BaseSprite.h"
#include "Lib/TextureCreator.h"
#include "Manager/SoundsManager.h"

USING_NS_CC;

namespace GameSprite
{
    /**
     @brief 章節按鈕
     */
    class EpisodeButton : public BaseSprite
    {
    public:
        /**
         @brief 建構式
         @param image 章節按鈕要使用的圖檔
         @param episodeNumber 章節編號，用來辨別玩家要進入
         */
        EpisodeButton(std::string image, int episodeNumber);

        // 章節編號
        int episodeNumber;

        // 此章節是否被鎖住
        bool isLocked;

        /**
         @brief 將此章節上鎖，玩家無法遊玩此章節
         */
        void locked();

        /**
         @brief 將此章節解鎖
        */
        void unlocked();

        /**
         @brief 加入事件監聽，物件會開始偵測觸控輸入
        */
        void addEventListener();
    private:
        /**
         @brief 偵測章節按鈕被按下的狀態，按鈕會變小
         @param touch 觸控區塊資訊
         @param event 事件監聽物件
         @return 一個布林變數，代表此狀態結束後是否要繼續監聽其他事件
         */
        static bool onTouchBegan(Touch *touch, Event *event);

        /**
         @brief 偵測章節按鈕點擊結束的狀態
         點擊結束後會將場景切換至玩家所選擇的章節場景
         @param touch 觸控區塊資訊
         @param event 事件監聽物件
         */
        static void onTouchEnded(Touch *touch, Event *event);

        /**
         @brief 偵測章節按鈕被拖曳的狀態，這裡不會執行任何動作
         @param touch 觸控區塊資訊
         @param event 事件監聽物件
         */
        static void onTouchMoved(Touch *touch, Event *event);

        /**
         @brief 偵測章節按鈕被拖曳的狀態，這裡不會執行任何動作
         @param touch 觸控區塊資訊
         @param event 事件監聽物件
         */
        static void onTouchCanceled(Touch *touch, Event *event);
    };
}


#endif /* _GameSprite_EpisodeButton_H_ */
