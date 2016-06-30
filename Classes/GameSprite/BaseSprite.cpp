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
    
    BaseSprite::BaseSprite(std::string image, bool fromCache) : Sprite()
    {
        SpriteFrame* frame = SpriteFrameCache::getInstance()->getSpriteFrameByName(image);
        
        #if COCOS2D_DEBUG > 0
            char msg[256] = {0};
            sprintf(msg, "Invalid spriteFrameName: %s", image.c_str());
            CCASSERT(frame != nullptr, msg);
        #endif
        Texture2D* texture = TextureCreator::getInstance()->getAutoSizeTexture2d(frame->getTexture());
        this->initWithTexture(texture, frame->getRect());
        this->setSpriteFrame(frame);
        this->autorelease();
        this->retain();
    }
    
    BaseSprite::~BaseSprite(){}
        
    void BaseSprite::addEventListener(){}
    
}
