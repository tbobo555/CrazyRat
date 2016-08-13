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
    std::vector<float> loadLevelSetting(int episodeNumber, int stageNumber, int roadNumber);
    
    /**
     @brief 取得甜點降落的速度
     @param episodeNumber 章節編號
     @param stageNumber 關卡編號
     @return 該關卡甜點降落的速度
     */
    float loadRunningTimeByEpisodeAndStage(int episodeNumber, int stageNumber);
    
    /**
     @brief 依據關卡來取得各星星數所需的得分數
     @param episodeNumber 章節編號
     @param stageNumber 關卡編號
     @return 取得該關卡每個星星數所需要的分數
     */
    std::vector<int> loadStarScoresByEpisodeAndStage(int episodeNumber, int stageNumber);

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
    
    
    std::vector<std::vector<float>>  setLevelByRandom(int episodeNumber, int stageNumber);
    
    /**
     @brief 取得章節0指定關卡的甜點掉落時間列表
     @param stageNumber 關卡編號
     @param roadNumber 路線編號
     @return 指定關卡的甜點掉落時間列表
     */
    std::vector<float> loadEpisode0LevelSetting(int stageNumber, int roadNumber);
    //std::vector<float> loadEpisode1LevelSetting(int stageNumber, int roadNumber);
    
    
    void initLevelSetting(int episodeNumber, int stageNumber);
    
    
};


#endif /* _Lib_LevelDesigner_H_ */
