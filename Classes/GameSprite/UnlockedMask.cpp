#include "UnlockedMask.h"
#include "GameScene/SelectionScene.h"

namespace GameSprite
{
    UnlockedMask::UnlockedMask(std::string image) : GameSprite::BaseSprite(image)
    {
        this->addEventListener();
    }
    
    void UnlockedMask::addEventListener()
    {
        auto listener = EventListenerTouchOneByOne::create();
        listener->setSwallowTouches(true);
        listener->onTouchBegan = UnlockedMask::onTouchBegan;
        listener->onTouchEnded = UnlockedMask::onTouchEnded;
        listener->onTouchMoved = UnlockedMask::onTouchMoved;
        listener->onTouchCancelled = UnlockedMask::onTouchCanceled;
        Director::getInstance()->getEventDispatcher()
        ->addEventListenerWithSceneGraphPriority(listener, this);
    }
    
    bool UnlockedMask::onTouchBegan(Touch* touch, Event* event)
    {
        auto target = static_cast<Sprite*>(event->getCurrentTarget());
        Vec2 locationInNode = target->convertToNodeSpace(touch->getLocation());
        Size s = target->getContentSize();
        Rect rect = Rect(0, 0, s.width, s.height);
        if (rect.containsPoint(locationInNode)) {
            log("UnlockedMask began... x = %f, y = %f", locationInNode.x, locationInNode.y);
            return true;
        }
        return false;
    }
    
    void UnlockedMask::onTouchEnded(Touch* touch, Event* event)
    {
        SelectionScene* scene = static_cast<SelectionScene*>(Manager::SceneManager::getInstance()->getCurrent());
        scene->removeUnlockedSprite();
    }
    
    void UnlockedMask::onTouchMoved(Touch* touch, Event* event)
    {
    }
    
    void UnlockedMask::onTouchCanceled(Touch* touch, Event* event)
    {
    }

}
