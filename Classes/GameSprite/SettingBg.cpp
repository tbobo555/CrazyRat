#include "SettingBg.h"

namespace GameSprite
{
    SettingBg::SettingBg() : BaseSprite()
    {
        Size visibleSize = Director::getInstance()->getVisibleSize();
        Vec2 origin = Director::getInstance()->getVisibleOrigin();

        this->sprite->setTexture("image/BG.png");
        this->sprite->setOpacity(200);
        this->sprite->setColor(Color3B(255, 0, 0));
        this->sprite->setPosition(Vec2(origin.x + visibleSize.width / 2,
                                       origin.y + visibleSize.height / 2));
        this->addEventListner();
    }
    
    void SettingBg::addEventListner()
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
        if (rect.containsPoint(locationInNode))
        {
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
