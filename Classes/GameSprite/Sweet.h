#ifndef _GameSprite_Sweet_H_
#define _GameSprite_Sweet_H_

#include "cocos2d.h"
#include "BaseSprite.h"
#include "Manager/SceneManager.h"
#include "Manager/SpriteManager.h"

USING_NS_CC;


namespace GameSprite
{
    class Sweet : public BaseSprite
    {
    public:
        Sweet(std::string image, int pSweetType, int pRoadIndex, int pSweetId);
        int sweetType;
        int roadIndex;
        int sweetId;
        float runningTime;
        void eaten();
        void missEat();
        void run();
    };
}

#endif /* _GameSprite_Sweet_H_ */
