#ifndef _GameSprite_BaseSprite_H_
#define _GameSprite_BaseSprite_H_

#include "cocos2d.h"
#include "Lib/TextureCreator.h"

USING_NS_CC;

namespace GameSprite
{
    class BaseSprite : public Sprite
    {
    public:
        BaseSprite();
        virtual ~BaseSprite();
        BaseSprite(std::string image);
        virtual void addEventListener();
    private:
    };
}

#endif /* defined(_GameSprite_BaseSprite_H_) */
