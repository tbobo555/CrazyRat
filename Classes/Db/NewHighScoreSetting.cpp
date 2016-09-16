#include "NewHighScoreSetting.h"

namespace DB
{
    
    NewHighScoreSetting* NewHighScoreSetting::instance = new NewHighScoreSetting();
    
    NewHighScoreSetting::NewHighScoreSetting(){}
    
    NewHighScoreSetting* NewHighScoreSetting::getInstance()
    {
        return instance;
    }
    
    void NewHighScoreSetting::createTable()
    {
        if (Sqlite3Engine::getInstance()->getIsConnect() == false) {
            CCAssert(false, "Error : Can't create NewHighScoreSetting table , you need connect to DB first.");
        }
        if (Sqlite3Engine::getInstance()->getIsFirstCreate() == false) {
            CCAssert(false, "Error : NewHighScoreSetting table already exists, you can't create it again.");
        }
        char* errMsg = NULL;
        int result;
        result = sqlite3_exec(Sqlite3Engine::getInstance()->getDb(),
                              "CREATE TABLE NewHighScoreSetting (HighScore INTEGER DEFAULT 0)",
                              NULL, NULL, &errMsg);
        if(result != SQLITE_OK) {
            CCLOG("CREATE TABLE FAIL %d, Msg: %s",result,errMsg);
            CCAssert(false, "CREATE TABLE NewHighScoreSetting failed.");
        }
        CCLOG("result %d", result);
    }
    
    void NewHighScoreSetting::initTable()
    {
        if (Sqlite3Engine::getInstance()->getIsConnect() == false) {
            CCAssert(false, "Error : Can't init NewHighScoreSetting table, you need connect to DB first.");
        }
        if (Sqlite3Engine::getInstance()->getIsFirstCreate() == false) {
            CCAssert(false, "Error : NewHighScoreSetting table already exists, you can't init it again.");
        }
        int result;
        sqlite3_stmt *stmt;
        result = sqlite3_prepare_v2(
                                    Sqlite3Engine::getInstance()->getDb(),
                                    "INSERT INTO NewHighScoreSetting (HighScore) VALUES (?)", -1, &stmt, NULL);
        if(result != SQLITE_OK) {
            CCAssert(false, "sqlite3_prepare_v2 Error : INSERT TABLE NewHighScoreSetting failed.");
        }
        sqlite3_bind_int(stmt, 1, 0);
        result = sqlite3_step(stmt);
        if(result != SQLITE_DONE) {
            CCAssert(false, "sqlite3_step Error : INSERT TABLE NewHighScoreSetting failed.");
        }
        sqlite3_finalize(stmt);
        CCLOG("init NewHighScoreSetting Table result %d", result);
    }
    
    void NewHighScoreSetting::updateHighScore(int highScore)
    {
        if (Sqlite3Engine::getInstance()->getIsConnect() == false) {
            CCAssert(false, "Error : Can't update NewHighScoreSetting table, you need connect to DB first.");
        }
        int result;
        sqlite3_stmt *stmt;
        result = sqlite3_prepare_v2(
                                    Sqlite3Engine::getInstance()->getDb(),
                                    "UPDATE NewHighScoreSetting SET HighScore = ?", -1, &stmt, NULL);
        if(result != SQLITE_OK) {
            CCAssert(false, "sqlite3_prepare_v2 Error : UPDATE TABLE NewHighScoreSetting failed.");
        }
        sqlite3_bind_int(stmt, 1, highScore);
        result = sqlite3_step(stmt);
        if(result != SQLITE_DONE) {
            CCAssert(false, "sqlite3_step Error : UPDATE TABLE NewHighScoreSetting failed.");
        }
        sqlite3_finalize(stmt);
        CCLOG("UPDATE NewHighScoreSetting starValue result %d", result);
    }
    
    int NewHighScoreSetting::getHighScore()
    {
        if (Sqlite3Engine::getInstance()->getIsConnect() == false) {
            CCAssert(false, "Error : Can't select NewHighScoreSetting table, you need connect to DB first.");
        }
        int result;
        sqlite3_stmt *stmt;
        result = sqlite3_prepare_v2(
                                    Sqlite3Engine::getInstance()->getDb(),
                                    "SELECT * FROM NewHighScoreSetting", -1, &stmt, NULL);
        if(result != SQLITE_OK) {
            CCAssert(false, "sqlite3_prepare_v2 Error : SELECT TABLE NewHighScoreSetting failed.");
        }
        result = sqlite3_step(stmt);
        if (result == SQLITE_DONE) {
            CCLOG("No New High Score data");
            sqlite3_finalize(stmt);
            return 0;
        }
        if (result != SQLITE_ROW) {
            printf("error: result %d message: %s!\n", result, sqlite3_errmsg(Sqlite3Engine::getInstance()->getDb()));
            CCAssert(false, "sqlite3_step Error : SELECT TABLE NewHighScoreSetting failed.");
        }
        int highScore = sqlite3_column_int(stmt, 0);
        sqlite3_finalize(stmt);
        CCLOG("Get NewHighScoreSetting HighScore result %d", highScore);
        return highScore;

    }
    
}
