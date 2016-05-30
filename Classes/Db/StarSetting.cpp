#include "StarSetting.h"

namespace DB
{
    StarSetting* StarSetting::instance = new StarSetting();
    
    StarSetting::StarSetting(){}
    
    StarSetting* StarSetting::getInstance()
    {
        return instance;
    }
    
    int StarSetting::createTable()
    {
        if (Sqlite3Engine::getInstance()->getIsConnect() == false) {
            return -1;
        }
        if (Sqlite3Engine::getInstance()->getIsFirstCreate() == false) {
            return -1;
        }
        char* errMsg = NULL;
        int result;
        result = sqlite3_exec(Sqlite3Engine::getInstance()->getDb(),
                              "CREATE TABLE StarSetting (Episode INTEGER DEFAULT 0, Stage INTEGER DEFAULT 0, Value INTEGER DEFAULT 0)",
                              NULL, NULL, &errMsg);
        if(result != SQLITE_OK) {
            CCLOG("CREATE TABLE FAIL %d, Msg: %s",result,errMsg);
        }
        CCLOG("result %d", result);
        return result;
    }
    
    int StarSetting::initTable()
    {
        if (Sqlite3Engine::getInstance()->getIsConnect() == false) {
            return -1;
        }
        if (Sqlite3Engine::getInstance()->getIsFirstCreate() == false) {
            return -1;
        }
        int result;
        sqlite3_stmt *stmt;
        result = sqlite3_prepare_v2(
                                    Sqlite3Engine::getInstance()->getDb(),
                                    "INSERT INTO StarSetting (Episode, Stage, Value) VALUES (?,?,?)", -1, &stmt, NULL);
        if(result != SQLITE_OK) {
            return -1;
        }
        sqlite3_bind_int(stmt, 1, 0);
        sqlite3_bind_int(stmt, 2, 0);
        sqlite3_bind_int(stmt, 3, 0);
        result = sqlite3_step(stmt);
        if(result != SQLITE_DONE) {
            return -1;
        }
        sqlite3_finalize(stmt);
        CCLOG("init StarSetting Table result %d", result);
        return result;

    }
    
    int StarSetting::updateStar(int episodeNumber, int stageNumber, int starValue)
    {
        if (Sqlite3Engine::getInstance()->getIsConnect() == false) {
            return -1;
        }
        int result;
        sqlite3_stmt *stmt;
        result = sqlite3_prepare_v2(
                                    Sqlite3Engine::getInstance()->getDb(),
                                    "UPDATE StarSetting SET Value = ? WHERE Episode = ? AND Stage = ?", -1, &stmt, NULL);
        if(result != SQLITE_OK) {
            return -1;
        }
        sqlite3_bind_int(stmt, 1, starValue);
        sqlite3_bind_int(stmt, 2, episodeNumber);
        sqlite3_bind_int(stmt, 3, stageNumber);
        result = sqlite3_step(stmt);
        if(result != SQLITE_DONE) {
            return -1;
        }
        sqlite3_finalize(stmt);
        CCLOG("UPDATE StarSetting starValue result %d", result);
        return result;
    }
    
    int StarSetting::missionComplete(int episodeNumber, int stageNumber, int starValue)
    {
        if (Sqlite3Engine::getInstance()->getIsConnect() == false) {
            return -1;
        }
        std::vector<std::vector<int>> starOfStage = this->getAllStarNumber();
        try {
            std::vector<int> child = starOfStage.at(episodeNumber);
            child.at(stageNumber);
            CCLOG("Already complete with episodeNumber %d  stageNumber %d", episodeNumber, stageNumber);
            return -1;
        } catch (std::out_of_range ex) {
            CCLOG("Complete episodeNumber %d  stageNumber %d", episodeNumber, stageNumber);
        }
        int result;
        sqlite3_stmt *stmt;
        result = sqlite3_prepare_v2(
                                    Sqlite3Engine::getInstance()->getDb(),
                                    "INSERT INTO StarSetting (Episode, Stage, Value) VALUES (?,?,?)", -1, &stmt, NULL);
        if(result != SQLITE_OK) {
            return -1;
        }
        sqlite3_bind_int(stmt, 1, episodeNumber);
        sqlite3_bind_int(stmt, 2, stageNumber);
        sqlite3_bind_int(stmt, 3, starValue);
        result = sqlite3_step(stmt);
        if(result != SQLITE_DONE) {
            return -1;
        }
        sqlite3_finalize(stmt);
        CCLOG("missionComplete result %d", result);
        return result;
    }
    
    std::vector<std::vector<int>> StarSetting::getAllStarNumber()
    {
        std::vector<std::vector<int>> starOfStage;
        std::vector<int> child;
        int lastEpisode = 0;
        
        if (Sqlite3Engine::getInstance()->getIsConnect() == false) {
            return starOfStage;
        }
        int result;
        sqlite3_stmt *stmt;
        result = sqlite3_prepare_v2(Sqlite3Engine::getInstance()->getDb(), "SELECT * FROM StarSetting", -1, &stmt, NULL);
        if(result != SQLITE_OK) {
            return starOfStage;
        }
        for (;;) {
            result = sqlite3_step(stmt);
            if (result == SQLITE_DONE)
                break;
            if (result != SQLITE_ROW) {
                printf("error: %s!\n", sqlite3_errmsg(Sqlite3Engine::getInstance()->getDb()));
                break;
            }
            int episode = sqlite3_column_int(stmt, 0);
            int stage = sqlite3_column_int(stmt, 1);
            int star = sqlite3_column_int(stmt, 2);
            if (lastEpisode < episode) {
                lastEpisode = episode;
                starOfStage.push_back(child);
                child.clear();
            }
            child.push_back(star);
        }
        starOfStage.push_back(child);
        child.clear();
        return starOfStage;
    }
    
    int StarSetting::getStarNumber(int episodeNumber, int stageNumber)
    {
        if (Sqlite3Engine::getInstance()->getIsConnect() == false) {
            return -1;
        }
        int result;
        sqlite3_stmt *stmt;
        result = sqlite3_prepare_v2(
                                    Sqlite3Engine::getInstance()->getDb(),
                                    "SELECT * FROM StarSetting WHERE Episode = ? AND Stage = ?", -1, &stmt, NULL);
        if(result != SQLITE_OK) {
            CCLOG("Fail1");
            return -1;
        }
        sqlite3_bind_int(stmt, 1, episodeNumber);
        sqlite3_bind_int(stmt, 2, stageNumber);
        result = sqlite3_step(stmt);
        if (result != SQLITE_ROW) {
            printf("error: %s!\n", sqlite3_errmsg(Sqlite3Engine::getInstance()->getDb()));
        }
        int star = sqlite3_column_int(stmt, 2);
        sqlite3_finalize(stmt);
        CCLOG("Get StarSetting starValue result %d", star);
        return star;

    }
}
