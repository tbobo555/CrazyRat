#include "SceneManager.h"
#include <iostream>

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
        std::cout << "set scene: " << key << std::endl;
        this->container[key] = scene;
    }
    
    BaseScene* SceneManager::getByKey(std::string key)
    {
        std::cout << "get scene: " << key << std::endl;
        return this->container.at(key);
    }
    
    void SceneManager::releaseByKey(std::string key)
    {
        std::cout << "release scene: " << key << std::endl;
        this->container[key]->release();
        this->container.erase(key);
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
