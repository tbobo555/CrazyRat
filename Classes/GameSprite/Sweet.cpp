#include "Sweet.h"
#include "GameScene/PlayScene.h"
#include "Pig.h"

namespace GameSprite
{
    Sweet::Sweet(std::string image, int pRoadIndex, int pSweetId) : GameSprite::BaseSprite(image)
    {
        this->sweetId = pSweetId;
        this->roadIndex = pRoadIndex;
        this->runningTime = 6.f;
    }
    
    Sweet::Sweet(std::string image, int pRoadIndex, int pSweetId, float pRunningTime) : GameSprite::BaseSprite(image)
    {
        this->sweetId = pSweetId;
        this->roadIndex = pRoadIndex;
        this->runningTime = pRunningTime;
    }

    void Sweet::eaten()
    {
        this->stopAllActions();
        auto current = static_cast<GameScene::PlayScene*>(Manager::SceneManager::getInstance()->getCurrent());
        if (this->roadIndex == 0) {
            current->road0AvailableIndex.push_back(this->sweetId);
            current->road0RunningIndex.pop();
        }
        if (this->roadIndex == 1) {
            current->road1AvailableIndex.push_back(this->sweetId);
            current->road1RunningIndex.pop();
        }
        if (this->roadIndex == 2) {
            current->road2AvailableIndex.push_back(this->sweetId);
            current->road2RunningIndex.pop();
        }
        this->setPosition(-150, -200);
    }
    
    void Sweet::missEat()
    {
        this->eaten();
        std::stringstream key;
        key << "PlayScene_Road" << this->roadIndex << "Pig";
        auto pig = static_cast<Pig*>(Manager::SpriteManager::getInstance()->getByKey(key.str()));
        pig->hurt();
        CCLOG("missEat hurt!!!");
    }
    
    void Sweet::setRunningTime(float time)
    {
        this->runningTime = time;
    }
    
    void Sweet::run()
    {
        Size visibleSize = Director::getInstance()->getVisibleSize();
        Vec2 visibleOrigin = Director::getInstance()->getVisibleOrigin();

        float distance = (visibleOrigin.y + 0.87 * visibleSize.height) - (0.24 * 1920 + 130);
        CCLOG("distance %f", distance);
        auto actionBy = MoveBy::create(this->runningTime, Vec2(0, -1 * distance));
        //auto blink = Blink::create(0.3f, 3);
        this->runAction(Sequence::create(actionBy, CallFunc::create(CC_CALLBACK_0(Sweet::missEat, this)), nullptr));
    }
}
