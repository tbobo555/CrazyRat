#include "SpriteManager.h"

namespace Manager
{
    SpriteManager* SpriteManager::instance;
    std::map<std::string, BaseSprite*> SpriteManager::container;
    
    SpriteManager::SpriteManager(){}
    
    SpriteManager* SpriteManager::getInstance()
    {
        return instance;
    }
    
    void SpriteManager::setWithKey(std::string key, BaseSprite *sprite)
    {
        container[key] = sprite;
    }
    
    BaseSprite* SpriteManager::getByKey(std::string key)
    {
        return container[key];
    }
    
    void SpriteManager::releaseByKey(std::string key)
    {
        container[key]->release();
        container.erase(key);
    }
    
    void SpriteManager::resetContainer()
    {
        for (auto& kv : container) {
            delete kv.second;
        }
        container.clear();
    }
}
