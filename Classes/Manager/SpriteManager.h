#ifndef _Manager_SpriteManager_H_
#define _Manager_SpriteManager_H_

#include "GameSprite/BaseSprite.h"

using namespace GameSprite;

namespace Manager
{
    class SpriteManager
    {
    public:
        static SpriteManager* getInstance();
        BaseSprite* getByKey(std::string key);
        void setWithKey(std::string key, BaseSprite* sprite);
        void releaseByKey(std::string key);
        void resetContainer();
        void clearEmptyKey();
    private:
        SpriteManager();
        static SpriteManager* instance;
        std::map<std::string, BaseSprite*> container;
    };
}

#endif /* defined(_Manager_SpriteManager_H_) */
