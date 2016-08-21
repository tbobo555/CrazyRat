#include "LevelDesigner.h"

LevelDeisgner* LevelDeisgner::instance = new LevelDeisgner();

LevelDeisgner::LevelDeisgner(){};

LevelDeisgner* LevelDeisgner::getInstance()
{
    return instance;
}

std::vector<float> LevelDeisgner::loadSweetTimingSetting(int episodeNumber, int stageNumber, int roadNumber)
{
    if (episodeNumber == 0) {
        return this->loadEpisode0SweetTimingSetting(stageNumber, roadNumber);
    }
    if (episodeNumber == 1) {
        return this->loadEpisode1SweetTimingSetting(stageNumber, roadNumber);
    }
    return this->loadEpisode0SweetTimingSetting(stageNumber, roadNumber);
}

std::vector<float> LevelDeisgner::loadIntervalSetting(int episodeNumber, int stageNumber)
{
    std::vector<std::vector<std::vector<float>>> intervalSet = {
        {
            {1, 1}, {1, 1}, {1, 1}, {1, 1}, {1, 1}, {1, 1}, {1, 1}, {1, 1}, {1, 1}, {1, 1},
            {1, 1}, {1, 1}, {1, 1}, {1, 1}, {1, 1}, {1, 1}, {1, 1}, {1, 1}, {1, 1}, {1, 1}
        },
        {
            {1, 1}, {1, 1}, {1, 1}, {1, 1}, {1, 1}, {1, 1}, {1, 1}, {1, 1}, {1, 1}, {1, 1},
            {1, 1}, {1, 1}, {1, 1}, {1, 1}, {1, 1}, {1, 1}, {1, 1}, {1, 1}, {1, 1}, {1, 1}
        }
    };
    
    if (episodeNumber >= intervalSet.size()) {
        char str[100] = {0};
        sprintf(str, "Load Interval Set Failed : setting vector out of bound with episodeNumber: %d", episodeNumber);
        CCASSERT(false, str);
    }
    if (stageNumber >= intervalSet.at(episodeNumber).size()) {
        char str[100] = {0};
        sprintf(str, "Load Interval Set Failed : setting vector out of bound with stageNumber: %d", stageNumber);
        CCASSERT(false, str);
    }
    return intervalSet.at(episodeNumber).at(stageNumber);
    
}

float LevelDeisgner::loadSweetSpeedSetting(int episodeNumber, int stageNumber)
{
    std::vector<std::vector<float>> sweetSpeedSet = {
        {3.0, 2.8, 2.6, 2.5, 2.5, 2.3, 2.3, 2.1, 2.1, 2.0,
         2.0, 2.0, 2.0, 2.0, 2.0, 1.95, 1.95, 1.95, 1.95, 1.95},
        {1.9, 1.9, 1.9, 1.9, 1.9, 1.8, 1.8, 1.8, 1.8, 1.8,
         1.7, 1.68, 1.66, 1.64, 1.62, 1.6, 1.58, 1.56, 1.54, 1.52}
    };
    if (episodeNumber >= sweetSpeedSet.size()) {
        char str[100] = {0};
        sprintf(str, "Load Sweet Speed Set Failed : setting vector out of bound with episodeNumber: %d", episodeNumber);
        CCASSERT(false, str);
    }
    if (stageNumber >= sweetSpeedSet.at(episodeNumber).size()) {
        char str[100] = {0};
        sprintf(str, "Load Sweet Speed Set Failed : setting vector out of bound with stageNumber: %d", stageNumber);
        CCASSERT(false, str);
    }
    
    return sweetSpeedSet.at(episodeNumber).at(stageNumber);
}

float LevelDeisgner::loadGameOverTimeSetting(int episodeNumber, int stageNumber)
{
    std::vector<std::vector<float>> gameOverTimeSet = {
        {30.f, 45.f, 45.f, 45.f, 45.f, 45.f, 45.f, 45.f, 45.f, 45.f,
         60.f, 60.f, 60.f, 60.f, 60.f, 60.f, 60.f, 60.f, 60.f, 60.f},
        {60.f, 60.f, 60.f, 60.f, 60.f, 60.f, 60.f, 60.f, 60.f, 60.f,
         65.f, 65.f, 65.f, 65.f, 65.f, 65.f, 65.f, 65.f, 65.f, 65.f}
    };
    
    if (episodeNumber >= gameOverTimeSet.size()) {
        char str[100] = {0};
        sprintf(str, "Load GameOverTime Setting Failed : setting vector out of bound with episodeNumber: %d", episodeNumber);
        CCASSERT(false, str);
    }
    if (stageNumber >= gameOverTimeSet.at(episodeNumber).size()) {
        char str[100] = {0};
        sprintf(str, "Load GameOverTime Setting Failed : setting vector out of bound with stageNumber: %d", stageNumber);
        CCASSERT(false, str);
    }
    return gameOverTimeSet.at(episodeNumber).at(stageNumber);
}

int LevelDeisgner::loadQuantitySetting(int episodeNumber, int stageNumber)
{
    std::vector<std::vector<int>> quantitySet = {
        {50, 90, 100, 100, 100, 100, 100, 100, 100, 100,
         145, 150, 155, 155, 160, 165, 165, 165, 170, 170},
        {170, 170, 170, 170, 170, 175, 175, 175, 175, 175,
         190, 190, 190, 190, 190, 200, 200, 200, 200, 200}
    };
    
    if (episodeNumber >= quantitySet.size()) {
        char str[100] = {0};
        sprintf(str, "Load Quantity Set  Failed : setting vector out of bound with episodeNumber: %d", episodeNumber);
        CCASSERT(false, str);
    }
    if (stageNumber >= quantitySet.at(episodeNumber).size()) {
        char str[100] = {0};
        sprintf(str, "Load Quantity Set Failed : setting vector out of bound with stageNumber: %d", stageNumber);
        CCASSERT(false, str);
    }
    return quantitySet.at(episodeNumber).at(stageNumber);

}

std::vector<int> LevelDeisgner::loadStarAndScoresSetting(int episodeNumber, int stageNumber)
{
    int quantity = this->loadQuantitySetting(episodeNumber, stageNumber);
    int oneStarScores = std::floor((quantity - 6) * 0.6 * 100);
    int twoStarScores = std::floor(quantity * 100 * 0.8);
    int threeStarScores = std::floor(quantity * 100 * 0.95);
    return {oneStarScores, twoStarScores, threeStarScores};
}


std::vector<std::vector<float>> LevelDeisgner::setSweetTimingByRandom(int episodeNumber, int stageNumber)
{
    // 產生甜點的最後時間為: 總遊戲時間 - 甜點降落時間 - 遊戲破關靜置時間(3秒)
    float totalTime = this->loadGameOverTimeSetting(episodeNumber, stageNumber) - this->loadSweetSpeedSetting(episodeNumber, stageNumber) - 3;
    int quantity = this->loadQuantitySetting(episodeNumber, stageNumber);
    float intervalMin = this->loadIntervalSetting(episodeNumber, stageNumber).at(0);
    float intervalMax = this->loadIntervalSetting(episodeNumber, stageNumber).at(1);
    float sweetSpeed = this->loadSweetSpeedSetting(episodeNumber, stageNumber);
    
    float baseTime = totalTime / (quantity-1);
    std::vector<float> road0;
    std::vector<float> road1;
    std::vector<float> road2;
    
    std::vector<std::vector<float>> randomLevel = {road0, road1, road2};
    this->lastRoadIndex = -1;
    this->lastSweetTime = -1;
    this->sameRoadTimes = 0;
    for (int i = 0; i < quantity; i++) {
        int randomRoad = rand() % 3;
        if (this->lastRoadIndex == randomRoad) {
            this->sameRoadTimes ++;
        } else {
            this->sameRoadTimes = 0;
        }
        
        // 當甜點連續出現在同一路徑3次，強制甜點轉換出現路徑
        if (this->sameRoadTimes >= 3) {
            while (1) {
                randomRoad = rand() % 3;
                if (this->lastRoadIndex != randomRoad) {
                    break;
                }
            }
            this->sameRoadTimes = 0;
        }
        
        double randomIntervalOffset = (double)rand() / RAND_MAX;
        float randomInterval = intervalMin + randomIntervalOffset * (intervalMax - intervalMin);
        float second = (randomInterval + (i-1)) * baseTime;
        
        // 如果秒數間隔小於甜點降落速度的10分之1，會導致甜點重疊，因此必須避免
        if (this->lastRoadIndex == randomRoad && (second - this->lastSweetTime) < sweetSpeed / 10.f) {
            second = this->lastSweetTime + sweetSpeed / 10.f;
        }
        if (i == 0) {
            second = 0;
        }
        randomLevel.at(randomRoad).push_back(second);
        this->lastSweetTime = second;
        this->lastRoadIndex = randomRoad;
    }
    
    return randomLevel;
}

std::vector<float> LevelDeisgner::loadEpisode0SweetTimingSetting(int stageNumber, int roadNumber)
{
    if (this->episode0LevelSetting.size() == 0) {
        this->initEpisode0SweetTimingSetting();
    }
    if (stageNumber < 0 || stageNumber > episode0LevelSetting.size()) {
        char str[100] = {0};
        sprintf(str, "Load Sweet Timing Setting Failed : setting vector out of bound with stageNumber: %d", stageNumber);
        CCASSERT(false, str);
    }
    auto selectedStage = this->episode0LevelSetting.at(stageNumber);
    if (roadNumber < 0 || roadNumber > selectedStage.size()) {
        char str[100] = {0};
        sprintf(str, "Load Sweet Timing Failed : setting vector out of bound with roadNumber: %d", roadNumber);
        CCASSERT(false, str);
    }

    return selectedStage.at(roadNumber);
}

std::vector<float> LevelDeisgner::loadEpisode1SweetTimingSetting(int stageNumber, int roadNumber)
{
    if (this->episode1LevelSetting.size() == 0) {
        this->initEpisode1SweetTimingSetting();
    }
    if (stageNumber < 0 || stageNumber > episode1LevelSetting.size()) {
        char str[100] = {0};
        sprintf(str, "Load Sweet Timing Setting Failed : setting vector out of bound with stageNumber: %d", stageNumber);
        CCASSERT(false, str);
    }
    auto selectedStage = this->episode1LevelSetting.at(stageNumber);
    if (roadNumber < 0 || roadNumber > selectedStage.size()) {
        char str[100] = {0};
        sprintf(str, "Load Sweet Timing Failed : setting vector out of bound with roadNumber: %d", roadNumber);
        CCASSERT(false, str);
    }
    
    return selectedStage.at(roadNumber);
}


void LevelDeisgner::initEpisode0SweetTimingSetting()
{
    std::vector<std::vector<float>> stage0 = this->setSweetTimingByRandom(0, 0);
    std::vector<std::vector<float>> stage1 = this->setSweetTimingByRandom(0, 1);
    std::vector<std::vector<float>> stage2 = this->setSweetTimingByRandom(0, 2);
    std::vector<std::vector<float>> stage3 = this->setSweetTimingByRandom(0, 3);
    std::vector<std::vector<float>> stage4 = this->setSweetTimingByRandom(0, 4);
    std::vector<std::vector<float>> stage5 = this->setSweetTimingByRandom(0, 5);
    std::vector<std::vector<float>> stage6 = this->setSweetTimingByRandom(0, 6);
    std::vector<std::vector<float>> stage7 = this->setSweetTimingByRandom(0, 7);
    std::vector<std::vector<float>> stage8 = this->setSweetTimingByRandom(0, 8);
    std::vector<std::vector<float>> stage9 = this->setSweetTimingByRandom(0, 9);
    std::vector<std::vector<float>> stage10 = this->setSweetTimingByRandom(0, 10);
    std::vector<std::vector<float>> stage11 = this->setSweetTimingByRandom(0, 11);
    std::vector<std::vector<float>> stage12 = this->setSweetTimingByRandom(0, 12);
    std::vector<std::vector<float>> stage13 = this->setSweetTimingByRandom(0, 13);
    std::vector<std::vector<float>> stage14 = this->setSweetTimingByRandom(0, 14);
    std::vector<std::vector<float>> stage15 = this->setSweetTimingByRandom(0, 15);
    std::vector<std::vector<float>> stage16 = this->setSweetTimingByRandom(0, 16);
    std::vector<std::vector<float>> stage17 = this->setSweetTimingByRandom(0, 17);
    std::vector<std::vector<float>> stage18 = this->setSweetTimingByRandom(0, 18);
    std::vector<std::vector<float>> stage19 = this->setSweetTimingByRandom(0, 19);
    this->episode0LevelSetting = {
        stage0, stage1, stage2, stage3, stage4,
        stage5, stage6, stage7, stage8, stage9,
        stage10, stage11, stage12, stage13, stage14,
        stage15, stage16, stage17, stage18, stage19
    };

}

void LevelDeisgner::initEpisode1SweetTimingSetting()
{
    std::vector<std::vector<float>> stage0 = this->setSweetTimingByRandom(1, 0);
    std::vector<std::vector<float>> stage1 = this->setSweetTimingByRandom(1, 1);
    std::vector<std::vector<float>> stage2 = this->setSweetTimingByRandom(1, 2);
    std::vector<std::vector<float>> stage3 = this->setSweetTimingByRandom(1, 3);
    std::vector<std::vector<float>> stage4 = this->setSweetTimingByRandom(1, 4);
    std::vector<std::vector<float>> stage5 = this->setSweetTimingByRandom(1, 5);
    std::vector<std::vector<float>> stage6 = this->setSweetTimingByRandom(1, 6);
    std::vector<std::vector<float>> stage7 = this->setSweetTimingByRandom(1, 7);
    std::vector<std::vector<float>> stage8 = this->setSweetTimingByRandom(1, 8);
    std::vector<std::vector<float>> stage9 = this->setSweetTimingByRandom(1, 9);
    std::vector<std::vector<float>> stage10 = this->setSweetTimingByRandom(1, 10);
    std::vector<std::vector<float>> stage11 = this->setSweetTimingByRandom(1, 11);
    std::vector<std::vector<float>> stage12 = this->setSweetTimingByRandom(1, 12);
    std::vector<std::vector<float>> stage13 = this->setSweetTimingByRandom(1, 13);
    std::vector<std::vector<float>> stage14 = this->setSweetTimingByRandom(1, 14);
    std::vector<std::vector<float>> stage15 = this->setSweetTimingByRandom(1, 15);
    std::vector<std::vector<float>> stage16 = this->setSweetTimingByRandom(1, 16);
    std::vector<std::vector<float>> stage17 = this->setSweetTimingByRandom(1, 17);
    std::vector<std::vector<float>> stage18 = this->setSweetTimingByRandom(1, 18);
    std::vector<std::vector<float>> stage19 = this->setSweetTimingByRandom(1, 19);
    this->episode1LevelSetting = {
        stage0, stage1, stage2, stage3, stage4,
        stage5, stage6, stage7, stage8, stage9,
        stage10, stage11, stage12, stage13, stage14,
        stage15, stage16, stage17, stage18, stage19
    };
    
}

