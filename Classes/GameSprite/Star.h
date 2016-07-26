#ifndef _GameSprite_Star_H_
#define _GameSprite_Star_H_

#include "cocos2d.h"
#include "BaseSprite.h"

USING_NS_CC;

namespace GameSprite
{
    /**
     @brief 勝利畫面和章節場景的關卡所需要顯示的星星物件
     */
    class Star : public BaseSprite
    {
    public:
        /**
         @brief 建構式
         @param image 星星所需要使用的圖檔，章節場景裡的星星較小，勝利畫面的星星較大
         */
        Star(std::string image);
        
        /**
         @brief 將星星設定成為灰階版本
         */
        void setBlank();
    };
}

#endif /* _GameSprite_Star_H_ */
