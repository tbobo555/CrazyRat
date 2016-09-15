#include "Pig.h"
#include "GameScene/PlayBaseScene.h"
#include "Sweet.h"
#include <iostream>

namespace GameSprite
{
    
    Pig::Pig(std::string image, int pRoadIndex, int pigType) : GameSprite::BaseSprite(image, true)
    {
        this->roadIndex = pRoadIndex;
        this->hp = 3;
        this->pigType = pigType;
        this->mouth = new Mouth("MouthAnimation_0.png");
        this->mouth->setVisible(false);
        this->mouth->setPosition(Vec2(this->getContentSize().width/2, this->getContentSize().height/2));
        this->addChild(this->mouth);
        this->explode = new GameSprite::Image("image/Explode0.png");
        this->explode->setPosition(Vec2(this->getContentSize().width/2, this->getContentSize().height*2/3));
        this->addChild(this->explode);
        this->explode->setVisible(false);
        
        this->goodEffect = new Image("image/Good.png");
        this->goodEffect->setGlobalZOrder(4);
        this->addChild(this->goodEffect);
        
        this->greatEffect = new Image("image/Great.png");
        this->greatEffect->setGlobalZOrder(4);
        this->addChild(this->greatEffect);

        this->perfectEffect = new Image("image/Perfect.png");
        this->perfectEffect->setGlobalZOrder(4);
        this->addChild(this->perfectEffect);
        
        this->initAllScoreEffect();

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
            auto nearestSweet = currentScene->getNearestSweet(this->roadIndex);
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
            this->showEatAnimation();
            nearestSweet->eaten();
            Manager::ScoresManager::getInstance()->addScores(scores);
            
            
            std::stringstream haloKeyName;
            if (currentScene->name == "PlayInfiniteScene") {
                haloKeyName << "PlayInfiniteScene_ScoreHalo";
            } else {
                haloKeyName << "PlayScene_ScoreHalo";
            }
            auto scoreHalo = Manager::SpriteManager::getInstance()->getByKey(haloKeyName.str());
            scoreHalo->cleanup();
            scoreHalo->setOpacity(0);
            auto fadeIn = FadeIn::create(0.1f);
            scoreHalo->runAction(Sequence::create(fadeIn, fadeIn->reverse(), NULL));
            currentScene->updateScoreBarStar();
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
        auto autoSizeFrame = TextureCreator::getInstance()->getAutoSizeFrame(cache->getSpriteFrameByName(str));
        animFrames.pushBack(autoSizeFrame);
        auto animation = Animation::createWithSpriteFrames(animFrames, 0.2f);
        this->mouth->runAction(Sequence::create(Animate::create(animation), CallFunc::create(CC_CALLBACK_0(Pig::hideMouth, this)) , NULL));
        
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
        auto autoSizeFrame = TextureCreator::getInstance()->getAutoSizeFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName(str));
        this->setSpriteFrame(autoSizeFrame);
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
        auto autoSizeFrame = TextureCreator::getInstance()->getAutoSizeFrame(cache->getSpriteFrameByName(str));
        animFrames.pushBack(autoSizeFrame);
        
        sprintf(str, "Pig%dAnimation_%d.png", this->pigType, status + 1);
        autoSizeFrame = TextureCreator::getInstance()->getAutoSizeFrame(cache->getSpriteFrameByName(str));
        animFrames.pushBack(autoSizeFrame);
        
        sprintf(str, "Pig%dAnimation_%d.png", this->pigType, status);
        autoSizeFrame = TextureCreator::getInstance()->getAutoSizeFrame(cache->getSpriteFrameByName(str));
        animFrames.pushBack(autoSizeFrame);
        
        auto animation = Animation::createWithSpriteFrames(animFrames, 0.1f);
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
