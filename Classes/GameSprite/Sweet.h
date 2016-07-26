#ifndef _GameSprite_Sweet_H_
#define _GameSprite_Sweet_H_

#include "cocos2d.h"
#include "BaseSprite.h"
#include "Manager/SceneManager.h"
#include "Manager/SpriteManager.h"

USING_NS_CC;


namespace GameSprite
{
    /**
     @brief 甜點物件，會再闖關時從天而降
     */
    class Sweet : public BaseSprite
    {
    public:
        /**
         @brief 建構式
         @param image 甜點要使用的圖檔
         @param pRoadIndex 甜點被放置的路線
         @param pSweetId 這個甜點的索引，遊戲迴圈會用索引來取得可以被使用的甜點(正在降落的甜點不可被使用)
         */
        Sweet(std::string image, int pRoadIndex, int pSweetId);
        
        // 甜點被放置的路徑
        int roadIndex;
        
        // 甜點的索引
        int sweetId;
        
        // 甜點降落的速度
        float runningTime;
        
        /**
         @brief 甜點被吃的動作
         */
        void eaten();
        
        /**
         @brief 甜點沒被吃到的動作
         */
        void missEat();
        
        /**
         @brief 甜點開始降落
         */
        void run();
    };
}

#endif /* _GameSprite_Sweet_H_ */
