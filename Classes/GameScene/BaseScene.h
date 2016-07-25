#ifndef _GameScene_BaseScene_H_
#define _GameScene_BaseScene_H_

#include "GameSprite/BaseSprite.h"
#include "cocos2d.h"

USING_NS_CC;

namespace GameScene
{

    /**
     @brief 基礎場景，所有GameScene都需繼承此類別
     */
    class BaseScene : public Scene
    {
    public:
        /**
         @brief 建構式
         */
        BaseScene();

        /**
         @brief 解構式
         */
        virtual ~BaseScene();

        /**
         @brief 場景初始化
         將場景會用到的物件建置出來，並放置場景中，此方法並不會取代目前的場景
         */
        virtual void initScene();

        /**
         @brief 將場景釋放，此方法會同時釋放該場景有使用的資源
         */
        virtual void releaseScene();

        // 場景名稱
        std::string name;
    protected:
        // 裝置可見的尺寸
        cocos2d::Size visibleSize;

        // 可見畫面尺寸的原點，座標是以左下角開始計算，因此可見原點在畫面中的左下角
        // 此座標不一定會是(0,0)，會依據裝置大小而有不同的數值
        Vec2 visibleOrigin;

        // 可見場景的中心點
        Vec2 center;

        // 可見場景的左上角
        Vec2 leftTop;

        // 可見場景的右上角
        Vec2 rightTop;

        // 可見場景的左下角
        Vec2 leftBottom;

        // 可見場景的右下角
        Vec2 rightBottom;

        // 可見場景的中間最上方的點
        Vec2 centerTop;

        // 可見場景的中間最下方的點
        Vec2 centerBottom;

        // 可見場景的中間最左邊的點
        Vec2 centerLeft;

        // 可見場景的中間最右邊的點
        Vec2 centerRight;
    };
}

#endif /* defined(_GameScene_BaseScene_H_) */
