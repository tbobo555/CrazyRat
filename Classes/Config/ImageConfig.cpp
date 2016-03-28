#include "ImageConfig.h"

ImageConfig* ImageConfig::instance = new ImageConfig();

ImageConfig::ImageConfig(){};

ImageConfig* ImageConfig::getInstance()
{
    return instance;
}

Size ImageConfig::getImageSize(std::string key)
{
    if (this->imageSize.empty()) {
        this->imageSize = {
            {"StartBackground", Size(1080, 1920)},
            {"SelectionBackground", Size(1080, 1920)},
            {"StartButton", Size(300, 170)},
            {"MusicOnButton", Size(230, 230)},
            {"MusicOffButton", Size(230, 230)},
            {"SoundsOnButton", Size(230, 230)},
            {"SoundsOffButton", Size(230, 230)},
            {"SettingBackground", Size(690, 640)},
            {"BackButton", Size(180, 120)},
            {"SettingButton", Size(250, 165)},
            {"StageButton", Size(245, 245)},
            {"StageLockedButton", Size(245, 245)},
            {"Master", Size(85, 135)},
            {"Star", Size(75, 75)},
            {"Rat", Size(140, 180)},
            {"TimeBarDown", Size(500, 75)},
            {"TimeBarUp", Size(500, 75)},
        };
    }
    return this->imageSize.at(key);
}
