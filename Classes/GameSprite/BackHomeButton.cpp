#include "BackHomeButton.h"
#include "Controller/GameController.h"
#include "GameScene/PlayScene.h"

namespace GameSprite
{
    BackHomeButton::BackHomeButton(std::string image) : GameSprite::BaseSprite(image)
    {
        this->setName("BackHomeButton");
        this->addEventListener();
    }
    
    void BackHomeButton::addEventListener()
    {
        auto listener = EventListenerTouchOneByOne::create();
        listener->setSwallowTouches(true);
        listener->onTouchBegan = BackHomeButton::onTouchBegan;
        listener->onTouchEnded = BackHomeButton::onTouchEnded;
        listener->onTouchMoved = BackHomeButton::onTouchMoved;
        listener->onTouchCancelled = BackHomeButton::onTouchCanceled;
        Director::getInstance()->getEventDispatcher()
        ->addEventListenerWithSceneGraphPriority(listener, this);
    }
    
    bool BackHomeButton::onTouchBegan(Touch* touch, Event* event)
    {
        auto target = static_cast<Sprite*>(event->getCurrentTarget());
        Vec2 locationInNode = target->convertToNodeSpace(touch->getLocation());
        Size s = target->getContentSize();
        Rect rect = Rect(0, 0, s.width, s.height);
        if (rect.containsPoint(locationInNode)) {
            log("BackHomeButton began... x = %f, y = %f", locationInNode.x, locationInNode.y);
            target->setScale(1.2);
            return true;
        }
        return false;
    }
    
    void BackHomeButton::onTouchEnded(Touch* touch, Event* event)
    {
        auto target = static_cast<Sprite*>(event->getCurrentTarget());
        Vec2 locationInNode = target->convertToNodeSpace(touch->getLocation());
        Size s = target->getContentSize();
        Rect rect = Rect(0, 0, s.width, s.height);
        if (rect.containsPoint(locationInNode)) {
            target->setScale(1.0);
            auto scene = static_cast<GameScene::PlayScene*>(SceneManager::getInstance()->getCurrent());
            auto controller = Controller::GameController::getInstance();
            controller->PlaySceneToMapScene(scene->mapNumber, scene->stageNumber);
        } else {
            target->setScale(1.0);
        }
    }
    
    void BackHomeButton::onTouchMoved(Touch* touch, Event* event)
    {
        
    }
    
    void BackHomeButton::onTouchCanceled(Touch* touch, Event* event)
    {
        auto target = static_cast<Sprite*>(event->getCurrentTarget());
        target->setScale(1.0);
    }

}