#ifndef _DB_EpisodeSetting_H_
#define _DB_EpisodeSetting_H_

#include "Sqlite3Engine.h"

namespace DB
{
    class EpisodeSetting
    {
    public:
        static EpisodeSetting* getInstance();
        int createTable();
        int initTable();
        int updateCurrent(int current);
        int updateMax(int max);
        int getCurrent();
        int getMax();
    private:
        EpisodeSetting();
        static EpisodeSetting* instance;
    };
}


#endif /* _DB_EpisodeSetting_H_ */
