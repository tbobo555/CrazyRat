#include "Sweet.h"
#include "GameScene/PlayScene.h"
#include "Pig.h"

namespace GameSprite
{
    Sweet::Sweet(std::string image, int pSweetType, int pRoadIndex, int pSweetId) : GameSprite::BaseSprite(image)
    {
        this->sweetId = pSweetId;
        this->roadIndex = pRoadIndex;
        this->runningTime = 3.f;
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
        pig->hp -- ;
    }
    
    void Sweet::run()
    {
        auto actionBy = MoveBy::create(this->runningTime, Vec2(0, -1000));
        //auto blink = Blink::create(0.3f, 3);
        this->runAction(Sequence::create(actionBy, CallFunc::create(CC_CALLBACK_0(Sweet::missEat, this)), nullptr));
    }
}
