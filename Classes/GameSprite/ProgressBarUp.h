#ifndef _GameSprite_ProgressBarUp_H_
#define _GameSprite_ProgressBarUp_H_

#include "cocos2d.h"
#include "BaseSprite.h"

USING_NS_CC;

namespace GameSprite
{
    class ProgressBarUp : public BaseSprite
    {
    public:
        ProgressBarUp(std::string image);
        void runProgress(float time);
        void addEventListener();
    private:
        static bool onTouchBegan(Touch *touch, Event *event);
        static void onTouchEnded(Touch *touch, Event *event);
        static void onTouchMoved(Touch *touch, Event *event);
        static void onTouchCanceled(Touch *touch, Event *event);
    };
}


#endif /* _GameSprite_ProgressBarUp_H_ */
