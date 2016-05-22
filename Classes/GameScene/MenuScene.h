#ifndef _GameScene_MenuScene_H_
#define _GameScene_MenuScene_H_

#include "cocos2d.h"
#include "BaseScene.h"
#include "GameSprite/SettingButton.h"
#include "GameSprite/Background.h"
#include "GameSprite/SettingBackButton.h"
#include "GameSprite/MusicButton.h"
#include "GameSprite/SoundsButton.h"
#include "Config/ImageConfig.h"
#include "Manager/SpriteManager.h"

namespace GameScene
{
    class MenuScene : public BaseScene
    {
    public:
        MenuScene();
        void initScene();
        void releaseScene();
        GameSprite::Background* settingBackground;
        GameSprite::SettingButton* settingButton;
        GameSprite::SettingBackButton* settingBackButton;
        GameSprite::MusicButton* musicButton;
        GameSprite::SoundsButton* soundsButton;
    private:
        Vec2 getSettingBackgroundPosition();
        Vec2 getSettingButtonPosition();
        Vec2 getSettingBackButtonPosition();
        Vec2 getMusicButtonPosition();
        Vec2 getSoundsButtonPosition();
    };
}

#endif /* _GameSprite_MenuScene_H_ */
