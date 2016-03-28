#ifndef _GameSprite_Rat_H_
#define _GameSprite_Rat_H_

#include "cocos2d.h"
#include "BaseSprite.h"
#include "Manager/SceneManager.h"

USING_NS_CC;


namespace GameSprite
{
    class Rat : public BaseSprite
    {
    public:
        Rat(std::string image, int pRatType, int pRoadIndex, int pRatId);
        int ratType;
        int roadIndex;
        int ratId;
        float runningTime;
        void hit();
        void addEventListener();
        void run();
    private:
        static bool onTouchBegan(Touch* touch, Event* event);
        static void onTouchEnded(Touch* touch, Event* event);
        static void onTouchMoved(Touch* touch, Event* event);
        static void onTouchCanceled(Touch* touch, Event* event);
    };
}

#endif /* _GameSprite_Rat_H_ */
