#ifndef _GameSprite_StageButton_H_
#define _GameSprite_StageButton_H_

#include "BaseSprite.h"
#include "Config/ImageConfig.h"
#include "Config/PositionConfig.h"
#include "cocos2d.h"

USING_NS_CC;

namespace GameSprite
{
    class StageButton : public BaseSprite
    {
    public:
        StageButton();
        void addEventListener();
    private:
        static bool onTouchBegan(Touch *touch, Event *event);
        static void onTouchEnded(Touch *touch, Event *event);
        static void onTouchCanceled(Touch *touch, Event *event);
        static void onTouchMoved(Touch *touch, Event *event);
        const static std::string originImage;
    };
}

#endif /* _GameSprite_StageButton_H_ */
