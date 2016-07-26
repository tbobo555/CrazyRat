#ifndef _GameSprite_ScoreStar_H_
#define _GameSprite_ScoreStar_H_

#include "cocos2d.h"
#include "BaseSprite.h"
#include "Lib/TextureCreator.h"

namespace GameSprite
{
    /**
     @brief 計分板星星
     */
    class ScoreStar : public BaseSprite
    {
    public:
        /**
         @brief 建構式
         */
        ScoreStar();
        
        /**
         @brief 將星星點亮
         */
        void setLight();
        
        /**
         @brief 將星星改為灰階
         */
        void setDark();

        // 星星是否被點亮
        bool isLight;
    };
}

#endif /* _GameSprite_ScoreStar_H_ */
