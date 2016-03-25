#ifndef _GameScene_SelectionScene_H_
#define _GameScene_SelectionScene_H_

#include "cocos2d.h"
#include "BaseScene.h"
#include "BaseScene.h"
#include "GameSprite/Background.h"
#include "GameSprite/MapButton.h"
#include "GameSprite/BackButton.h"
#include "Db/CommonSetting.h"
#include "Manager/SpriteManager.h"
#include "Config/ImageConfig.h"

USING_NS_CC;

namespace GameScene
{
    class SelectionScene : public BaseScene
    {
    public:
        SelectionScene();
        void initScene();
        void releaseScene();
        GameSprite::Background* selectionBackground;
        GameSprite::BackButton* selectionBackButton;
        std::vector<GameSprite::MapButton*> mapButtonVector;
    private:
        Vec2 getBackButtonPosition();
        Vec2 getMapButtonPosition(int mapNumber);
    };
}

#endif /* _GameScene_SelectionScene_H_ */
