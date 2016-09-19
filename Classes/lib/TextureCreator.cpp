#include "TextureCreator.h"


TextureCreator* TextureCreator::instance = new TextureCreator();

TextureCreator::TextureCreator()
{
    this->rectPadding = 10;
};

TextureCreator* TextureCreator::getInstance()
{
    return instance;
}

Texture2D* TextureCreator::getAutoSizeTexture2d(std::string img)
{
    // 用原始圖檔建置一個暫存精靈，該精靈依裝置尺寸縮放 螢幕
    auto originSprite = Sprite::create(img);
    originSprite->setScale(Director::getInstance()->getContentScaleFactor());
    originSprite->setFlippedY(true);
    originSprite->setPosition(Vec2(ceil(originSprite->getBoundingBox().size.width + this->rectPadding) / 2,
                                   ceil(originSprite->getBoundingBox().size.height + this->rectPadding) / 2));
    
    // 建立一個繪製圖紋的容器，大小與縮放後的暫存精靈一樣。
    auto renderTexture = RenderTexture::create(ceil(originSprite->getBoundingBox().size.width + this->rectPadding),
                                               ceil(originSprite->getBoundingBox().size.height + this->rectPadding),
                                               Texture2D::PixelFormat::RGBA8888);
    // 開始繪製圖紋
    renderTexture->begin();
    originSprite->visit();
    renderTexture->end();
    return renderTexture->getSprite()->getTexture();
}
