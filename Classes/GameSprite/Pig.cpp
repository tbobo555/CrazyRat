#include "Pig.h"
#include "GameScene/PlayScene.h"
#include "Sweet.h"
#include <iostream>

namespace GameSprite
{
    
    Pig::Pig(std::string image, int pRoadIndex) : GameSprite::BaseSprite(image)
    {
        this->roadIndex = pRoadIndex;
        this->hp = 3;
        this->addEventListener();
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
            } else if (diffPosition > 100 && diffPosition <= 130) {
                scores =  60;
            } else {
                this->hp --;
                return 0;
            }
            nearestSweet->eaten();
            return scores;
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
