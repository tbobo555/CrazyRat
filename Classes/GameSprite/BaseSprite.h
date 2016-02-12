#ifndef _GameSprite_BaseSprite_H_
#define _GameSprite_BaseSprite_H_

#include "cocos2d.h"

USING_NS_CC;

namespace GameSprite
{
    class BaseSprite
    {
    public:
        BaseSprite();
        ~BaseSprite();
        BaseSprite(std::string img);
        void release();
        virtual void addEventListner();
        Sprite* getCCSprite();
    protected:
        Sprite* sprite;
    };
}

#endif /* defined(_GameSprite_BaseSprite_H_) */
