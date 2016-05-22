#ifndef _GameScene_StartScene_H_
#define _GameScene_StartScene_H_

#include "GameSprite/Background.h"
#include "GameSprite/StartButton.h"
#include "GameSprite/startTitle.h"
#include "Manager/SpriteManager.h"
#include "BaseScene.h"

namespace GameScene
{
    class StartScene : public BaseScene
    {
    public:
        StartScene();
        void initScene();
        void releaseScene();
        GameSprite::Background* startBackground;
        GameSprite::StartButton* startButton;
        GameSprite::StartTitle* startTitle;
    private:
        Vec2 getStartButtonPosition();
        Vec2 getStartTitlePosition();
    };
}

#endif /* defined(_Game_Scene_StartScene_H_) */
