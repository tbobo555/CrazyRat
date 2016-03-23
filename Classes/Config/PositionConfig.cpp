#include "PositionConfig.h"
#include <iostream>

PositionConfig* PositionConfig::instance = new PositionConfig();

PositionConfig::PositionConfig(){}

PositionConfig* PositionConfig::getInstance()
{
    return instance;
}

Vec2 PositionConfig::getBasePsotion(std::string key)
{
    std::cout << key << std::endl;
    if (this->basePosition.empty()) {
        auto visibleSize = Director::getInstance()->getVisibleSize();
        auto visibleOrigin = Director::getInstance()->getVisibleOrigin();
        auto center = Vec2(visibleOrigin.x + visibleSize.width / 2,
                           visibleOrigin.y + visibleSize.height / 2);
        auto leftTop = Vec2(visibleOrigin.x,
                            visibleOrigin.y + visibleSize.height);
        auto rightTop = Vec2(visibleOrigin.x + visibleSize.width,
                             visibleOrigin.y + visibleSize.height);
        auto leftBottom = Vec2(visibleOrigin.x,
                               visibleOrigin.y);
        auto rightBottom = (Vec2(visibleOrigin.x + visibleSize.height,
                                 visibleOrigin.y));
        Size musicButton = ImageConfig::getInstance()->getImageSize("MusicOnButton");
        Size soundsButton = ImageConfig::getInstance()->getImageSize("SoundsOnButton");
        Size settingBackButton = ImageConfig::getInstance()->getImageSize("BackButton");
        Size settingButton = ImageConfig::getInstance()->getImageSize("SettingButton");
        Size stageButton = ImageConfig::getInstance()->getImageSize("StageButton");
        Size master = ImageConfig::getInstance()->getImageSize("Master");
        Size star = ImageConfig::getInstance()->getImageSize("Star");

        this->basePosition = {
            {"StartBackground", center},
            {"SelectionBackground", center},
            {"StartButton", Vec2(center.x, visibleOrigin.y + visibleSize.height / 4.0)},
            {"MusicButton", Vec2(center.x - musicButton.width * 0.6, center.y)},
            {"SoundsButton", Vec2(center.x + soundsButton.width * 0.6, center.y)},
            {"SettingBackground", center},
            {"SettingBackButton", Vec2(leftTop.x + settingBackButton.width * 0.6,
                                       leftTop.y - settingBackButton.height * 0.6)},
            {"SettingButton", Vec2(leftBottom.x + settingButton.width * 0.6,
                                   leftBottom.y + settingButton.height * 0.6)},
            {"StageButton", Vec2(leftBottom.x - stageButton.width,
                                 leftBottom.y - stageButton.height)},
            {"Master", Vec2(leftBottom.x - master.width,
                                  leftBottom.y - master.height)},
            {"Star", Vec2(leftBottom.x - star.width,
                                leftBottom.y - star.height)},
        };
    }
    return this->basePosition.at(key);
}

Vec2 PositionConfig::getStagePosition(std::string key)
{
    if (this->stagePosition.empty()) {
        this->stagePosition = {
            {"Stage1", Vec2(165, 1100)},
            {"Stage2", Vec2(550, 1100)},
            {"Stage3", Vec2(930, 1100)},
            {"Stage4", Vec2(165, 650)},
            {"Stage5", Vec2(550, 650)},
            {"Stage6", Vec2(930, 650)},
        };
    }
    
    return this->stagePosition.at(key);
}
