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

float LevelDeisgner::loadRunningTimeByEpisodeAndStage(int episodeNumber, int stageNumber)
{
    return 6.f;
}

std::vector<std::vector<float>> LevelDeisgner::setLevelByRandom(int episodeNumber, int stageNumber)
{
    float totalTime = 84.f;
    int quantity = 85;
    float baseTime = totalTime / (quantity-1);
    float intervalMin = 1.05f;
    float intervalMax = 0.95f;
    std::vector<float> road0;
    std::vector<float> road1;
    std::vector<float> road2;
    
    std::vector<std::vector<float>> randomLevel = {road0, road1, road2};
    
    for (int i = 0; i < quantity; i ++) {
        int randomRoad = rand() % 3;
        double randomIntervalOffset = (double)rand() / RAND_MAX;
        float randomInterval = intervalMin + randomIntervalOffset * (intervalMax - intervalMin);
        
        float second = (randomInterval + (i-1)) * baseTime;
        if (i == 0) {
            second = 0;
        }
        randomLevel.at(randomRoad).push_back(second);
    }
    
    return randomLevel;
}

std::vector<float> LevelDeisgner::loadEpisode0LevelSetting(int stageNumber, int roadNumber)
{
    if (this->episode0LevelSetting.size() == 0) {
        this->initLevelSetting(0, stageNumber);
    }
    if (stageNumber < 0 || stageNumber > episode0LevelSetting.size()) {
        char str[100] = {0};
        sprintf(str, "Load Level Setting Failed : setting vector out of bound with stageNumber: %d", stageNumber);
        CCASSERT(false, str);
    }
    auto selectedStage = this->episode0LevelSetting.at(stageNumber);
    if (roadNumber < 0 || roadNumber > selectedStage.size()) {
        char str[100] = {0};
        sprintf(str, "Load Level Setting Failed : setting vector out of bound with roadNumber: %d", roadNumber);
        CCASSERT(false, str);
    }

    return selectedStage.at(roadNumber);
}


void LevelDeisgner::initLevelSetting(int episodeNumber, int stageNumber)
{
    std::vector<std::vector<float>> stage0 = {
        {0.0f, 4.f, 7.f, 8.f, 10.f, 11.f, 17.f, 21.f, 22.f, 23.f,
            28.f, 29.f, 30.f, 36.f, 37.f, 47.f, 48.f, 50.f, 53.f, 56.f,
            61.f, 65.f, 66.f, 72.f, 73.f, 75.f, 76.f, 83.f, 84.f},
        
        {1.f, 2.1f, 5.f, 9.f, 12.f, 13.f, 14.f, 16.f, 20.f, 25.f,
            26.f, 31.f, 35.f, 41.f, 44.f, 45.f, 46.f, 49.f, 57.f, 58.f,
            59.f, 60.f, 67.f, 68.f, 69.f, 78.f, 79.f, 80.f},
        
        {3.0f, 6.f, 15.f, 18.f, 19.f, 24.f, 27.f, 32.f, 33.f, 34.f,
            38.f, 39.f, 40.f, 42.f, 43.f, 51.f, 52.f, 54.f, 55.f, 62.f,
            63.f, 64.f, 70.f, 71.f, 74.f, 77.f, 81.f, 82.f},
    };
    std::vector<std::vector<float>> stage1 = this->setLevelByRandom(0, stageNumber);
    
    
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
    std::vector<std::vector<float>> stage7 = {
        {1.3f, 1.9f, 11.3f, 15.8f, 16.8f, 17.9f},
        {0.0f, 3.7f, 7.1f, 8.5f, 10.0f},
        {2.6f, 4.9f, 5.8f, 12.2f, 12.9f, 14.5f},
    };
    std::vector<std::vector<float>> stage8 = {
        {1.3f, 1.9f, 11.3f, 15.8f, 16.8f, 17.9f},
        {0.0f, 3.7f, 7.1f, 8.5f, 10.0f},
        {2.6f, 4.9f, 5.8f, 12.2f, 12.9f, 14.5f},
    };
    std::vector<std::vector<float>> stage9 = {
        {1.3f, 1.9f, 11.3f, 15.8f, 16.8f, 17.9f},
        {0.0f, 3.7f, 7.1f, 8.5f, 10.0f},
        {2.6f, 4.9f, 5.8f, 12.2f, 12.9f, 14.5f},
    };
    std::vector<std::vector<float>> stage10 = {
        {1.3f, 1.9f, 11.3f, 15.8f, 16.8f, 17.9f},
        {0.0f, 3.7f, 7.1f, 8.5f, 10.0f},
        {2.6f, 4.9f, 5.8f, 12.2f, 12.9f, 14.5f},
    };
    std::vector<std::vector<float>> stage11 = {
        {1.3f, 1.9f, 11.3f, 15.8f, 16.8f, 17.9f},
        {0.0f, 3.7f, 7.1f, 8.5f, 10.0f},
        {2.6f, 4.9f, 5.8f, 12.2f, 12.9f, 14.5f},
    };
    std::vector<std::vector<float>> stage12 = {
        {1.3f, 1.9f, 11.3f, 15.8f, 16.8f, 17.9f},
        {0.0f, 3.7f, 7.1f, 8.5f, 10.0f},
        {2.6f, 4.9f, 5.8f, 12.2f, 12.9f, 14.5f},
    };
    std::vector<std::vector<float>> stage13 = {
        {1.3f, 1.9f, 11.3f, 15.8f, 16.8f, 17.9f},
        {0.0f, 3.7f, 7.1f, 8.5f, 10.0f},
        {2.6f, 4.9f, 5.8f, 12.2f, 12.9f, 14.5f},
    };
    std::vector<std::vector<float>> stage14 = {
        {1.3f, 1.9f, 11.3f, 15.8f, 16.8f, 17.9f},
        {0.0f, 3.7f, 7.1f, 8.5f, 10.0f},
        {2.6f, 4.9f, 5.8f, 12.2f, 12.9f, 14.5f},
    };
    std::vector<std::vector<float>> stage15 = {
        {1.3f, 1.9f, 11.3f, 15.8f, 16.8f, 17.9f},
        {0.0f, 3.7f, 7.1f, 8.5f, 10.0f},
        {2.6f, 4.9f, 5.8f, 12.2f, 12.9f, 14.5f},
    };
    std::vector<std::vector<float>> stage16 = {
        {1.3f, 1.9f, 11.3f, 15.8f, 16.8f, 17.9f},
        {0.0f, 3.7f, 7.1f, 8.5f, 10.0f},
        {2.6f, 4.9f, 5.8f, 12.2f, 12.9f, 14.5f},
    };
    std::vector<std::vector<float>> stage17 = {
        {1.3f, 1.9f, 11.3f, 15.8f, 16.8f, 17.9f},
        {0.0f, 3.7f, 7.1f, 8.5f, 10.0f},
        {2.6f, 4.9f, 5.8f, 12.2f, 12.9f, 14.5f},
    };
    std::vector<std::vector<float>> stage18 = {
        {1.3f, 1.9f, 11.3f, 15.8f, 16.8f, 17.9f},
        {0.0f, 3.7f, 7.1f, 8.5f, 10.0f},
        {2.6f, 4.9f, 5.8f, 12.2f, 12.9f, 14.5f},
    };
    std::vector<std::vector<float>> stage19 = {
        {1.3f, 1.9f, 11.3f, 15.8f, 16.8f, 17.9f},
        {0.0f, 3.7f, 7.1f, 8.5f, 10.0f},
        {2.6f, 4.9f, 5.8f, 12.2f, 12.9f, 14.5f},
    };
    std::vector<std::vector<float>> stage20 = {
        {1.3f, 1.9f, 11.3f, 15.8f, 16.8f, 17.9f},
        {0.0f, 3.7f, 7.1f, 8.5f, 10.0f},
        {2.6f, 4.9f, 5.8f, 12.2f, 12.9f, 14.5f},
    };
    
    this->episode0LevelSetting = {
        stage0, stage1, stage2, stage3, stage4,
        stage5, stage6, stage7, stage8, stage9,
        stage10, stage11, stage12, stage13, stage14,
        stage15, stage16, stage17, stage18, stage19
    };

}

