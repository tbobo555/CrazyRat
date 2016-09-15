#include "BackHomeButton.h"
#include "Controller/GameController.h"
#include "GameScene/PlayBaseScene.h"
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
            Manager::SoundsManager::getInstance()->playSound("audio/sounds/ButtonClick.caf");
            log("BackHomeButton began... x = %f, y = %f", locationInNode.x, locationInNode.y);
            target->setScale(0.95);
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
            auto current = SceneManager::getInstance()->getCurrent();
            if (current->name == "PlayInfiniteScene") {
                auto controller = Controller::GameController::getInstance();
                controller->playInfiniteSceneToStartScene();
            } else {
                auto scene = static_cast<PlayScene*>(SceneManager::getInstance()->getCurrent());
                auto controller = Controller::GameController::getInstance();
                controller->PlaySceneToEpisodeScene(scene->episodeNumber, scene->stageNumber);
            }
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
