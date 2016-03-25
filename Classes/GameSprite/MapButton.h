#ifndef _GameSprite_MapButton_H_
#define _GameSprite_MapButton_H_

#include "cocos2d.h"
#include "BaseSprite.h"
#include "Lib/TextureCreator.h"

USING_NS_CC;

namespace GameSprite
{
    class MapButton : public BaseSprite
    {
    public:
        MapButton(std::string image, int mapNumber);
        int mapNumber;
        bool isLocked;
        void locked();
        void unlocked();
        void addEventListener();
    private:
        static bool onTouchBegan(Touch *touch, Event *event);
        static void onTouchEnded(Touch *touch, Event *event);
        static void onTouchMoved(Touch *touch, Event *event);
        static void onTouchCanceled(Touch *touch, Event *event);
    };
}


#endif /* _GameSprite_MapButton_H_ */
