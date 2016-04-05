#include "PauseButton.h"
#include "GameScene/PlayScene.h"

namespace GameSprite
{
    PauseButton::PauseButton(std::string image) : GameSprite::BaseSprite(image)
    {
        this->setName("PauseButton");
        this->addEventListener();
    }
    
    void PauseButton::addEventListener()
    {
        auto listener = EventListenerTouchOneByOne::create();
        listener->setSwallowTouches(true);
        listener->onTouchBegan = PauseButton::onTouchBegan;
        listener->onTouchEnded = PauseButton::onTouchEnded;
        listener->onTouchMoved = PauseButton::onTouchMoved;
        listener->onTouchCancelled = PauseButton::onTouchCanceled;
        Director::getInstance()->getEventDispatcher()
        ->addEventListenerWithSceneGraphPriority(listener, this);
    }
    
    bool PauseButton::onTouchBegan(Touch* touch, Event* event)
    {
        auto target = static_cast<Sprite*>(event->getCurrentTarget());
        
        Vec2 locationInNode = target->convertToNodeSpace(touch->getLocation());
        Size s = target->getContentSize();
        Rect rect = Rect(0, 0, s.width, s.height);
        
        if (rect.containsPoint(locationInNode)) {
            log("PauseButton began... x = %f, y = %f", locationInNode.x, locationInNode.y);
            target->setScale(1.2);
            return true;
        }
        return false;
        
    }
    
    void PauseButton::onTouchEnded(Touch* touch, Event* event)
    {
        auto target = static_cast<Sprite*>(event->getCurrentTarget());
        Vec2 locationInNode = target->convertToNodeSpace(touch->getLocation());
        Size s = target->getContentSize();
        Rect rect = Rect(0, 0, s.width, s.height);
        if (rect.containsPoint(locationInNode)) {
            
            auto scene = static_cast<GameScene::PlayScene*>(Manager::SceneManager::getInstance()->getCurrent());
            scene->pauseScene();
            Manager::SpriteManager* spriteManager = Manager::SpriteManager::getInstance();
            auto pauseBackground = spriteManager->getByKey("PauseScene_PauseBackground");
            auto pauseBackButton = spriteManager->getByKey("PauseScene_PauseBackButton");
            auto musicButton = spriteManager->getByKey("PauseScene_MusicButton");
            auto soundsButton = spriteManager->getByKey("PauseScene_SoundsButton");
            auto backHomeButton = spriteManager->getByKey("PauseScene_BackHomeButton");
            auto retryButton = spriteManager->getByKey("PauseScene_RetryButton");
            pauseBackground->setVisible(true);
            pauseBackground->setLocalZOrder(100);
            pauseBackButton->setVisible(true);
            pauseBackButton->setLocalZOrder(101);
            backHomeButton->setVisible(true);
            backHomeButton->setLocalZOrder(101);
            retryButton->setVisible(true);
            retryButton->setLocalZOrder(101);
            musicButton->setVisible(true);
            musicButton->setLocalZOrder(101);
            soundsButton->setVisible(true);
            soundsButton->setLocalZOrder(101);
            
            target->setScale(1.0);
        } else {
            target->setScale(1.0);
        }
    }
    
    void PauseButton::onTouchMoved(Touch* touch, Event* event)
    {
        
    }
    
    void PauseButton::onTouchCanceled(Touch* touch, Event* event)
    {
        auto target = static_cast<Sprite*>(event->getCurrentTarget());
        target->setScale(1.0);
    }

}
