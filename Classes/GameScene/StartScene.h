#ifndef _GameScene_StartScene_H_
#define _GameScene_StartScene_H_

#include "GameSprite/StartBg.h"
#include "GameSprite/StartButton.h"
#include "BaseScene.h"

namespace GameScene
{
    class StartScene : public BaseScene
    {
    public:
        StartScene();
        void initScene();
        GameSprite::StartBg* startBg;
        GameSprite::StartButton* startButton;
    };
}

#endif /* defined(_Game_Scene_StartScene_H_) */
