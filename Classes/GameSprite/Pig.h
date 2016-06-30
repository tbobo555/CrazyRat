#ifndef _GameSprite_Pig_H_
#define _GameSprite_Pig_H_

#include "cocos2d.h"
#include "BaseSprite.h"
#include "Mouth.h"
#include "Image.h"
#include "Manager/SceneManager.h"

namespace GameSprite
{
    class Pig : public BaseSprite
    {
    public:
        Pig(std::string image, int pRoadIndex, int pigType);
        ~Pig();
        int roadIndex;
        int pigType;
        int hp;
        int eat();
        void hurt();
        void wink();
        void addEventListener();
    private:
        Image* explode;
        Mouth* mouth;
        void hideMouth();
        void showEatAnimation();
        void showExplode();
        void hideExplode(float delta);
        static bool onTouchBegan(Touch* touch, Event* event);
        static void onTouchEnded(Touch* touch, Event* event);
        static void onTouchMoved(Touch* touch, Event* event);
        static void onTouchCanceled(Touch* touch, Event* event);
    };
}


#endif /* _GameSprite_Pig_H_ */
