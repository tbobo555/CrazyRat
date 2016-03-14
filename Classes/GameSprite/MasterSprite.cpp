#include "MasterSprite.h"


namespace GameSprite
{
    const std::string MasterSprite::originImage = ImageConfig::getInstance()->getImagePath("MasterSprite");
    
    MasterSprite::MasterSprite() : BaseSprite(MasterSprite::originImage)
    {
        this->sprite->setPosition(PositionConfig::getInstance()->getBasePsotion("MasterSprite"));
    }
    
    void MasterSprite::addEventListener()
    {
        auto listener = EventListenerTouchOneByOne::create();
        listener->setSwallowTouches(true);
        listener->onTouchBegan = MasterSprite::onTouchBegan;
        listener->onTouchEnded = MasterSprite::onTouchEnded;
        listener->onTouchMoved = MasterSprite::onTouchMoved;
        listener->onTouchCancelled = MasterSprite::onTouchCanceled;
        Director::getInstance()->getEventDispatcher()
        ->addEventListenerWithSceneGraphPriority(listener, this->sprite);
    }

    
    bool MasterSprite::onTouchBegan(Touch *touch, Event *event)
    {
        auto target = static_cast<Sprite*>(event->getCurrentTarget());
        Vec2 locationInNode = target->convertToNodeSpace(touch->getLocation());
        Size s = target->getContentSize();
        Rect rect = Rect(0, 0, s.width, s.height);
        
        if (rect.containsPoint(locationInNode)) {
            log("MasterSprite began... x = %f, y = %f", locationInNode.x, locationInNode.y);
            target->setScale(1.2);
            return true;
        }
        return false;
    }
    
    void MasterSprite::onTouchEnded(Touch *touch, Event *event)
    {
        auto target = static_cast<Sprite*>(event->getCurrentTarget());
        target->setScale(1.0);
    }
    
    void MasterSprite::onTouchMoved(Touch *touch, Event *event)
    {
    }
    
    void MasterSprite::onTouchCanceled(Touch *touch, Event *event)
    {
        auto target = static_cast<Sprite*>(event->getCurrentTarget());
        target->setScale(1.0);
    }

}