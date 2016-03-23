#ifndef _GameScene_SelectionScene_H_
#define _GameScene_SelectionScene_H_

#include "cocos2d.h"
#include "BaseScene.h"
#include "GameSprite/SelectionBackground.h"
#include "GameSprite/StageButton.h"
#include "GameSprite/Master.h"
#include "GameSprite/Star.h"
#include "Db/CommonSetting.h"
#include "Config/PositionConfig.h"
#include "Lib/TextureCreator.h"
#include "Config/ImageConfig.h" 

USING_NS_CC;

namespace GameScene
{
    class SelectionScene : public BaseScene
    {
    public:
        SelectionScene();
        void initScene();
        GameSprite::SelectionBackground* selectionBackground;
        std::vector<GameSprite::StageButton*> stageButtonVector;
        GameSprite::Master* master;
        std::vector<GameSprite::Star*> starVector;
        void setStageDisplay();
        void setStarDisplay();
        void setMasterPosition();
    };
}

#endif /* _GameScene_SelectionScene_H_ */
