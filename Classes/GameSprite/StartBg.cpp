#include "StartBg.h"

namespace GameSprite
{
    const std::string StartBg::originImage = "image/Bg.png";
    
    StartBg::StartBg() : GameSprite::BaseSprite(StartBg::originImage)
    {
        Size visibleSize = Director::getInstance()->getVisibleSize();
        Vec2 origin = Director::getInstance()->getVisibleOrigin();
        this->sprite->setPosition(Vec2(origin.x + visibleSize.width / 2,
                                       origin.y + visibleSize.height / 2));
    }
}
