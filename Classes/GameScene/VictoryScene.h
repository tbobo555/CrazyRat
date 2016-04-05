#ifndef _GameScene_VictoryScene_H_
#define _GameScene_VictoryScene_H_

#include "cocos2d.h"
#include "BaseScene.h"
#include "Manager/SpriteManager.h"
#include "GameSprite/Background.h"
#include "GameSprite/NextButton.h"

USING_NS_CC;

namespace GameScene
{
    class VictoryScene : public BaseScene
    {
    public:
        VictoryScene();
        void initScene();
        void releaseScene();
        GameSprite::Background* victoryBackground;
        GameSprite::NextButton* nextButton;
    };
}


#endif /* _GameScene_VictoryScene_H_ */
