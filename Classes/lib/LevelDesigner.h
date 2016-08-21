#ifndef _Lib_LevelDesigner_H_
#define _Lib_LevelDesigner_H_

#include "cocos2d.h"

USING_NS_CC;

/**
 @brief 關卡設計師，設計每一關卡的困難度與變化
 */
class LevelDeisgner
{
public:
    /**
     @brief 取得物件實體物件
     */
    static LevelDeisgner* getInstance();
    
    /**
     @brief 載入指定關卡的甜點掉落時間列表
     @param episodeNumber 章節編號
     @param stageNumber 關卡編號
     @param roadNumber 路線編號
     @return 指定關卡的甜點掉落時間列表
     */
    std::vector<float> loadSweetTimingSetting(int episodeNumber, int stageNumber, int roadNumber);
    
    /**
     @brief 取得甜點降落的速度
     @param episodeNumber 章節編號
     @param stageNumber 關卡編號
     @return 該關卡甜點降落的速度
     */
    float loadSweetSpeedSetting(int episodeNumber, int stageNumber);
    
    /**
     @brief 取得各星星數所需的得分數
     @param episodeNumber 章節編號
     @param stageNumber 關卡編號
     @return 取得該關卡每個星星數所需要的分數
     */
    std::vector<int> loadStarAndScoresSetting(int episodeNumber, int stageNumber);
    
    /**
     @brief 取得指定關卡的遊戲時間
     @param episodeNumber 章節編號
     @param stageNumber 關卡編號
     */
    float loadGameOverTimeSetting(int episodeNumber, int stageNumber);
    
    /**
     @brief 取得指定關卡的總甜點數量
     @param episodeNumber 章節編號
     @param stageNumber 關卡編號
     */
    int loadQuantitySetting(int episodeNumber, int stageNumber);
    
    /**
     @brief 取得指定關卡的甜點降落間隔
     @param episodeNumber 章節編號
     @param stageNumber 關卡編號
     */
    std::vector<float> loadIntervalSetting(int episodeNumber, int stageNumber);

private:
    /**
     @brief 建構式
     */
    LevelDeisgner();
    
    // 靜態實體物件
    static LevelDeisgner* instance;
    
    // 第一章所有關卡設定
    std::vector<std::vector<std::vector<float>>> episode0LevelSetting;
    
    // 第二章所有關卡設定
    std::vector<std::vector<std::vector<float>>> episode1LevelSetting;
    
    // 上一個甜點的路徑編號
    int lastRoadIndex;
    
    // 上一個甜點的出現時間
    float lastSweetTime;
    
    // 甜點在同一路徑出現的次數，從0開始計算
    int sameRoadTimes;
    
    /**
     @brief 取得章節0指定關卡的甜點掉落時間列表
     @param stageNumber 關卡編號
     @param roadNumber 路線編號
     @return 指定關卡的甜點掉落時間列表
     */
    std::vector<float> loadEpisode0SweetTimingSetting(int stageNumber, int roadNumber);
    
    /**
     @brief 取得章節1指定關卡的甜點掉落時間列表
     @param stageNumber 關卡編號
     @param roadNumber 路線編號
     @return 指定關卡的甜點掉落時間列表
     */
    std::vector<float> loadEpisode1SweetTimingSetting(int stageNumber, int roadNumber);

    
    /**
     @brief 亂數產生甜點掉落時間列表
     @param episodeNumber 章節編號
     @param stageNumber 關卡編號
     */
    std::vector<std::vector<float>> setSweetTimingByRandom(int episodeNumber, int stageNumber);
    
    /**
     @brief 初始化章節0的關卡甜點掉落時間設定
     @param stageNumber 關卡編號
     */
    void initEpisode0SweetTimingSetting();
    
    /**
     @brief 初始化章節1的關卡甜點掉落時間設定
     @param stageNumber 關卡編號
     */
    void initEpisode1SweetTimingSetting();

};


#endif /* _Lib_LevelDesigner_H_ */
