#include "SelectionBackground.h"


namespace GameSprite
{
    SelectionBackground::SelectionBackground() :
    GameSprite::BaseSprite(ImageConfig::getInstance()->getImagePath("SelectionBackground"))
    {
        this->sprite->setPosition(PositionConfig::getInstance()->getBasePsotion("SelectionBackground"));
    }
}
