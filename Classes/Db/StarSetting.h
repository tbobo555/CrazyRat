#ifndef _DB_StarSetting_H_
#define _DB_StarSetting_H_

#include "Sqlite3Engine.h"

namespace DB
{
    /**
     @brief 資料表StarSetting的操作物件
     星星分數資料表，存取玩家每個關卡的星星數。
     */
    class StarSetting
    {
    public:
        /**
         @brief 取得操作StarSetting資料表的實體物件
         */
        static StarSetting* getInstance();
        
        /**
         @brief 建立StarSetting資料表
         當系統第一次建立資料庫時必須呼叫此方法
         */
        void createTable();
        
        /**
         @brief 資料表初始化
         將預設資料寫入資料表StarSetting，第一次建立資料庫時必須呼叫此方法
         */
        void initTable();
        
        /**
         @brief 更新關卡的星星數
         @param episodeNumber 要更新星星數的章節編號
         @param stageNumber 要更新星星數的關卡編號
         @param starValue 要更新的星星數量
         */
        void updateStar(int episodeNumber, int stageNumber, int starValue);
        
        /**
         @brief 新增一筆關卡的星星資訊，若該關卡已有星星資訊，則不新增
         @param episodeNumber 要新增星星數的章節編號
         @param stageNumber 要新增星星數的關卡編號
         @param starValue 要新增的星星數量
         */
        void insertStar(int episodeNumber, int stageNumber, int starValue);
        
        /**
         @brief 取得所有關卡的星星數
         回傳資料格式為: vector(vector(int))，第一層vector為章節，第二層vector為關卡，第三層int為星星數
         @return 各關卡的星星數的集合
         */
        std::vector<std::vector<int>> getAllStarNumber();
        
        /**
         @brief 取得指定關卡的星星數
         @param episodeNumber 指定的章節編號
         @param stageNumber 指定的關卡編號
         @return 星星數
         */
        int getStarNumber(int episodeNumber, int stageNumber);
    private:
        // 靜態實例
        static StarSetting* instance;
        
        /**
         @brief 建構式
         */
        StarSetting();
    };
}

#endif /* _DB_StarSetting_H_ */
