#ifndef _GameSprite_SelectionTitle_H_
#define _GameSprite_SelectionTitle_H_

#include "cocos2d.h"
#include "BaseSprite.h"

USING_NS_CC;

namespace GameSprite
{
    /**
     @brief 章節選擇場景的標題
     */
    class SelectionTitle : public BaseSprite
    {
    public:
        /**
         @brief 建構式
         @param image 標題要使用的圖檔
         */
        SelectionTitle(std::string image);
    };
}

#endif /* _GameSprite_SelectionTitle_H_ */
