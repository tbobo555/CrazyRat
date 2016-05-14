#ifndef _GameScene_LoseScene_H_
#define _GameScene_LoseScene_H_

#include "cocos2d.h"
#include "BaseScene.h"
#include "Manager/SpriteManager.h"
#include "GameSprite/Background.h"
#include "GameSprite/NextButton.h"

USING_NS_CC;

namespace GameScene
{
    class LoseScene : public BaseScene
    {
    public:
        LoseScene();
        void initScene();
        void releaseScene();
        GameSprite::Background* loseBackground;
        GameSprite::NextButton* nextButton;
    };
}


#endif /* _GameScene_LoseScene_H_ */