#ifndef _Controller_GameController_H_
#define _Controller_GameController_H_

#include "cocos2d.h"
#include "GameSprite/StartBackground.h"
#include "GameSprite/SelectionBackground.h"
#include "GameSprite/StartButton.h"
#include "GameSprite/SettingButton.h"
#include "GameSprite/SettingBackground.h"
#include "GameSprite/MusicButton.h"
#include "GameSprite/SoundsButton.h"
#include "GameSprite/SettingBackButton.h"
#include "GameSprite/StageButton.h"
#include "GameSprite/Star.h"
#include "GameSprite/Master.h"
#include "GameScene/StartScene.h"
#include "GameScene/SelectionScene.h"
#include "Manager/SceneManager.h"
#include "Manager/SpriteManager.h"
#include "Db/CommonSetting.h"

using namespace GameSprite;
using namespace Manager;
using namespace DB;
USING_NS_CC;

namespace Controller
{
    class GameController
    {
    public:
        static GameController* getInstance();
        void runStartScene();
        void startSceneToSelectionScene();
        void loadStaticResourcesForSettingMenu();
        void loadStaticResourcesForStartScene();
        void loadStaticResourcesForSelectionScene();
        //void runLoadingScene();
        void setSettingMenuToCurrentScene();
        void releaseSettingMenuFromCurrentScene();
    private:
        GameController();
        static GameController* instance;
    };
}


#endif /* _Controller_GameController_H_ */
