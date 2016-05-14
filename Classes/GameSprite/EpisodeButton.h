#ifndef _GameSprite_EpisodeButton_H_
#define _GameSprite_EpisodeButton_H_

#include "cocos2d.h"
#include "BaseSprite.h"
#include "Lib/TextureCreator.h"

USING_NS_CC;

namespace GameSprite
{
    class EpisodeButton : public BaseSprite
    {
    public:
        EpisodeButton(std::string image, int episodeNumber);
        int episodeNumber;
        bool isLocked;
        void locked();
        void unlocked();
        void addEventListener();
    private:
        static bool onTouchBegan(Touch *touch, Event *event);
        static void onTouchEnded(Touch *touch, Event *event);
        static void onTouchMoved(Touch *touch, Event *event);
        static void onTouchCanceled(Touch *touch, Event *event);
    };
}


#endif /* _GameSprite_EpisodeButton_H_ */
