#ifndef _GameScene_EpisodeScene_H_
#define _GameScene_EpisodeScene_H_

#include "cocos2d.h"
#include "BaseScene.h"
#include "GameSprite/Background.h"
#include "GameSprite/StageButton.h"
#include "GameSprite/BackButton.h"
#include "GameSprite/Star.h"
#include "GameSprite/Master.h"
#include "Db/CommonSetting.h"
#include "Manager/SpriteManager.h"
#include "Config/ImageConfig.h"

namespace GameScene
{
    class EpisodeScene :  public BaseScene
    {
    public:
        EpisodeScene(int pEpisodeNumber);
        void initScene();
        void releaseScene();
        int episodeNumber;
        GameSprite::Background* episodeBackground;
        GameSprite::Master* master;
        GameSprite::BackButton* episodeBackButton;
        std::vector<GameSprite::StageButton*> stageButtonVector;
    private:
        Vec2 getMasterPosition(int currentStage, int currentEpisode);
        Vec2 getBackButtonPosition();
        Vec2 getStageButtonPosition(int stageNumber, int episodeNumber);
        Vec2 getStarPosition(int stageNumber, int episodeNumber, int starNumber);
    };
}

#endif /* _GameScene_EpisodeScene_H_ */