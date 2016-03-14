#ifndef _Config_PositionConfig_H_
#define _Config_PositionConfig_H_

#include "cocos2d.h"
#include "ImageConfig.h"

USING_NS_CC;

class PositionConfig
{
public:
    static PositionConfig* getInstance();
    Vec2 getBasePsotion(std::string);
    Vec2 getStagePosition(std::string);
private:
    PositionConfig();
    static PositionConfig* instance;
    std::map<std::string, Vec2> basePosition;
    std::map<std::string, Vec2> stagePosition;
};

#endif /* _Config_PositionConfig_H_ */
