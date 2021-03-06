#ifndef  _APP_DELEGATE_H_
#define  _APP_DELEGATE_H_

#include "cocos2d.h"
#include "Controller/GameController.h"
#include "Db/Sqlite3Engine.h"
#include "Db/SwitchSetting.h"
#include "Db/EpisodeSetting.h"
#include "Db/StageSetting.h"
#include "Db/StarSetting.h"
#include "Db/NewHighScoreSetting.h"
#include "PluginIAP/PluginIAP.h"
#include "Lib/InAppPurchase.h"

USING_NS_CC;

/**
@brief    The cocos2d Application.

The reason for implement as private inheritance is to hide some interface call by Director.
*/
class  AppDelegate : private cocos2d::Application
{
public:
    AppDelegate();
    virtual ~AppDelegate();

    virtual void initGLContextAttrs();

    /**
    @brief    Implement Director and Scene init code here.
    @return true    Initialize success, app continue.
    @return false   Initialize failed, app terminate.
    */
    virtual bool applicationDidFinishLaunching();

    /**
    @brief  The function be called when the application enter background
    @param  the pointer of the application
    */
    virtual void applicationDidEnterBackground();

    /**
    @brief  The function be called when the application enter foreground
    @param  the pointer of the application
    */
    virtual void applicationWillEnterForeground();
};

#endif // _APP_DELEGATE_H_

