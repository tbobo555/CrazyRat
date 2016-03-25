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
        virtual void initScene();
        virtual void releaseScene();
    protected:
        Scene* scene;
        cocos2d::Size visibleSize;
        Vec2 visibleOrigin;
        Vec2 center;
        Vec2 leftTop;
        Vec2 rightTop;
        Vec2 leftBottom;
        Vec2 rightBottom;
    };
}

#endif /* defined(_GameScene_BaseScene_H_) */
