#include "TextureCreator.h"


TextureCreator* TextureCreator::instance = new TextureCreator();

TextureCreator::TextureCreator(){};

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
    originSprite->setPosition(Vec2(originSprite->getBoundingBox().size.width / 2,
                                   originSprite->getBoundingBox().size.height / 2));
    // 建立一個繪製圖紋的容器，大小與縮放後的暫存精靈一樣。
    auto renderTexture = RenderTexture::create(originSprite->getBoundingBox().size.width,
                                               originSprite->getBoundingBox().size.height,
                                               Texture2D::PixelFormat::RGBA8888);
    // 開始繪製圖紋
    renderTexture->begin();
    originSprite->visit();
    renderTexture->end();
    return renderTexture->getSprite()->getTexture();
}


Texture2D* TextureCreator::getAutoSizeTexture2d(Texture2D* texture)
{
    // 用原始圖紋建置一個暫存精靈，該精靈依裝置尺寸縮放
    auto originSprite = Sprite::createWithTexture(texture);
    originSprite->setScale(Director::getInstance()->getContentScaleFactor());
    originSprite->setFlippedY(true);
    originSprite->setPosition(Vec2(originSprite->getBoundingBox().size.width / 2,
                                   originSprite->getBoundingBox().size.height / 2));
    // 建立一個繪製圖紋的容器，大小與縮放後的暫存精靈一樣。
    auto renderTexture = RenderTexture::create(originSprite->getBoundingBox().size.width,
                                               originSprite->getBoundingBox().size.height,
                                               Texture2D::PixelFormat::RGBA8888);
    // 開始繪製圖紋
    renderTexture->begin();
    originSprite->visit();
    renderTexture->end();
    return renderTexture->getSprite()->getTexture();
}

SpriteFrame* TextureCreator::getAutoSizeFrame(SpriteFrame* frame)
{
    // 取得裝置解析度與原始圖檔的縮放因數
    float scaleFactor = Director::getInstance()->getContentScaleFactor();
    
    // 用影格的圖紋來創造一個依裝置縮放過大小的新圖紋
    Texture2D* texture = TextureCreator::getInstance()->getAutoSizeTexture2d(frame->getTexture());
    
    // 用圖紋建立影格需要指定區塊(就是Rect)，而此區塊的長寬與起始原點需要依”縮放因數“調整
    Rect* rect = new Rect(frame->getRect().origin.x * scaleFactor , frame->getRect().origin.y * scaleFactor, frame->getRect().size.width * scaleFactor, frame->getRect().size.height * scaleFactor);
    return SpriteFrame::createWithTexture(texture, *rect);
}
