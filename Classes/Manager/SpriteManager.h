#ifndef _Manager_Spritemanager_H_
#define _Manager_Spritemanager_H_

#include "GameSprite/BaseSprite.h"

using namespace GameSprite;

namespace Manager
{
    class SpriteManager
    {
    public:
        static SpriteManager* getInstance();
        static BaseSprite* getByKey(std::string key);
        static void setWithKey(std::string key, BaseSprite* sprite);
        static void releaseByKey(std::string key);
        static void resetContainer();
    private:
        SpriteManager();
        static SpriteManager* instance;
        static std::map<std::string, BaseSprite*> container;
    };
}

#endif /* defined(_Manager_Spritemanager_H_) */
