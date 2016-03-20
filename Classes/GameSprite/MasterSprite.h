#ifndef _GameSprite_MasterSprite_H_
#define _GameSprite_MasterSprite_H_

#include "BaseSprite.h"
#include "Config/ImageConfig.h"
#include "Config/PositionConfig.h"
#include "cocos2d.h"

USING_NS_CC;

namespace GameSprite
{
    class MasterSprite : public BaseSprite
    {
    public:
        MasterSprite();
        void addEventListener();
    private:
        static bool onTouchBegan(Touch *touch, Event *event);
        static void onTouchEnded(Touch *touch, Event *event);
        static void onTouchMoved(Touch *touch, Event *event);
        static void onTouchCanceled(Touch *touch, Event *event);
    };
}


#endif /* _GameSprite_MasterSprite_H_ */
