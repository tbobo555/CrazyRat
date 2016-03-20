#include "StartBg.h"

namespace GameSprite
{
    StartBg::StartBg() :
    GameSprite::BaseSprite(ImageConfig::getInstance()->getImagePath("StartBg"))
    {
        this->sprite->setPosition(PositionConfig::getInstance()->getBasePsotion("StartBg"));
    }
}
