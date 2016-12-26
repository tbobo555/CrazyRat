#include "PlayBaseScene.h"

namespace  GameScene
{
    PlayBaseScene::PlayBaseScene() : GameScene::BaseScene(){}
    void PlayBaseScene::initScene(){}
    void PlayBaseScene::releaseScene(){}
    void PlayBaseScene::play(){}
    void PlayBaseScene::pauseScene(){}
    void PlayBaseScene::resumeScene(){}
    void PlayBaseScene::addWinScene(){}
    void PlayBaseScene::addLoseScene(){}
    void PlayBaseScene::updateScoreBarStar(){}
    void PlayBaseScene::gameUpdate(){}
    void PlayBaseScene::road0Update(float delta){}
    void PlayBaseScene::road1Update(float delta){}
    void PlayBaseScene::road2Update(float delta){}
    void PlayBaseScene::prepareUpdate(float delta){}
    void PlayBaseScene::prepareDone(){}
    
    int  PlayBaseScene::getNearestSweetIndex(int road)
    {
        if (road == 0 && ! this->road0RunningIndex.empty()) {
            return this->road0RunningIndex.front();
        } else if (road == 1 && ! this->road1RunningIndex.empty()) {
            return this->road1RunningIndex.front();
        } else if (road == 2 && ! this->road2RunningIndex.empty()) {
            return this->road2RunningIndex.front();
        } else {
            return -1;
        }
    }
    
    GameSprite::Sweet* PlayBaseScene::getNearestSweet(int road)
    {
        if (road == 0 && ! this->road0RunningIndex.empty()) {
            return this->road0SweetVector.at(this->road0RunningIndex.front());
        } else if (road == 1 && ! this->road1RunningIndex.empty()) {
            return this->road1SweetVector.at(this->road1RunningIndex.front());
        } else if (road == 2 && ! this->road2RunningIndex.empty()) {
            return this->road2SweetVector.at(this->road2RunningIndex.front());
        } else {
            return nullptr;
        }
    }

    void PlayBaseScene::changeDeadExplode()
    {
        int x = rand() % 5;
        char str[100] = {0};
        sprintf(str, "image/Explode%d.png", x);
        TextureCreator* textureCreator = TextureCreator::getInstance();
        Texture2D* texutre = textureCreator->getAutoSizeTexture2d(str);
        int randomNumber = rand() % 7;
        std::stringstream punchName;
        punchName << "audio/sounds/Punch" << randomNumber << ".caf";
        Manager::SoundsManager::getInstance()->playSound(punchName.str().c_str());
        this->deadExplode->setTexture(texutre);
    }
    
    void PlayBaseScene::showDeadPig()
    {
        this->deadPig = new GameSprite::Image(this->getDeadPigImagePath());
        this->deadPig->setPosition(this->getFailedPig()->getPosition());
        this->addChild(this->deadPig, 2);
    }
    
    void PlayBaseScene::showGhost()
    {
        auto pig = this->getFailedPig();
        this->ghost->setPosition(Vec2(pig->getPositionX(), pig->getPositionY() + 50));
        this->addChild(this->ghost, 5);
        Manager::SoundsManager::getInstance()->playSound("audio/sounds/GhostFly.caf");
        this->ghost->runAction(Sequence::create(MoveBy::create(1.f, Vec2(0, 250)), FadeOut::create(0.1f), NULL));
    }
    
    void PlayBaseScene::showFailAnimation()
    {
        int x = rand() % 5;
        char str[100] = {0};
        sprintf(str, "image/Explode%d.png", x);
        this->deadExplode = new GameSprite::Image(str);
        this->deadExplode->setPosition(Vec2(this->getFailedPig()->getPositionX(),
                                            this->getFailedPig()->getPositionY() + 50));
        this->addChild(this->deadExplode, 3);
        int randomNumber = rand() % 7;
        std::stringstream punchName;
        punchName << "audio/sounds/Punch" << randomNumber << ".caf";
        Manager::SoundsManager::getInstance()->playSound(punchName.str().c_str());
        
        this->deadExplode->runAction(Sequence::create(CallFunc::create(CC_CALLBACK_0(PlayBaseScene::showDeadPig, this)),
                                                      DelayTime::create(0.3f),
                                                      CallFunc::create(CC_CALLBACK_0(PlayBaseScene::changeDeadExplode, this)),
                                                      MoveBy::create(0.0f, Vec2(-50, -50)),
                                                      DelayTime::create(0.3f),
                                                      CallFunc::create(CC_CALLBACK_0(PlayBaseScene::changeDeadExplode, this)),
                                                      MoveBy::create(0.0f, Vec2(100, 0)),
                                                      DelayTime::create(0.3f),
                                                      FadeOut::create(0.0f),
                                                      CallFunc::create(CC_CALLBACK_0(PlayBaseScene::showGhost, this)),
                                                      DelayTime::create(1.5f),
                                                      CallFunc::create(CC_CALLBACK_0(PlayBaseScene::addLoseScene, this)),
                                                      NULL));
    }

    std::string PlayBaseScene::getDeadPigImagePath()
    {
        std::string deadImagePath;
        switch (this->failRoadIndex) {
            case 0:
                deadImagePath = "image/DeadPig0.png";
                break;
            case 1:
                deadImagePath = "image/DeadPig1.png";
                break;
            case 2:
                deadImagePath = "image/DeadPig2.png";
                break;
            default:
                deadImagePath = "image/DeadPig0.png";
                break;
        }
        return deadImagePath;
    }
    
    GameSprite::Pig* PlayBaseScene::getFailedPig()
    {
        GameSprite::Pig* pig;
        switch (this->failRoadIndex) {
            case 0:
                pig = this->road0Pig;
                break;
            case 1:
                pig = this->road1Pig;
                break;
            case 2:
                pig = this->road2Pig;
                break;
            default:
                pig = this->road0Pig;
                break;
        }
        return pig;
    }
    
    void PlayBaseScene::removePrepareNumber()
    {
        this->removeChild(this->prepareNumber);
    }
    
    Vec2 PlayBaseScene::getBackgroundPosition()
    {
        return this->center;
    }
    
    void PlayBaseScene::bossHurted()
    {
        this->bossIsHurting = true;
        if (this->addSweetRoad != -1) {
            this->resetBossRoad = this->addSweetRoad;
            
        } else {
            this->resetBossRoad = rand() % 3;
        }
        this->addSweetRoad = -1;
        this->boss->stopAllActions();
        this->boss->runAction(Sequence::create(
                                               DelayTime::create(0.5f),
                                               MoveTo::create(0.6f, this->getCloudPosition(this->resetBossRoad)),
                                               CallFunc::create(CC_CALLBACK_0(PlayBaseScene::resetBossMotion, this)),
                                               CallFunc::create(CC_CALLBACK_0(PlayBaseScene::setBossNotHurt, this)),
                                               NULL));
    }
    
    void PlayBaseScene::resetBossMotion()
    {
        this->playTime = 0;
        this->addSweetRoad = this->resetBossRoad;
    }
    
    void PlayBaseScene::setBossNotHurt()
    {
        this->bossIsHurting = false;
    }
    
    Vec2 PlayBaseScene::getPigPosition(int roadNumber)
    {
        float height = Director::getInstance()->getWinSize().height;
        std::vector<Vec2> pigPositionSet = {
            Vec2(this->center.x - 365, 0.24 * height),
            Vec2(this->center.x, 0.24 * height),
            Vec2(this->center.x + 365, 0.24 * height),
        };
        return pigPositionSet.at(roadNumber);
    }
    
    Vec2 PlayBaseScene::getEatBlockPosition(int roadNumber)
    {
        float height = Director::getInstance()->getWinSize().height;
        std::vector<Vec2> pigPositionSet = {
            Vec2(this->center.x - 365, 0.24 * height + 200),
            Vec2(this->center.x, 0.24 * height + 200),
            Vec2(this->center.x + 365, 0.24 * height + 200),
        };
        return pigPositionSet.at(roadNumber);
    }
    
    Vec2 PlayBaseScene::getCloudPosition(int roadNumber)
    {
        std::vector<Vec2> cloudPositionSet = {
            Vec2(this->center.x - 365, this->visibleOrigin.y + 0.87 * this->visibleSize.height),
            Vec2(this->center.x, this->visibleOrigin.y + 0.87 * this->visibleSize.height),
            Vec2(this->center.x + 365, this->visibleOrigin.y + 0.87 * this->visibleSize.height),
        };
        return cloudPositionSet.at(roadNumber);
    }
    
    Vec2 PlayBaseScene::getSweetPosition(int roadNumber)
    {
        std::vector<Vec2> sweetPositionSet = {
            Vec2(this->center.x - 365, this->visibleOrigin.y + 0.87 * this->visibleSize.height),
            Vec2(this->center.x, this->visibleOrigin.y + 0.87 * this->visibleSize.height),
            Vec2(this->center.x + 365, this->visibleOrigin.y + 0.87 * this->visibleSize.height),
        };
        return sweetPositionSet.at(roadNumber);
    }
    
    Vec2 PlayBaseScene::getScoreHaloPosition()
    {
        return Vec2(925, this->visibleOrigin.y + this->visibleSize.height - this->visibleSize.width / 11);
    }
    
    Vec2 PlayBaseScene::getScoresPosition()
    {
        return Vec2(925, this->visibleOrigin.y + this->visibleSize.height - this->visibleSize.width / 11 - 15);
    }
}
