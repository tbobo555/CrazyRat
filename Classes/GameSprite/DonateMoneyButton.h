#ifndef _GameSprite_DonateMoneyButton_H_
#define _GameSprite_DonateMoneyButton_H_

#include "cocos2d.h"
#include "BaseSprite.h"
#include "PluginIAP/PluginIAP.h"
#include "Manager/SoundsManager.h"

USING_NS_CC;

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
         @brief 解構式
         */
        ~DonateMoneyButton();
        
        // 金額文字是否已被設置當地幣別
        bool isSetLocalCurrency;
        
        /**
         @brief 取得金額
         @return 金額
         */
        int getMoney();
        
        /**
         @brief 將金額文字顯示成當地幣別
         */
        void setMoneyTextWithLocalCurrency();
        
        /**
         @brief 將精靈加入事件監聽，精靈會開始偵測觸控輸入
         */
        void addEventListener();
    private:
        // 捐贈金額
        int money;
        
        // 會依不同幣別顯示，金額的顯示字串，預設為美金
        Label* moneyText;
        
        /**
         @brief 取得金額文字的座標位置
         @return 二維坐標
         */
        Vec2 getMoneyTextPoition();
        
        /**
         @brief 偵測捐贈按鈕被按下的狀態，按鈕會變小
         @param touch 觸控區塊資訊
         @param event 事件監聽物件
         @return 一個布林變數，代表此狀態結束後是否要繼續監聽其他事件
         */
        static bool onTouchBegan(Touch *touch, Event *event);
        
        /**
         @brief 偵測捐贈按鈕點擊結束的狀態
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
