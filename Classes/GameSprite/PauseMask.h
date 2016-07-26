#ifndef _GameSprite_PauseMask_H_
#define _GameSprite_PauseMask_H_

#include "cocos2d.h"
#include "BaseSprite.h"
#include "Manager/SceneManager.h"
#include "Manager/SpriteManager.h"


namespace GameSprite
{
    /**
     @brief 暫停遮罩，用來將選單背後的畫面作黑屏
     */
    class PauseMask : public BaseSprite
    {
    public:
        /**
         @brief 建構式
         @param image 遮罩要套用的圖檔
         */
        PauseMask(std::string image);

        /**
         @brief 將按鈕加入事件監聽，按鈕會開始偵測觸控輸入
         */
        void addEventListener();
    private:
        /**
         @brief 偵測暫停遮罩被按下的狀態，這裡不會作任何動作，但會偵測觸控狀態
         @param touch 觸控區塊資訊
         @param event 事件監聽物件
         @return 一個布林變數，代表此狀態結束後是否要繼續監聽其他事件
         */
        static bool onTouchBegan(Touch *touch, Event *event);

        /**
         @brief 偵測暫停遮罩點擊結束的狀態
         會將暫停選單關閉，並繼續進行遊戲
         @param touch 觸控區塊資訊
         @param event 事件監聽物件
         */
        static void onTouchEnded(Touch *touch, Event *event);

        /**
         @brief 偵測暫停遮罩被拖曳的狀態，這裡不會執行任何動作
         @param touch 觸控區塊資訊
         @param event 事件監聽物件
         */
        static void onTouchMoved(Touch *touch, Event *event);

        /**
         @brief 偵測暫停遮罩被取消的狀態，這裡不會執行任何動作
         @param touch 觸控區塊資訊
         @param event 事件監聽物件
         */
        static void onTouchCanceled(Touch *touch, Event *event);
    };
}


#endif /* _GameSprite_PauseMask_H_ */
