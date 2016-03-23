#include "SettingBackground.h"

namespace GameSprite
{        
    SettingBackground::SettingBackground() : BaseSprite(ImageConfig::getInstance()->getImagePath("SettingBackground"))
    {
        this->sprite->setPosition(PositionConfig::getInstance()->getBasePsotion("SettingBackground"));
        this->addEventListener();
    }
    
    void SettingBackground::addEventListener()
    {
        auto listener = EventListenerTouchOneByOne::create();
        listener->setSwallowTouches(true);
        listener->onTouchBegan = SettingBackground::onTouchBegan;
        listener->onTouchEnded = SettingBackground::onTouchEnded;
        listener->onTouchMoved = SettingBackground::onTouchMoved;
        listener->onTouchCancelled = SettingBackground::onTouchCanceled;
        Director::getInstance()->getEventDispatcher()
        ->addEventListenerWithSceneGraphPriority(listener, this->sprite);
    }
    
    bool SettingBackground::onTouchBegan(Touch* touch, Event* event)
    {
        auto target = static_cast<Sprite*>(event->getCurrentTarget());
        Vec2 locationInNode = target->convertToNodeSpace(touch->getLocation());
        Size s = target->getContentSize();
        Rect rect = Rect(0, 0, s.width, s.height);
        if (rect.containsPoint(locationInNode)) {
            log("SettingBg began... x = %f, y = %f", locationInNode.x, locationInNode.y);
            return true;
        }
        return false;
    }
    
    void SettingBackground::onTouchEnded(Touch* touch, Event* event)
    {
        
    }
    
    void SettingBackground::onTouchMoved(Touch* touch, Event* event)
    {
        
    }
    
    void SettingBackground::onTouchCanceled(Touch* touch, Event* event)
    {
        
    }

}
