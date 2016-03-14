#ifndef _Config_ImageConfig_H_
#define _Config_ImageConfig_H_

#include "cocos2d.h"

USING_NS_CC;

class ImageConfig
{
public:
    static ImageConfig* getInstance();
    cocos2d::Size getImageSize(std::string);
    std::string getImagePath(std::string);
private:
    ImageConfig();
    static ImageConfig* instance;
    std::map<std::string, cocos2d::Size> imageSize;
    std::map<std::string, std::string> imagePath;
};

#endif /* _Config_ImageConfig_H_ */
