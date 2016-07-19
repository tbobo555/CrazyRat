#include "SwitchSetting.h"

namespace DB
{
    SwitchSetting* SwitchSetting::instance = new SwitchSetting::SwitchSetting();
    
    SwitchSetting::SwitchSetting(){}
    
    SwitchSetting* SwitchSetting::getInstance()
    {
        return instance;
    }
    
    void SwitchSetting::createTable()
    {
        // 當資料庫未連線或不是第一次建立資料庫時，不能執行此方法
        if (Sqlite3Engine::getInstance()->getIsConnect() == false) {
            CCAssert(false, "Error : Can't create SwitchSetting table , you need connect to DB first.");
        }
        if (Sqlite3Engine::getInstance()->getIsFirstCreate() == false) {
            CCAssert(false, "Error : SwitchSetting table already exists, you can't create it again.");
        }
        char* errMsg = NULL;
        int result;
        // 建立資料表SwitchSetting，欄位為Setting預設為1，代表開關預設為開
        result = sqlite3_exec(Sqlite3Engine::getInstance()->getDb(), "CREATE TABLE SwitchSetting (Name varchar(32), Setting BOOL DEFAULT 1)", NULL, NULL, &errMsg);
        if(result != SQLITE_OK) {
            CCLOG("CREATE TABLE FAIL %d, Msg: %s", result, errMsg);
            CCAssert(false, "CREATE TABLE SwitchSetting failed.");
        }
        CCLOG("createTable result %d", result);
    }
    
    void SwitchSetting::initTable()
    {
        // 當資料庫未連線或不是第一次建立資料庫時，不能執行此方法
        if (Sqlite3Engine::getInstance()->getIsConnect() == false) {
            CCAssert(false, "Error : Can't init SwitchSetting table , you need connect to DB first.");
        }
        if (Sqlite3Engine::getInstance()->getIsFirstCreate() == false) {
            CCAssert(false, "Error : SwitchSetting table already exists, you can't init it again.");
        }
        int result;
        sqlite3_stmt *stmt;
        result = sqlite3_prepare_v2(Sqlite3Engine::getInstance()->getDb(), "INSERT INTO SwitchSetting (Name) VALUES (?)", -1, &stmt, NULL);
        if(result != SQLITE_OK) {
            CCAssert(false, "sqlite3_prepare_v2 Error : INSERT TABLE SwitchSetting failed.");
        }
        sqlite3_bind_text(stmt, 1, "Music", -1.0, NULL);
        result = sqlite3_step(stmt);
        if(result != SQLITE_DONE) {
            CCAssert(false, "sqlite3_step Error : INSERT TABLE SwitchSetting failed.");
        }
        result = sqlite3_prepare_v2(Sqlite3Engine::getInstance()->getDb(), "INSERT INTO SwitchSetting (Name) VALUES (?)", -1, &stmt, NULL);
        if(result != SQLITE_OK) {
            CCAssert(false, "sqlite3_prepare_v2 Error : INSERT TABLE SwitchSetting failed.");
        }
        sqlite3_bind_text(stmt, 1, "Sounds", -1.0, NULL);
        result = sqlite3_step(stmt);
        if(result != SQLITE_DONE) {
            CCAssert(false, "sqlite3_step Error : INSERT TABLE SwitchSetting failed.");
        }
        sqlite3_finalize(stmt);
        
        CCLOG("init SwitchSetting Table result %d", result);
    }
    
    void SwitchSetting::turnOnMusic()
    {
        if (Sqlite3Engine::getInstance()->getIsConnect() == false) {
            CCAssert(false, "Error : Can't update SwitchSetting table for turn on music, you need connect to DB first.");
        }
        int result;
        sqlite3_stmt *stmt;
        result = sqlite3_prepare_v2(Sqlite3Engine::getInstance()->getDb(), "UPDATE SwitchSetting SET Setting = ? WHERE Name = ?", -1, &stmt, NULL);
        if(result != SQLITE_OK) {
            CCAssert(false, "sqlite3_prepare_v2 Error : UPDATE TABLE SwitchSetting failed.");
        }
        // 開啟音樂，Setting欄位改為1
        sqlite3_bind_int(stmt, 1, 1);
        sqlite3_bind_text(stmt, 2, "Music", -1.0, NULL);
        result = sqlite3_step(stmt);
        if(result != SQLITE_DONE) {
            CCAssert(false, "sqlite3_step Error : UPDATE TABLE SwitchSetting failed.");
        }
        sqlite3_finalize(stmt);
        CCLOG("turnOnMusic result %d", result);
    }
    
    void SwitchSetting::turnOffMusic()
    {
        if (Sqlite3Engine::getInstance()->getIsConnect() == false) {
            CCAssert(false, "Error : Can't update SwitchSetting table for turn off music, you need connect to DB first.");
        }
        int result;
        sqlite3_stmt *stmt;
        result = sqlite3_prepare_v2(Sqlite3Engine::getInstance()->getDb(), "UPDATE SwitchSetting SET Setting = ? WHERE Name = ?", -1, &stmt, NULL);
        if(result != SQLITE_OK) {
            CCAssert(false, "sqlite3_prepare_v2 Error : UPDATE TABLE SwitchSetting failed.");
        }
        // 關閉音樂，Setting欄位改為0
        sqlite3_bind_int(stmt, 1, 0);
        sqlite3_bind_text(stmt, 2, "Music", -1.0, NULL);
        result = sqlite3_step(stmt);
        if(result != SQLITE_DONE) {
            CCAssert(false, "sqlite3_step Error : UPDATE TABLE SwitchSetting failed.");
        }
        sqlite3_finalize(stmt);
        CCLOG("turnOffMusic result %d", result);
    }
    
    void SwitchSetting::turnOnSounds()
    {
        if (Sqlite3Engine::getInstance()->getIsConnect() == false) {
            CCAssert(false, "Error : Can't update SwitchSetting table for turn on sounds, you need connect to DB first.");
        }
        int result;
        sqlite3_stmt *stmt;
        result = sqlite3_prepare_v2(Sqlite3Engine::getInstance()->getDb(), "UPDATE SwitchSetting SET Setting = ? WHERE Name = ?", -1, &stmt, NULL);
        if(result != SQLITE_OK) {
            CCAssert(false, "sqlite3_prepare_v2 Error : UPDATE TABLE SwitchSetting failed.");
        }
        // 開啟音效，Setting欄位改為1
        sqlite3_bind_int(stmt, 1, 1);
        sqlite3_bind_text(stmt, 2, "Sounds", -1.0, NULL);
        result = sqlite3_step(stmt);
        if(result != SQLITE_DONE) {
            CCAssert(false, "sqlite3_step Error : UPDATE TABLE SwitchSetting failed.");
        }
        sqlite3_finalize(stmt);
        CCLOG("turnOnSounds result %d", result);
    }
    
    void SwitchSetting::turnOffSounds()
    {
        if (Sqlite3Engine::getInstance()->getIsConnect() == false) {
            CCAssert(false, "Error : Can't update SwitchSetting table for turn off sounds, you need connect to DB first.");
        }
        int result;
        sqlite3_stmt *stmt;
        result = sqlite3_prepare_v2(Sqlite3Engine::getInstance()->getDb(), "UPDATE SwitchSetting SET Setting = ? WHERE Name = ?", -1, &stmt, NULL);
        if(result != SQLITE_OK) {
            CCAssert(false, "sqlite3_prepare_v2 Error : UPDATE TABLE SwitchSetting failed.");
        }
        // 關閉音效，Setting欄位改為0
        sqlite3_bind_int(stmt, 1, 0);
        sqlite3_bind_text(stmt, 2, "Sounds", -1.0, NULL);
        result = sqlite3_step(stmt);
        if(result != SQLITE_DONE) {
            CCAssert(false, "sqlite3_step Error : UPDATE TABLE SwitchSetting failed.");
        }
        sqlite3_finalize(stmt);
        CCLOG("turnOffSounds result %d", result);
    }
    
    int SwitchSetting::getMusicSwitch()
    {
        if (Sqlite3Engine::getInstance()->getIsConnect() == false) {
            CCAssert(false, "Error : Can't select SwitchSetting table for music switch, you need connect to DB first.");
        }
        int result;
        int setting;
        sqlite3_stmt *stmt;
        result = sqlite3_prepare_v2(Sqlite3Engine::getInstance()->getDb(), "SELECT Setting FROM SwitchSetting WHERE Name = 'Music'", -1, &stmt, NULL);
        if(result != SQLITE_OK) {
            CCAssert(false, "sqlite3_prepare_v2 Error : SELECT TABLE SwitchSetting failed.");
        }
        result = sqlite3_step(stmt);
        if (result == SQLITE_DONE) {
            CCLOG("No music switch data");
            sqlite3_finalize(stmt);
            CCAssert(false, "Error : Table SwitchSetting no music switch data, it may no call initTable() when create table.");
        }
        if (result != SQLITE_ROW) {
            CCAssert(false, "sqlite3_step Error : SELECT TABLE SwitchSetting failed.");
        }
        setting = sqlite3_column_int(stmt, 0);
        CCLOG("get music setting %i ", setting);
        sqlite3_finalize(stmt);
        return setting;
    }
    
    int SwitchSetting::getSoundsSwitch()
    {
        if (Sqlite3Engine::getInstance()->getIsConnect() == false) {
            CCAssert(false, "Error : Can't select SwitchSetting table for sounds switch, you need connect to DB first.");
        }
        int result;
        int setting;
        sqlite3_stmt *stmt;
        result = sqlite3_prepare_v2(Sqlite3Engine::getInstance()->getDb(), "SELECT Setting FROM SwitchSetting WHERE Name = 'Sounds'", -1, &stmt, NULL);
        if(result != SQLITE_OK) {
            CCAssert(false, "sqlite3_prepare_v2 Error : SELECT TABLE SwitchSetting failed.");
        }
        result = sqlite3_step(stmt);
        if (result == SQLITE_DONE) {
            CCLOG("No sounds switch data");
            sqlite3_finalize(stmt);
            CCAssert(false, "Error : Table SwitchSetting no sounds switch data, it may no call initTable() when create table.");
        }
        if (result != SQLITE_ROW) {
            CCAssert(false, "sqlite3_step Error : SELECT TABLE SwitchSetting failed.");
        }
        setting = sqlite3_column_int(stmt, 0);
        CCLOG("get sounds setting %i ", setting);
        sqlite3_finalize(stmt);
        return setting;
    }

}
