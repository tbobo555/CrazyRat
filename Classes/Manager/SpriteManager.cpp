#include "SpriteManager.h"
#include <iostream>

namespace Manager
{
    SpriteManager* SpriteManager::instance = new SpriteManager();
    
    SpriteManager::SpriteManager(){}
    
    SpriteManager* SpriteManager::getInstance()
    {
        return instance;
    }
    
    void SpriteManager::setWithKey(std::string key, BaseSprite *sprite)
    {
        std::cout << "set sprite: " << key << std::endl;
        this->container[key] = sprite;
    }
    
    BaseSprite* SpriteManager::getByKey(std::string key)
    {
        std::cout << "get sprite: " << key << std::endl;
        return this->container.at(key);
    }
    
    void SpriteManager::releaseByKey(std::string key)
    {
        std::cout << "release sprite: " << key << std::endl;
        this->container[key]->release();
        this->container.erase(key);
    }
    
    void SpriteManager::resetContainer()
    {
        for (auto& kv : this->container) {
            delete kv.second;
        }
        this->container.clear();
    }
    
    void SpriteManager::clearEmptyKey()
    {
        for (auto& kv : this->container) {
            if (kv.second == nullptr) {
                this->container.erase(kv.first);
            }
        }
    }
}
