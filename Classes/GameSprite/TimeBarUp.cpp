#include "TimeBarUp.h"


namespace GameSprite
{
    TimeBarUp::TimeBarUp(std::string image) : GameSprite::BaseSprite(image){}
    
    void TimeBarUp::addEventListener(){}
    
    void TimeBarUp::runProgress(float time)
    {
        
    }
    
    bool TimeBarUp::onTouchBegan(Touch *touch, Event *event)
    {
        return false;
    }
    
    void TimeBarUp::onTouchEnded(Touch *touch, Event *event){}
    
    void TimeBarUp::onTouchMoved(Touch *touch, Event *event){}
    
    void TimeBarUp::onTouchCanceled(Touch *touch, Event *event){}
    
}
