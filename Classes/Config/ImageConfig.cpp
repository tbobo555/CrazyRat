#include "ImageConfig.h"
# include <iostream>

ImageConfig* ImageConfig::instance = new ImageConfig();

ImageConfig::ImageConfig(){};

ImageConfig* ImageConfig::getInstance()
{
    return instance;
}

std::string ImageConfig::getImagePath(std::string key)
{
    if (this->imagePath.empty()) {
        this->imagePath = {
            {"StartBackground", "image/StartBackground.png"},
            {"SelectionBackground", "image/SelectionBackground.png"},
            {"StartButton", "image/StartButton.png"},
            {"MusicOnButton", "image/MusicOnButton.png"},
            {"MusicOffButton", "image/MusicOffBtn.png"},
            {"SoundsOnButton", "image/SoundsOnButton.png"},
            {"SoundsOffButton", "image/SoundsOffButton.png"},
            {"SettingBackground", "image/SettingBackground.png"},
            {"BackButton", "image/BackButton.png"},
            {"SettingButton", "image/SettingButton.png"},
            {"StageButton", "image/StageButton.png"},
            {"StageLockedButton", "image/StageLockedButton.png"},
            {"Master", "image/Master.png"},
            {"Star", "image/Star.png"},
        };
    }
    return this->imagePath.at(key);
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
            {"StageButton", Size(246, 246)},
            {"StageLockedButton", Size(246, 246)},
            {"Master", Size(86, 136)},
            {"Star", Size(76, 76)},

        };
    }
    return this->imageSize.at(key);
}
