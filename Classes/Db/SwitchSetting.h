#ifndef _DB_SwitchSetting_H_
#define _DB_SwitchSetting_H_

#include "Sqlite3Engine.h"

namespace DB
{
    /**
     @brief 資料表SwitchSetting的操作物件
     開關設定資料表，用以存取遊戲裡的開關設定，像是音樂與音效開關。
     */
    class SwitchSetting
    {
    public:
        /**
         取得操作SwitchSetting資料表的實體物件
         */
        static SwitchSetting* getInstance();
        
        /**
         @brief 建立資料表
         建立資料表SwitchSetting，當系統第一次建立資料庫時必須呼叫此方法
         */
        void createTable();
        
        /**
         @brief 資料表初始化
         將預設資料寫入資料表SwitchSetting，第一次建立資料庫時必須呼叫此方法
         */
        void initTable();
        
        /**
         @brief 將開啟音樂的設定寫入資料表
         此方法並不會真的開啟音樂，僅是將設定寫入資料表
         */
        void turnOnMusic();
        
        /**
         @brief 將關閉音樂的設定寫入資料表
         此方法並不會真的關閉音樂，僅是將設定寫入資料表
         */
        void turnOffMusic();
        
        /**
         @brief 將開啟音效的設定寫入資料表
         此方法並不會真的開啟音效，僅是將設定寫入資料表
         */
        void turnOnSounds();
        
        /**
         @brief 將關閉音效的設定寫入資料表
         此方法並不會真的關閉音效，僅是將設定寫入資料表
         */
        void turnOffSounds();
        
        /**
         @brief 取得音樂開關在資料庫裡的設定
         @return 一個代表開關的整數，打開為1，關閉為0
         */
        int getMusicSwitch();
        
        /**
         @brief 取得音效開關在資料庫裡的設定
         @return 一個代表開關的整數，打開為1，關閉為0
         */
        int getSoundsSwitch();
    private:
        /**
         @brief 建構式
         */
        SwitchSetting();
        
        // 靜態實例
        static SwitchSetting *instance;
    };
}


#endif /* _DB_SwitchSetting_H_ */
