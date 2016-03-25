#ifndef _GameSprite_Background_H_
#define _GameSprite_Background_H_

#include "BaseSprite.h"
#include "cocos2d.h"


USING_NS_CC;

namespace GameSprite
{
    class Background : public BaseSprite
    {
    public:
        Background(std::string image);
        void addEventListener();
    private:
        static bool onTouchBegan(Touch* touch, Event* event);
        static void onTouchEnded(Touch* touch, Event* event);
        static void onTouchMoved(Touch* touch, Event* event);
        static void onTouchCanceled(Touch* touch, Event* event);

    };
}


#endif /* _GameSprite_Background_H_ */
