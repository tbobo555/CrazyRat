#ifndef _GameScene_BaseScene_H_
#define _GameScene_BaseScene_H_

#include "GameSprite/BaseSprite.h"
#include "cocos2d.h"

USING_NS_CC;

namespace GameScene
{
    class BaseScene
    {
    public:
        BaseScene();
        ~BaseScene();
        void release();
        Scene* getCCScene();
    protected:
        Scene* scene;
    };
}

#endif /* defined(_GameScene_BaseScene_H_) */
