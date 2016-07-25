#ifndef _GameScene_StartScene_H_
#define _GameScene_StartScene_H_

#include "GameSprite/Background.h"
#include "GameSprite/StartButton.h"
#include "GameSprite/startTitle.h"
#include "GameSprite/image.h"
#include "Manager/SpriteManager.h"
#include "BaseScene.h"

namespace GameScene
{
    /**
     @brief 開始場景，遊戲最一開始的場景(在storyboard結束之後)
     */
    class StartScene : public BaseScene
    {
    public:
        /**
         @brief 建構式
         */
        StartScene();
        
        /**
         @brief 場景初始化，將開始場景會用到的資源載入
         */
        void initScene();
        
        /**
         @brief 釋放開始場景的所有資源
         */
        void releaseScene();
        
        /**
         @brief 執行開始場景的動畫
         場景標題會由上往下進場，小豬會由右邊進場，必隱藏相關設定與開始按鈕
         */
        void runAnimation();
        
        /**
         @brief 動畫結束後需要呼叫的方法
         會顯示設定與開始按鈕
         */
        void animationCallback();
        
        // 背景圖檔物件
        GameSprite::Background* startBackground;
        
        // 開始按鈕
        GameSprite::StartButton* startButton;
        
        // 開始場景的標題
        GameSprite::StartTitle* startTitle;
        
        // 紅豬
        GameSprite::Image* movePig0;
        
        // 粉紅豬
        GameSprite::Image* movePig1;
    private:
        
        /**
         @brief 取得開始按鈕的座標位置
         @return 一個二維向量，代表開始按鈕的座標
         */
        Vec2 getStartButtonPosition();
        
        /**
         @brief 取得開始標題的座標位置
         @return 一個二維向量，代表開始標題的座標
         */
        Vec2 getStartTitlePosition();
        
        /**
         @brief 取得紅豬動畫開始的座標位置
         @return 一個二維向量，代表紅豬動畫開始的座標
         */
        Vec2 getMovePig0StartPosition();
        
        /**
         @brief 取得紅豬動畫結束的座標位置
         @return 一個二維向量，代表紅豬動畫結束的座標
         */
        Vec2 getMovePig0EndPosition();
        
        /**
         @brief 取得粉紅豬動畫開始的座標位置
         @return 一個二維向量，代表粉紅豬動畫開始的座標
         */
        Vec2 getMovePig1StartPosition();
        
        /**
         @brief 取得粉紅豬動畫結束的座標位置
         @return 一個二維向量，代表粉紅豬動畫結束的座標
         */
        Vec2 getMovePig1EndPosition();
    };
}

#endif /* defined(_Game_Scene_StartScene_H_) */
