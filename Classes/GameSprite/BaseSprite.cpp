#include "BaseSprite.h"

namespace GameSprite
{
    BaseSprite::BaseSprite()
    {
        this->sprite = Sprite::create();
        this->sprite->retain();
    }
    
    BaseSprite::~BaseSprite()
    {
        if (this->sprite) {
            this->sprite->release();
        }
    }
    
    BaseSprite::BaseSprite(std::string img)
    {
        Texture2D* texture = TextureCreator::getInstance()->getAutoSizeTexture2d(img);
        this->sprite = Sprite::createWithTexture(texture);
        this->sprite->retain();
    }

    void BaseSprite::release()
    {
        delete this;
    }
    
    Sprite* BaseSprite::getCCSprite()
    {
        return this->sprite;
    }
    
    void BaseSprite::addEventListener()
    {
    }
    
}
