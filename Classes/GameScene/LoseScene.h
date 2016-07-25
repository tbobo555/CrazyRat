#ifndef _GameScene_LoseScene_H_
#define _GameScene_LoseScene_H_

#include "cocos2d.h"
#include "BaseScene.h"
#include "Manager/SpriteManager.h"
#include "GameSprite/Background.h"
#include "GameSprite/Image.h"
#include "GameSprite/NextButton.h"

USING_NS_CC;

namespace GameScene
{
    /**
     @brief 闖關失敗要顯示的場景
     */
    class LoseScene : public BaseScene
    {
    public:
        /**
         @brief 建構式
         */
        LoseScene();

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
         @brief 動畫播放完畢後要執行的方法
         */
        void animationCallback();

        // 失敗場景的背景圖片
        GameSprite::Background* loseBackground;

        // 失敗場景的文字標題
        GameSprite::Image* loseTitle;

        // 繼續按鈕
        GameSprite::NextButton* nextButton;
    private:

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
         @brief 取得繼續文字標題要放置的座標
         @return 一個二維向量，代表繼續文字標題放置的座標
         */
        Vec2 getLoseTitlePosition();
    };
}


#endif /* _GameScene_LoseScene_H_ */
