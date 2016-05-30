#ifndef _DB_Sqlite3Engine_H_
#define _DB_Sqlite3Engine_H_

#include "cocos2d.h"
#include <sqlite3.h>
#include <fstream>

USING_NS_CC;

namespace DB
{
    class Sqlite3Engine
    {
    public:
        static Sqlite3Engine* getInstance();
        void checkIsFirstCreate();
        void connect();
        void close();
        sqlite3* getDb();
        bool getIsFirstCreate();
        bool getIsConnect();
    protected:
        Sqlite3Engine();
        static Sqlite3Engine* instance;
        sqlite3 *db;
        std::string dbPath;
        bool isFirstCreate;
        bool isInit;
        bool isConnect;
    };
}


#endif /* _DB_Sqlite3Engine_H_ */
