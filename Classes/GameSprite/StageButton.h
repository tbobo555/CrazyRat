#ifndef _GameSprite_StageButton_H_
#define _GameSprite_StageButton_H_

#include "BaseSprite.h"
#include "cocos2d.h"

USING_NS_CC;

namespace GameSprite
{
    class StageButton : public BaseSprite
    {
    public:
        StageButton(std::string image, int pEpisodeNumber, int pStageNumber);
        int episodeNumber;
        int stageNumber;
        bool isLocked;
        void locked();
        void unlocked();
        void addEventListener();
    private:
        static bool onTouchBegan(Touch *touch, Event *event);
        static void onTouchEnded(Touch *touch, Event *event);
        static void onTouchCanceled(Touch *touch, Event *event);
        static void onTouchMoved(Touch *touch, Event *event);
    };
}

#endif /* _GameSprite_StageButton_H_ */
