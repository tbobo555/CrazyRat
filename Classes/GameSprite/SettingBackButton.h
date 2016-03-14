#ifndef _GameSprite_SettingBackButton_H_
#define _GameSprite_SettingBackButton_H_

#include "BaseSprite.h"
#include "cocos2d.h"
#include "Config/ImageConfig.h"
#include "Config/PositionConfig.h"
#include "Manager/SceneManager.h"
#include "Manager/SpriteManager.h"

USING_NS_CC;

namespace GameSprite
{
    class SettingBackButton : public BaseSprite
    {
    public:
        SettingBackButton();
        void addEventListener();
    private:
        static bool onTouchBegan(Touch* touch, Event* event);
        static void onTouchEnded(Touch* touch, Event* event);
        static void onTouchMoved(Touch* touch, Event* event);
        static void onTouchCanceled(Touch* touch, Event* event);
        const static std::string originImage;
    };
}

#endif /* defined(_GameSprite_SettingBackButton_H_) */
