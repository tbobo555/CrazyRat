#ifndef _DB_CommonSetting_H_
#define _DB_CommonSetting_H_

namespace DB {
    class CommonSetting
    {
    public:
        static bool musicSwitch;
        static bool soundsSwitch;
        static int currentStage;
        static std::vector<int> starOfStage;
    };
}

#endif /* defined(_DB_CommonSetting_H_) */
