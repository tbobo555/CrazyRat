#ifndef _GameScene_BaseScene_H_
#define _GameScene_BaseScene_H_

#include "GameSprite/BaseSprite.h"
#include "cocos2d.h"

USING_NS_CC;

namespace GameScene
{
    class BaseScene : public Scene
    {
    public:
        BaseScene();
        virtual ~BaseScene();
        std::string name;
        virtual void initScene();
        virtual void releaseScene();
    protected:
        cocos2d::Size visibleSize;
        Vec2 visibleOrigin;
        Vec2 center;
        Vec2 leftTop;
        Vec2 rightTop;
        Vec2 leftBottom;
        Vec2 rightBottom;
        Vec2 centerTop;
        Vec2 centerBottom;
        Vec2 centerLeft;
        Vec2 centerRight;
    };
}

#endif /* defined(_GameScene_BaseScene_H_) */
