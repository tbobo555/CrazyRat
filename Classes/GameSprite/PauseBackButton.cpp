#include "PauseBackButton.h"
#include "GameScene/PlayScene.h"

namespace GameSprite
{
    PauseBackButton::PauseBackButton(std::string image) : GameSprite::BaseSprite(image)
    {
        this->setName("PauseBackButton");
        this->addEventListener();
    }
    
    void PauseBackButton::addEventListener()
    {
        auto listener = EventListenerTouchOneByOne::create();
        listener->setSwallowTouches(true);
        listener->onTouchBegan = PauseBackButton::onTouchBegan;
        listener->onTouchEnded = PauseBackButton::onTouchEnded;
        listener->onTouchMoved = PauseBackButton::onTouchMoved;
        listener->onTouchCancelled = PauseBackButton::onTouchCanceled;
        Director::getInstance()->getEventDispatcher()
        ->addEventListenerWithSceneGraphPriority(listener, this);
    }
    
    bool PauseBackButton::onTouchBegan(Touch* touch, Event* event)
    {
        auto target = static_cast<Sprite*>(event->getCurrentTarget());
        Vec2 locationInNode = target->convertToNodeSpace(touch->getLocation());
        Size s = target->getContentSize();
        Rect rect = Rect(0, 0, s.width, s.height);
        if (rect.containsPoint(locationInNode)) {
            log("PauseBackButon began... x = %f, y = %f", locationInNode.x, locationInNode.y);
            target->setScale(1.2);
            return true;
        }
        return false;
    }
    
    void PauseBackButton::onTouchEnded(Touch* touch, Event* event)
    {
        auto target = static_cast<Sprite*>(event->getCurrentTarget());
        Vec2 locationInNode = target->convertToNodeSpace(touch->getLocation());
        Size s = target->getContentSize();
        Rect rect = Rect(0, 0, s.width, s.height);
        if (rect.containsPoint(locationInNode)) {
            target->setScale(1.0);
            auto scene = static_cast<GameScene::PlayScene*>(Manager::SceneManager::getInstance()->getCurrent());
            /**
             if (scene->getIsPaused()) {
             scene->resumeScene();
             } else {
             scene->pauseScene();
             }**/
            Manager::SpriteManager* spriteManager = Manager::SpriteManager::getInstance();
            auto pauseBackground = spriteManager->getByKey("PlayScene_PauseBackground");
            auto pauseBackButton = spriteManager->getByKey("PlayScene_PauseBackButton");
            auto musicButton = spriteManager->getByKey("PlayScene_MusicButton");
            auto soundsButton = spriteManager->getByKey("PlayScene_SoundsButton");
            auto backHomeButton = spriteManager->getByKey("PlayScene_BackHomeButton");
            auto retryButton = spriteManager->getByKey("PlayScene_RetryButton");
            pauseBackground->setVisible(false);
            pauseBackground->setLocalZOrder(-100);
            pauseBackButton->setVisible(false);
            pauseBackButton->setLocalZOrder(-100);
            backHomeButton->setVisible(false);
            backHomeButton->setLocalZOrder(-100);
            retryButton->setVisible(false);
            retryButton->setLocalZOrder(-100);
            musicButton->setVisible(false);
            musicButton->setLocalZOrder(-100);
            soundsButton->setVisible(false);
            soundsButton->setLocalZOrder(-100);
            scene->resumeScene();
        } else {
            target->setScale(1.0);
        }
    }
    
    void PauseBackButton::onTouchMoved(Touch* touch, Event* event)
    {
        
    }
    
    void PauseBackButton::onTouchCanceled(Touch* touch, Event* event)
    {
        auto target = static_cast<Sprite*>(event->getCurrentTarget());
        target->setScale(1.0);
    }
}
