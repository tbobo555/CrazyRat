#include "CommonSetting.h"

namespace DB
{
    bool CommonSetting::musicSwitch = true;
    bool CommonSetting::soundsSwitch = true;
    int CommonSetting::currentStage = 3;
    int CommonSetting::maxEpisode = 2;
    int CommonSetting::maxStage = 5;
    int CommonSetting::currentMap = 1;
    std::vector<std::vector<int>> CommonSetting::starOfStage = {
        {3, 2, 1, 2, 0},
        {3, 1, 1, },
    };
}
