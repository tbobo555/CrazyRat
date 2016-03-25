#include "CommonSetting.h"

namespace DB
{
    bool CommonSetting::musicSwitch = true;
    bool CommonSetting::soundsSwitch = true;
    int CommonSetting::currentStage = 4;
    int CommonSetting::currentMap = 3;
    std::vector<std::vector<int>> CommonSetting::starOfStage = {
        {3, 3, 3, 3, 2},
        {1, 3, 2, 1, 1},
        {3, 1, 1, 2, 2},
        {1, 2, 3, 3}
    };
}
