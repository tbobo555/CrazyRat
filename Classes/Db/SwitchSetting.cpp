#include "SwitchSetting.h"

namespace DB
{
    SwitchSetting* SwitchSetting::instance = new SwitchSetting::SwitchSetting();
    
    SwitchSetting::SwitchSetting(){}
    
    SwitchSetting* SwitchSetting::getInstance()
    {
        return instance;
    }
    
    int SwitchSetting::createTable()
    {
        if (Sqlite3Engine::getInstance()->getIsConnect() == false) {
            return -1;
        }
        if (Sqlite3Engine::getInstance()->getIsFirstCreate() == false) {
            return -1;
        }
        char* errMsg = NULL;
        int result;
        result = sqlite3_exec(Sqlite3Engine::getInstance()->getDb(), "CREATE TABLE SwitchSetting (Name varchar(32), Setting BOOL DEFAULT 1)", NULL, NULL, &errMsg);
        if(result != SQLITE_OK) {
            CCLOG("CREATE TABLE FAIL %d, Msg: %s", result, errMsg);
        }
        CCLOG("createTable result %d", result);
        return result;
    }
    
    int SwitchSetting::initTable()
    {
        if (Sqlite3Engine::getInstance()->getIsConnect() == false) {
            return -1;
        }
        if (Sqlite3Engine::getInstance()->getIsFirstCreate() == false) {
            return -1;
        }
        int result;
        sqlite3_stmt *stmt;
        result = sqlite3_prepare_v2(Sqlite3Engine::getInstance()->getDb(), "INSERT INTO SwitchSetting (Name) VALUES (?)", -1, &stmt, NULL);
        if(result != SQLITE_OK) {
            return -1;
        }
        sqlite3_bind_text(stmt, 1, "Music", -1.0, NULL);
        result = sqlite3_step(stmt);
        if(result != SQLITE_DONE) {
            return -1;
        }
        result = sqlite3_prepare_v2(Sqlite3Engine::getInstance()->getDb(), "INSERT INTO SwitchSetting (Name) VALUES (?)", -1, &stmt, NULL);
        if(result != SQLITE_OK) {
            return -1;
        }
        sqlite3_bind_text(stmt, 1, "Sounds", -1.0, NULL);
        result = sqlite3_step(stmt);
        if(result != SQLITE_DONE) {
            return -1;
        }
        sqlite3_finalize(stmt);
        
        CCLOG("init SwitchSetting Table result %d", result);
        return 0;
    }
    
    int SwitchSetting::turnOnMusic()
    {
        if (Sqlite3Engine::getInstance()->getIsConnect() == false) {
            return -1;
        }
        int result;
        sqlite3_stmt *stmt;
        result = sqlite3_prepare_v2(Sqlite3Engine::getInstance()->getDb(), "UPDATE SwitchSetting SET Setting = ? WHERE Name = ?", -1, &stmt, NULL);
        if(result != SQLITE_OK) {
            return -1;
        }
        sqlite3_bind_int(stmt, 1, 1);
        sqlite3_bind_text(stmt, 2, "Music", -1.0, NULL);
        result = sqlite3_step(stmt);
        if(result != SQLITE_DONE) {
            return -1;
        }
        sqlite3_finalize(stmt);
        CCLOG("turnOnMusic result %d", result);
        return 0;
    }
    
    int SwitchSetting::turnOffMusic()
    {
        if (Sqlite3Engine::getInstance()->getIsConnect() == false) {
            return -1;
        }
        int result;
        sqlite3_stmt *stmt;
        result = sqlite3_prepare_v2(Sqlite3Engine::getInstance()->getDb(), "UPDATE SwitchSetting SET Setting = ? WHERE Name = ?", -1, &stmt, NULL);
        if(result != SQLITE_OK) {
            return -1;
        }
        sqlite3_bind_int(stmt, 1, 0);
        sqlite3_bind_text(stmt, 2, "Music", -1.0, NULL);
        result = sqlite3_step(stmt);
        if(result != SQLITE_DONE) {
            return -1;
        }
        sqlite3_finalize(stmt);
        CCLOG("turnOffMusic result %d", result);
        return 0;
    }
    
    int SwitchSetting::turnOnSounds()
    {
        if (Sqlite3Engine::getInstance()->getIsConnect() == false) {
            return -1;
        }
        int result;
        sqlite3_stmt *stmt;
        result = sqlite3_prepare_v2(Sqlite3Engine::getInstance()->getDb(), "UPDATE SwitchSetting SET Setting = ? WHERE Name = ?", -1, &stmt, NULL);
        if(result != SQLITE_OK) {
            return -1;
        }
        sqlite3_bind_int(stmt, 1, 1);
        sqlite3_bind_text(stmt, 2, "Sounds", -1.0, NULL);
        result = sqlite3_step(stmt);
        if(result != SQLITE_DONE) {
            return -1;
        }
        sqlite3_finalize(stmt);
        CCLOG("turnOnSounds result %d", result);
        return 0;
    }
    
    int SwitchSetting::turnOffSounds()
    {
        if (Sqlite3Engine::getInstance()->getIsConnect() == false) {
            return -1;
        }
        int result;
        sqlite3_stmt *stmt;
        result = sqlite3_prepare_v2(Sqlite3Engine::getInstance()->getDb(), "UPDATE SwitchSetting SET Setting = ? WHERE Name = ?", -1, &stmt, NULL);
        if(result != SQLITE_OK) {
            return -1;
        }
        sqlite3_bind_int(stmt, 1, 0);
        sqlite3_bind_text(stmt, 2, "Sounds", -1.0, NULL);
        result = sqlite3_step(stmt);
        if(result != SQLITE_DONE) {
            return -1;
        }
        sqlite3_finalize(stmt);
        CCLOG("turnOffSounds result %d", result);
        return 0;
    }
    
    int SwitchSetting::getMusicSwitch()
    {
        if (Sqlite3Engine::getInstance()->getIsConnect() == false) {
            return -1;
        }
        int result;
        int setting;
        sqlite3_stmt *stmt;
        result = sqlite3_prepare_v2(Sqlite3Engine::getInstance()->getDb(), "SELECT Setting FROM SwitchSetting WHERE Name = 'Music'", -1, &stmt, NULL);
        if(result != SQLITE_OK) {
            return -1;
        }
        result = sqlite3_step(stmt);
        if (result != SQLITE_ROW) {
            return -1;
        }
        setting = sqlite3_column_int(stmt, 0);
        CCLOG("get music setting %i ", setting);
        return setting;
    }
    
    int SwitchSetting::getSoundsSwitch()
    {
        if (Sqlite3Engine::getInstance()->getIsConnect() == false) {
            return -1;
        }
        int result;
        int setting;
        sqlite3_stmt *stmt;
        result = sqlite3_prepare_v2(Sqlite3Engine::getInstance()->getDb(), "SELECT Setting FROM SwitchSetting WHERE Name = 'Sounds'", -1, &stmt, NULL);
        if(result != SQLITE_OK) {
            return -1;
        }
        result = sqlite3_step(stmt);
        if (result != SQLITE_ROW) {
            return -1;
        }
        setting = sqlite3_column_int(stmt, 0);
        CCLOG("get sounds setting %i ", setting);
        return setting;
    }

}
