#ifndef _DB_NewHighScoreSetting_H_
#define _DB_NewHighScoreSetting_H_

#include "Sqlite3Engine.h"


namespace DB
{
    class NewHighScoreSetting
    {
    public:
        /**
         @brief 取得操作StarSetting資料表的實體物件
         */
        static NewHighScoreSetting* getInstance();
        
        /**
         @brief 建立NewHighScoreSetting資料表
         當系統第一次建立資料庫時必須呼叫此方法
         */
        void createTable();
        
        /**
         @brief 資料表初始化
         將預設資料寫入資料表NewHighScoreSetting，第一次建立資料庫時必須呼叫此方法
         */
        void initTable();
        
        /**
         @brief 更新最高分數紀錄
         @param highScore 要更新的分數紀錄
         */
        void updateHighScore(int highScore);
        
        /**
         @brief 取得最高分數紀錄
         @return 最高分數紀錄
         */
        int getHighScore();
    private:
        // 靜態實例
        static NewHighScoreSetting* instance;
        
        /**
         @brief 建構式
         */
        NewHighScoreSetting();
    };
}

#endif /* _DB_NewHighScoreSetting_H_ */
