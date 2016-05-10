#ifndef _GameSprite_ProgressBarDown_H_
#define _GameSprite_ProgressBarDown_H_


#include "cocos2d.h"
#include "BaseSprite.h"

USING_NS_CC;

namespace GameSprite
{
    class ProgressBarDown : public BaseSprite
    {
    public:
        ProgressBarDown(std::string image);
        void addEventListener();
    private:
        static bool onTouchBegan(Touch *touch, Event *event);
        static void onTouchEnded(Touch *touch, Event *event);
        static void onTouchMoved(Touch *touch, Event *event);
        static void onTouchCanceled(Touch *touch, Event *event);
    };
}


#endif /* _GameSprite_ProgressBarDown_H_ */
