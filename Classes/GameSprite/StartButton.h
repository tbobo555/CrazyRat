#ifndef _GameSprite_StartButton_H_
#define _GameSprite_StartButton_H_

#include "BaseSprite.h"
#include "Config/PositionConfig.h"
#include "Config/ImageConfig.h"
#include "cocos2d.h"

USING_NS_CC;

namespace GameSprite
{
    class StartButton : public BaseSprite
    {
    public:
        StartButton();
        void addEventListener();
    private:
        static bool onTouchBegan(Touch* touch, Event* event);
        static void onTouchEnded(Touch* touch, Event* event);
        static void onTouchMoved(Touch* touch, Event* event);
        static void onTouchCanceled(Touch* touch, Event* event);
    };
    
}

#endif /* defined(_GameSprite_StartButton_H_) */
