#include "ProgressBarUp.h"


namespace GameSprite
{
    ProgressBarUp::ProgressBarUp(std::string image) : GameSprite::BaseSprite(image){}
    
    void ProgressBarUp::addEventListener(){}
    
    void ProgressBarUp::runProgress(float time)
    {
        
    }
    
    bool ProgressBarUp::onTouchBegan(Touch *touch, Event *event)
    {
        return false;
    }
    
    void ProgressBarUp::onTouchEnded(Touch *touch, Event *event){}
    
    void ProgressBarUp::onTouchMoved(Touch *touch, Event *event){}
    
    void ProgressBarUp::onTouchCanceled(Touch *touch, Event *event){}
    
}
