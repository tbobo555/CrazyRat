#include "SelectionScene.h"

namespace GameScene
{
    SelectionScene::SelectionScene(){}
    
    void SelectionScene::initScene()
    {
        this->scene->addChild(this->selectionBackground->getCCSprite(), 0);
        for (int i = 0; i < this->stageButtonVector.size(); i++) {
            this->scene->addChild(this->stageButtonVector[i]->getCCSprite(), 2);
        }
        for (int i = 0; i < this->starVector.size(); i++) {
            this->scene->addChild(this->starVector[i]->getCCSprite(), 2);
        }
        this->scene->addChild(this->master->getCCSprite(), 3);
        this->setMasterPosition();
        this->setStageDisplay();
        this->setStarDisplay();
    }
    
    void SelectionScene::setStageDisplay()
    {
        int currentStage = DB::CommonSetting::currentStage;
        for (int i = 0; i <= currentStage; i++) {
            std::stringstream key;
            key << "Stage" << i + 1;
            Vec2 position = PositionConfig::getInstance()->getStagePosition(key.str());
            this->stageButtonVector[i]->getCCSprite()->setPosition(position);
        }
        
        for (int i = currentStage + 1; i < this->stageButtonVector.size(); i++) {
            std::stringstream key;
            key << "Stage" << i + 1;
            Vec2 position = PositionConfig::getInstance()->getStagePosition(key.str());
            Texture2D* texture = TextureCreator::getInstance()
            ->getAutoSizeTexture2d(ImageConfig::getInstance()->getImagePath("StageLockedButton"));
            this->stageButtonVector[i]->getCCSprite()->setPosition(position);
            this->stageButtonVector[i]->getCCSprite()->setTexture(texture);
        }
    }
    
    void SelectionScene::setStarDisplay()
    {
        int currentStage = DB::CommonSetting::currentStage;
        std::vector<int> starNumberVector = DB::CommonSetting::starOfStage;
        for (int i = 0; i < currentStage-1; i++) {
            std::stringstream key;
            key << "Stage" << i + 1;
            for (int x = 1; x <= starNumberVector[i]; x++) {
                Vec2 position = PositionConfig::getInstance()->getStagePosition(key.str());
                position.y += 50;
                switch (x) {
                    case 1:
                        position.x -= 35;
                        break;
                    case 2:
                        break;
                    case 3:
                        position.x += 35;
                        break;
                    default:
                        break;
                }
                this->starVector[(i*3)+(x-1)]->getCCSprite()->setPosition(position);
            }
        }
    }
    
    void SelectionScene::setMasterPosition()
    {
        int currentStage = DB::CommonSetting::currentStage;
        std::stringstream key;
        key << "Stage" << currentStage ;
        Vec2 position = PositionConfig::getInstance()->getStagePosition(key.str());
        this->master->getCCSprite()->setPosition(Vec2(position.x, position.y+100));
    }
}
