#ifndef _GameScene_VictoryScene_H_
#define _GameScene_VictoryScene_H_

#include "cocos2d.h"
#include "BaseScene.h"
#include "Manager/SpriteManager.h"
#include "GameSprite/Background.h"
#include "GameSprite/NextButton.h"
#include "GameSprite/Star.h"

USING_NS_CC;

namespace GameScene
{
    class VictoryScene : public BaseScene
    {
    public:
        VictoryScene();
        void initScene();
        void releaseScene();
        void runAnimation();
        void animationCallback();
        GameSprite::Background* victoryBackground;
        GameSprite::NextButton* nextButton;
        GameSprite::Star* starLeft;
        GameSprite::Star* starMiddle;
        GameSprite::Star* starRight;
    private:
        Vec2 getStarPosition(int position);
        Vec2 getBackgroundPosition();
        Vec2 getNextButtonPosition();
    };
}


#endif /* _GameScene_VictoryScene_H_ */
