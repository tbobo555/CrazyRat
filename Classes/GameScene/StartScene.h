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
    class StartScene : public BaseScene
    {
    public:
        StartScene();
        void initScene();
        void releaseScene();
        void runAnimation();
        void animationCallback();
        //void stopAnimation();
        GameSprite::Background* startBackground;
        GameSprite::StartButton* startButton;
        GameSprite::StartTitle* startTitle;
        GameSprite::Image* movePig0;
        GameSprite::Image* movePig1;
    private:
        Vec2 getStartButtonPosition();
        Vec2 getStartTitlePosition();
        Vec2 getMovePig0StartPosition();
        Vec2 getMovePig0EndPosition();
        Vec2 getMovePig1StartPosition();
        Vec2 getMovePig1EndPosition();
    };
}

#endif /* defined(_Game_Scene_StartScene_H_) */
