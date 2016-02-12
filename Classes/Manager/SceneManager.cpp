#include "SceneManager.h"

namespace Manager
{
    SceneManager* SceneManager::instance;
    BaseScene* SceneManager::current;
    std::map<std::string, BaseScene*> SceneManager::container;

    SceneManager::SceneManager(){}
    
    SceneManager* SceneManager::getInstance()
    {
        return instance;
    }
    
    void SceneManager::setWithKey(std::string key, BaseScene *scene)
    {
        container[key] = scene;
    }
    
    BaseScene* SceneManager::getByKey(std::string key)
    {
        return container[key];
    }
    
    BaseScene* SceneManager::getCurrent()
    {
        return current;
    }
    
    void SceneManager::setCurrent(BaseScene *scene)
    {
        current = scene;
    }
    
    void SceneManager::resetContainer()
    {
        for (auto& kv : container) {
            delete kv.second;
        }
        container.clear();
    }

}
