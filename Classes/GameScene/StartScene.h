#ifndef _GameScene_StartScene_H_
#define _GameScene_StartScene_H_

#include "GameSprite/Background.h"
#include "GameSprite/StartButton.h"
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
    private:
        Vec2 getStartButtonPosition();
    };
}

#endif /* defined(_Game_Scene_StartScene_H_) */
