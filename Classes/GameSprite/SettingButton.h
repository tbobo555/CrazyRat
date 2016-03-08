#ifndef _GameSprite_SettingButton_H_
#define _GameSprite_SettingButton_H_

#include "cocos2d.h"
#include "BaseSprite.h"
#include "Manager/SceneManager.h"
#include "Manager/SpriteManager.h"

USING_NS_CC;

namespace GameSprite
{
    class SettingButton : public BaseSprite
    {
    public:
        SettingButton();
        void addEventListner();
    private:
        static bool onTouchBegan(Touch* touch, Event* event);
        static void onTouchEnded(Touch* touch, Event* event);
        static void onTouchMoved(Touch* touch, Event* event);
        static void onTouchCanceled(Touch* touch, Event* event);
        const static std::string originImage;
    };
}

#endif /* defined(_GameSprite_SettingButton_H_) */
