#ifndef _GameSprite_Sweet_H_
#define _GameSprite_Sweet_H_

#include "cocos2d.h"
#include "BaseSprite.h"
#include "Manager/SceneManager.h"
#include "Manager/SpriteManager.h"
#include "Lib/TextureCreator.h"

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
        
        /**
         @brief 建構式
         @param image 甜點要使用的圖檔
         @param pRoadIndex 甜點被放置的路線
         @param pSweetId 這個甜點的索引，遊戲迴圈會用索引來取得可以被使用的甜點(正在降落的甜點不可被使用)
         @param pRunningTime 甜點降落的時間
         */
        Sweet(std::string image, int pRoadIndex, int pSweetId, float pRunningTime);
        
        /**
         @brief 解構式
         */
        ~Sweet();
        
        // 甜點被放置的路徑
        int roadIndex;
        
        // 甜點的索引
        int sweetId;
        
        // 甜點降落的速度
        float runningTime;
        
        // 是不是炸彈
        bool isBomb;
        
        // 甜點的圖紋
        Texture2D* sweetTexture;
        
        // 炸彈的圖紋
        Texture2D* bombTexture;
        
        /**
         @brief 加入事件監聽，甜點會開始偵測觸控輸入
         */
        void addEventListener();
        
        /**
         @brief 甜點移除事件監聽
         */
        void removeEventListener();
        
        /**
         @brief 甜點被吃的動作
         */
        void eaten();
        
        /**
         @brief 甜點沒被吃到的動作
         */
        void missEat();
        
        /**
         @brief 設置糖果掉落的時間
         */
        void setRunningTime(float time);
        
        /**
         @brief 甜點開始降落
         */
        void run();
        
        /**
         @brief 甜點依據魔王位置降落
         */
        void runWithBoss();
        
        /**
         @param 設成甜點
         */
        void setSweet();
        
        /**
         @param 設成炸彈
         */
        void setBomb();
    private:
        // 事件監聽物件
        EventListenerTouchOneByOne* listener;
        
        /**
         @brief 初始化甜點物件
         @param image 甜點要使用的圖檔
         */
        void initSweet(std::string image);
        
        /**
         @brief 偵測甜點被按下的狀態
         @param touch 觸控區塊資訊
         @param event 事件監聽物件
         @return 一個布林變數，代表此狀態結束後是否要繼續監聽其他事件
         */
        static bool onTouchBegan(Touch *touch, Event *event);
        
        /**
         @brief 偵測甜點點擊結束的狀態，這裡不會執行任何動作
         遊戲會暫停，並顯示暫停選單
         @param touch 觸控區塊資訊
         @param event 事件監聽物件
         */
        static void onTouchEnded(Touch *touch, Event *event);
        
        /**
         @brief 偵測甜點被拖曳的狀態，這裡不會執行任何動作
         @param touch 觸控區塊資訊
         @param event 事件監聽物件
         */
        static void onTouchMoved(Touch *touch, Event *event);
        
        /**
         @brief 偵測甜點被取消的狀態，這裡不會執行任何動作
         @param touch 觸控區塊資訊
         @param event 事件監聽物件
         */
        static void onTouchCanceled(Touch *touch, Event *event);
    };
}

#endif /* _GameSprite_Sweet_H_ */
