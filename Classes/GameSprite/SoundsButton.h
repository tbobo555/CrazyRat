#ifndef _GameSprite_SoundsButton_H_
#define _GameSprite_SoundsButton_H_

#include "BaseSprite.h"
#include "cocos2d.h"
#include "Config/ImageConfig.h"
#include "Config/PositionConfig.h"

USING_NS_CC;

namespace GameSprite
{
    class SoundsButton : public BaseSprite
    {
    public:
        SoundsButton();
        void addEventListener();
    private:
        static bool onTouchBegan(Touch* touch, Event* event);
        static void onTouchEnded(Touch* touch, Event* event);
        static void onTouchMoved(Touch* touch, Event* event);
        static void onTouchCanceled(Touch* touch, Event* event);
    };
}

#endif /* defined(_GameSprite_SoundsButton_H_) */
