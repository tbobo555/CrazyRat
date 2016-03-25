#ifndef _GameSprite_BackButton_H_
#define _GameSprite_BackButton_H_

#include "cocos2d.h"
#include "BaseSprite.h"
#include "Manager/SceneManager.h"

USING_NS_CC;


namespace GameSprite
{
    class BackButton : public BaseSprite
    {
    public:
        BackButton(std::string image);
        void addEventListener();
    private:
        static bool onTouchBegan(Touch *touch, Event *event);
        static void onTouchEnded(Touch *touch, Event *event);
        static void onTouchMoved(Touch *touch, Event *event);
        static void onTouchCanceled(Touch *touch, Event *event);
    };
}


#endif /* _GameSprite_BackButton_H_ */
