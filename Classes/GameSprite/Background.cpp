#include "Background.h"


namespace GameSprite
{
    Background::Background(std::string image) : GameSprite::BaseSprite(image)
    {
        this->addEventListener();
    }
    
    
    void Background::addEventListener()
    {
        auto listener = EventListenerTouchOneByOne::create();
        listener->setSwallowTouches(true);
        listener->onTouchBegan = Background::onTouchBegan;
        listener->onTouchEnded = Background::onTouchEnded;
        listener->onTouchMoved = Background::onTouchMoved;
        listener->onTouchCancelled = Background::onTouchCanceled;
        Director::getInstance()->getEventDispatcher()
        ->addEventListenerWithSceneGraphPriority(listener, this);
    }
    
    bool Background::onTouchBegan(Touch *touch, Event *event)
    {
        auto target = static_cast<Sprite*>(event->getCurrentTarget());
        Vec2 locationInNode = target->convertToNodeSpace(touch->getLocation());
        Size s = target->getContentSize();
        Rect rect = Rect(0, 0, s.width, s.height);
        if (rect.containsPoint(locationInNode)) {
            return true;
        }
        return false;
    }
    
    void Background::onTouchEnded(Touch *touch, Event *event)
    {
    }
    
    void Background::onTouchMoved(Touch *touch, Event *event)
    {
    }
    
    void Background::onTouchCanceled(Touch *touch, Event *event)
    {
    }

}
