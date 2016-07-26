#ifndef _GameSprite_Image_H_
#define _GameSprite_Image_H_

#include "BaseSprite.h"
#include "cocos2d.h"


USING_NS_CC;

namespace GameSprite
{
    /**
     @brief 純圖片物件
     */
    class Image : public BaseSprite
    {
    public:
        /**
         @brief 建構式
         @param image 該物件要使用的圖檔
         */
        Image(std::string image);
    };
}


#endif /* _GameSprite_Image_H_ */
