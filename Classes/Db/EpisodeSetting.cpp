#include "EpisodeSetting.h"

namespace DB
{
    EpisodeSetting* EpisodeSetting::instance = new EpisodeSetting::EpisodeSetting();
    
    EpisodeSetting::EpisodeSetting(){}
    
    EpisodeSetting* EpisodeSetting::getInstance()
    {
        return instance;
    }

    void EpisodeSetting::createTable()
    {
        if (Sqlite3Engine::getInstance()->getIsConnect() == false) {
            CCAssert(false, "Error : Can't create EpisodeSetting table , you need connect to DB first.");
        }
        if (Sqlite3Engine::getInstance()->getIsFirstCreate() == false) {
            CCAssert(false, "Error : EpisodeSetting table already exists, you can't create it again.");
        }
        char* errMsg = NULL;
        int result;
        result = sqlite3_exec(Sqlite3Engine::getInstance()->getDb(), "CREATE TABLE EpisodeSetting (Name TEXT, Value INTEGER DEFAULT 0)", NULL, NULL, &errMsg);
        if(result != SQLITE_OK) {
            CCLOG("CREATE TABLE FAIL %d, Msg: %s",result,errMsg);
            CCAssert(false, "CREATE TABLE EpisodeSetting failed.");
        }
        CCLOG("result %d", result);
    }
    
    void EpisodeSetting::initTable()
    {
        if (Sqlite3Engine::getInstance()->getIsConnect() == false) {
            CCAssert(false, "Error : Can't init EpisodeSetting table , you need connect to DB first.");
        }
        if (Sqlite3Engine::getInstance()->getIsFirstCreate() == false) {
            CCAssert(false, "Error : EpisodeSetting table already exists, you can't init it again.");
        }
        int result;
        sqlite3_stmt *stmt;
        result = sqlite3_prepare_v2(Sqlite3Engine::getInstance()->getDb(), "INSERT INTO EpisodeSetting (Name) VALUES (?)", -1, &stmt, NULL);
        if(result != SQLITE_OK) {
            CCAssert(false, "sqlite3_prepare_v2 Error : INSERT TABLE EpisodeSetting failed.");
        }
        sqlite3_bind_text(stmt, 1, "Current", -1.0, NULL);
        result = sqlite3_step(stmt);
        if(result != SQLITE_DONE) {
            CCAssert(false, "sqlite3_step Error : INSERT TABLE EpisodeSetting failed.");
        }
        result = sqlite3_prepare_v2(Sqlite3Engine::getInstance()->getDb(), "INSERT INTO EpisodeSetting (Name) VALUES (?)", -1, &stmt, NULL);
        if(result != SQLITE_OK) {
            CCAssert(false, "sqlite3_prepare_v2 Error : INSERT TABLE EpisodeSetting failed.");
        }
        sqlite3_bind_text(stmt, 1, "Max", -1.0, NULL);
        result = sqlite3_step(stmt);
        if(result != SQLITE_DONE) {
            CCAssert(false, "sqlite3_step Error : INSERT TABLE EpisodeSetting failed.");
        }
        sqlite3_finalize(stmt);
        
        CCLOG("init EpisodeSetting Table result %d", result);
    }
    
    void EpisodeSetting::updateCurrent(int current)
    {
        if (Sqlite3Engine::getInstance()->getIsConnect() == false) {
            CCAssert(false, "Error : Can't update EpisodeSetting table, you need connect to DB first.");
        }
        int result;
        sqlite3_stmt *stmt;
        result = sqlite3_prepare_v2(Sqlite3Engine::getInstance()->getDb(), "UPDATE EpisodeSetting SET Value = ? WHERE Name = ?", -1, &stmt, NULL);
        if(result != SQLITE_OK) {
            CCAssert(false, "sqlite3_prepare_v2 Error : UPDATE TABLE EpisodeSetting failed.");
        }
        sqlite3_bind_int(stmt, 1, current);
        sqlite3_bind_text(stmt, 2, "Current", -1.0, NULL);
        result = sqlite3_step(stmt);
        if(result != SQLITE_DONE) {
            CCAssert(false, "sqlite3_step Error : UPDATE TABLE EpisodeSetting failed.");
        }
        sqlite3_finalize(stmt);
        CCLOG("UPDATE EpisodeSetting Current result %d", result);
    }
    
    void EpisodeSetting::updateMax(int max)
    {
        if (Sqlite3Engine::getInstance()->getIsConnect() == false) {
            CCAssert(false, "Error : Can't update EpisodeSetting table, you need connect to DB first.");
        }
        int result;
        sqlite3_stmt *stmt;
        result = sqlite3_prepare_v2(Sqlite3Engine::getInstance()->getDb(), "UPDATE EpisodeSetting SET Value = ? WHERE Name = ?", -1, &stmt, NULL);
        if(result != SQLITE_OK) {
            CCAssert(false, "sqlite3_prepare_v2 Error : UPDATE TABLE EpisodeSetting failed.");
        }
        sqlite3_bind_int(stmt, 1, max);
        sqlite3_bind_text(stmt, 2, "Max", -1.0, NULL);
        result = sqlite3_step(stmt);
        if(result != SQLITE_DONE) {
            CCAssert(false, "sqlite3_step Error : UPDATE TABLE EpisodeSetting failed.");
        }
        sqlite3_finalize(stmt);
        CCLOG("UPDATE EpisodeSetting Max result %d", result);
    }
    
    int EpisodeSetting::getCurrent()
    {
        if (Sqlite3Engine::getInstance()->getIsConnect() == false) {
            CCAssert(false, "Error : Can't select EpisodeSetting table, you need connect to DB first.");
        }
        int result;
        int current;
        sqlite3_stmt *stmt;
        result = sqlite3_prepare_v2(Sqlite3Engine::getInstance()->getDb(), "SELECT Value FROM EpisodeSetting WHERE Name = 'Current'", -1, &stmt, NULL);
        if(result != SQLITE_OK) {
            CCAssert(false, "sqlite3_prepare_v2 Error : SELECT TABLE EpisodeSetting failed.");
        }
        result = sqlite3_step(stmt);
        if (result == SQLITE_DONE) {
            CCLOG("No current data");
            sqlite3_finalize(stmt);
            CCAssert(false, "Error : Table EpisodeSetting no current data, it may no call initTable() when create table.");
        }
        if (result != SQLITE_ROW) {
            CCAssert(false, "sqlite3_step Error : SELECT TABLE EpisodeSetting failed.");
        }
        current = sqlite3_column_int(stmt, 0);
        CCLOG("get current EpisodeSetting  %i ", current);
        sqlite3_finalize(stmt);
        return current;
    }

    int EpisodeSetting::getMax()
    {
        if (Sqlite3Engine::getInstance()->getIsConnect() == false) {
            CCAssert(false, "Error : Can't select EpisodeSetting table, you need connect to DB first.");
        }
        int result;
        int max;
        sqlite3_stmt *stmt;
        result = sqlite3_prepare_v2(Sqlite3Engine::getInstance()->getDb(), "SELECT Value FROM EpisodeSetting WHERE Name = 'Max'", -1, &stmt, NULL);
        if(result != SQLITE_OK) {
            CCAssert(false, "sqlite3_prepare_v2 Error : SELECT TABLE EpisodeSetting failed.");
        }
        result = sqlite3_step(stmt);
        if (result == SQLITE_DONE) {
            CCLOG("No max data");
            sqlite3_finalize(stmt);
            CCAssert(false, "Error : Table EpisodeSetting no max data, it may no call initTable() when create table.");
        }
        if (result != SQLITE_ROW) {
            CCAssert(false, "sqlite3_step Error : SELECT TABLE EpisodeSetting failed.");
        }
        max = sqlite3_column_int(stmt, 0);
        CCLOG("get max EpisodeSetting  %i ", max);
        sqlite3_finalize(stmt);
        return max;
    }
}
