#ifndef _GameScene_SelectionScene_H_
#define _GameScene_SelectionScene_H_

#include "cocos2d.h"
#include "BaseScene.h"
#include "GameSprite/StartBg.h"
#include "GameSprite/StageButton.h"
#include "GameSprite/MasterSprite.h"
#include "GameSprite/StarSprite.h"
#include "Db/CommonSetting.h"
#include "Config/PositionConfig.h"

USING_NS_CC;

namespace GameScene
{
    class SelectionScene : public BaseScene
    {
    public:
        SelectionScene();
        void initScene();
        GameSprite::StartBg* startBg;
        std::vector<GameSprite::StageButton*> stageButtonVector;
        GameSprite::MasterSprite* masterSprite;
        std::vector<GameSprite::StarSprite*> starSpriteVector;
        void setStageDisplay();
        void setStarDisplay();
        void setMasterPosition();
    };
}

#endif /* _GameScene_SelectionScene_H_ */
