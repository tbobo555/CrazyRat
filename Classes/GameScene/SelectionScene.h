#ifndef _GameScene_SelectionScene_H_
#define _GameScene_SelectionScene_H_

#include "cocos2d.h"
#include "BaseScene.h"
#include "BaseScene.h"
#include "GameSprite/Image.h"
#include "GameSprite/Background.h"
#include "GameSprite/EpisodeButton.h"
#include "GameSprite/BackButton.h"
#include "GameSprite/SelectionTitle.h"
#include "GameSprite/UnlockedMask.h"
#include "Db/EpisodeSetting.h"
#include "Manager/SpriteManager.h"
#include "Config/ImageConfig.h"

USING_NS_CC;

namespace GameScene
{
    /**
     @brief 章節選擇場景，可以讓玩家選擇要玩的章節
     */
    class SelectionScene : public BaseScene
    {
    public:
        /**
         @brief 建構式
         */
        SelectionScene();
        
        /**
         @brief 初始化場景，將選擇場景中需要使用到資源載入
         */
        void initScene();
        
        /**
         @brief 釋放選擇場景的所有資源
         */
        void releaseScene();
        
        /**
         @brief 執行常態的動畫，會讓選擇場景的雲進行飄移
         */
        void runConstantAnimation();
        
        /**
         @breief 播放章節解鎖動畫
         */
        void runUnlockedEpisodeAnimation(int unlockedEpisodeNumber);
        
        /**
         @brief 將unlocked chapter的物件從畫面中移除
         */
        void removeUnlockedSprite();
        
        /**
         @brief 關閉unlocked mask的觸控監聽
         */
        void setUnlockedMaskClickable();
        
        // 背景圖檔物件
        GameSprite::Background* selectionBackground;
        
        // 返回按鈕
        GameSprite::BackButton* selectionBackButton;
        
        // 選擇場景的標題
        GameSprite::SelectionTitle* selectionTitle;
        
        // 章節按鈕，讓玩家選擇不同的章節來進行遊戲
        std::vector<GameSprite::EpisodeButton*> episodeButtonVector;
        
        // 章節解鎖的通知圖示
        GameSprite::Image* chapterUnlocked;
        
        // 章節解鎖的背景遮罩
        GameSprite::UnlockedMask* unlockedMask;
        
        // 移動的雲
        GameSprite::Image* moveCloud0;
        GameSprite::Image* moveCloud1;
        GameSprite::Image* moveCloud2;
        GameSprite::Image* moveCloud3;
        GameSprite::Image* moveCloud4;
        
        // 彩虹
        GameSprite::Image* rainbow;
    private:
        
        /**
         @brief 取得背景圖檔的位置
         @return 一個二維向量，代表背景圖檔的座標
         */
        Vec2 getBackgroundPosition();
        
        /**
         @brief 取得標題的位置
         @return 一個二維向量，代表標題的座標
         */
        Vec2 getTitlePosition();
        
        /**
         @brief 取得返回按鈕的位置
         @return 一個二維向量，代表返回按鈕的座標
         */
        Vec2 getBackButtonPosition();
        
        /**
         @brief 取得章節按鈕的位置
         @param episodeNumber 指定的章節編號
         @return 一個二維向量，代表指定的章節編號的座標
         */
        Vec2 getEpisodeButtonPosition(int episodeNumber);
        
        /**
         @brief 取得彩虹的位置
         @return 一個二維向量，代表彩虹的座標
         */
        Vec2 getRainbowPosition();
        
        /**
         @brief 取得指定索引的雲的位置
         @param index 代表雲的索引
         @return 一個二維向量，代表雲的座標
         */
        Vec2 getMoveCloudPosition(int index);
    };
}

#endif /* _GameScene_SelectionScene_H_ */
