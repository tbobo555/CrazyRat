#ifndef _GameSprite_SettingBg_H_
#define _GameSprite_SettingBg_H_

#include "BaseSprite.h"
#include "cocos2d.h"
#include "Config/ImageConfig.h"
#include "Config/PositionConfig.h"

USING_NS_CC;

namespace GameSprite
{
    class SettingBg : public BaseSprite
    {
    public:
        SettingBg();
        void addEventListener();
    private:
        static bool onTouchBegan(Touch* touch, Event* event);
        static void onTouchEnded(Touch* touch, Event* event);
        static void onTouchMoved(Touch* touch, Event* event);
        static void onTouchCanceled(Touch* touch, Event* event);
    };
}

#endif /* defined(_GameSprite_SettingBg_H_) */
