#include "HighScoreMask.h"
#include "GameScene/StartScene.h"

namespace GameSprite
{
    
    HighScoreMask::HighScoreMask(std::string image) : GameSprite::BaseSprite(image)
    {
        this->addEventListener();
    }
    
    void HighScoreMask::addEventListener()
    {
        auto listener = EventListenerTouchOneByOne::create();
        listener->setSwallowTouches(true);
        listener->onTouchBegan = HighScoreMask::onTouchBegan;
        listener->onTouchEnded = HighScoreMask::onTouchEnded;
        listener->onTouchMoved = HighScoreMask::onTouchMoved;
        listener->onTouchCancelled = HighScoreMask::onTouchCanceled;
        Director::getInstance()->getEventDispatcher()
        ->addEventListenerWithSceneGraphPriority(listener, this);
    }
    
    bool HighScoreMask::onTouchBegan(Touch* touch, Event* event)
    {
        auto target = static_cast<Sprite*>(event->getCurrentTarget());
        Vec2 locationInNode = target->convertToNodeSpace(touch->getLocation());
        Size s = target->getContentSize();
        Rect rect = Rect(0, 0, s.width, s.height);
        if (rect.containsPoint(locationInNode)) {
            log("HighScoreMask began... x = %f, y = %f", locationInNode.x, locationInNode.y);
            return true;
        }
        return false;
    }
    
    void HighScoreMask::onTouchEnded(Touch* touch, Event* event)
    {
        auto current = static_cast<StartScene*>(Manager::SceneManager::getInstance()->getCurrent());
        current->hideHighScore();
    }
    
    void HighScoreMask::onTouchMoved(Touch* touch, Event* event)
    {
    }
    
    void HighScoreMask::onTouchCanceled(Touch* touch, Event* event)
    {
    }
}
