#ifndef _GameSprite_ProgressBarDown_H_
#define _GameSprite_ProgressBarDown_H_


#include "cocos2d.h"
#include "BaseSprite.h"

USING_NS_CC;

namespace GameSprite
{
    /**
     @brief 進度條的容器
     */
    class ProgressBarDown : public BaseSprite
    {
    public:
        /**
         @brief 建構式
         @param 進度條容器要使用的圖檔
         */
        ProgressBarDown(std::string image);
    };
}


#endif /* _GameSprite_ProgressBarDown_H_ */
