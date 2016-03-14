#include "StageButton.h"

namespace GameSprite
{
    const std::string StageButton::originImage = ImageConfig::getInstance()->getImagePath("StageButton");
    
    StageButton::StageButton() : BaseSprite(StageButton::originImage)
    {
        this->sprite->setPosition(PositionConfig::getInstance()->getBasePsotion("StageButton"));
    }
    
    void StageButton::addEventListener()
    {
        auto listener = EventListenerTouchOneByOne::create();
        listener->setSwallowTouches(true);
        listener->onTouchBegan = StageButton::onTouchBegan;
        listener->onTouchEnded = StageButton::onTouchEnded;
        listener->onTouchMoved = StageButton::onTouchMoved;
        listener->onTouchCancelled = StageButton::onTouchCanceled;
        Director::getInstance()->getEventDispatcher()
        ->addEventListenerWithSceneGraphPriority(listener, this->sprite);
    }

    
    bool StageButton::onTouchBegan(Touch *touch, Event *event)
    {
        auto target = static_cast<Sprite*>(event->getCurrentTarget());
        Vec2 locationInNode = target->convertToNodeSpace(touch->getLocation());
        Size s = target->getContentSize();
        Rect rect = Rect(0, 0, s.width, s.height);
        
        if (rect.containsPoint(locationInNode)) {
            log("StageButton began... x = %f, y = %f", locationInNode.x, locationInNode.y);
            target->setScale(1.2);
            return true;
        }
        return false;
    }
    
    void StageButton::onTouchEnded(Touch *touch, Event *event)
    {
        auto target = static_cast<Sprite*>(event->getCurrentTarget());
        target->setScale(1.0);
    }
    
    void StageButton::onTouchMoved(Touch *touch, Event *event)
    {
    }

    void StageButton::onTouchCanceled(Touch *touch, Event *event)
    {
        auto target = static_cast<Sprite*>(event->getCurrentTarget());
        target->setScale(1.0);
    }
    
}
