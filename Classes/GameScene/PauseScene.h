#ifndef _GameScene_PauseScene_H_
#define _GameScene_PauseScene_H_

#include "cocos2d.h"
#include "BaseScene.h"
#include "Manager/SpriteManager.h"
#include "Config/ImageConfig.h"
#include "GameSprite/Background.h"
#include "GameSprite/BackHomeButton.h"
#include "GameSprite/RetryButton.h"
#include "GameSprite/PauseButton.h"
#include "GameSprite/PauseBackButton.h"
#include "GameSprite/MusicButton.h"
#include "GameSprite/SoundsButton.h"

USING_NS_CC;

namespace GameScene
{
    class PauseScene : public BaseScene
    {
    public:
        PauseScene();
        void initScene();
        void releaseScene();
        GameSprite::Background* pauseBackground;
        GameSprite::BackHomeButton* backHomeButton;
        GameSprite::RetryButton* retryButton;
        GameSprite::PauseButton* pauseButton;
        GameSprite::PauseBackButton* pauseBackButton;
        GameSprite::MusicButton* musicButton;
        GameSprite::SoundsButton* soundsButton;
    private:
        Vec2 getPauseButtonPosition();
        Vec2 getPauseBackgroundPosition();
        Vec2 getPauseBackButtonPosition();
        Vec2 getMusicButtonPosition();
        Vec2 getSoundsButtonPosition();
        Vec2 getBackHomeButtonPosition();
        Vec2 getRetryButtonPosition();
    };
}


#endif /* _GameScene_PauseScene_H_ */
