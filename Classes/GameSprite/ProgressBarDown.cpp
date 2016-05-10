#include "ProgressBarDown.h"

namespace GameSprite
{
    ProgressBarDown::ProgressBarDown(std::string image) : GameSprite::BaseSprite(image){}
    
    void ProgressBarDown::addEventListener(){}
    
    bool ProgressBarDown::onTouchBegan(Touch *touch, Event *event)
    {
        return false;
    }
    
    void ProgressBarDown::onTouchEnded(Touch *touch, Event *event){}
    
    void ProgressBarDown::onTouchMoved(Touch *touch, Event *event){}
    
    void ProgressBarDown::onTouchCanceled(Touch *touch, Event *event){}
    
}
