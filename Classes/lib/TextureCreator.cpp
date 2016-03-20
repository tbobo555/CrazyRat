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
