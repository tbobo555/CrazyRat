#include "RetryButton.h"
#include "Controller/GameController.h"
#include "GameScene/PlayBaseScene.h"
#include "GameScene/PlayScene.h"

namespace GameSprite
{
    RetryButton::RetryButton(std::string image) : GameSprite::BaseSprite(image)
    {
        this->setName("RetryButton");
        this->addEventListener();
    }
    
    void RetryButton::addEventListener()
    {
        auto listener = EventListenerTouchOneByOne::create();
        listener->setSwallowTouches(true);
        listener->onTouchBegan = RetryButton::onTouchBegan;
        listener->onTouchEnded = RetryButton::onTouchEnded;
        listener->onTouchMoved = RetryButton::onTouchMoved;
        listener->onTouchCancelled = RetryButton::onTouchCanceled;
        Director::getInstance()->getEventDispatcher()
        ->addEventListenerWithSceneGraphPriority(listener, this);
    }
    
    bool RetryButton::onTouchBegan(Touch* touch, Event* event)
    {
        auto target = static_cast<Sprite*>(event->getCurrentTarget());
        Vec2 locationInNode = target->convertToNodeSpace(touch->getLocation());
        Size s = target->getContentSize();
        Rect rect = Rect(0, 0, s.width, s.height);
        if (rect.containsPoint(locationInNode)) {
            Manager::SoundsManager::getInstance()->playSound("audio/sounds/ButtonClick.caf");
            log("RetryButton began... x = %f, y = %f", locationInNode.x, locationInNode.y);
            target->setScale(0.95);
            return true;
        }
        return false;
    }
    
    void RetryButton::onTouchEnded(Touch* touch, Event* event)
    {
        auto target = static_cast<Sprite*>(event->getCurrentTarget());
        Vec2 locationInNode = target->convertToNodeSpace(touch->getLocation());
        Size s = target->getContentSize();
        Rect rect = Rect(0, 0, s.width, s.height);
        if (rect.containsPoint(locationInNode)) {
            target->setScale(1.0);
            auto current = SceneManager::getInstance()->getCurrent();
            auto controller = Controller::GameController::getInstance();
            if (current->name == "PlayInfiniteScene") {
                controller->retryPlayInfiniteScene();
            } else {
                auto scene = static_cast<PlayScene*>(SceneManager::getInstance()->getCurrent());
                controller->RetryPlayScene(scene->episodeNumber, scene->stageNumber);
            }
        } else {
            target->setScale(1.0);
        }
    }
    
    void RetryButton::onTouchMoved(Touch* touch, Event* event)
    {
        
    }
    
    void RetryButton::onTouchCanceled(Touch* touch, Event* event)
    {
        auto target = static_cast<Sprite*>(event->getCurrentTarget());
        target->setScale(1.0);
    }

}
