#ifndef _DB_SwitchSetting_H_
#define _DB_SwitchSetting_H_

#include "Sqlite3Engine.h"

namespace DB
{
    class SwitchSetting
    {
    public:
        static SwitchSetting* getInstance();
        int createTable();
        int initTable();
        int turnOnMusic();
        int turnOffMusic();
        int turnOnSounds();
        int turnOffSounds();
        int getMusicSwitch();
        int getSoundsSwitch();
    private:
        SwitchSetting();
        static SwitchSetting *instance;
    };
}


#endif /* _DB_SwitchSetting_H_ */
