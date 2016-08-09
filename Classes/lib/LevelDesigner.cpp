#include "LevelDesigner.h"

LevelDeisgner* LevelDeisgner::instance = new LevelDeisgner();

LevelDeisgner::LevelDeisgner(){};

LevelDeisgner* LevelDeisgner::getInstance()
{
    return instance;
}

std::vector<float> LevelDeisgner::loadLevelSetting(int episodeNumber, int stageNumber, int roadNumber)
{
    if (episodeNumber == 0) {
        return this->loadEpisode0LevelSetting(stageNumber, roadNumber);
    }
    if (episodeNumber == 1) {
        return this->loadEpisode0LevelSetting(stageNumber, roadNumber);
    }
    return this->loadEpisode0LevelSetting(stageNumber, roadNumber);
}


std::vector<float> LevelDeisgner::loadEpisode0LevelSetting(int stageNumber, int roadNumber)
{
    std::vector<std::vector<float>> stage0 = {
        {1.3f, 1.9f, 11.3f, 15.8f, 16.8f, 17.9f},
        {0.0f, 3.7f, 7.1f, 8.5f, 10.0f},
        {2.6f, 4.9f, 5.8f, 12.2f, 12.9f, 14.5f},
    };
    std::vector<std::vector<float>> stage1 = {
        {1.3f, 1.9f, 11.3f, 15.8f, 16.8f, 17.9f},
        {0.0f, 3.7f, 7.1f, 8.5f, 10.0f},
        {2.6f, 4.9f, 5.8f, 12.2f, 12.9f, 14.5f},
    };
    std::vector<std::vector<float>> stage2 = {
        {1.3f, 1.9f, 11.3f, 15.8f, 16.8f, 17.9f},
        {0.0f, 3.7f, 7.1f, 8.5f, 10.0f},
        {2.6f, 4.9f, 5.8f, 12.2f, 12.9f, 14.5f},
    };
    std::vector<std::vector<float>> stage3 = {
        {1.3f, 1.9f, 11.3f, 15.8f, 16.8f, 17.9f},
        {0.0f, 3.7f, 7.1f, 8.5f, 10.0f},
        {2.6f, 4.9f, 5.8f, 12.2f, 12.9f, 14.5f},
    };
    std::vector<std::vector<float>> stage4 = {
        {1.3f, 1.9f, 11.3f, 15.8f, 16.8f, 17.9f},
        {0.0f, 3.7f, 7.1f, 8.5f, 10.0f},
        {2.6f, 4.9f, 5.8f, 12.2f, 12.9f, 14.5f},
    };
    std::vector<std::vector<float>> stage5 = {
        {1.3f, 1.9f, 11.3f, 15.8f, 16.8f, 17.9f},
        {0.0f, 3.7f, 7.1f, 8.5f, 10.0f},
        {2.6f, 4.9f, 5.8f, 12.2f, 12.9f, 14.5f},
    };
    std::vector<std::vector<float>> stage6 = {
        {1.3f, 1.9f, 11.3f, 15.8f, 16.8f, 17.9f},
        {0.0f, 3.7f, 7.1f, 8.5f, 10.0f},
        {2.6f, 4.9f, 5.8f, 12.2f, 12.9f, 14.5f},
    };
    
    std::vector<std::vector<std::vector<float>>> episode0LevelSetting = {
        stage0, stage1
    };
    
    if (stageNumber < 0 || stageNumber > episode0LevelSetting.size()) {
        char str[100] = {0};
        sprintf(str, "Load Level Setting Failed : setting vector out of bound with stageNumber: %d", stageNumber);
        CCASSERT(false, str);
    }
    
    auto selectedStage = episode0LevelSetting.at(stageNumber);
    
    if (roadNumber < 0 || roadNumber > selectedStage.size()) {
        char str[100] = {0};
        sprintf(str, "Load Level Setting Failed : setting vector out of bound with roadNumber: %d", roadNumber);
        CCASSERT(false, str);
    }

    return selectedStage.at(roadNumber);
}
