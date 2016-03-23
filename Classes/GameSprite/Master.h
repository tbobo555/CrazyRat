#ifndef _GameSprite_Master_H_
#define _GameSprite_Master_H_

#include "BaseSprite.h"
#include "Config/ImageConfig.h"
#include "Config/PositionConfig.h"
#include "cocos2d.h"

USING_NS_CC;

namespace GameSprite
{
    class Master : public BaseSprite
    {
    public:
        Master();
        void addEventListener();
    private:
        static bool onTouchBegan(Touch *touch, Event *event);
        static void onTouchEnded(Touch *touch, Event *event);
        static void onTouchMoved(Touch *touch, Event *event);
        static void onTouchCanceled(Touch *touch, Event *event);
    };
}


#endif /* _GameSprite_Master_H_ */
