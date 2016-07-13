#include "TextureCreator.h"


TextureCreator* TextureCreator::instance = new TextureCreator();

TextureCreator::TextureCreator(){};

TextureCreator* TextureCreator::getInstance()
{
    return instance;
}

Texture2D* TextureCreator::getAutoSizeTexture2d(std::string img)
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
    return renderTexture->getSprite()->getTexture();
}


Texture2D* TextureCreator::getAutoSizeTexture2d(Texture2D* texture)
{
    auto originSprite = Sprite::createWithTexture(texture);
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
    return renderTexture->getSprite()->getTexture();
}

SpriteFrame* TextureCreator::getAutoSizeFrame(SpriteFrame* frame)
{
    float scaleFactor = Director::getInstance()->getContentScaleFactor();
    Texture2D* texture = TextureCreator::getInstance()->getAutoSizeTexture2d(frame->getTexture());
    Rect* rect = new Rect(frame->getRect().origin.x * scaleFactor , frame->getRect().origin.y * scaleFactor, frame->getRect().size.width * scaleFactor, frame->getRect().size.height * scaleFactor);
    return SpriteFrame::createWithTexture(texture, *rect);
}
