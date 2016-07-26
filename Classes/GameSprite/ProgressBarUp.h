#ifndef _GameSprite_ProgressBarUp_H_
#define _GameSprite_ProgressBarUp_H_

#include "cocos2d.h"
#include "BaseSprite.h"

USING_NS_CC;

namespace GameSprite
{
    /**
     @brief 進度條
     */
    class ProgressBarUp : public BaseSprite
    {
    public:
        /**
         @brief 建構式
         @param image 進度條的圖檔
         */
        ProgressBarUp(std::string image);
    };
}


#endif /* _GameSprite_ProgressBarUp_H_ */
