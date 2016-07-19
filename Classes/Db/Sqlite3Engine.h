#ifndef _DB_Sqlite3Engine_H_
#define _DB_Sqlite3Engine_H_

#include "cocos2d.h"
#include <sqlite3.h>
#include <fstream>

USING_NS_CC;

namespace DB
{
    /**
     @brief Sqlite3的操作物件
     用來取得DB連線，DB初始化等操作，使用前需先呼叫initEngine()來進行初始化
     */
    class Sqlite3Engine
    {
    public:
        /**
         @brief 取得Sqlite3 Engine的實體物件
         */
        static Sqlite3Engine* getInstance();
        
        /**
         @brief 初始化Engine，此方法必須被執行一次，且不能重複執行
         */
        void initEngine();
        
        /**
         @brief 檢查是否第一次建立資料庫
         檢查的方式為查看檔案GreedyPig.sqlite是否已被建立，並將檢查結果存到變數isFirstCreate
         */
        void checkIsFirstCreate();
        
        /**
         @brief 打開Sqlite3的連線
         */
        void connect();
        
        /**
         @brief 關閉Sqlite3的連線
         */
        void close();
        
        /**
         @brief 取得資料庫操作物件，該物件可對操作sql命令
         */
        sqlite3* getDb();
        
        /**
         @brief 取得變數isFirstCreate，該變數代表著系統是否第一次建立資料庫
         @return 第一次建立DB則回傳true，否則回傳false
         */
        bool getIsFirstCreate();
        
        /**
         @brief 資料庫是否已建立連線，如果是回傳true，否則回傳false
         @return 已建立連線則回傳true，否則回傳false
         */
        bool getIsConnect();
    protected:
        /**
         @brief 建構式
         */
        Sqlite3Engine();
        
        // 靜態實例
        static Sqlite3Engine* instance;
        
        // 操作資料庫的實體物件
        sqlite3 *db;
        
        // 資料庫檔案存放路徑
        std::string dbPath;
        
        // 系統是否第一次建立資料庫
        bool isFirstCreate;
        
        // 資料庫是否已建立連線
        bool isConnect;
        
        // Sqlite3 Engine 是否已初始化
        bool isInit;
    };
}


#endif /* _DB_Sqlite3Engine_H_ */
