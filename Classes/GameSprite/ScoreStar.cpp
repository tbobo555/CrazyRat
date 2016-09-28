#include "ScoreStar.h"

namespace GameSprite
{
    ScoreStar::ScoreStar() : GameSprite::BaseSprite()
    {
        this->isLight = false;
        TextureCreator* textureCreator = TextureCreator::getInstance();
        this->darkTexture = textureCreator->getAutoSizeTexture2d("image/ScoreStarDark.png");
        this->lightTexture = textureCreator->getAutoSizeTexture2d("image/ScoreStarLight.png");
        this->darkTexture->retain();
        this->lightTexture->retain();
        this->initWithTexture(this->darkTexture);
    }
    
    ScoreStar::~ScoreStar()
    {
        this->darkTexture->release();
        this->lightTexture->release();
    }
    
    void ScoreStar::setLight()
    {
        this->setTexture(this->lightTexture);
        this->isLight = true;
    }
    
    void ScoreStar::setDark()
    {
        this->setTexture(this->darkTexture);
        this->isLight = false;
    }
    
}
