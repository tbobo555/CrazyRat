#include "StarSetting.h"

namespace DB
{
    StarSetting* StarSetting::instance = new StarSetting();
    
    StarSetting::StarSetting(){}
    
    StarSetting* StarSetting::getInstance()
    {
        return instance;
    }
    
    void StarSetting::createTable()
    {
        if (Sqlite3Engine::getInstance()->getIsConnect() == false) {
            CCAssert(false, "Error : Can't create StarSetting table , you need connect to DB first.");
        }
        if (Sqlite3Engine::getInstance()->getIsFirstCreate() == false) {
            CCAssert(false, "Error : StarSetting table already exists, you can't create it again.");
        }
        char* errMsg = NULL;
        int result;
        result = sqlite3_exec(Sqlite3Engine::getInstance()->getDb(),
                              "CREATE TABLE StarSetting (Episode INTEGER DEFAULT 0, Stage INTEGER DEFAULT 0, Value INTEGER DEFAULT 0)",
                              NULL, NULL, &errMsg);
        if(result != SQLITE_OK) {
            CCLOG("CREATE TABLE FAIL %d, Msg: %s",result,errMsg);
            CCAssert(false, "CREATE TABLE StarSetting failed.");
        }
        CCLOG("result %d", result);
    }
    
    void StarSetting::initTable()
    {
        if (Sqlite3Engine::getInstance()->getIsConnect() == false) {
            CCAssert(false, "Error : Can't init StarSetting table , you need connect to DB first.");
        }
        if (Sqlite3Engine::getInstance()->getIsFirstCreate() == false) {
            CCAssert(false, "Error : StarSetting table already exists, you can't init it again.");
        }
        int result;
        sqlite3_stmt *stmt;
        result = sqlite3_prepare_v2(
                                    Sqlite3Engine::getInstance()->getDb(),
                                    "INSERT INTO StarSetting (Episode, Stage, Value) VALUES (?,?,?)", -1, &stmt, NULL);
        if(result != SQLITE_OK) {
            CCAssert(false, "sqlite3_prepare_v2 Error : INSERT TABLE StarSetting failed.");
        }
        sqlite3_bind_int(stmt, 1, 0);
        sqlite3_bind_int(stmt, 2, 0);
        sqlite3_bind_int(stmt, 3, 0);
        result = sqlite3_step(stmt);
        if(result != SQLITE_DONE) {
            CCAssert(false, "sqlite3_step Error : INSERT TABLE StarSetting failed.");
        }
        sqlite3_finalize(stmt);
        CCLOG("init StarSetting Table result %d", result);

    }
    
    void StarSetting::updateStar(int episodeNumber, int stageNumber, int starValue)
    {
        if (Sqlite3Engine::getInstance()->getIsConnect() == false) {
            CCAssert(false, "Error : Can't update StarSetting table, you need connect to DB first.");
        }
        int result;
        sqlite3_stmt *stmt;
        result = sqlite3_prepare_v2(
                                    Sqlite3Engine::getInstance()->getDb(),
                                    "UPDATE StarSetting SET Value = ? WHERE Episode = ? AND Stage = ?", -1, &stmt, NULL);
        if(result != SQLITE_OK) {
            CCAssert(false, "sqlite3_prepare_v2 Error : UPDATE TABLE StarSetting failed.");
        }
        sqlite3_bind_int(stmt, 1, starValue);
        sqlite3_bind_int(stmt, 2, episodeNumber);
        sqlite3_bind_int(stmt, 3, stageNumber);
        result = sqlite3_step(stmt);
        if(result != SQLITE_DONE) {
            CCAssert(false, "sqlite3_step Error : UPDATE TABLE StarSetting failed.");
        }
        sqlite3_finalize(stmt);
        CCLOG("UPDATE StarSetting starValue result %d", result);
    }
    
    void StarSetting::insertStar(int episodeNumber, int stageNumber, int starValue)
    {
        if (Sqlite3Engine::getInstance()->getIsConnect() == false) {
            CCAssert(false, "Error : Can't insert StarSetting table, you need connect to DB first.");
        }
        std::vector<std::vector<int>> starOfStage = this->getAllStarNumber();
        
        // 如果指定的章節與關卡已經有星星資料了，則不再做新增。
        try {
            std::vector<int> child = starOfStage.at(episodeNumber);
            child.at(stageNumber);
            CCLOG("Star data already exists in episodeNumber %d  stageNumber %d", episodeNumber, stageNumber);
            return;
        } catch (std::out_of_range ex) {
            CCLOG("Star data will insert into episodeNumber %d  stageNumber %d", episodeNumber, stageNumber);
        }
        int result;
        sqlite3_stmt *stmt;
        result = sqlite3_prepare_v2(
                                    Sqlite3Engine::getInstance()->getDb(),
                                    "INSERT INTO StarSetting (Episode, Stage, Value) VALUES (?,?,?)", -1, &stmt, NULL);
        if(result != SQLITE_OK) {
            CCAssert(false, "sqlite3_prepare_v2 Error : INSERT TABLE StarSetting failed.");
        }
        sqlite3_bind_int(stmt, 1, episodeNumber);
        sqlite3_bind_int(stmt, 2, stageNumber);
        sqlite3_bind_int(stmt, 3, starValue);
        result = sqlite3_step(stmt);
        if(result != SQLITE_DONE) {
            CCAssert(false, "sqlite3_step Error : INSERT TABLE StarSetting failed.");
        }
        sqlite3_finalize(stmt);
        CCLOG("INSERT StarSetting result %d", result);
    }
    
    std::vector<std::vector<int>> StarSetting::getAllStarNumber()
    {
        std::vector<std::vector<int>> starOfStage;
        std::vector<int> child;
        int lastEpisode = 0;
        
        if (Sqlite3Engine::getInstance()->getIsConnect() == false) {
            CCAssert(false, "Error : Can't select StarSetting table, you need connect to DB first.");
        }
        int result;
        sqlite3_stmt *stmt;
        result = sqlite3_prepare_v2(Sqlite3Engine::getInstance()->getDb(), "SELECT * FROM StarSetting", -1, &stmt, NULL);
        if(result != SQLITE_OK) {
            CCAssert(false, "sqlite3_prepare_v2 Error : SELECT TABLE StarSetting failed.");
        }
        for (;;) {
            result = sqlite3_step(stmt);
            if (result == SQLITE_DONE)
                break;
            if (result != SQLITE_ROW) {
                printf("error: %s!\n", sqlite3_errmsg(Sqlite3Engine::getInstance()->getDb()));
                CCAssert(false, "sqlite3_step Error : SELECT TABLE StarSetting failed.");
                break;
            }
            int episode = sqlite3_column_int(stmt, 0);
            int star = sqlite3_column_int(stmt, 2);
            // 如果以統計到下一個章節，則將該章節統計的資訊(資料存在child變數裡)存入starOfStage，並清空child。
            if (lastEpisode < episode) {
                lastEpisode = episode;
                starOfStage.push_back(child);
                child.clear();
            }
            child.push_back(star);
        }
        starOfStage.push_back(child);
        child.clear();
        sqlite3_finalize(stmt);
        return starOfStage;
    }
    
    int StarSetting::getStarNumber(int episodeNumber, int stageNumber)
    {
        if (Sqlite3Engine::getInstance()->getIsConnect() == false) {
            CCAssert(false, "Error : Can't select StarSetting table, you need connect to DB first.");
        }
        int result;
        sqlite3_stmt *stmt;
        result = sqlite3_prepare_v2(
                                    Sqlite3Engine::getInstance()->getDb(),
                                    "SELECT * FROM StarSetting WHERE Episode = ? AND Stage = ?", -1, &stmt, NULL);
        if(result != SQLITE_OK) {
            CCAssert(false, "sqlite3_prepare_v2 Error : SELECT TABLE StarSetting failed.");
        }
        sqlite3_bind_int(stmt, 1, episodeNumber);
        sqlite3_bind_int(stmt, 2, stageNumber);
        result = sqlite3_step(stmt);
        if (result == SQLITE_DONE) {
            CCLOG("No star data with Episode %d  Stage %d",episodeNumber, stageNumber);
            sqlite3_finalize(stmt);
            return 0;
        }
        if (result != SQLITE_ROW) {
            printf("error: result %d message: %s!\n", result, sqlite3_errmsg(Sqlite3Engine::getInstance()->getDb()));
            CCAssert(false, "sqlite3_step Error : SELECT TABLE StarSetting failed.");
        }
        int star = sqlite3_column_int(stmt, 2);
        sqlite3_finalize(stmt);
        CCLOG("Get StarSetting starValue result %d", star);
        return star;

    }
}
