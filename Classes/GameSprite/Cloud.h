#ifndef _GameSprite_Cloud_H_
#define _GameSprite_Cloud_H_

#include "cocos2d.h"
#include "BaseSprite.h"


namespace GameSprite
{
    /**
     @brief 雲
     */
    class Cloud : public BaseSprite
    {
    public:
        /**
         @brief 建構式
         @param image 雲要使用的圖檔
         */
        Cloud(std::string image);
    };
}

#endif /* _GameSprite_Cloud_H_ */
