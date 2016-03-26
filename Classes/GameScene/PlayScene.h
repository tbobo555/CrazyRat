#ifndef _GameScene_PlayScene_H_
#define _GameScene_PlayScene_H_

#include "cocos2d.h"
#include "BaseScene.h"
#include "Manager/SpriteManager.h"
#include "GameSprite/Background.h"

USING_NS_CC;

namespace GameScene
{
    class PlayScene : public BaseScene
    {
    public:
        PlayScene(int pMapNumber, int pStageNumber);
        void initScene();
        void releaseScene();
        int mapNumber;
        int stageNumber;
        GameSprite::Background* playBackground;
        void run();
    private:
        virtual void update(float delta);
        int prepareTime;
        Label* prepareLabel;
        Scheduler* prepareScheduler;
        void prepareCountdown();
        void start();
    };
}




#endif /* _GameScene_PlayScene_H_ */
