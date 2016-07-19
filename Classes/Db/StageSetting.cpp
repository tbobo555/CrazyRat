#include "StageSetting.h"

namespace DB
{
    StageSetting* StageSetting::instance = new StageSetting::StageSetting();
    
    StageSetting::StageSetting(){}
    
    StageSetting* StageSetting::getInstance()
    {
        return instance;
    }
    
    void StageSetting::createTable()
    {
        if (Sqlite3Engine::getInstance()->getIsConnect() == false) {
            CCAssert(false, "Error : Can't create StageSetting table , you need connect to DB first.");
        }
        if (Sqlite3Engine::getInstance()->getIsFirstCreate() == false) {
            CCAssert(false, "Error : StageSetting table already exists, you can't create it again.");
        }
        char* errMsg = NULL;
        int result;
        result = sqlite3_exec(Sqlite3Engine::getInstance()->getDb(), "CREATE TABLE StageSetting (Name TEXT, Value INTEGER DEFAULT 0)", NULL, NULL, &errMsg);
        if(result != SQLITE_OK) {
            CCLOG("CREATE TABLE FAIL %d, Msg: %s",result,errMsg);
            CCAssert(false, "CREATE TABLE StageSetting failed.");
        }
        CCLOG("result %d", result);
    }
    
    void StageSetting::initTable()
    {
        if (Sqlite3Engine::getInstance()->getIsConnect() == false) {
            CCAssert(false, "Error : Can't init StageSetting table , you need connect to DB first.");
        }
        if (Sqlite3Engine::getInstance()->getIsFirstCreate() == false) {
            CCAssert(false, "Error : StageSetting table already exists, you can't init it again.");
        }
        int result;
        sqlite3_stmt *stmt;
        
        result = sqlite3_prepare_v2(Sqlite3Engine::getInstance()->getDb(), "INSERT INTO StageSetting (Name) VALUES (?)", -1, &stmt, NULL);
        if(result != SQLITE_OK) {
            CCAssert(false, "sqlite3_prepare_v2 Error : INSERT TABLE StageSetting failed.");
        }
        sqlite3_bind_text(stmt, 1, "Current", -1.0, NULL);
        result = sqlite3_step(stmt);
        if(result != SQLITE_DONE) {
            CCAssert(false, "sqlite3_step Error : INSERT TABLE StageSetting failed.");
        }
        result = sqlite3_prepare_v2(Sqlite3Engine::getInstance()->getDb(), "INSERT INTO StageSetting (Name) VALUES (?)", -1, &stmt, NULL);
        if(result != SQLITE_OK) {
            CCAssert(false, "sqlite3_prepare_v2 Error : INSERT TABLE StageSetting failed.");
        }
        sqlite3_bind_text(stmt, 1, "Max", -1.0, NULL);
        result = sqlite3_step(stmt);
        if(result != SQLITE_DONE) {
            CCAssert(false, "sqlite3_step Error : INSERT TABLE StageSetting failed.");
        }
        sqlite3_finalize(stmt);
        CCLOG("init StageSetting Table result %d", result);
    }
    
    void StageSetting::updateCurrent(int current)
    {
        if (Sqlite3Engine::getInstance()->getIsConnect() == false) {
            CCAssert(false, "Error : Can't update StageSetting table, you need connect to DB first.");
        }
        int result;
        sqlite3_stmt *stmt;
        result = sqlite3_prepare_v2(Sqlite3Engine::getInstance()->getDb(), "UPDATE StageSetting SET Value = ? WHERE Name = ?", -1, &stmt, NULL);
        if(result != SQLITE_OK) {
            CCAssert(false, "sqlite3_prepare_v2 Error : UPDATE TABLE StageSetting failed.");
        }
        sqlite3_bind_int(stmt, 1, current);
        sqlite3_bind_text(stmt, 2, "Current", -1.0, NULL);
        result = sqlite3_step(stmt);
        if(result != SQLITE_DONE) {
            CCAssert(false, "sqlite3_step Error : UPDATE TABLE StageSetting failed.");
        }
        sqlite3_finalize(stmt);
        CCLOG("UPDATE StageSetting Current result %d", result);

    }
    
    void StageSetting::updateMax(int max)
    {
        if (Sqlite3Engine::getInstance()->getIsConnect() == false) {
            CCAssert(false, "Error : Can't update StageSetting table, you need connect to DB first.");
        }
        int result;
        sqlite3_stmt *stmt;
        result = sqlite3_prepare_v2(Sqlite3Engine::getInstance()->getDb(), "UPDATE StageSetting SET Value = ? WHERE Name = ?", -1, &stmt, NULL);
        if(result != SQLITE_OK) {
            CCAssert(false, "sqlite3_prepare_v2 Error : UPDATE TABLE StageSetting failed.");
        }
        sqlite3_bind_int(stmt, 1, max);
        sqlite3_bind_text(stmt, 2, "Max", -1.0, NULL);
        result = sqlite3_step(stmt);
        if(result != SQLITE_DONE) {
            CCAssert(false, "sqlite3_step Error : UPDATE TABLE StageSetting failed.");
        }
        sqlite3_finalize(stmt);
        CCLOG("UPDATE StageSetting Max result %d", result);
    }
    
    int StageSetting::getCurrent()
    {
        if (Sqlite3Engine::getInstance()->getIsConnect() == false) {
            CCAssert(false, "Error : Can't select StageSetting table, you need connect to DB first.");
        }
        int result;
        int current;
        sqlite3_stmt *stmt;
        result = sqlite3_prepare_v2(Sqlite3Engine::getInstance()->getDb(), "SELECT Value FROM StageSetting WHERE Name = 'Current'", -1, &stmt, NULL);
        if(result != SQLITE_OK) {
            CCAssert(false, "sqlite3_prepare_v2 Error : SELECT TABLE StageSetting failed.");
        }
        result = sqlite3_step(stmt);
        if (result == SQLITE_DONE) {
            CCLOG("No current data");
            sqlite3_finalize(stmt);
            CCAssert(false, "Error : Table StageSetting no current data, it may no call initTable() when create table.");
        }
        if (result != SQLITE_ROW) {
            CCAssert(false, "sqlite3_step Error : SELECT TABLE StageSetting failed.");
        }
        current = sqlite3_column_int(stmt, 0);
        CCLOG("get current StageSetting  %i ", current);
        sqlite3_finalize(stmt);
        return current;
    }
    
    int StageSetting::getMax()
    {
        if (Sqlite3Engine::getInstance()->getIsConnect() == false) {
            CCAssert(false, "Error : Can't select StageSetting table, you need connect to DB first.");
        }
        int result;
        int max;
        sqlite3_stmt *stmt;
        result = sqlite3_prepare_v2(Sqlite3Engine::getInstance()->getDb(), "SELECT Value FROM StageSetting WHERE Name = 'Max'", -1, &stmt, NULL);
        if(result != SQLITE_OK) {
            CCAssert(false, "sqlite3_prepare_v2 Error : SELECT TABLE StageSetting failed.");
        }
        result = sqlite3_step(stmt);
        if (result == SQLITE_DONE) {
            CCLOG("No max data");
            sqlite3_finalize(stmt);
            CCAssert(false, "Error : Table StageSetting no max data, it may no call initTable() when create table.");
        }
        if (result != SQLITE_ROW) {
            CCAssert(false, "sqlite3_step Error : SELECT TABLE StageSetting failed.");
        }
        max = sqlite3_column_int(stmt, 0);
        CCLOG("get max StageSetting  %i ", max);
        sqlite3_finalize(stmt);
        return max;
    }
    
}
