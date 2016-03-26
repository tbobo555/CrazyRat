#include "BaseSprite.h"

namespace GameSprite
{
    BaseSprite::BaseSprite() : Sprite()
    {
        this->init();
        this->autorelease();
        this->retain();
    }
    
    BaseSprite::BaseSprite(std::string image) : Sprite()
    {
        Texture2D* texture = TextureCreator::getInstance()->getAutoSizeTexture2d(image);
        this->initWithTexture(texture);
        this->autorelease();
        this->retain();
    }
    
    BaseSprite::~BaseSprite(){}
        
    void BaseSprite::addEventListener(){}
    
}
