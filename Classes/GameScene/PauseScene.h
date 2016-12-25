#ifndef _GameScene_PauseScene_H_
#define _GameScene_PauseScene_H_

#include "cocos2d.h"
#include "BaseScene.h"
#include "Manager/SpriteManager.h"
#include "GameSprite/Background.h"
#include "GameSprite/BackHomeButton.h"
#include "GameSprite/RetryButton.h"
#include "GameSprite/PauseButton.h"
#include "GameSprite/PauseBackButton.h"
#include "GameSprite/MusicButton.h"
#include "GameSprite/SoundsButton.h"
#include "GameSprite/PauseMask.h"

USING_NS_CC;

namespace GameScene
{
    /**
     @brief 暫停場景，可以開啟或關閉音樂與音效，或是重新開始關卡和返回主選單
     */
    class PauseScene : public BaseScene
    {
    public:
        /**
         @brief 建構式
         */
        PauseScene();
        
        /**
         @brief 場景初始化
         */
        void initScene();
        
        /**
         @brief 釋放場景
         */
        void releaseScene();
        
        // 暫停場景的背景物件
        GameSprite::Background* pauseBackground;
        
        // 返回主畫面的按鈕
        GameSprite::BackHomeButton* backHomeButton;
        
        // 重新開始遊戲
        GameSprite::RetryButton* retryButton;
        
        // 暫停按鈕
        GameSprite::PauseButton* pauseButton;
        
        // 暫停場景的返回按鈕，既取消暫停並恢復遊戲
        GameSprite::PauseBackButton* pauseBackButton;
        
        // 音樂開關按鈕
        GameSprite::MusicButton* musicButton;
        
        // 音效開關按鈕
        GameSprite::SoundsButton* soundsButton;
        
        // 暫停場景的遮罩
        GameSprite::PauseMask* pauseMask;
    private:
        /**
         @brief 取得暫停按鈕的座標位置
         @return 一個二維向量，代表暫停按鈕的二維坐標
         */
        Vec2 getPauseButtonPosition();
        
        /**
         @brief 取得背景圖的座標位置
         @return 一個二維向量，代表背景的二維坐標
         */
        Vec2 getPauseBackgroundPosition();
        
        /**
         @brief 取得返回鍵的座標位置
         @return 一個二維向量，代表返回鍵的二維坐標
         */
        Vec2 getPauseBackButtonPosition();
        
        /**
         @brief 取得音樂開關的座標位置
         @return 一個二維向量，代表音樂開關的二維坐標
         */
        Vec2 getMusicButtonPosition();
        
        /**
         @brief 取得音效開關的座標位置
         @return 一個二維向量，代表音效開關的二維坐標
         */
        Vec2 getSoundsButtonPosition();
        
        /**
         @brief 取得返回主選單按鈕的座標位置
         @return 一個二維向量，代表返回主選單按鈕的二維坐標
         */
        Vec2 getBackHomeButtonPosition();
        
        /**
         @brief 取得重新開始關卡按鈕的座標位置
         @return 一個二維向量，代表重新開始關卡按鈕的二維坐標
         */
        Vec2 getRetryButtonPosition();
    };
}


#endif /* _GameScene_PauseScene_H_ */
