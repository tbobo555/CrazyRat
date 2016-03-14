#ifndef _Config_GameConfig_H_
#define _Config_GameConfig_H_

#include "cocos2d.h"

USING_NS_CC;

class GameConfig
{
public:
    static GameConfig* getInstance();
private:
    GameConfig();
    static GameConfig* instance;
    //std::map<std::string, std::map<std::string, Vec2>> level1Game1;
};


#endif /* _Config_GameConfig_H_ */
