#include "SpriteManager.h"

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
        this->container[key] = sprite;
    }
    
    BaseSprite* SpriteManager::getByKey(std::string key)
    {
        return this->container[key];
    }
    
    void SpriteManager::releaseByKey(std::string key)
    {
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
}
