#ifndef _GameScene_VictoryScene_H_
#define _GameScene_VictoryScene_H_

#include "cocos2d.h"
#include "BaseScene.h"
#include "Manager/SpriteManager.h"
#include "Manager/SoundsManager.h"
#include "GameSprite/Background.h"
#include "GameSprite/NextButton.h"
#include "GameSprite/Star.h"

USING_NS_CC;

namespace GameScene
{
    /**
     @brief 玩家成功破關後顯示的畫面
     */
    class VictoryScene : public BaseScene
    {
    public:
        /**
         @brief 建構式
         */
        VictoryScene();
        
        /**
         @brief 場景初始化
         */
        void initScene();
        
        /**
         @brief 釋放場景有使用到的所有資源
         */
        void releaseScene();
        
        /**
         @brief 執行勝利場景的動畫
         將玩家獲得的星星由左下角飛入定位
         */
        void runAnimation(int newScores);
        
        /**
         @brief 動畫播放完畢要執行的方法，此方法用來顯示Next Nutton
         */
        void animationCallback();
        
        /**
         @brief 當星星飛到定位時要播放的音效
         */
        void playBigStarSound();
        
        // 背景圖物件
        GameSprite::Background* victoryBackground;
        
        // 繼續按鈕
        GameSprite::NextButton* nextButton;
        
        // 左方星星物件
        GameSprite::Star* starLeft;
        
        // 中間星星物件
        GameSprite::Star* starMiddle;
        
        // 右方星星物件
        GameSprite::Star* starRight;
    private:
        
        /**
         @brief 取得指定位置的星星座標
         @param position 0代表左邊的星星，1代表中間的星星，2代表右邊的星星
         @return 一個二維向量，代表星星的二維坐標
         */
        Vec2 getStarPosition(int position);
        
        /**
         @brief 取得背景圖座標位置
         @return 一個二維向量，代表背景的二維坐標
         */
        Vec2 getBackgroundPosition();
        
        /**
         @brief 取得繼續按鈕的座標位置
         @return 一個二維向量，代表繼續按鈕的二維坐標
         */
        Vec2 getNextButtonPosition();
    };
}


#endif /* _GameScene_VictoryScene_H_ */
