#ifndef _GameScene_MapScene_H_
#define _GameScene_MapScene_H_

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
    class MapScene :  public BaseScene

    {
    public:
        MapScene(int pMapNumber);
        void initScene();
        void releaseScene();
        int mapMumber;
        GameSprite::Background* mapBackground;
        GameSprite::Master* master;
        GameSprite::BackButton* mapBackButton;
        std::vector<GameSprite::StageButton*> stageButtonVector;
        std::vector<GameSprite::Star*> starVector;
    private:
        Vec2 getMasterPosition(int currentStage, int currentMap);
        Vec2 getBackButtonPosition();
        Vec2 getStageButtonPosition(int stageNumber, int mapNumber);
        Vec2 getStarPosition(int stageNumber, int mapNumber, int starNumber);
    };
}

#endif /* _GameScene_MapScene_H_ */
