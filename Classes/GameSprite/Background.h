#ifndef _GameSprite_Background_H_
#define _GameSprite_Background_H_

#include "BaseSprite.h"
#include "cocos2d.h"


USING_NS_CC;

namespace GameSprite
{
    class Background : public BaseSprite
    {
    public:
        Background(std::string image);
    };
}


#endif /* _GameSprite_Background_H_ */
