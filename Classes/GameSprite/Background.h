#ifndef _GameSprite_Background_H_
#define _GameSprite_Background_H_

#include "BaseSprite.h"
#include "cocos2d.h"


USING_NS_CC;

namespace GameSprite
{
    /**
     @brief 背景
     */
    class Background : public BaseSprite
    {
    public:
        /**
         @brief 背景
         @param image 背景要使用的圖檔
         */
        Background(std::string image);

        /**
         @brief 將精靈加入事件監聽，精靈會開始偵測觸控輸入
         */
        void addEventListener();
    private:
        /**
         @brief 偵測背景被按下的狀態，不會執行任何動作，但仍會偵測背景是否被點擊
         @param touch 觸控區塊資訊
         @param event 事件監聽物件
         @return 一個布林變數，代表此狀態結束後是否要繼續監聽其他事件
         */
        static bool onTouchBegan(Touch* touch, Event* event);

        /**
         @brief 偵測背景點擊結束的狀態，這裡不會執行任何動作
         @param touch 觸控區塊資訊
         @param event 事件監聽物件
         */
        static void onTouchEnded(Touch* touch, Event* event);

        /**
         @brief 偵測背景被拖曳的狀態，這裡不會執行任何動作
         @param touch 觸控區塊資訊
         @param event 事件監聽物件
         */
        static void onTouchMoved(Touch* touch, Event* event);

        /**
         @brief 偵測背景被取消的狀態，這裡不會執行任何動作
         @param touch 觸控區塊資訊
         @param event 事件監聽物件
         */
        static void onTouchCanceled(Touch* touch, Event* event);

    };
}


#endif /* _GameSprite_Background_H_ */
