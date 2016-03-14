#include "GameConfig.h"

GameConfig* GameConfig::instance;

GameConfig::GameConfig(){}

GameConfig* GameConfig::getInstance()
{
    return instance;
}
