#ifndef _GameScene_PlayScene_H_
#define _GameScene_PlayScene_H_

#include "cocos2d.h"
#include "BaseScene.h"
#include "Manager/SpriteManager.h"
#include "Config/ImageConfig.h"
#include "GameSprite/Background.h"
#include "GameSprite/TimeBarUp.h"
#include "GameSprite/TimeBarDown.h"
#include "GameSprite/PauseButton.h"
#include "GameSprite/MusicButton.h"
#include "GameSprite/SoundsButton.h"
#include "GameSprite/PauseBackButton.h"
#include "GameSprite/BackHomeButton.h"
#include "GameSprite/RetryButton.h"
#include "GameSprite/Rat.h"

USING_NS_CC;

namespace GameScene
{
    class PlayScene : public BaseScene
    {
    public:
        PlayScene(int pMapNumber, int pStageNumber);
        void initScene();
        void releaseScene();
        void play();
        void pauseScene();
        void resumeScene();
        bool getIsPaused();
        int mapNumber;
        int stageNumber;
        GameSprite::Background* playBackground;
        GameSprite::TimeBarUp* timeBarUp;
        GameSprite::TimeBarDown* timeBarDown;
        ProgressTimer* timeBar;
        GameSprite::PauseButton* pauseButton;
        GameSprite::Background* pauseBackground;
        GameSprite::MusicButton* musicButton;
        GameSprite::SoundsButton* soundsButton;
        GameSprite::PauseBackButton* pauseBackButton;
        GameSprite::BackHomeButton* backHomeButton;
        GameSprite::RetryButton* retryButton;
        
        std::vector<GameSprite::Rat*> road0RatVector;
        std::vector<GameSprite::Rat*> road1RatVector;
        std::vector<GameSprite::Rat*> road2RatVector;
        std::vector<int> road0AvailableIndex;
        std::vector<int> road1AvailableIndex;
        std::vector<int> road2AvailableIndex;
    private:
        bool isPaused;
        int prepareTime;
        Label* prepareLabel;
        void prepareUpdate(float delta);
        void prepareDone();
        void initConfig();
        float playTime;
        void gameUpdate(float delta);
        int road0MaxSpriteNumber;
        int road1MaxSpriteNumber;
        int road2MaxSpriteNumber;
        int road0CurrentIndex;
        int road1CurrentIndex;
        int road2CurrentIndex;
        std::vector<float> road0TimeConfig;
        std::vector<float> road1TimeConfig;
        std::vector<float> road2TimeConfig;
        std::vector<int> road0TypeConfig;
        std::vector<int> road1TypeConfig;
        std::vector<int> road2TypeConfig;
        void road0Update(float delta);
        void road1Update(float delta);
        void road2Update(float delta);
    };
}


#endif /* _GameScene_PlayScene_H_ */
