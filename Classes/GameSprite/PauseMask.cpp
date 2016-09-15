#include "PauseMask.h"
#include "GameScene/PlayBaseScene.h"

namespace GameSprite
{
    PauseMask::PauseMask(std::string image) : GameSprite::BaseSprite(image)
    {
        this->setName("PauseMask");
        this->addEventListener();
    }
    
    void PauseMask::addEventListener()
    {
        auto listener = EventListenerTouchOneByOne::create();
        listener->setSwallowTouches(true);
        listener->onTouchBegan = PauseMask::onTouchBegan;
        listener->onTouchEnded = PauseMask::onTouchEnded;
        listener->onTouchMoved = PauseMask::onTouchMoved;
        listener->onTouchCancelled = PauseMask::onTouchCanceled;
        Director::getInstance()->getEventDispatcher()
        ->addEventListenerWithSceneGraphPriority(listener, this);
    }
    
    bool PauseMask::onTouchBegan(Touch* touch, Event* event)
    {
        auto target = static_cast<Sprite*>(event->getCurrentTarget());
        Vec2 locationInNode = target->convertToNodeSpace(touch->getLocation());
        Size s = target->getContentSize();
        Rect rect = Rect(0, 0, s.width, s.height);
        if (rect.containsPoint(locationInNode)) {
            log("PauseMask began... x = %f, y = %f", locationInNode.x, locationInNode.y);
            return true;
        }
        return false;
    }
    
    void PauseMask::onTouchEnded(Touch* touch, Event* event)
    {
        auto target = static_cast<Sprite*>(event->getCurrentTarget());
        Vec2 locationInNode = target->convertToNodeSpace(touch->getLocation());
        Size s = target->getContentSize();
        Rect rect = Rect(0, 0, s.width, s.height);
        auto pauseBackground = Manager::SpriteManager::getInstance()->getByKey("PauseScene_PauseBackground");
        Size pauseBackgroundSize = pauseBackground->getContentSize();
        Rect pauseBackgroundRect = Rect(pauseBackground->getPositionX() - pauseBackgroundSize.width / 2,
                                        pauseBackground->getPositionY() - pauseBackgroundSize.height / 2,
                                        pauseBackgroundSize.width,
                                        pauseBackgroundSize.height);
        auto pauseBackButton = Manager::SpriteManager::getInstance()->getByKey("PauseScene_PauseBackButton");
        Size pauseBackButtonSize = pauseBackButton->getContentSize();
        Rect pauseBackButtonRect = Rect(
                                        (pauseBackground->getPositionX() + pauseBackgroundSize.width / 2) - pauseBackButtonSize.width / 2,
                                        (pauseBackground->getPositionY() + pauseBackgroundSize.height / 2) - pauseBackButtonSize.height / 2,
                                        pauseBackButtonSize.width, pauseBackButtonSize.height);
        if (!pauseBackgroundRect.containsPoint(locationInNode) &&
            !pauseBackButtonRect.containsPoint(locationInNode) &&
            rect.containsPoint(locationInNode)) {
            auto scene = static_cast<GameScene::PlayBaseScene*>(Manager::SceneManager::getInstance()->getCurrent());
            Manager::SpriteManager* spriteManager = Manager::SpriteManager::getInstance();
            auto pauseBackground = spriteManager->getByKey("PauseScene_PauseBackground");
            auto pauseBackButton = spriteManager->getByKey("PauseScene_PauseBackButton");
            auto musicButton = spriteManager->getByKey("PauseScene_MusicButton");
            auto soundsButton = spriteManager->getByKey("PauseScene_SoundsButton");
            auto backHomeButton = spriteManager->getByKey("PauseScene_BackHomeButton");
            auto retryButton = spriteManager->getByKey("PauseScene_RetryButton");
            auto pauseMask = spriteManager->getByKey("PauseScene_PauseMask");
            pauseMask->setVisible(false);
            pauseMask->setLocalZOrder(-100);
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
        }
    }
    
    void PauseMask::onTouchMoved(Touch* touch, Event* event)
    {
    }
    
    void PauseMask::onTouchCanceled(Touch* touch, Event* event)
    {
    }

}
