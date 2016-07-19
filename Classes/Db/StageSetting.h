#ifndef _DB_StageSetting_H_
#define _DB_StageSetting_H_

#include "Sqlite3Engine.h"

namespace DB
{
    /**
     @brief 資料表StageSetting的操作物件
     關卡設定資料表，存取玩家目前章節的破關數。
     */
    class StageSetting
    {
    public:
        /**
         @brief 取得操作StageSetting資料表的實體物件
         */
        static StageSetting* getInstance();
        
        /**
         @brief 建立StageSetting資料表
         當系統第一次建立資料庫時必須呼叫此方法
         */
        void createTable();
        
        /**
         @brief 資料表初始化
         將預設資料寫入資料表StageSetting，第一次建立資料庫時必須呼叫此方法
         */
        void initTable();
        
        /**
         @brief 更新正在進行的關卡編號
         若current為2，代表玩家已破關第三關(0代表第一關)
         @param current 新的關卡編號
         */
        void updateCurrent(int current);
        
        /**
         @brief 更新每個章節的關卡總數
         若max為25，代表每個章節總共有25個關卡可供玩家遊玩
         @param max 新的關卡總數
         */
        void updateMax(int max);
        
        /**
         @brief 取得目前章節正在進行的關卡編號
         @return 正在進行的關卡編號
         */
        int getCurrent();
        
        /**
         @brief 取得每個章節的關卡總數
         @return 已設定的的關卡總數
         */
        int getMax();
    private:
        /**
         brief 建構式
         */
        StageSetting();
        
        // 靜態實例
        static StageSetting* instance;
    };
}

#endif /* _DB_StageSetting_H_ */
