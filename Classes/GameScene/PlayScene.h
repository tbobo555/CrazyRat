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
        int episodeNumber;
        int stageNumber;
        GameSprite::Background* playBackground;
        GameSprite::ProgressBarUp* progressBarUp;
        GameSprite::ProgressBarDown* progressBarDown;
        ProgressTimer* timeBar;
        GameSprite::Pig* road0Pig;
        GameSprite::Pig* road1Pig;
        GameSprite::Pig* road2Pig;
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
        bool isVictory;
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
