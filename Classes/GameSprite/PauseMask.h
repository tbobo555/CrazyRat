#ifndef _GameSprite_PauseMask_H_
#define _GameSprite_PauseMask_H_

#include "cocos2d.h"
#include "BaseSprite.h"
#include "Manager/SceneManager.h"
#include "Manager/SpriteManager.h"


namespace GameSprite
{
    class PauseMask : public BaseSprite
    {
    public:
        PauseMask(std::string image);
        void addEventListener();
    private:
        static bool onTouchBegan(Touch* touch, Event* event);
        static void onTouchEnded(Touch* touch, Event* event);
        static void onTouchMoved(Touch* touch, Event* event);
        static void onTouchCanceled(Touch* touch, Event* event);
    };
}


#endif /* _GameSprite_PauseMask_H_ */
