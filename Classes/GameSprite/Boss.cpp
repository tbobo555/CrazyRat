#include "Boss.h"
#include "GameScene/PlayBaseScene.h"

namespace GameSprite
{
    Boss::Boss(std::string image) : BaseSprite()
    {
        this->life = 1;
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
    
    void Boss::dead()
    {
        this->stopAllActions();
        this->explode->setVisible(false);
        this->setHurtImage(3);
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
    
    void Boss::attackDone()
    {
        this->isAttacking = false;
    }
    
    void Boss::attackRoad0()
    {
        static_cast<PlayBaseScene*>(Manager::SceneManager::getInstance()->getCurrent())->addSweetToRoad0 = true;
    }
    
    void Boss::attackRoad1()
    {
        static_cast<PlayBaseScene*>(Manager::SceneManager::getInstance()->getCurrent())->addSweetToRoad1 = true;
    }
    
    void Boss::attackRoad2()
    {
        static_cast<PlayBaseScene*>(Manager::SceneManager::getInstance()->getCurrent())->addSweetToRoad2 = true;
    }
    
    void Boss::attackMode1()
    {
        this->isAttacking = true;
        auto currentScene = static_cast<PlayBaseScene*>(Manager::SceneManager::getInstance()->getCurrent());
        this->runAction(Sequence::create(
                        MoveTo::create(1.5f, currentScene->getBossAttackPosition(0)),
                        CallFunc::create(CC_CALLBACK_0(Boss::attackRoad0, this)),
                        MoveTo::create(1.5f, currentScene->getBossAttackPosition(1)),
                        CallFunc::create(CC_CALLBACK_0(Boss::attackRoad1, this)),
                        MoveTo::create(1.5f, currentScene->getBossAttackPosition(2)),
                        CallFunc::create(CC_CALLBACK_0(Boss::attackRoad2, this)),
                        CallFunc::create(CC_CALLBACK_0(Boss::attackDone, this)),
                        NULL));
    }
}
