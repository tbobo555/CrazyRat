#ifndef _GameSprite_BaseSprite_H_
#define _GameSprite_BaseSprite_H_

#include "cocos2d.h"
#include "Lib/TextureCreator.h"

USING_NS_CC;

namespace GameSprite
{
    /**
     @brief 基礎精靈，所有GameSprite皆需繼承此類別
     */
    class BaseSprite : public Sprite
    {
    public:
        /**
         @brief 建構式
         */
        BaseSprite();

        /**
         @brief 解構式
         */
        virtual ~BaseSprite();

        /**
         @brief 建構式
         @param image 精靈要套用的圖檔
         */
        BaseSprite(std::string image);

        /**
         @brief 從 cache 初始化精靈
         @param image 精靈要套用的圖檔
         */
        void initWithCache(std::string image);

        /**
         @brief 將精靈加入事件監聽，精靈會開始偵測觸控輸入
         */
        virtual void addEventListener();
    private:
    };
}

#endif /* defined(_GameSprite_BaseSprite_H_) */
