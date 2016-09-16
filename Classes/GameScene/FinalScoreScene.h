#ifndef _GameScene_FinalScoreScene_H_
#define _GameScene_FinalScoreScene_H_

#include "BaseScene.h"
#include "cocos2d.h"
#include "GameSprite/Background.h"
#include "GameSprite/NextButton.h"
#include "Manager/SpriteManager.h"

USING_NS_CC;

namespace GameScene
{
    class FinalScoreScene : public BaseScene
    {
    public:
        /**
         @brief 建構式
         @param score 分數
         */
        FinalScoreScene(std::string score);
        
        /**
         @brief 初始化場景
         */
        void initScene();
        
        /**
         @brief 釋放場景所有資源
         */
        void releaseScene();
        
        /**
         @brief 執行場景動畫
         */
        void runAnimation();
        
        /**
         @brief 顯示繼續按鈕
         */
        void showNextButton();
        
        /**
         @brief 取得分數物件
         @return 分數物件
         */
        Label* getScoreLabel();
        
        /**
         @brief 設定分數
         @param score 分數
         */
        void setScore(std::string score);
    private:
        // 分數
        std::string score;
        
        // 背景
        GameSprite::Background* background;
        
        // 繼續按鈕
        GameSprite::NextButton* nextButton;
        
        //分數物件
        Label* scoreLabel;
        
        /**
         @brief 取得背景要放置的座標
         @return 一個二維向量，代表背景放置的座標
         */
        Vec2 getBackgroundPosition();
        
        /**
         @brief 取得繼續按鈕要放置的座標
         @return 一個二維向量，代表繼續按鈕放置的座標
         */
        Vec2 getNextButtonPosition();
        
        /**
         @brief 取得分數物件要放置的座標
         @return 一個二維向量，代表分數物件的座標
         */
        Vec2 getScorePosition();
    };
}

#endif /* _GameScene_FinalScoreScene_H_ */
