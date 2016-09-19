#include "Mouth.h"

namespace GameSprite
{
    Mouth::Mouth(std::string image) : GameSprite::BaseSprite()
    {
        this->initWithCache(image);
        this->setScale(Director::getInstance()->getContentScaleFactor());
    }
}
