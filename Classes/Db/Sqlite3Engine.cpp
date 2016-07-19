#include "Sqlite3Engine.h"
#include <sqlite3.h>
#include <iostream>

namespace DB
{
    
    Sqlite3Engine* Sqlite3Engine::instance = new Sqlite3Engine::Sqlite3Engine();
    
    Sqlite3Engine::Sqlite3Engine()
    {
        this->isInit = false;
    }
    
    Sqlite3Engine* Sqlite3Engine::getInstance()
    {
        return instance;
    }
    
    void Sqlite3Engine::initEngine()
    {
        CCAssert(this->isInit == false, "Error : Sqlite3 Engine already init.");
        this->isFirstCreate = false;
        this->isConnect = false;
        this->dbPath = FileUtils::getInstance()->getWritablePath();
        this->dbPath.append("GreedyPig.sqlite");
        this->isInit = true;
        this->checkIsFirstCreate();
    }
    
    bool Sqlite3Engine::getIsConnect()
    {
        CCAssert(this->isInit == true, "Error : Sqlite3 Engine no init.");
        return this->isConnect;
    }
    
    bool Sqlite3Engine::getIsFirstCreate()
    {
        CCAssert(this->isInit == true, "Error : Sqlite3 Engine no init.");
        return this->isFirstCreate;
    }
    
    sqlite3* Sqlite3Engine::getDb()
    {
        CCAssert(this->isInit == true, "Error : Sqlite3 Engine no init.");
        return this->db;
    }
    
    void Sqlite3Engine::checkIsFirstCreate()
    {
        CCAssert(this->isInit == true, "Error : Sqlite3 Engine no init.");
        std::cout << this->dbPath << std::endl;
        if (std::ifstream(dbPath.c_str())) {
            std::cout << "Sqlite3Engine::init  File already exists" << std::endl;
            this->isFirstCreate = false;
        } else {
            std::cout << "Sqlite3Engine::init  File not exists" << std::endl;
            this->isFirstCreate = true;
        }
    }
    
    void Sqlite3Engine::connect()
    {
        CCAssert(this->isInit == true, "Error : Sqlite3 Engine no init.");
        if (this->isConnect == true) {
            CCLOG("Already Connect.");
            return;
        }
        char* errMsg = NULL;
        int result;
        result = sqlite3_open(this->dbPath.c_str(), &this->db);
        if (result != SQLITE_OK) {
            this->isConnect = false;
            CCLOG("OPENING WRONG, %d, MSG:%s", result, errMsg);
            CCAssert(false, "Sqlite3 connect failed.");
        } else {
            this->isConnect = true;
        }
        CCLOG("result %d", result);
    }
    
    void Sqlite3Engine::close()
    {
        CCAssert(this->isInit == true, "Error : Sqlite3 Engine no init.");
        if (this->isConnect == false) {
            CCLOG("Already Close Connect.");
            return;
        }
        sqlite3_close(this->db);
        this->isConnect = false;
    }
}
