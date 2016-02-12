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
        
    void BaseSprite::release()
    {
        delete this;
    }
    
    Sprite* BaseSprite::getCCSprite()
    {
        return this->sprite;
    }
    
    void BaseSprite::addEventListner()
    {
    }
    
}
