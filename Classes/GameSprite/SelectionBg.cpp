#include "SelectionBg.h"


namespace GameSprite
{
    SelectionBg::SelectionBg() :
    GameSprite::BaseSprite(ImageConfig::getInstance()->getImagePath("SelectionBg"))
    {
        this->sprite->setPosition(PositionConfig::getInstance()->getBasePsotion("SelectionBg"));
    }
}
