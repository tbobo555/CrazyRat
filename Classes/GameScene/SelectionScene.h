#ifndef _GameScene_SelectionScene_H_
#define _GameScene_SelectionScene_H_

#include "cocos2d.h"
#include "BaseScene.h"
#include "BaseScene.h"
#include "GameSprite/Background.h"
#include "GameSprite/EpisodeButton.h"
#include "GameSprite/BackButton.h"
#include "GameSprite/SelectionTitle.h"
#include "Db/EpisodeSetting.h"
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
        GameSprite::SelectionTitle* selectionTitle;
        std::vector<GameSprite::EpisodeButton*> episodeButtonVector;
    private:
        Vec2 getBackgroundPosition();
        Vec2 getTitlePosition();
        Vec2 getBackButtonPosition();
        Vec2 getEpisodeButtonPosition(int episodeNumber);
    };
}

#endif /* _GameScene_SelectionScene_H_ */
