#ifndef _Manager_SpriteManager_H_
#define _Manager_SpriteManager_H_

#include "GameSprite/BaseSprite.h"

using namespace GameSprite;

namespace Manager
{
    /**
     @brief 精靈管理者
     存取與刪除所有已建立的精靈
     */
    class SpriteManager
    {
    public:
        /**
         @brief 取得實體物件
         */
        static SpriteManager* getInstance();
        
        /**
         @brief 用key來取得指定精靈
         @param key 指定精靈的金鑰
         @return 回傳一個符合金鑰的精靈
         */
        BaseSprite* getByKey(std::string key);
        
        /**
         @brief 增加一個精靈到管理器
         @param key 精靈的金鑰
         @param sprite 精靈實體物件
         */
        void setWithKey(std::string key, BaseSprite* sprite);
        
        /**
         @brief 釋放指定精靈的資源
         @param key 精靈的金鑰
         */
        void releaseByKey(std::string key);
        
        /**
         @brief 清空存放精靈的容器，此方法會釋放所有精靈物件
         */
        void resetContainer();
        
        /**
         @brief 將所有已經不存在的精靈從容器移除
         */
        void clearEmptyKey();
    private:
        /**
         @brief 建構式
         */
        SpriteManager();
        
        // 靜態實例
        static SpriteManager* instance;
        
        // 精靈管理者的容器，用來存放精靈
        std::map<std::string, BaseSprite*> container;
    };
}

#endif /* defined(_Manager_SpriteManager_H_) */
