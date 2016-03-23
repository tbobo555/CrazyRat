#include "CommonSetting.h"

namespace DB
{
    bool CommonSetting::musicSwitch = true;
    bool CommonSetting::soundsSwitch = true;
    int CommonSetting::currentStage = 5;
    std::vector<int> CommonSetting::starOfStage = {2, 1, 3, 2};
}
