#include "StartBg.h"

namespace GameSprite
{
    const std::string StartBg::originImage = ImageConfig::getInstance()->getImagePath("StartBg");
    
    StartBg::StartBg() : GameSprite::BaseSprite(StartBg::originImage)
    {
        this->sprite->setPosition(PositionConfig::getInstance()->getBasePsotion("StartBg"));
    }
}
