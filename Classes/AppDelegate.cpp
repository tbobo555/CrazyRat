#include "AppDelegate.h"


static cocos2d::Size designResolutionSize = cocos2d::Size(1080, 1920);
static cocos2d::Size mediumResolutionSize = cocos2d::Size(1080, 1920);

AppDelegate::AppDelegate() {

}

AppDelegate::~AppDelegate() 
{
}

//if you want a different context,just modify the value of glContextAttrs
//it will takes effect on all platforms
void AppDelegate::initGLContextAttrs()
{
    //set OpenGL context attributions,now can only set six attributions:
    //red,green,blue,alpha,depth,stencil
    GLContextAttrs glContextAttrs = {8, 8, 8, 8, 24, 8};

    GLView::setGLContextAttrs(glContextAttrs);
}

// If you want to use packages manager to install more packages, 
// don't modify or remove this function
static int register_all_packages()
{
    return 0; //flag for packages manager
}

bool AppDelegate::applicationDidFinishLaunching() {
    // initialize director
    auto director = Director::getInstance();
    auto glview = director->getOpenGLView();
    if(!glview) {
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32) || (CC_TARGET_PLATFORM == CC_PLATFORM_MAC) || (CC_TARGET_PLATFORM == CC_PLATFORM_LINUX)
        glview = GLViewImpl::createWithRect("CrazyRat", Rect(0, 0, designResolutionSize.width, designResolutionSize.height));
#else
        glview = GLViewImpl::create("CrazyRat");
#endif
        director->setOpenGLView(glview);
    }

    // turn on display FPS
    director->setDisplayStats(true);

    // set FPS. the default value is 1.0/60 if you don't call this
    director->setAnimationInterval(1.0 / 60);

    // Set the design resolution
    glview->setDesignResolutionSize(designResolutionSize.width,
                                    designResolutionSize.height,
                                    ResolutionPolicy::NO_BORDER);
    
    Size frameSize = glview->getFrameSize();
    
    float scaleFactor = fmax(frameSize.width / mediumResolutionSize.width,
                             frameSize.height / mediumResolutionSize.height);
 
    director->setContentScaleFactor(scaleFactor);

    register_all_packages();
    
    Sqlite3Engine::getInstance()->checkIsFirstCreate();
    Sqlite3Engine::getInstance()->connect();
    SwitchSetting *switchSetting = SwitchSetting::getInstance();
    EpisodeSetting *episodeSetting = EpisodeSetting::getInstance();
    StageSetting *stageSetting = StageSetting::getInstance();
    StarSetting *starSetting = StarSetting::getInstance();
    
    if (Sqlite3Engine::getInstance()->getIsFirstCreate()) {
        switchSetting->createTable();
        switchSetting->initTable();
        episodeSetting->createTable();
        episodeSetting->initTable();
        stageSetting->createTable();
        stageSetting->initTable();
        starSetting->createTable();
        starSetting->initTable();
    }
    episodeSetting->updateMax(2);
    stageSetting->updateMax(5);
    //stageSetting->updateCurrent(0);
    Director::getInstance()->getEventDispatcher()->setEnabled(true);
    Controller::GameController* controller = Controller::GameController::getInstance();
    controller->runStartScene();
    
    return true;
}

// This function will be called when the app is inactive. When comes a phone call,it's be invoked too
void AppDelegate::applicationDidEnterBackground() {
    Director::getInstance()->stopAnimation();

    // if you use SimpleAudioEngine, it must be pause
    // SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground() {
    Director::getInstance()->startAnimation();

    // if you use SimpleAudioEngine, it must resume here
    // SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
}
