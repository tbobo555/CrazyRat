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
        ->addEventListenerWithSceneGraphPriority(listener, this->sprite);
    }
    
    bool Background::onTouchBegan(Touch *touch, Event *event)
    {
        return true;
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
