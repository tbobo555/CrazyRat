#ifndef _GameScene_EpisodeScene_H_
#define _GameScene_EpisodeScene_H_

#include "cocos2d.h"
#include "BaseScene.h"
#include "GameSprite/Image.h"
#include "GameSprite/Background.h"
#include "GameSprite/StageButton.h"
#include "GameSprite/BackButton.h"
#include "GameSprite/Star.h"
#include "Db/EpisodeSetting.h"
#include "Db/StageSetting.h"
#include "Db/StarSetting.h"
#include "Manager/SpriteManager.h"
#include "Manager/SoundsManager.h"
#include "Config/ImageConfig.h"

namespace GameScene
{
    /**
     @brief 指定章節的場景，可選擇該章節的關卡
     */
    class EpisodeScene :  public BaseScene
    {
    public:
        /**
         @brief 建構式
         @param pEpisodeNumber 要載入的章節編號
         */
        EpisodeScene(int pEpisodeNumber);

        /**
         @brief Episode場景初始化
         */
        void initScene();

        /**
         @brief 釋放Episode場景
         */
        void releaseScene();

        /**
         @brief 播放星星動畫
         當關卡取得較高星星數時，由PlayScene切換回EpidsodeScene時會將新獲得的星星
         從畫面中央飛入場景
         */
        void runStarAnimation();

        /**
         @brief 星星動畫播放結束，需要執行的方法
         */
        void animationCallback();

        // 章節編號
        int episodeNumber;

        // 是否為最新高分(這裡的分數代表星星數)，
        // EX: 原本玩家獲得的星星為1顆，再次闖關後為2顆
        // 此狀況 isNewHighScore 為 true
        bool isNewHighScore;

        // 最新分數與原本分數的差
        // EX: 原本玩家獲得的星星為1顆，再次闖關後為2顆
        // 此狀況 newHighScoreDiff 為 1
        int newHighScoreDiff;

        // 取得最新高分的關卡編號
        int newHighScoreStage;

        // 章節場景中的背景
        GameSprite::Background* episodeBackground;

        // 章節場景中的返回按鈕
        GameSprite::BackButton* episodeBackButton;

        // 章節場景中的關卡按鈕
        std::vector<GameSprite::StageButton*> stageButtonVector;
    private:
        /**
         @brief 取得背景的放置座標
         @return 一個二維向量，代表背景放置的座標
         */
        Vec2 getBackgroundPosition();

        /**
         @brief 取得返回鍵的放置座標
         @return 一個二維向量，代表返回鍵放置的座標
         */
        Vec2 getBackButtonPosition();

        /**
         @brief 取得指定關卡按鈕的放置座標
         @param stageNumber 關卡編號
         @return 一個二維向量，代表指定關卡按鈕放置的座標
         */
        Vec2 getStageButtonPosition(int stageNumber);

        /**
         @brief 取得指定星星的放置座標
         @param stageNumber 關卡編號
         @param starNumber 星星編號
         @return 一個二維向量，代表指定星星放置的座標
         */
        Vec2 getStarPosition(int stageNumber, int starNumber);
    };
}

#endif /* _GameScene_EpisodeScene_H_ */
