#include "StartBackground.h"

namespace GameSprite
{
    StartBackground::StartBackground() :
    GameSprite::BaseSprite(ImageConfig::getInstance()->getImagePath("StartBackground"))
    {
        this->sprite->setPosition(PositionConfig::getInstance()
                                  ->getBasePsotion("StartBackground"));
    }
}
