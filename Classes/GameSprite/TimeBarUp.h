#ifndef _GameSprite_TimeBarUp_H_
#define _GameSprite_TimeBarUp_H_

#include "cocos2d.h"
#include "BaseSprite.h"

USING_NS_CC;

namespace GameSprite
{
    class TimeBarUp : public BaseSprite
    {
    public:
        TimeBarUp(std::string image);
        void runProgress(float time);
        void addEventListener();
    private:
        static bool onTouchBegan(Touch *touch, Event *event);
        static void onTouchEnded(Touch *touch, Event *event);
        static void onTouchMoved(Touch *touch, Event *event);
        static void onTouchCanceled(Touch *touch, Event *event);
    };
}


#endif /* _GameSprite_TimeBarUp_H_ */