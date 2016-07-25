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
#include "Config/ImageConfig.h"
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
    };
}

#endif /* _GameSprite_MenuScene_H_ */
