#ifndef _Manager_ScoresManager_H_
#define _Manager_ScoresManager_H_

#include "cocos2d.h"

USING_NS_CC;

namespace Manager
{
    
    /**
     @brief 分數管理者
     用來配置與調整玩家在遊戲場景裡取得的分數
     */
    class ScoresManager
    {
    public:
        /**
         @brief 取得分數管理者的實體物件
         */
        static ScoresManager* getInstance();
        
        /**
         @brief 取得存放分數的Label物件
         @return 一個Label物件，該Label的文字為遊戲分數
         */
        Label* getScoresLabel();
        
        /**
         @brief 將Label初始化
         */
        void initScores();
        
        /**
         @brief 取得目前的遊戲分數
         @return 遊戲分數
         */
        int getScores();
        
        /**
         @brief 設置累積分數
         @param newScores 要設置的數值
         */
        void setScores(int newScores);
        
        /**
         @brief 加分
         @param points 要增加的分數
         */
        void addScores(int points);
        
        /**
         @brief 重新設定分數，設置後分數為0
         */
        void resetScores();
        
        /**
         @brief 將存放分數的Label釋放
         */
        void releaseScores();
    private:
        /**
         @brief 建構式
         */
        ScoresManager();
        
        // 存放與顯示分數的Label
        Label* scores;
        
        // 靜態實例
        static ScoresManager* instance;
    };
}

#endif /* _Manager_ScoresManager_H_ */
