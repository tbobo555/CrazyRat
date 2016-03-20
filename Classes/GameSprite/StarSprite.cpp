#include "StarSprite.h"

namespace GameSprite
{    
    StarSprite::StarSprite() : BaseSprite(ImageConfig::getInstance()->getImagePath("StarSprite"))
    {
        this->sprite->setPosition(PositionConfig::getInstance()->getBasePsotion("StarSprite"));
    }
    
    void StarSprite::addEventListener()
    {
        auto listener = EventListenerTouchOneByOne::create();
        listener->setSwallowTouches(true);
        listener->onTouchBegan = StarSprite::onTouchBegan;
        listener->onTouchEnded = StarSprite::onTouchEnded;
        listener->onTouchMoved = StarSprite::onTouchMoved;
        listener->onTouchCancelled = StarSprite::onTouchCanceled;
        Director::getInstance()->getEventDispatcher()
        ->addEventListenerWithSceneGraphPriority(listener, this->sprite);
    }

    
    bool StarSprite::onTouchBegan(Touch *touch, Event *event)
    {
        auto target = static_cast<Sprite*>(event->getCurrentTarget());
        Vec2 locationInNode = target->convertToNodeSpace(touch->getLocation());
        Size s = target->getContentSize();
        Rect rect = Rect(0, 0, s.width, s.height);
        
        if (rect.containsPoint(locationInNode)) {
            log("StarSprite began... x = %f, y = %f", locationInNode.x, locationInNode.y);
            target->setScale(1.2);
            return true;
        }
        return false;
    }
    
    void StarSprite::onTouchEnded(Touch *touch, Event *event)
    {
        auto target = static_cast<Sprite*>(event->getCurrentTarget());
        target->setScale(1.0);
    }
    
    void StarSprite::onTouchMoved(Touch *touch, Event *event)
    {
    }
    
    void StarSprite::onTouchCanceled(Touch *touch, Event *event)
    {
        auto target = static_cast<Sprite*>(event->getCurrentTarget());
        target->setScale(1.0);
    }
    
}
