#include "Pig.h"
#include "GameScene/PlayBaseScene.h"
#include "Sweet.h"
#include <iostream>

namespace GameSprite
{
    
    Pig::Pig(std::string image, int pRoadIndex, int pigType) : GameSprite::BaseSprite()
    {
        this->initWithCache(image);
        this->setScale(Director::getInstance()->getContentScaleFactor());
        this->roadIndex = pRoadIndex;
        this->hp = 3;
        this->pigType = pigType;
        
        this->mouth = new Mouth("MouthAnimation_0.png");
        this->mouth->setVisible(false);
        this->mouth->setPosition(Vec2(this->getContentSize().width/2, this->getContentSize().height/2));
        this->mouth->setScale(1);
        this->addChild(this->mouth);
        
        this->explode = new GameSprite::Image("image/Explode0.png");
        this->explode->setPosition(Vec2(this->getContentSize().width/2, this->getContentSize().height*2/3));
        this->explode->setScale(1 / Director::getInstance()->getContentScaleFactor());
        this->addChild(this->explode);
        this->explode->setVisible(false);
        
        this->goodEffect = new Image("image/Good.png");
        this->goodEffect->setGlobalZOrder(4);
        this->goodEffect->setScale(1 / Director::getInstance()->getContentScaleFactor());
        this->addChild(this->goodEffect);
        
        this->greatEffect = new Image("image/Great.png");
        this->greatEffect->setGlobalZOrder(4);
        this->greatEffect->setScale(1 / Director::getInstance()->getContentScaleFactor());
        this->addChild(this->greatEffect);

        this->perfectEffect = new Image("image/Perfect.png");
        this->perfectEffect->setGlobalZOrder(4);
        this->perfectEffect->setScale(1 / Director::getInstance()->getContentScaleFactor());
        this->addChild(this->perfectEffect);
        
        this->initAllScoreEffect();
        
        this->isCheckBlast = false;
    }
    
    Pig::~Pig()
    {
        this->mouth->release();
        this->explode->release();
        this->goodEffect->release();
        this->greatEffect->release();
        this->perfectEffect->release();
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
    
    void Pig::recordPigPosition(cocos2d::Vec2 position)
    {
        this->originPosition = position;
    }
    
    int Pig::eat()
    {
        int scores = 0;
        
        auto currentScene = static_cast<PlayBaseScene*>(Manager::SceneManager::getInstance()->getCurrent());
        
        int nearestSweetIndex = currentScene->getNearestSweetIndex(this->roadIndex);
        if (nearestSweetIndex == -1) {
            this->showEatAnimation();
            return scores;
        } else {
            Sweet* nearestSweet = currentScene->getNearestSweet(this->roadIndex);
            if (nearestSweet == nullptr) {
                this->showEatAnimation();
                return scores;
            }
            float sweetPosition = nearestSweet->getPosition().y;
            float eatBlockPosition = this->getPosition().y + 200;
            float diffPosition = sweetPosition - eatBlockPosition;
            if (diffPosition < 0) {
                diffPosition = diffPosition * -1;
            }
            
            if (nearestSweet->isBomb && diffPosition <= 200) {
                this->hideMouth();
                this->hurt(true);
                CCLOG("hurt!!!");
            } else {
                if (diffPosition <= 50) {
                    this->showScoreEffect(2);
                    scores =  100;
                } else if (diffPosition > 50 && diffPosition <= 75) {
                    this->showScoreEffect(1);
                    scores =  80;
                } else if (diffPosition > 75 && diffPosition <= 150) {
                    this->showScoreEffect(0);
                    scores =  60;
                } else if (diffPosition > 150 && diffPosition <= 200){
                    this->hideMouth();
                    this->hurt();
                    CCLOG("hurt!!!");
                } else {
                    this->showEatAnimation();
                    return 0;
                }
            }
            this->showEatAnimation();
            nearestSweet->eaten();
            if (scores > 0) {
                Manager::ScoresManager::getInstance()->addScores(scores);                
            }
            return scores;
        }
    }
    
    void Pig::showEatAnimation()
    {
        if (this->hp == 0) {
            return;
        }
        this->mouth->stopAllActions();
        this->mouth->setVisible(true);
        this->mouth->runAction(Sequence::create(DelayTime::create(0.2f), CallFunc::create(CC_CALLBACK_0(Pig::hideMouth, this)) , NULL));
        
        this->resetPigPosition();
        auto move = MoveBy::create(0.1f, Vec2(0, 150));
        auto action = Sequence::create(move, move->reverse(), NULL);
        action->setTag(0);
        this->runAction(action);
    }
    
    void Pig::hideMouth()
    {
        this->mouth->stopAllActions();
        this->mouth->setVisible(false);
    }
    
    void Pig::hurt(bool byBomb)
    {
        this->unschedule(CC_SCHEDULE_SELECTOR(Pig::hideExplode));
        this->hideExplode(0);
        if (byBomb) {
            this->showBombExplode();
        } else {
            this->showExplode();
        }
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
        auto frame = SpriteFrameCache::getInstance()->getSpriteFrameByName(str);
        this->setSpriteFrame(frame);
        this->resetPigPosition();
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
        int randomNumber = rand() % 7;
        std::stringstream punchName;
        punchName << "audio/sounds/Punch" << randomNumber << ".caf";
        Manager::SoundsManager::getInstance()->playSound(punchName.str().c_str());
    }
    
    void Pig::showBombExplode()
    {
        TextureCreator* textureCreator = TextureCreator::getInstance();
        Texture2D* texutre = textureCreator->getAutoSizeTexture2d("image/Boom.png");
        this->explode->setTexture(texutre);
        this->explode->setVisible(true);
        Manager::SoundsManager::getInstance()->playSound("audio/sounds/Punch6.caf");
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
        char str[100] = {0};
        int status = 0;
        if (this->hp == 2) {
            status = 2;
        }
        if (this->hp == 1) {
            status = 4;
        }
        Animation* animation = Animation::create();
        
        sprintf(str, "Pig%dAnimation_%d.png", this->pigType, status);
        auto frame = cache->getSpriteFrameByName(str);
        animation->addSpriteFrame(frame);
        
        sprintf(str, "Pig%dAnimation_%d.png", this->pigType, status + 1);
        frame = cache->getSpriteFrameByName(str);
        animation->addSpriteFrame(frame);
        
        sprintf(str, "Pig%dAnimation_%d.png", this->pigType, status);
        frame = cache->getSpriteFrameByName(str);
        animation->addSpriteFrame(frame);
        
        animation->setDelayPerUnit(0.1f);
        this->runAction(RepeatForever::create(Sequence::create(DelayTime::create(rand() % 5 + 1), Animate::create(animation), NULL)));
    }
    
    void Pig::resetPigPosition()
    {
        this->stopActionByTag(0);
        this->setPosition(this->originPosition);
    }
    
    Vec2 Pig::getEffectPosition()
    {
        return Vec2(this->getContentSize().width/2, this->getContentSize().height);
    }
    
    void Pig::initAllScoreEffect()
    {
        this->goodEffect->setPosition(this->getEffectPosition());
        this->goodEffect->setOpacity(0);
        
        this->greatEffect->setPosition(this->getEffectPosition());
        this->greatEffect->setOpacity(0);
        
        this->perfectEffect->setPosition(this->getEffectPosition());
        this->perfectEffect->setOpacity(0);
    }
    
    void Pig::runEnergyBlast()
    {
        auto scene = static_cast<PlayBaseScene*>(Manager::SceneManager::getInstance()->getCurrent());
        auto energyBlast = new Image("image/EnergyBlast.png");
        energyBlast->setPosition(this->getPosition());
        scene->addChild(energyBlast, 4);
        auto visibleSize = Director::getInstance()->getVisibleSize();
        log("visibleSize.height  %f", visibleSize.height);
        this->energyBlastList.push_back(energyBlast);
        energyBlast->runAction(Sequence::create(MoveTo::create(1.f, Vec2(energyBlast->getPosition().x, visibleSize.height)),
                                                NULL));
        if (this->isCheckBlast == false) {
            this->isCheckBlast = true;
            schedule(CC_SCHEDULE_SELECTOR(Pig::isEnergyBlastTouchBoss), 0.1f);
        }
        
    }
    
    void Pig::isEnergyBlastTouchBoss(float delta)
    {
        Vec2 bossPosition = static_cast<PlayBaseScene*>(Manager::SceneManager::getInstance()->getCurrent())->boss->getPosition();
        for (auto i = this->energyBlastList.begin(); i != this->energyBlastList.end();) {
            if (*i == nullptr) {
                i = this->energyBlastList.erase(i);
            } else {
                if (static_cast<Image*>(*i)->getNumberOfRunningActions() == 0) {
                    static_cast<Image*>(*i)->stopAllActions();
                    static_cast<PlayBaseScene*>(Manager::SceneManager::getInstance()->getCurrent())->removeChild(static_cast<Image*>(*i));
                    static_cast<Image*>(*i)->release();
                    this->energyBlastList.erase(i);
                    ++i;
                    continue;
                }
                float xDiff = static_cast<Image*>(*i)->getPosition().x - bossPosition.x;
                float yDiff = static_cast<Image*>(*i)->getPosition().y - bossPosition.y;
                if (xDiff < 0) {
                    xDiff = xDiff * -1;
                }
                if (yDiff < 0) {
                    yDiff = yDiff * -1;
                }
                if (yDiff < 100 && xDiff < 100) {
                    log("fuck it");
                    static_cast<Image*>(*i)->stopAllActions();
                    static_cast<PlayBaseScene*>(Manager::SceneManager::getInstance()->getCurrent())->removeChild(static_cast<Image*>(*i));
                    static_cast<Image*>(*i)->release();
                    static_cast<PlayBaseScene*>(Manager::SceneManager::getInstance()->getCurrent())->boss->setOpacity(150);
                    this->energyBlastList.erase(i);
                }
            }
            ++i;
        }
        if (this->energyBlastList.empty()) {
            unschedule(CC_SCHEDULE_SELECTOR(Pig::isEnergyBlastTouchBoss));
            log("empty");
            this->isCheckBlast = false;
        }
    }
    
    void Pig::longTouch(float delta)
    {
        this->presstTime += delta;
    }
    
    void Pig::showScoreEffect(int type)
    {
        Manager::SoundsManager::getInstance()->playSound("audio/sounds/GotScores.caf");
        this->goodEffect->cleanup();
        this->greatEffect->cleanup();
        this->perfectEffect->cleanup();
        this->initAllScoreEffect();
        auto moveBy = Sequence::create(FadeIn::create(0), MoveBy::create(0.3, Vec2(0, 50)), FadeOut::create(0), NULL) ;
        switch (type) {
            case 0:
                this->goodEffect->runAction(moveBy);
                break;
            case 1:
                this->greatEffect->runAction(moveBy);
                break;
            case 2:
                this->perfectEffect->runAction(moveBy);
                break;
            default:
                this->goodEffect->runAction(moveBy);
                break;
        }
    }
    
    bool Pig::onTouchBegan(Touch* touch, Event* event)
    {
        auto target = static_cast<Pig*>(event->getCurrentTarget());
        Vec2 locationInNode = target->convertToNodeSpace(touch->getLocation());
        Size s = target->getContentSize();
        Rect rect = Rect(0, 0, s.width, s.height);
        if (rect.containsPoint(locationInNode)) {
            auto scene = static_cast<PlayBaseScene*>(Manager::SceneManager::getInstance()->getCurrent());
            log("Pig began... x = %f, y = %f", locationInNode.x, locationInNode.y);
            if (scene->name == "ChallengePlayScene") {
                target->presstTime = 0.f;
                target->schedule(CC_SCHEDULE_SELECTOR(Pig::longTouch), 0.1f);
            }
            return true;
        }
        return false;
    }
    
    void Pig::onTouchEnded(Touch* touch, Event* event)
    {
        auto target = static_cast<Pig*>(event->getCurrentTarget());
        target->unschedule(CC_SCHEDULE_SELECTOR(Pig::longTouch));
        auto scene = static_cast<PlayBaseScene*>(Manager::SceneManager::getInstance()->getCurrent());
        if (scene->name == "ChallengePlayScene") {
            if (target->presstTime < 0.35f) {
                int point = target->eat();
                std::cout << point << std::endl;
            } else {
                target->runEnergyBlast();
                log("shoot");
            }
        } else {
            int point = target->eat();
            std::cout << point << std::endl;
        }
    }
    
    void Pig::onTouchMoved(Touch* touch, Event* event)
    {
        auto target = static_cast<Pig*>(event->getCurrentTarget());
        Vec2 locationInNode = target->convertToNodeSpace(touch->getLocation());
        Size s = target->getContentSize();
        Rect rect = Rect(0, 0, s.width, s.height);
        if (! rect.containsPoint(locationInNode)) {
            auto scene = static_cast<PlayBaseScene*>(Manager::SceneManager::getInstance()->getCurrent());
            if (scene->name == "ChallengePlayScene") {
                target->presstTime = 0.f;
                target->unschedule(CC_SCHEDULE_SELECTOR(Pig::longTouch));
            }
        }
    }
    
    void Pig::onTouchCanceled(Touch* touch, Event* event){}

}
