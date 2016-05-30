#ifndef _DB_StageSetting_H_
#define _DB_StageSetting_H_

#include "Sqlite3Engine.h"

namespace DB
{
    class StageSetting
    {
    public:
        static StageSetting* getInstance();
        int createTable();
        int initTable();
        int updateCurrent(int current);
        int updateMax(int max);
        int getCurrent();
        int getMax();
    private:
        StageSetting();
        static StageSetting* instance;
    };
}

#endif /* _DB_StageSetting_H_ */
