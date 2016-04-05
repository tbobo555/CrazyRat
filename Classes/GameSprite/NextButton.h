#ifndef _GameSprite_NextButton_H_
#define _GameSprite_NextButton_H_

#include "cocos2d.h"
#include "BaseSprite.h"

USING_NS_CC;

namespace GameSprite
{
    class NextButton : public BaseSprite
    {
    public:
        NextButton(std::string image);
        void addEventListener();
    private:
        static bool onTouchBegan(Touch* touch, Event* event);
        static void onTouchEnded(Touch* touch, Event* event);
        static void onTouchMoved(Touch* touch, Event* event);
        static void onTouchCanceled(Touch* touch, Event* event);
    };
}

#endif /* _GameSprite_NextButton_H_ */
