#include "StartBg.h"

namespace GameSprite
{
    StartBg::StartBg() : GameSprite::BaseSprite()
    {
        Size visibleSize = Director::getInstance()->getVisibleSize();
        Vec2 origin = Director::getInstance()->getVisibleOrigin();
        this->sprite->setTexture("image/BG.png");
        this->sprite->setPosition(Vec2(origin.x + visibleSize.width / 2,
                              origin.y + visibleSize.height / 2));
    }
}
