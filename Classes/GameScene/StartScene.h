#ifndef _GameScene_StartScene_H_
#define _GameScene_StartScene_H_

#include "GameSprite/Background.h"
#include "GameSprite/PlayButton.h"
#include "GameSprite/HighScoresButton.h"
#include "GameSprite/ChallengeButton.h"
#include "GameSprite/StartTitle.h"
#include "GameSprite/image.h"
#include "GameSprite/HighScoreMask.h"
#include "Manager/SpriteManager.h"
#include "BaseScene.h"
#include "Manager/MusicManager.h"
#include "Db/NewHighScoreSetting.h"


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
        
        /**
         @brief 顯示最高得分紀錄畫面
         */
        void showHighScore();
        
        /**
         @brief 隱藏最高得分紀錄畫面
         */
        void hideHighScore();
        
        // 背景圖檔物件
        GameSprite::Background* startBackground;
        
        // 遊玩按鈕
        GameSprite::PlayButton* playButton;
        
        
        // 高分成就按鈕
        GameSprite::HighScoresButton* highScoresButton;
        
        // 闖關按鈕
        GameSprite::ChallengeButton* challengeButton;
        
        // 開始場景的標題
        GameSprite::StartTitle* startTitle;
        
        // 紅豬
        GameSprite::Image* movePig0;
        
        // 粉紅豬
        GameSprite::Image* movePig1;
        
        // 最高得分背景圖檔
        GameSprite::HighScoreMask* highScoreMask;
        
        // 最高得分
        Label* highScore;
    private:
        /**
         @brief 取得遊玩按鈕的座標位置
         @return 一個二維向量，代表遊玩按鈕的座標
         */
        Vec2 getPlayButtonPosition();
        
        
        /**
         @brief 取得高分成就按鈕的座標位置
         @return 一個二維向量，代表高分成就按鈕的座標
         */
        Vec2 getHighScoresButtonPosition();
        
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
        
        /**
         @brief 取得challenge button的座標位置
         @return 一個二維向量，代表challenge button的座標
         */
        Vec2 getChallengeButtonPosition();
    };
}

#endif /* defined(_Game_Scene_StartScene_H_) */
