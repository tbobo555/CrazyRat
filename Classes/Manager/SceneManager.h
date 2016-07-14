#ifndef _Manager_SceneManager_H_
#define _Manager_SceneManager_H_

#include "GameScene/BaseScene.h"

using namespace GameScene;

namespace Manager
{
    /**
     @brief 場景管理者
     存取與刪除所有已建立的場景
     */
    class SceneManager
    {
    public:
        /**
         @brief 取得實體物件
         */
        static SceneManager* getInstance();
        
        /**
         @brief 用key來取得指定場景
         @param key 指定場景的金鑰
         @return 回傳一個符合金鑰的場景
         */
        BaseScene* getByKey(std::string key);
        
        /**
         @brief 增加一個場景到管理器
         @param key 場景的金鑰
         @param scene 場景實體物件
         */
        void setWithKey(std::string key, BaseScene* scene);
        
        /**
         @brief 取得App目前正在顯示的場景
         @return 場景實體物件
         */
        BaseScene* getCurrent();
        
        /**
         @brief 告訴管理者目前的場景為何，此方法不會真的切換場景
         @param scene 場景實體物件
         */
        void setCurrent(BaseScene* scene);
        
        /**
         @brief 釋放指定場景的資源
         @param key 場景的金鑰
         */
        void releaseByKey(std::string key);
        
        /**
         @brief 清空存放場景的容器，此方法會釋放所有場景物件
         */
        void resetContainer();
    private:
        /**
         @brief 建構式
         */
        SceneManager();
        
        // 靜態實例
        static SceneManager* instance;
        
        // App正在顯示的場景的實例
        BaseScene* current;
        
        // 場景管理者的容器，用來存放場景
        std::map<std::string, BaseScene*> container;
    };
}

#endif /* defined(_Manager_SceneManager_H_) */
