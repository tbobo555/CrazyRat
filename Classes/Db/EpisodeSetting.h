#ifndef _DB_EpisodeSetting_H_
#define _DB_EpisodeSetting_H_

#include "Sqlite3Engine.h"

namespace DB
{
    /**
     @brief 資料表EpisodeSetting的操作物件
     章節設定資料表，可存取玩家目前已破關或正在進行的章節編號。
     */
    class EpisodeSetting
    {
    public:
        /**
         @brief 取得操作資料表EpisodeSetting的實體物件
         */
        static EpisodeSetting* getInstance();
        
        /**
         @brief 建立EpisodeSetting資料表
         當系統第一次建立資料庫時必須呼叫此方法
         */
        void createTable();
        
        /**
         @brief 資料表初始化
         將預設資料寫入資料表EpisodeSetting，第一次建立資料庫時必須呼叫此方法
         */
        void initTable();
        
        /**
         @brief 更新正在進行的章節編號
         若current為2，代表玩家已破關第三章節(0代表第一章)
         @param current 新的章節編號
         */
        void updateCurrent(int current);
        
        /**
         @brief 更新遊戲章節總數
         若max為5，代表遊戲總共有5個章節可供玩家遊玩
         @param max 新的章節總數
         */
        void updateMax(int max);
        
        /**
         @brief 取得玩家正在進行的章節編號
         @return 目前的章節編號
         */
        int getCurrent();
        
        /**
         @brief 取得遊戲章節總數
         @return 已設定的的章節總數
         */
        int getMax();
    private:
        /**
         @brief 建構式
         */
        EpisodeSetting();
        
        // 靜態實例
        static EpisodeSetting* instance;
    };
}


#endif /* _DB_EpisodeSetting_H_ */
