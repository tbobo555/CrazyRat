#ifndef _GameSprite_TimeBarDown_H_
#define _GameSprite_TimeBarDown_H_


#include "cocos2d.h"
#include "BaseSprite.h"

USING_NS_CC;

namespace GameSprite
{
    class TimeBarDown : public BaseSprite
    {
    public:
        TimeBarDown(std::string image);
        void addEventListener();
    private:
        static bool onTouchBegan(Touch *touch, Event *event);
        static void onTouchEnded(Touch *touch, Event *event);
        static void onTouchMoved(Touch *touch, Event *event);
        static void onTouchCanceled(Touch *touch, Event *event);
    };
}


#endif /* _GameSprite_TimeBarDown_H_ */
