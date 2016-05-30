#ifndef _DB_StarSetting_H_
#define _DB_StarSetting_H_

#include "Sqlite3Engine.h"

namespace DB
{
    class StarSetting
    {
    public:
        static StarSetting* getInstance();
        int createTable();
        int initTable();
        int updateStar(int episodeNumber, int stageNumber, int starValue);
        int missionComplete(int episodeNumber, int stageNumber, int starValue);
        std::vector<std::vector<int>> getAllStarNumber();
        int getStarNumber(int episodeNumber, int stageNumber);
    private:
        static StarSetting* instance;
        StarSetting();
    };
}

#endif /* _DB_StarSetting_H_ */
