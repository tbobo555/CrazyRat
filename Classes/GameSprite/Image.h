#ifndef _GameSprite_Image_H_
#define _GameSprite_Image_H_

#include "BaseSprite.h"
#include "cocos2d.h"


USING_NS_CC;

namespace GameSprite
{
    class Image : public BaseSprite
    {
    public:
        Image(std::string image);
    };
}


#endif /* _GameSprite_Image_H_ */
