#include "Boss.h"
#include "GameScene/PlayBaseScene.h"

namespace GameSprite
{
    Boss::Boss(std::string image) : BaseSprite()
    {
        this->life = 30;
        this->initWithCache(image);
        this->setScale(Director::getInstance()->getContentScaleFactor());
        
        this->explode = new GameSprite::Image("image/Explode0.png");
        this->explode->setPosition(Vec2(this->getContentSize().width/2, this->getContentSize().height*1/3));
        this->explode->setScale(1 / Director::getInstance()->getContentScaleFactor());
        this->addChild(this->explode);
        this->explode->setVisible(false);
    }
    
    Boss::~Boss()
    {
        this->explode->release();
    }
    
    void Boss::hurt()
    {
        this->life--;
        int i = rand() % 3;
        this->setHurtImage(i);
        this->showExplode();
        static_cast<PlayBaseScene*>(Manager::SceneManager::getInstance()->getCurrent())->bossHurted();
        this->scheduleOnce(CC_SCHEDULE_SELECTOR(Boss::hideExplode), 0.5f);
    }
    
    void Boss::setHurtImage(int index)
    {
        char str[100] = {0};
        sprintf(str, "Boss01Animation_%d.png", index);
        auto frame = SpriteFrameCache::getInstance()->getSpriteFrameByName(str);
        this->setSpriteFrame(frame);
    }
    
    void Boss::showExplode()
    {
        int x = rand() % 5;
        char str[100] = {0};
        sprintf(str, "image/Explode%d.png", x);
        TextureCreator* textureCreator = TextureCreator::getInstance();
        Texture2D* texutre = textureCreator->getAutoSizeTexture2d(str);
        this->explode->setTexture(texutre);
        this->explode->setVisible(true);
    }
    
    void Boss::hideExplode(float delta)
    {
        this->explode->setVisible(false);
    }
}
