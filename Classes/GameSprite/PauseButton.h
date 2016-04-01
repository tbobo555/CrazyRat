#ifndef _GameSprite_PauseButton_H_
#define _GameSprite_PauseButton_H_

#include "cocos2d.h"
#include "BaseSprite.h"
#include "Manager/SceneManager.h"
#include "Manager/SpriteManager.h"

USING_NS_CC;

namespace GameSprite
{
    class PauseButton : public BaseSprite
    {
    public:
        PauseButton(std::string image);
        void addEventListener();
    private:
        static bool onTouchBegan(Touch *touch, Event *event);
        static void onTouchEnded(Touch *touch, Event *event);
        static void onTouchMoved(Touch *touch, Event *event);
        static void onTouchCanceled(Touch *touch, Event *event);
    };
}


#endif /* _GameSprite_PauseButton_H_ */