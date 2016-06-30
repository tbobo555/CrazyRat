#include "Pig.h"
#include "GameScene/PlayScene.h"
#include "Sweet.h"
#include <iostream>

namespace GameSprite
{
    
    Pig::Pig(std::string image, int pRoadIndex, int pigType) : GameSprite::BaseSprite(image, true)
    {
        this->roadIndex = pRoadIndex;
        this->hp = 3;
        this->pigType = pigType;
        this->addEventListener();
        this->mouth = new Mouth("MouthAnimation_0.png");
        this->mouth->setVisible(false);
        this->mouth->setPosition(Vec2(this->getContentSize().width/2, this->getContentSize().height/2));
        this->addChild(this->mouth);
        this->explode = new GameSprite::Image("image/Explode0.png");
        this->explode->setPosition(Vec2(this->getContentSize().width/2, this->getContentSize().height*2/3));
        this->addChild(this->explode);
        this->explode->setVisible(false);
    }
    
    Pig::~Pig()
    {
        this->mouth->release();
        this->explode->release();
    }

    void Pig::addEventListener()
    {
        auto listener = EventListenerTouchOneByOne::create();
        listener->setSwallowTouches(true);
        listener->onTouchBegan = Pig::onTouchBegan;
        listener->onTouchEnded = Pig::onTouchEnded;
        listener->onTouchMoved = Pig::onTouchMoved;
        listener->onTouchCancelled = Pig::onTouchCanceled;
        Director::getInstance()->getEventDispatcher()
        ->addEventListenerWithSceneGraphPriority(listener, this);
    }
    
    int Pig::eat()
    {
        int scores = 0;
        auto currentScene = static_cast<PlayScene*>(Manager::SceneManager::getInstance()->getCurrent());
        int nearestSweetIndex = currentScene->getNearestSweetIndex(this->roadIndex);
        if (nearestSweetIndex == -1) {
            return scores;
        } else {
            auto nearestSweet = currentScene->getNearestSweet(this->roadIndex);
            if (nearestSweet == nullptr) {
                return scores;
            }
            float sweetPosition = nearestSweet->getPosition().y;
            float pigPosition = this->getPosition().y;
            float diffPosition = sweetPosition - pigPosition;
            if (diffPosition > 0 && diffPosition < 70) {
                scores =  100;
            } else if (diffPosition >= 70 && diffPosition <= 100) {
                scores =  80;
            } else if (diffPosition > 100 && diffPosition <= 150) {
                scores =  60;
            } else if (diffPosition > 150 && diffPosition <= 200){
                this->hideMouth();
                this->hurt();
                CCLOG("hurt!!!");
            } else {
                this->showEatAnimation();
                return 0;
            }
            this->showEatAnimation();
            nearestSweet->eaten();
            return scores;
        }
    }
    
    void Pig::showEatAnimation()
    {
        if (this->hp == 0) {
            return;
        }
        auto cache = SpriteFrameCache::getInstance();
        this->mouth->stopAllActions();
        this->mouth->setVisible(true);
        Vector<SpriteFrame*> animFrames(1);
        char str[100] = {0};
        sprintf(str, "MouthAnimation_%d.png", 0);
        auto frame = cache->getSpriteFrameByName(str);
        animFrames.pushBack(frame);
        auto animation = Animation::createWithSpriteFrames(animFrames, 0.2f);
        this->mouth->runAction(Sequence::create(Animate::create(animation), CallFunc::create(CC_CALLBACK_0(Pig::hideMouth, this)) , NULL));
    }
    
    void Pig::hideMouth()
    {
        this->mouth->stopAllActions();
        this->mouth->setVisible(false);
    }
    
    void Pig::hurt()
    {
        this->unschedule(CC_SCHEDULE_SELECTOR(Pig::hideExplode));
        this->hideExplode(0);
        this->showExplode();
        this->scheduleOnce(CC_SCHEDULE_SELECTOR(Pig::hideExplode), 0.5f);
        char str[100] = {0};
        this->stopAllActions();
        this->hp --;
        if (this->hp == 0) {
            this->setVisible(false);
            return;
        }
        int status = 0;
        if (this->hp == 2) {
            status = 2;
        }
        if (this->hp == 1) {
            status = 4;
        }
        sprintf(str, "Pig%dAnimation_%d.png", this->pigType, status);
        this->setSpriteFrame(str);
        this->wink();
    }
    
    void Pig::showExplode()
    {
        int x = rand() % 5;
        char str[100] = {0};
        sprintf(str, "image/Explode%d.png", x);
        TextureCreator* textureCreator = TextureCreator::getInstance();
        Texture2D* texutre = textureCreator->getAutoSizeTexture2d(str);
        this->explode->setTexture(texutre);
        this->explode->setVisible(true);
    }
    
    void Pig::hideExplode(float delta)
    {
        this->explode->setVisible(false);
    }
    
    void Pig::wink()
    {
        if (this->hp == 0) {
            return;
        }
        this->stopAllActions();
        auto cache = SpriteFrameCache::getInstance();
        Vector<SpriteFrame*> animFrames(3);
        char str[100] = {0};
        int status = 0;
        if (this->hp == 2) {
            status = 2;
        }
        if (this->hp == 1) {
            status = 4;
        }
        sprintf(str, "Pig%dAnimation_%d.png", this->pigType, status);
        auto frame = cache->getSpriteFrameByName(str);
        animFrames.pushBack(frame);
        sprintf(str, "Pig%dAnimation_%d.png", this->pigType, status + 1);
        frame = cache->getSpriteFrameByName(str);
        animFrames.pushBack(frame);
        sprintf(str, "Pig%dAnimation_%d.png", this->pigType, status);
        frame = cache->getSpriteFrameByName(str);
        animFrames.pushBack(frame);
        auto animation = Animation::createWithSpriteFrames(animFrames, 0.1f);
        this->runAction(RepeatForever::create(Sequence::create(DelayTime::create(rand() % 5 + 1), Animate::create(animation), NULL)));
    }
    
    bool Pig::onTouchBegan(Touch* touch, Event* event)
    {
        auto target = static_cast<Pig*>(event->getCurrentTarget());
        Vec2 locationInNode = target->convertToNodeSpace(touch->getLocation());
        Size s = target->getContentSize();
        Rect rect = Rect(0, 0, s.width, s.height);
        if (rect.containsPoint(locationInNode)) {
            log("Pig began... x = %f, y = %f", locationInNode.x, locationInNode.y);
            int point = target->eat();
            std::cout << point << std::endl;
            return true;
        }
        return false;
    }
    
    void Pig::onTouchEnded(Touch* touch, Event* event){}
    
    void Pig::onTouchMoved(Touch* touch, Event* event){}
    
    void Pig::onTouchCanceled(Touch* touch, Event* event){}

}
