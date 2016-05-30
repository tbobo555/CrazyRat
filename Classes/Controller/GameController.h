#ifndef _Controller_GameController_H_
#define _Controller_GameController_H_

#include "cocos2d.h"
#include "GameSprite/SettingButton.h"
#include "GameSprite/SettingBackButton.h"
#include "GameSprite/Background.h"
#include "GameSprite/MusicButton.h"
#include "GameSprite/SoundsButton.h"
#include "GameScene/StartScene.h"
#include "GameScene/SelectionScene.h"
#include "GameScene/EpisodeScene.h"
#include "GameScene/MenuScene.h"
#include "GameScene/PlayScene.h"
#include "GameScene/PauseScene.h"
#include "GameScene/VictoryScene.h"
#include "GameScene/LoseScene.h"
#include "Manager/SceneManager.h"
#include "Manager/SpriteManager.h"

using namespace GameSprite;
using namespace Manager;
using namespace DB;
USING_NS_CC;

namespace Controller
{
    class GameController
    {
    public:
        static GameController* getInstance();
        void loadMenuSceneResource();
        void releaseMenuSceneResource();
        void loadStartSceneResource();
        void releaseStartSceneResource();
        void loadSelectionSceneResource();
        void releaseSelectionSceneResource();
        void loadEpisodeSceneResource(int episodeNumber);
        void releaseEpisodeSceneResource(int episodeNumber);
        void loadPlaySceneResource(int episodeNumber, int stageNumber);
        void releasePlaySceneResource(int episodeNumber, int stageNumber);
        void loadPauseSceneResource();
        void releasePauseSceneResource();
        void loadVictorySceneResource();
        void releaseVictorySceneResource();
        void loadLoseSceneResource();
        void releaseLoseSceneResource();
        void addMenuSceneToCurrentScene();
        void removeMenuSceneFromCurrentScene();
        void addPauseSceneToCurrentScene();
        void removePauseSceneFromCurrentScene();
        void addVictorySceneToCurrentScene();
        void removeVictorySceneFromCurrentScene();
        void addLoseSceneToCurrentScene();
        void removeLoseSceneFromCurrentScene();
        void runStartScene();
        void startSceneToSelectionScene();
        void selectionSceneToStartScene();
        void selectionSceneToEpisodeScene(int episodeNumber);
        void EpisodeSceneToSelectionScene(int episodeNumber);
        void EpisodeSceneToPlayScene(int episodeNumber, int stageNumber);
        void RetryPlayScene(int episodeNumber, int stageNumber);
        void PlaySceneToEpisodeScene(int episodeNumber, int stageNumber);
    private:
        GameController();
        static GameController* instance;
    };
}


#endif /* _Controller_GameController_H_ */
