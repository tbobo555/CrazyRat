#ifndef _GameSprite_Mouth_H_
#define _GameSprite_Mouth_H_

#include "cocos2d.h"
#include "BaseSprite.h"

namespace GameSprite
{
    /**
     @brief 嘴巴，當豬被玩家點擊時會呈現此圖片
     */
    class Mouth : public BaseSprite
    {
    public:
        /**
         @brief 建構式
         @param image 嘴巴要使用的圖檔
         */
        Mouth(std::string image);
    };
}

#endif /* _GameSprite_Mouth_H_ */
