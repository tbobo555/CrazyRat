#ifndef _Manager_SceneManager_H_
#define _Manager_SceneManager_H_

#include "GameScene/BaseScene.h"

using namespace GameScene;

namespace Manager
{
    class SceneManager
    {
    public:
        static SceneManager* getInstance();
        BaseScene* getByKey(std::string key);
        void setWithKey(std::string key, BaseScene* scene);
        BaseScene* getCurrent();
        void setCurrent(BaseScene* scene);
        void releaseByKey(std::string key);
        void resetContainer();
    private:
        SceneManager();
        static SceneManager* instance;
        BaseScene* current;
        std::map<std::string, BaseScene*> container;
    };
}

#endif /* defined(_Manager_SceneManager_H_) */
