#include "Rat.h"
#include "GameScene/PlayScene.h"

namespace GameSprite
{
    Rat::Rat(std::string image, int pRatType, int pRoadIndex, int pRatId) : GameSprite::BaseSprite(image)
    {
        this->ratId = pRatId;
        this->roadIndex = pRoadIndex;
        this->runningTime = 0.5f;
        this->addEventListener();
    }

    void Rat::hit()
    {
        this->stopAllActions();
        auto current = static_cast<GameScene::PlayScene*>(Manager::SceneManager::getInstance()->getCurrent());
        if (this->roadIndex == 0) {
            current->road0AvailableIndex.push_back(this->ratId);
        }
        if (this->roadIndex == 1) {
            current->road1AvailableIndex.push_back(this->ratId);
        }
        if (this->roadIndex == 2) {
            current->road2AvailableIndex.push_back(this->ratId);
        }
        this->setPosition(-150, -200);
    }
    
    void Rat::run()
    {
        auto actionBy = MoveBy::create(this->runningTime, Vec2(0, -1000));
        auto blink = Blink::create(0.3f, 3);
        this->runAction(Sequence::create(actionBy, blink, CallFunc::create(CC_CALLBACK_0(Rat::hit, this)), nullptr));
    }
    
    void Rat::addEventListener()
    {
        auto listener = EventListenerTouchOneByOne::create();
        listener->setSwallowTouches(true);
        listener->onTouchBegan = Rat::onTouchBegan;
        listener->onTouchEnded = Rat::onTouchEnded;
        listener->onTouchMoved = Rat::onTouchMoved;
        listener->onTouchCancelled = Rat::onTouchCanceled;
        Director::getInstance()->getEventDispatcher()
        ->addEventListenerWithSceneGraphPriority(listener, this);
    }
    
    bool Rat::onTouchBegan(Touch* touch, Event* event)
    {
        
        auto target = static_cast<Rat*>(event->getCurrentTarget());
        Vec2 locationInNode = target->convertToNodeSpace(touch->getLocation());
        Size s = target->getContentSize();
        Rect rect = Rect(0, 0, s.width, s.height);
        if (rect.containsPoint(locationInNode)) {
            log("Rat began... x = %f, y = %f", locationInNode.x, locationInNode.y);
            target->hit();
            return true;
        }
        return false;
    }

    void Rat::onTouchEnded(Touch* touch, Event* event){}

    void Rat::onTouchMoved(Touch* touch, Event* event){}

    void Rat::onTouchCanceled(Touch* touch, Event* event){}

}
