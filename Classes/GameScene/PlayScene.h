#ifndef _GameScene_PlayScene_H_
#define _GameScene_PlayScene_H_

#include "cocos2d.h"
#include "BaseScene.h"



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
    };
}




#endif /* _GameScene_PlayScene_H_ */
