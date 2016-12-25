#ifndef _GameScene_MenuScene_H_
#define _GameScene_MenuScene_H_

#include "cocos2d.h"
#include "BaseScene.h"
#include "GameSprite/SettingButton.h"
#include "GameSprite/Background.h"
#include "GameSprite/SettingBackButton.h"
#include "GameSprite/MusicButton.h"
#include "GameSprite/SoundsButton.h"
#include "GameSprite/SettingMask.h"
#include "GameSprite/DonateButton.h"
#include "GameSprite/DonateMoneyButton.h"
#include "GameSprite/DonateBackButton.h"
#include "GameSprite/AboutButton.h"
#include "GameSprite/Image.h"
#include "GameSprite/CreditMask.h"
#include "Manager/SpriteManager.h"

namespace GameScene
{
    /*
     @brief 選單場景，用來開啟或關閉音樂與音效
     */
    class MenuScene : public BaseScene
    {
    public:
        /**
         @brief 建構式
         */
        MenuScene();

        /**
         @brief 初始化場景
         */
        void initScene();

        /**
         @brief 釋放場景的所有資源
         */
        void releaseScene();

        /**
         @brief 打開設定選單
         */
        void openMenu();

        /**
         @brief 關閉設定選單
         */
        void closeMenu();

        // 選單場景的背景圖
        GameSprite::Background* settingBackground;

        // 選單場景的設定按鈕
        GameSprite::SettingButton* settingButton;

        // 返回按鈕
        GameSprite::SettingBackButton* settingBackButton;

        // 音樂開關按鈕
        GameSprite::MusicButton* musicButton;

        // 音效開關按鈕
        GameSprite::SoundsButton* soundsButton;

        // 選單的遮罩
        GameSprite::SettingMask* settingMask;
        
        // 關於按鈕
        GameSprite::AboutButton* aboutButton;
        
        // 進入捐贈畫面的按鈕
        GameSprite::DonateButton* donateButton;
        
        // 捐贈兩元按鈕
        GameSprite::DonateMoneyButton* donate2MoneyButton;
        
        // 捐贈五元按鈕
        GameSprite::DonateMoneyButton* donate5MoneyButton;
        
        // 捐贈返回按鈕
        GameSprite::DonateBackButton* donateBackButton;
        
        // 捐贈畫面標題
        GameSprite::Image* donateTitle;
        
        // 製作與感謝名單
        GameSprite::CreditMask* creditMask;
        
    private:
        /**
         @brief 取得背景的放置座標
         @return 一個二維向量，代表背景放置的座標
         */
        Vec2 getSettingBackgroundPosition();

        /**
         @brief 取得設定按鈕的放置座標
         @return 一個二維向量，代表設定按鈕放置的座標
         */
        Vec2 getSettingButtonPosition();

        /**
         @brief 取得設定按鈕的放置座標
         @return 一個二維向量，代表設定按鈕放置的座標
         */
        Vec2 getSettingBackButtonPosition();

        /**
         @brief 取得音樂按鈕的放置座標
         @return 一個二維向量，代表音樂按鈕放置的座標
         */
        Vec2 getMusicButtonPosition();

        /**
         @brief 取得音效按鈕的放置座標
         @return 一個二維向量，代表音效按鈕放置的座標
         */
        Vec2 getSoundsButtonPosition();
        
        /**
         @brief 取得音效按鈕的放置座標
         @return 一個二維向量，代表音效按鈕放置的座標
         */
        Vec2 getAboutButtonPosition();
        
        /**
         @brief 取得音效按鈕的放置座標
         @return 一個二維向量，代表音效按鈕放置的座標
         */
        Vec2 getDonateButtonPosition();
        
        /**
         @brief 取得音效按鈕的放置座標
         @return 一個二維向量，代表音效按鈕放置的座標
         */
        Vec2 getDonate2ButtonPoition();
        
        /**
         @brief 取得音效按鈕的放置座標
         @return 一個二維向量，代表音效按鈕放置的座標
         */
        Vec2 getDonate5ButtonPoition();
        
        /**
         @brief 取得音效按鈕的放置座標
         @return 一個二維向量，代表音效按鈕放置的座標
         */
        Vec2 getDonateBackButtonPosition();
        
        
        /**
         @brief 取得音效按鈕的放置座標
         @return 一個二維向量，代表音效按鈕放置的座標
         */
        Vec2 getDonateTitlePosition();
    };
}

#endif /* _GameSprite_MenuScene_H_ */
