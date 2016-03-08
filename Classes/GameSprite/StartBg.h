#ifndef _GameSprite_StartBg_H_
#define _GameSprite_StartBg_H_

#include "BaseSprite.h"
#include "cocos2d.h"

USING_NS_CC;

namespace GameSprite
{
    
    class StartBg : public BaseSprite
    {
    public:
        StartBg();
    private:
        const static std::string originImage;
    };

}

#endif /* defined(_GameSprite_StartBg_H_) */
