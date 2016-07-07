#ifndef _Manager_ScoresManager_H_
#define _Manager_ScoresManager_H_

#include "cocos2d.h"

USING_NS_CC;

namespace Manager
{
    class ScoresManager
    {
    public:
        static ScoresManager* getInstance();
        Label* getScoresLabel();
        void initScores();
        int getScores();
        void setScores(int newScores);
        void addScores(int points);
        void resetScores();
        void releaseScores();
    private:
        ScoresManager();
        Label* scores;
        static ScoresManager* instance;
    };
}

#endif /* _Manager_ScoresManager_H_ */
