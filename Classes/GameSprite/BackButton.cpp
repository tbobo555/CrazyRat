#include "BackButton.h"
#include "Controller/GameController.h"
#include <iostream>

namespace GameSprite {
    
    BackButton::BackButton(std::string image) : GameSprite::BaseSprite(image)
    {
        this->addEventListener();
    }
    
    void BackButton::addEventListener()
    {
        auto listener = EventListenerTouchOneByOne::create();
        listener->setSwallowTouches(true);
        listener->onTouchBegan = BackButton::onTouchBegan;
        listener->onTouchEnded = BackButton::onTouchEnded;
        listener->onTouchMoved = BackButton::onTouchMoved;
        listener->onTouchCancelled = BackButton::onTouchCanceled;
        Director::getInstance()->getEventDispatcher()
        ->addEventListenerWithSceneGraphPriority(listener, this);
    }

    bool BackButton::onTouchBegan(Touch *touch, Event *event)
    {
        auto target = static_cast<Sprite*>(event->getCurrentTarget());
        Vec2 locationInNode = target->convertToNodeSpace(touch->getLocation());
        Size s = target->getContentSize();
        Rect rect = Rect(0, 0, s.width, s.height);
        
        if (rect.containsPoint(locationInNode)) {
            log("BackButton began... x = %f, y = %f", locationInNode.x, locationInNode.y);
            target->setScale(0.9);
            return true;
        }
        return false;
    }

    void BackButton::onTouchEnded(Touch *touch, Event *event)
    {
        auto target = static_cast<Sprite*>(event->getCurrentTarget());
        Vec2 locationInNode = target->convertToNodeSpace(touch->getLocation());
        Size s = target->getContentSize();
        Rect rect = Rect(0, 0, s.width, s.height);
        if (rect.containsPoint(locationInNode)) {
            log("BackButton ended... x = %f, y = %f", locationInNode.x, locationInNode.y);
            auto scene = SceneManager::getInstance()->getCurrent();
            auto controller = Controller::GameController::getInstance();
            target->setScale(1.0);
            if (scene->name == "EpisodeScene") {
                controller->EpisodeSceneToSelectionScene(static_cast<EpisodeScene*>(scene)->episodeNumber);
            } else if (scene->name == "SelectionScene") {
                controller->selectionSceneToStartScene();
            }
        } else {
            target->setScale(1.0);
        }
    }

    void BackButton::onTouchMoved(Touch *touch, Event *event)
    {
    }

    void BackButton::onTouchCanceled(Touch *touch, Event *event)
    {
        auto target = static_cast<Sprite*>(event->getCurrentTarget());
        target->setScale(1.0);
    }
}
