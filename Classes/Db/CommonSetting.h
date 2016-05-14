#ifndef _DB_CommonSetting_H_
#define _DB_CommonSetting_H_

namespace DB {
    class CommonSetting
    {
    public:
        static bool musicSwitch;
        static bool soundsSwitch;
        static int maxEpisode;
        static int maxStage;
        static int currentEpisode;
        static int currentStage;
        static std::vector<std::vector<int>> starOfStage;
    };
}

#endif /* defined(_DB_CommonSetting_H_) */
