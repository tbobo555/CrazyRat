#ifndef _GameSprite_ScoreStar_H_
#define _GameSprite_ScoreStar_H_

#include "cocos2d.h"
#include "BaseSprite.h"
#include "Lib/TextureCreator.h"

namespace GameSprite
{
    class ScoreStar : public BaseSprite
    {
    public:
        ScoreStar();
        void setLight();
        void setDark();
        bool isLight;
    };
}

#endif /* _GameSprite_ScoreStar_H_ */
