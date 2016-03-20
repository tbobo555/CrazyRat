#include "PositionConfig.h"

PositionConfig* PositionConfig::instance = new PositionConfig();

PositionConfig::PositionConfig(){}

PositionConfig* PositionConfig::getInstance()
{
    return instance;
}

Vec2 PositionConfig::getBasePsotion(std::string key)
{
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
        Size musicButton = ImageConfig::getInstance()->getImageSize("MusicButton");
        Size soundsButton = ImageConfig::getInstance()->getImageSize("SoundsButton");
        Size settingBackButton = ImageConfig::getInstance()->getImageSize("SettingBackButton");
        Size settingButton = ImageConfig::getInstance()->getImageSize("SettingButton");
        Size stageButton = ImageConfig::getInstance()->getImageSize("StageButton");
        Size masterSprite = ImageConfig::getInstance()->getImageSize("MasterSprite");
        Size starSprite = ImageConfig::getInstance()->getImageSize("StarSprite");

        this->basePosition = {
            {"StartBg", center},
            {"SelectionBg", center},
            {"StartButton", Vec2(center.x, visibleOrigin.y + visibleSize.height / 4.0)},
            {"MusicButton", Vec2(center.x - musicButton.width * 0.6, center.y)},
            {"SoundsButton", Vec2(center.x + soundsButton.width * 0.6, center.y)},
            {"SettingBg", center},
            {"SettingBackButton", Vec2(leftTop.x + settingBackButton.width * 0.6,
                                       leftTop.y - settingBackButton.height * 0.6)},
            {"SettingButton", Vec2(leftBottom.x + settingButton.width * 0.6,
                                   leftBottom.y + settingButton.height * 0.6)},
            {"StageButton", Vec2(leftBottom.x - stageButton.width,
                                 leftBottom.y - stageButton.height)},
            {"MasterSprite", Vec2(leftBottom.x - masterSprite.width,
                                  leftBottom.y - masterSprite.height)},
            {"StarSprite", Vec2(leftBottom.x - starSprite.width,
                                leftBottom.y - starSprite.height)},
        };
    }
    return this->basePosition.at(key);
}

Vec2 PositionConfig::getStagePosition(std::string key)
{
    if (this->stagePosition.empty()) {
        this->stagePosition = {
            {"Stage0", Vec2(165, 1100)},
            {"Stage1", Vec2(550, 1100)},
            {"Stage2", Vec2(930, 1100)},
            {"Stage3", Vec2(165, 650)},
            {"Stage4", Vec2(550, 650)},
            {"Stage5", Vec2(930, 650)},
        };
    }
    
    return this->stagePosition.at(key);
}
