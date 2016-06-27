#ifndef _GameScene_PlayScene_H_
#define _GameScene_PlayScene_H_

#include <queue>
#include "cocos2d.h"
#include "BaseScene.h"
#include "Manager/SpriteManager.h"
#include "GameSprite/Background.h"
#include "GameSprite/ProgressBarUp.h"
#include "GameSprite/ProgressBarDown.h"
#include "GameSprite/Sweet.h"
#include "GameSprite/Pig.h"
#include "GameSprite/Cloud.h"
#include "Db/EpisodeSetting.h"
#include "Db/StageSetting.h"
#include "Db/StarSetting.h"


USING_NS_CC;

namespace GameScene
{
    class PlayScene : public BaseScene
    {
    public:
        PlayScene(int pEpisodeNumber, int pStageNumber);
        void initScene();
        void releaseScene();
        void play();
        void pauseScene();
        void resumeScene();
        bool getIsPaused();
        bool getIsVictory();
        bool getVictoryStar();
        bool getIsNewHighScore();
        bool getAlreadyComplete();
        int getNewHighScoreDiff();
        int episodeNumber;
        int stageNumber;
        GameSprite::Background* playBackground;
        GameSprite::ProgressBarUp* progressBarUp;
        GameSprite::ProgressBarDown* progressBarDown;
        ProgressTimer* timeBar;
        GameSprite::Pig* road0Pig;
        GameSprite::Pig* road1Pig;
        GameSprite::Pig* road2Pig;
        GameSprite::Cloud* road0Cloud;
        GameSprite::Cloud* road1Cloud;
        GameSprite::Cloud* road2Cloud;
        std::vector<GameSprite::Sweet*> road0SweetVector;
        std::vector<GameSprite::Sweet*> road1SweetVector;
        std::vector<GameSprite::Sweet*> road2SweetVector;
        std::vector<int> road0AvailableIndex;
        std::vector<int> road1AvailableIndex;
        std::vector<int> road2AvailableIndex;
        std::queue<int> road0RunningIndex;
        std::queue<int> road1RunningIndex;
        std::queue<int> road2RunningIndex;
        int getNearestSweetIndex(int road);
        GameSprite::Sweet* getNearestSweet(int road);
    private:
        float overGameTime;
        bool isVictory;
        bool isPaused;
        bool alreadyComplete;
        int alreadycompleteStar;
        bool isNewHighScore;
        int newHighScoreDiff;
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
        Vec2 getBackgroundPosition();
        Vec2 getPigPosition(int roadNumber);
        Vec2 getCloudPosition(int roadNumber);
        Vec2 getProgressPosition();
        Vec2 getSweetPosition(int roadNumber);
    };
}


#endif /* _GameScene_PlayScene_H_ */
