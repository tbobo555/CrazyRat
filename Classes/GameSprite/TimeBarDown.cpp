#include "TimeBarDown.h"

namespace GameSprite
{
    TimeBarDown::TimeBarDown(std::string image) : GameSprite::BaseSprite(image){}
    
    void TimeBarDown::addEventListener(){}
    
    bool TimeBarDown::onTouchBegan(Touch *touch, Event *event)
    {
        return false;
    }
    
    void TimeBarDown::onTouchEnded(Touch *touch, Event *event){}
    
    void TimeBarDown::onTouchMoved(Touch *touch, Event *event){}
    
    void TimeBarDown::onTouchCanceled(Touch *touch, Event *event){}
    
}
