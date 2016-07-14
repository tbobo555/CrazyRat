#ifndef _GameSprite_SettingMask_H_
#define _GameSprite_SettingMask_H_

#include "cocos2d.h"
#include "BaseSprite.h"
#include "Manager/SceneManager.h"
#include "Manager/SpriteManager.h"

namespace GameSprite
{
    class SettingMask : public BaseSprite
    {
    public:
        SettingMask(std::string image);
        void addEventListener();
    private:
        static bool onTouchBegan(Touch* touch, Event* event);
        static void onTouchEnded(Touch* touch, Event* event);
        static void onTouchMoved(Touch* touch, Event* event);
        static void onTouchCanceled(Touch* touch, Event* event);
    };
}

#endif /* _GameSprite_SettingMask_H_ */
