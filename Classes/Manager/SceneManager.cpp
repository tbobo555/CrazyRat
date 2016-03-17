#include "SceneManager.h"

namespace Manager
{
    SceneManager* SceneManager::instance = new SceneManager();

    SceneManager::SceneManager(){}
    
    SceneManager* SceneManager::getInstance()
    {
        return instance;
    }
    
    void SceneManager::setWithKey(std::string key, BaseScene *scene)
    {
        this->container[key] = scene;
    }
    
    BaseScene* SceneManager::getByKey(std::string key)
    {
        return this->container.at(key);
    }
    
    BaseScene* SceneManager::getCurrent()
    {
        return this->current;
    }
    
    void SceneManager::setCurrent(BaseScene *scene)
    {
        this->current = scene;
    }
    
    void SceneManager::resetContainer()
    {
        for (auto& kv : this->container) {
            delete kv.second;
        }
        this->container.clear();
    }

}
