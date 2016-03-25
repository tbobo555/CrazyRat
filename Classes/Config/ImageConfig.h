#ifndef _Config_ImageConfig_H_
#define _Config_ImageConfig_H_

#include "cocos2d.h"

USING_NS_CC;

class ImageConfig
{
public:
    static ImageConfig* getInstance();
    cocos2d::Size getImageSize(std::string);
private:
    ImageConfig();
    static ImageConfig* instance;
    std::map<std::string, cocos2d::Size> imageSize;
};

#endif /* _Config_ImageConfig_H_ */
