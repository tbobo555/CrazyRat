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
        static BaseScene* getByKey(std::string key);
        static void setWithKey(std::string key, BaseScene* scene);
        static BaseScene* getCurrent();
        static void setCurrent(BaseScene* scene);
        static void resetContainer();
    private:
        SceneManager();
        static SceneManager* instance;
        static BaseScene* current;
        static std::map<std::string, BaseScene*> container;
    };
}

#endif /* defined(_Manager_SceneManager_H_) */
