#include "ScoreStar.h"

namespace GameSprite
{
    ScoreStar::ScoreStar() : GameSprite::BaseSprite()
    {
        this->isLight = false;
        TextureCreator* textureCreator = TextureCreator::getInstance();
        Texture2D* texutre = textureCreator->getAutoSizeTexture2d("image/ScoreStarDark.png");
        this->initWithTexture(texutre);
    }
    
    void ScoreStar::setLight()
    {
        TextureCreator* textureCreator = TextureCreator::getInstance();
        Texture2D* texutre = textureCreator->getAutoSizeTexture2d("image/ScoreStarLight.png");
        this->setTexture(texutre);
        this->isLight = true;
    }
    
    void ScoreStar::setDark()
    {
        TextureCreator* textureCreator = TextureCreator::getInstance();
        Texture2D* texutre = textureCreator->getAutoSizeTexture2d("image/ScoreStarDark.png");
        this->setTexture(texutre);
        this->isLight = false;
    }
    
}
