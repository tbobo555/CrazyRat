#ifndef _Controller_StartController_H_
#define _Controller_StartController_H_
#include "GameScene/StartScene.h"
#include "GameSprite/StartBg.h"
#include "GameSprite/StartButton.h"
#include "GameSprite/SettingButton.h"
#include "GameSprite/SettingBg.h"
#include "GameSprite/MusicButton.h"
#include "GameSprite/SoundsButton.h"
#include "GameSprite/SettingBackButton.h"
#include "Manager/SceneManager.h"
#include "Manager/SpriteManager.h"
#include "cocos2d.h"

USING_NS_CC;

namespace Controller
{
    
    class StartController
    {
    public:
        void static run();
    };
    
}

#endif /* defined(_Controller_StartController_H_) */
