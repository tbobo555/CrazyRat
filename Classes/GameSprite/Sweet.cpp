#include "Sweet.h"
#include "GameScene/PlayBaseScene.h"
#include "Pig.h"

namespace GameSprite
{
    Sweet::Sweet(std::string image, int pRoadIndex, int pSweetId) : GameSprite::BaseSprite(image)
    {
        this->sweetId = pSweetId;
        this->roadIndex = pRoadIndex;
        this->runningTime = 6.f;
        this->initSweet(image);
    }
    
    Sweet::Sweet(std::string image, int pRoadIndex, int pSweetId, float pRunningTime) : GameSprite::BaseSprite(image)
    {
        this->sweetId = pSweetId;
        this->roadIndex = pRoadIndex;
        this->runningTime = pRunningTime;
        this->initSweet(image);
    }
    
    Sweet::~Sweet()
    {
        this->bombTexture->release();
        this->sweetTexture->release();
        this->listener->release();
    }
    
    void Sweet::initSweet(std::string image)
    {
        this->listener = EventListenerTouchOneByOne::create();
        listener->setSwallowTouches(true);
        listener->onTouchBegan = Sweet::onTouchBegan;
        listener->onTouchEnded = Sweet::onTouchEnded;
        listener->onTouchMoved = Sweet::onTouchMoved;
        listener->onTouchCancelled = Sweet::onTouchCanceled;
        this->isBomb = false;
        TextureCreator* textureCreator = TextureCreator::getInstance();
        this->sweetTexture = textureCreator->getAutoSizeTexture2d(image);
        this->bombTexture = textureCreator->getAutoSizeTexture2d("image/Bomb.png");
        this->sweetTexture->retain();
        this->bombTexture->retain();
        this->listener->retain();
    }
    
    void Sweet::setSweet()
    {
        this->removeEventListener();
        this->isBomb = false;
        this->setTexture(this->sweetTexture);
    }
    
    void Sweet::setBomb()
    {
        this->setTexture(this->bombTexture);
        this->addEventListener();
        this->isBomb = true;
    }
    
    void Sweet::eaten()
    {
        this->stopAllActions();
        if (this->isBomb) {
            this->setSweet();
        }
        auto current = static_cast<GameScene::PlayBaseScene*>(Manager::SceneManager::getInstance()->getCurrent());
        if (this->roadIndex == 0) {
            current->road0AvailableIndex.push_back(this->sweetId);
            for (auto i = current->road0RunningIndex.begin(); i != current->road0RunningIndex.end();) {
                if (*i == this->sweetId) {
                    i = current->road0RunningIndex.erase(i);
                    break;
                } else {
                    ++i;
                }
            }
        }
        if (this->roadIndex == 1) {
            current->road1AvailableIndex.push_back(this->sweetId);
            for (auto i = current->road1RunningIndex.begin(); i != current->road1RunningIndex.end();) {
                if (*i == this->sweetId) {
                    i = current->road1RunningIndex.erase(i);
                    break;
                } else {
                    ++i;
                }
            }
        }
        if (this->roadIndex == 2) {
            current->road2AvailableIndex.push_back(this->sweetId);
            for (auto i = current->road2RunningIndex.begin(); i != current->road2RunningIndex.end();) {
                if (*i == this->sweetId) {
                    i = current->road2RunningIndex.erase(i);
                    break;
                } else {
                    ++i;
                }
            }
        }
        this->setPosition(-150, -200);
    }
    
    void Sweet::missEat()
    {
        bool byBomb = this->isBomb;
        this->eaten();
        auto current = static_cast<GameScene::PlayBaseScene*>(Manager::SceneManager::getInstance()->getCurrent());
        std::string sceneName = current->name;
        std::stringstream key;
        key << sceneName << "_Road" << this->roadIndex << "Pig";
        auto pig = static_cast<Pig*>(Manager::SpriteManager::getInstance()->getByKey(key.str()));
        pig->hurt(byBomb);
        CCLOG("missEat hurt!!!");
    }
    
    void Sweet::setRunningTime(float time)
    {
        this->runningTime = time;
    }
    
    void Sweet::run()
    {
        int bombRandom = rand() % 7;
        if (bombRandom == 4) {
            this->setBomb();
        }

        Size visibleSize = Director::getInstance()->getVisibleSize();
        Vec2 visibleOrigin = Director::getInstance()->getVisibleOrigin();

        float distance = (visibleOrigin.y + 0.87 * visibleSize.height) - (0.24 * 1920 + 130);
        CCLOG("distance %f", distance);
        auto actionBy = MoveBy::create(this->runningTime, Vec2(0, -1 * distance));
        //auto blink = Blink::create(0.3f, 3);
        this->runAction(Sequence::create(actionBy, CallFunc::create(CC_CALLBACK_0(Sweet::missEat, this)), nullptr));
    }
    
    void Sweet::addEventListener()
    {
        Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(this->listener, this);
    }
    
    void Sweet::removeEventListener()
    {
        Director::getInstance()->getEventDispatcher()->removeEventListener(this->listener);
    }
    
    bool Sweet::onTouchBegan(Touch* touch, Event* event)
    {
        auto target = static_cast<Sweet*>(event->getCurrentTarget());
        Vec2 locationInNode = target->convertToNodeSpace(touch->getLocation());
        Size s = target->getContentSize();
        Rect rect = Rect(0, 0, s.width, s.height);
        if (rect.containsPoint(locationInNode)) {
            Manager::SoundsManager::getInstance()->playSound("audio/sounds/GotScores.caf");
            log("Sweet began... x = %f, y = %f", locationInNode.x, locationInNode.y);
            if (target->isBomb) {
                auto currentScene = Manager::SceneManager::getInstance()->getCurrent();
                Label* addScore = Label::createWithTTF("+100", "fonts/KOMIKAX.ttf", 100);
                addScore->setColor(Color3B(255, 114, 18));
                addScore->setPosition(target->getPosition());
                target->eaten();
                Manager::ScoresManager::getInstance()->addScores(100);
                currentScene->addChild(addScore, 10);
                addScore->runAction(Sequence::create(MoveBy::create(0.3f, Vec2(0, 50)), FadeOut::create(0.1f), NULL));
            }
        }
        return false;
    }
    
    void Sweet::onTouchEnded(Touch* touch, Event* event)
    {
    }
    
    void Sweet::onTouchMoved(Touch* touch, Event* event)
    {
    }
    
    void Sweet::onTouchCanceled(Touch* touch, Event* event)
    {
    }
}
