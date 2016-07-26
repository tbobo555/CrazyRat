#include "Star.h"

namespace GameSprite
{
    Star::Star(std::string image) : GameSprite::BaseSprite(image){}
    
    
    void Star::setBlank()
    {
        TextureCreator* textureCreator = TextureCreator::getInstance();
        Texture2D* texutre = textureCreator->getAutoSizeTexture2d("image/StarBlank.png");
        this->setTexture(texutre);

    }
}
