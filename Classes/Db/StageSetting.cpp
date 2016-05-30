#include "StageSetting.h"

namespace DB
{
    StageSetting* StageSetting::instance = new StageSetting::StageSetting();
    
    StageSetting::StageSetting(){}
    
    StageSetting* StageSetting::getInstance()
    {
        return instance;
    }
    
    int StageSetting::createTable()
    {
        if (Sqlite3Engine::getInstance()->getIsConnect() == false) {
            return -1;
        }
        if (Sqlite3Engine::getInstance()->getIsFirstCreate() == false) {
            return -1;
        }
        char* errMsg = NULL;
        int result;
        result = sqlite3_exec(Sqlite3Engine::getInstance()->getDb(), "CREATE TABLE StageSetting (Name TEXT, Value INTEGER DEFAULT 0)", NULL, NULL, &errMsg);
        if(result != SQLITE_OK) {
            CCLOG("CREATE TABLE FAIL %d, Msg: %s",result,errMsg);
        }
        CCLOG("result %d", result);
        return result;
    }
    
    int StageSetting::initTable()
    {
        if (Sqlite3Engine::getInstance()->getIsConnect() == false) {
            return -1;
        }
        if (Sqlite3Engine::getInstance()->getIsFirstCreate() == false) {
            return -1;
        }
        int result;
        sqlite3_stmt *stmt;
        
        result = sqlite3_prepare_v2(Sqlite3Engine::getInstance()->getDb(), "INSERT INTO StageSetting (Name) VALUES (?)", -1, &stmt, NULL);
        if(result != SQLITE_OK) {
            return -1;
        }
        sqlite3_bind_text(stmt, 1, "Current", -1.0, NULL);
        result = sqlite3_step(stmt);
        if(result != SQLITE_DONE) {
            return -1;
        }
        result = sqlite3_prepare_v2(Sqlite3Engine::getInstance()->getDb(), "INSERT INTO StageSetting (Name) VALUES (?)", -1, &stmt, NULL);
        if(result != SQLITE_OK) {
            return -1;
        }
        sqlite3_bind_text(stmt, 1, "Max", -1.0, NULL);
        result = sqlite3_step(stmt);
        if(result != SQLITE_DONE) {
            return -1;
        }
        sqlite3_finalize(stmt);
        CCLOG("init StageSetting Table result %d", result);
        return 0;
    }
    
    int StageSetting::updateCurrent(int current)
    {
        if (Sqlite3Engine::getInstance()->getIsConnect() == false) {
            return -1;
        }
        int result;
        sqlite3_stmt *stmt;
        result = sqlite3_prepare_v2(Sqlite3Engine::getInstance()->getDb(), "UPDATE StageSetting SET Value = ? WHERE Name = ?", -1, &stmt, NULL);
        if(result != SQLITE_OK) {
            return -1;
        }
        sqlite3_bind_int(stmt, 1, current);
        sqlite3_bind_text(stmt, 2, "Current", -1.0, NULL);
        result = sqlite3_step(stmt);
        if(result != SQLITE_DONE) {
            return -1;
        }
        sqlite3_finalize(stmt);
        CCLOG("UPDATE StageSetting Current result %d", result);
        return result;

    }
    
    int StageSetting::updateMax(int max)
    {
        if (Sqlite3Engine::getInstance()->getIsConnect() == false) {
            return -1;
        }
        int result;
        sqlite3_stmt *stmt;
        result = sqlite3_prepare_v2(Sqlite3Engine::getInstance()->getDb(), "UPDATE StageSetting SET Value = ? WHERE Name = ?", -1, &stmt, NULL);
        if(result != SQLITE_OK) {
            return -1;
        }
        sqlite3_bind_int(stmt, 1, max);
        sqlite3_bind_text(stmt, 2, "Max", -1.0, NULL);
        result = sqlite3_step(stmt);
        if(result != SQLITE_DONE) {
            return -1;
        }
        sqlite3_finalize(stmt);
        CCLOG("UPDATE StageSetting Max result %d", result);
        return result;
    }
    
    int StageSetting::getCurrent()
    {
        if (Sqlite3Engine::getInstance()->getIsConnect() == false) {
            return -1;
        }
        int result;
        int current;
        sqlite3_stmt *stmt;
        result = sqlite3_prepare_v2(Sqlite3Engine::getInstance()->getDb(), "SELECT Value FROM StageSetting WHERE Name = 'Current'", -1, &stmt, NULL);
        if(result != SQLITE_OK) {
            return -1;
        }
        result = sqlite3_step(stmt);
        if (result != SQLITE_ROW) {
            return -1;
        }
        current = sqlite3_column_int(stmt, 0);
        CCLOG("get current StageSetting  %i ", current);
        return current;
    }
    
    int StageSetting::getMax()
    {
        if (Sqlite3Engine::getInstance()->getIsConnect() == false) {
            return -1;
        }
        int result;
        int max;
        sqlite3_stmt *stmt;
        result = sqlite3_prepare_v2(Sqlite3Engine::getInstance()->getDb(), "SELECT Value FROM StageSetting WHERE Name = 'Max'", -1, &stmt, NULL);
        if(result != SQLITE_OK) {
            return -1;
        }
        result = sqlite3_step(stmt);
        if (result != SQLITE_ROW) {
            return -1;
        }
        max = sqlite3_column_int(stmt, 0);
        CCLOG("get max StageSetting  %i ", max);
        return max;
    }
    
}
