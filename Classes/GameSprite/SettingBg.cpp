#include "SettingBg.h"

namespace GameSprite
{        
    SettingBg::SettingBg() : BaseSprite(ImageConfig::getInstance()->getImagePath("SettingBg"))
    {
        this->sprite->setPosition(PositionConfig::getInstance()->getBasePsotion("SettingBg"));
        this->addEventListener();
    }
    
    void SettingBg::addEventListener()
    {
        auto listener = EventListenerTouchOneByOne::create();
        listener->setSwallowTouches(true);
        listener->onTouchBegan = SettingBg::onTouchBegan;
        listener->onTouchEnded = SettingBg::onTouchEnded;
        listener->onTouchMoved = SettingBg::onTouchMoved;
        listener->onTouchCancelled = SettingBg::onTouchCanceled;
        Director::getInstance()->getEventDispatcher()
        ->addEventListenerWithSceneGraphPriority(listener, this->sprite);
    }
    
    bool SettingBg::onTouchBegan(Touch* touch, Event* event)
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
    
    void SettingBg::onTouchEnded(Touch* touch, Event* event)
    {
        
    }
    
    void SettingBg::onTouchMoved(Touch* touch, Event* event)
    {
        
    }
    
    void SettingBg::onTouchCanceled(Touch* touch, Event* event)
    {
        
    }

}
