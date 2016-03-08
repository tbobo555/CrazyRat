#ifndef _GameSprite_StartButton_H_
#define _GameSprite_StartButton_H_

#include "BaseSprite.h"
#include "cocos2d.h"

USING_NS_CC;

namespace GameSprite
{
    class StartButton : public BaseSprite
    {
    public:
        StartButton();
        void addEventListner();
    private:
        static bool onTouchBegan(Touch* touch, Event* event);
        static void onTouchEnded(Touch* touch, Event* event);
        static void onTouchMoved(Touch* touch, Event* event);
        static void onTouchCanceled(Touch* touch, Event* event);
        const static std::string originImage;
    };
    
}

#endif /* defined(_GameSprite_StartButton_H_) */
