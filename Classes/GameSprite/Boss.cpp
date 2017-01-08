#include "Boss.h"
#include "GameScene/PlayBaseScene.h"

namespace GameSprite
{
    Boss::Boss(int type) : BaseSprite()
    {
        this->life = 100;
        this->type = type;
        this->isAttacking = false;
        this->initWithCache(this->getBossImagePath(0));
        this->setScale(Director::getInstance()->getContentScaleFactor());
        this->explode = new GameSprite::Image("image/Explode0.png");
        this->explode->setPosition(Vec2(this->getContentSize().width/2, this->getContentSize().height*1/3));
        this->explode->setScale(1 / Director::getInstance()->getContentScaleFactor());
        this->addChild(this->explode);
        this->explode->setVisible(false);
        this->startBaseMotion();
    }
    
    Boss::~Boss()
    {
        this->explode->release();
    }
    
    void Boss::hurt()
    {
        this->life--;
        this->pause();
        this->setHurtImage();
        this->showExplode();
        static_cast<PlayBaseScene*>(Manager::SceneManager::getInstance()->getCurrent())->bossHurted();
        this->scheduleOnce(CC_SCHEDULE_SELECTOR(Boss::hideExplode), 0.5f);
    }
    
    void Boss::dead()
    {
        this->stopAllActions();
        this->explode->setVisible(false);
        this->setDeadImage();
    }
    
    void Boss::setHurtImage()
    {
        auto frame = SpriteFrameCache::getInstance()->getSpriteFrameByName(this->getBossImagePath(3));
        this->setSpriteFrame(frame);
    }
    
    void Boss::setDeadImage()
    {
        auto frame = SpriteFrameCache::getInstance()->getSpriteFrameByName(this->getBossImagePath(4));
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
                        CallFunc::create(CC_CALLBACK_0(Boss::setMoveTarget0, this)),
                        CallFunc::create(CC_CALLBACK_0(Boss::autoSkewAdjust, this)),
                        MoveTo::create(1.5f, currentScene->getBossAttackPosition(0)),
                        CallFunc::create(CC_CALLBACK_0(Boss::attackRoad0, this)),
                        CallFunc::create(CC_CALLBACK_0(Boss::setMoveTarget1, this)),
                        CallFunc::create(CC_CALLBACK_0(Boss::autoSkewAdjust, this)),
                        MoveTo::create(1.5f, currentScene->getBossAttackPosition(1)),
                                         CallFunc::create(CC_CALLBACK_0(Boss::attackRoad0, this)),
                        CallFunc::create(CC_CALLBACK_0(Boss::attackRoad1, this)),
                                         CallFunc::create(CC_CALLBACK_0(Boss::attackRoad2, this)),
                        CallFunc::create(CC_CALLBACK_0(Boss::setMoveTarget2, this)),
                        CallFunc::create(CC_CALLBACK_0(Boss::autoSkewAdjust, this)),
                        MoveTo::create(1.5f, currentScene->getBossAttackPosition(2)),
                        CallFunc::create(CC_CALLBACK_0(Boss::attackRoad2, this)),
                        CallFunc::create(CC_CALLBACK_0(Boss::attackDone, this)),
                        NULL));
    }
    
    void Boss::autoSkewAdjust()
    {
        if (this->getPosition().x  < this->nextTargetPosition.x) {
            if (this->getScaleX() > 0) {
                this->cocos2d::Node::setScaleX(-1 * this->getScaleX());
            }
        } else if (this->getPosition().x  > this->nextTargetPosition.x) {
            if (this->getScaleX() < 0) {
                this->cocos2d::Node::setScaleX(-1 * this->getScaleX());
            }
        }
    }
    
    void Boss::setMoveTarget0()
    {
        auto currentScene = static_cast<PlayBaseScene*>(Manager::SceneManager::getInstance()->getCurrent());
        this->nextTargetPosition = currentScene->getBossAttackPosition(0);
    }
    
    void Boss::setMoveTarget1()
    {
        auto currentScene = static_cast<PlayBaseScene*>(Manager::SceneManager::getInstance()->getCurrent());
        this->nextTargetPosition = currentScene->getBossAttackPosition(1);
    }

    void Boss::setMoveTarget2()
    {
        auto currentScene = static_cast<PlayBaseScene*>(Manager::SceneManager::getInstance()->getCurrent());
        this->nextTargetPosition = currentScene->getBossAttackPosition(2);
    }
    
    void Boss::startBaseMotion()
    {
        auto cache = SpriteFrameCache::getInstance();
        Animation* animation = Animation::create();
        auto frame = cache->getSpriteFrameByName(this->getBossImagePath(0));
        animation->addSpriteFrame(frame);
        frame = cache->getSpriteFrameByName(this->getBossImagePath(1));
        animation->addSpriteFrame(frame);
        animation->setDelayPerUnit(0.1f);
        this->runAction(RepeatForever::create(Animate::create(animation)));
    }
    
    std::string Boss::getBossImagePath(int index)
    {
        char str[100] = {0};
        if (this->type < 10) {
            sprintf(str, "Boss0%dAnimation_%d.png", this->type, index);
        } else {
            sprintf(str, "Boss%dAnimation_%d.png", this->type, index);
        }
        return str;
    }
}
