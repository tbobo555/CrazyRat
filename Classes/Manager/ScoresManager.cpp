#include "ScoresManager.h"
#include "GameScene/PlayBaseScene.h"

namespace Manager
{
    ScoresManager* ScoresManager::instance = new ScoresManager();
    
    ScoresManager::ScoresManager()
    {
    }
    
    void ScoresManager::initScores()
    {
        this->scores = Label::createWithTTF("0", "fonts/KOMIKAX.ttf", 60);
        this->scores->retain();
    }
    
    ScoresManager* ScoresManager::getInstance()
    {
        return instance;
    }
    
    Label* ScoresManager::getScoresLabel()
    {
        return this->scores;
    }
    
    int ScoresManager::getScores()
    {
        std::stringstream buff;
        std::string numberStr = this->scores->getString();
        int scores;
        buff << numberStr;
        buff >> scores;
        buff.str("");
        buff.clear();
        return scores;
    }
    
    void ScoresManager::setScores(int newScores)
    {
        std::stringstream buff;
        buff << newScores;
        this->scores->setString(buff.str());
        buff.str("");
        buff.clear();
    }
    
    void ScoresManager::addScores(int points)
    {
        std::stringstream buff;
        std::string numberStr = this->scores->getString();
        int scores;
        buff << numberStr;
        buff >> scores;
        scores += points;
        buff.str("");
        buff.clear();
        buff << scores;
        this->scores->setString(buff.str());
        buff.str("");
        buff.clear();
        auto currentScene = static_cast<PlayBaseScene*>(Manager::SceneManager::getInstance()->getCurrent());
        std::stringstream haloKeyName;
        if (currentScene->name == "PlayInfiniteScene") {
            haloKeyName << "PlayInfiniteScene_ScoreHalo";
        } else if (currentScene->name == "ChallengePlayScene") {
            return;
        }
        else {
            haloKeyName << "PlayScene_ScoreHalo";
        }
        auto scoreHalo = Manager::SpriteManager::getInstance()->getByKey(haloKeyName.str());
        scoreHalo->cleanup();
        scoreHalo->setOpacity(0);
        auto fadeIn = FadeIn::create(0.1f);
        scoreHalo->runAction(Sequence::create(fadeIn, fadeIn->reverse(), NULL));
        currentScene->updateScoreBarStar();
    }
    
    void ScoresManager::resetScores()
    {
        this->scores->setString("0");
    }
    
    void ScoresManager::releaseScores()
    {
        this->scores->release();
    }

}


