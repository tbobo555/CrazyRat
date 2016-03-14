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
        auto originSprite = Sprite::create(img);
        originSprite->setScale(Director::getInstance()->getContentScaleFactor());
        originSprite->setFlippedY(true);
        originSprite->setPosition(Vec2(originSprite->getBoundingBox().size.width / 2,
                                       originSprite->getBoundingBox().size.height / 2));
        auto renderTexture = RenderTexture::create(originSprite->getBoundingBox().size.width,
                                                   originSprite->getBoundingBox().size.height,
                                                   Texture2D::PixelFormat::RGBA8888);
        renderTexture->begin();
        originSprite->visit();
        renderTexture->end();
        this->sprite = Sprite::createWithTexture(renderTexture->getSprite()->getTexture());
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
