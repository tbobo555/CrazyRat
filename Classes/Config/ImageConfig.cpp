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
            {"StartBg", "image/Bg.png"},
            {"SelectionBg", "image/Bg2.png"},
            {"StartButton", "image/StartBtn.png"},
            {"MusicButton", "image/MusicBtn.png"},
            {"MusicOffButton", "image/MusicOffBtn.png"},
            {"SoundsButton", "image/SoundsBtn.png"},
            {"SoundsOffButton", "image/SoundsOffBtn.png"},
            {"SettingBg", "image/CustomBg.png"},
            {"SettingBackButton", "image/BackBtn.png"},
            {"SettingButton", "image/SettingBtn.png"},
            {"StageButton", "image/StageBtn.png"},
            {"StageLockedButton", "image/StageLocked.png"},
            {"MasterSprite", "image/MasterSprite.png"},
            {"StarSprite", "image/StarSprite.png"},
        };
    }
    return this->imagePath.at(key);
}


Size ImageConfig::getImageSize(std::string key)
{
    if (this->imageSize.empty()) {
        this->imageSize = {
            {"StartBg", Size(1080, 1920)},
            {"SelectionBg", Size(1080, 1920)},
            {"StartButton", Size(300, 170)},
            {"MusicButton", Size(230, 230)},
            {"MusicOffButton", Size(230, 230)},
            {"SoundsButton", Size(230, 230)},
            {"SoundsOffButton", Size(230, 230)},
            {"SettingBg", Size(690, 640)},
            {"SettingBackButton", Size(180, 120)},
            {"SettingButton", Size(250, 165)},
            {"StageButton", Size(246, 246)},
            {"StageLockedButton", Size(246, 246)},
            {"MasterSprite", Size(86, 136)},
            {"StarSprite", Size(76, 76)},

        };
    }
    return this->imageSize.at(key);
}
