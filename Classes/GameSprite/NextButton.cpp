#include "NextButton.h"
#include "Controller/GameController.h"
#include "GameScene/PlayBaseScene.h"

namespace GameSprite
{
    NextButton::NextButton(std::string image) : GameSprite::BaseSprite(image)
    {
        this->setName("NextButton");
        this->addEventListener();
    }
    
    void NextButton::addEventListener()
    {
        auto listener = EventListenerTouchOneByOne::create();
        listener->setSwallowTouches(true);
        listener->onTouchBegan = NextButton::onTouchBegan;
        listener->onTouchEnded = NextButton::onTouchEnded;
        listener->onTouchMoved = NextButton::onTouchMoved;
        listener->onTouchCancelled = NextButton::onTouchCanceled;
        Director::getInstance()->getEventDispatcher()
        ->addEventListenerWithSceneGraphPriority(listener, this);
    }
    
    bool NextButton::onTouchBegan(Touch* touch, Event* event)
    {
        auto target = static_cast<Sprite*>(event->getCurrentTarget());
        Vec2 locationInNode = target->convertToNodeSpace(touch->getLocation());
        Size s = target->getContentSize();
        Rect rect = Rect(0, 0, s.width, s.height);
        if (rect.containsPoint(locationInNode)) {
            Manager::SoundsManager::getInstance()->playSound("audio/sounds/ButtonClick.caf");
            log("NextButton began... x = %f, y = %f", locationInNode.x, locationInNode.y);
            target->setScale(0.95);
            return true;
        }
        return false;
    }
    
    void NextButton::onTouchEnded(Touch* touch, Event* event)
    {
        auto target = static_cast<Sprite*>(event->getCurrentTarget());
        Vec2 locationInNode = target->convertToNodeSpace(touch->getLocation());
        Size s = target->getContentSize();
        Rect rect = Rect(0, 0, s.width, s.height);
        if (rect.containsPoint(locationInNode)) {
            log("NextButton ended... x = %f, y = %f", locationInNode.x, locationInNode.y);
            target->setScale(1.0);
            auto currentScene = static_cast<GameScene::PlayBaseScene*>(Manager::SceneManager::getInstance()->getCurrent());
            auto controller = Controller::GameController::getInstance();
            if (currentScene->name == "PlayInfiniteScene") {
                controller->playInfiniteSceneToChallengeScene();
            } else if (currentScene->name == "ChallengePlayScene") {
                controller->challengePlaySceneToChallengeScene();
            }
        } else {
            target->setScale(1.0);
        }
    }
    
    void NextButton::onTouchMoved(Touch* touch, Event* event)
    {
        
    }
    
    void NextButton::onTouchCanceled(Touch* touch, Event* event)
    {
        auto target = static_cast<Sprite*>(event->getCurrentTarget());
        target->setScale(1.0);
    }

}
