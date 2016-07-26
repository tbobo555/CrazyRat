#ifndef _GameSprite_StartTitle_H_
#define _GameSprite_StartTitle_H_

#include "cocos2d.h"
#include "BaseSprite.h"

USING_NS_CC;

namespace GameSprite
{
    /**
     @brief 開始標題
     */
    class StartTitle : public BaseSprite
    {
    public:
        /**
         @brief 建構式
         @param image 開始標題要使用的圖檔
         */
        StartTitle(std::string image);
    };
}

#endif /* _GameSprite_StartTitle_H_ */
