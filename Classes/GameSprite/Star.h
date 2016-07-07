#ifndef _GameSprite_Star_H_
#define _GameSprite_Star_H_

#include "cocos2d.h"
#include "BaseSprite.h"

USING_NS_CC;

namespace GameSprite
{
    class Star : public BaseSprite
    {
    public:
        Star(std::string image);
        void setBlank();
        void addEventListener();
    private:
        static bool onTouchBegan(Touch *touch, Event *event);
        static void onTouchEnded(Touch *touch, Event *event);
        static void onTouchMoved(Touch *touch, Event *event);
        static void onTouchCanceled(Touch *touch, Event *event);
    };
}

#endif /* _GameSprite_Star_H_ */
