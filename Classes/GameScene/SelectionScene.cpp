#include "SelectionScene.h"

namespace GameScene
{
    SelectionScene::SelectionScene(){}
    
    void SelectionScene::initScene()
    {
        this->scene->addChild(this->selectionBg->getCCSprite(), 0);
        for (int i = 0; i < this->stageButtonVector.size(); i++) {
            this->scene->addChild(this->stageButtonVector[i]->getCCSprite(), 2);
        }
        for (int i = 0; i < this->starSpriteVector.size(); i++) {
            this->scene->addChild(this->starSpriteVector[i]->getCCSprite(), 2);
        }
        this->scene->addChild(this->masterSprite->getCCSprite(), 3);
        this->setMasterPosition();
        this->setStageDisplay();
        this->setStarDisplay();
    }
    
    void SelectionScene::setStageDisplay()
    {
        for (int i = 0; i < this->stageButtonVector.size(); i++) {
            std::stringstream key;
            key << "Stage" << i + 1;
            Vec2 position = PositionConfig::getInstance()->getStagePosition(key.str());
            this->stageButtonVector[i]->getCCSprite()->setPosition(position);
        }
    }
    
    void SelectionScene::setStarDisplay()
    {
        for (int i = 0; i < this->starSpriteVector.size(); i++) {
            std::stringstream key;
            int num = i / 3;
            key << "Stage" << num + 1;
            Vec2 position = PositionConfig::getInstance()->getStagePosition(key.str());
            position.y += 50;
            
            switch (i % 3) {
                case 0:
                    position.x -= 35;
                    break;
                case 1:
                    break;
                case 2:
                    position.x += 35;
                    break;
                default:
                    break;
            }
            this->starSpriteVector[i]->getCCSprite()->setPosition(position);
        }
    }
    
    void SelectionScene::setMasterPosition()
    {
        Vec2 position = PositionConfig::getInstance()->getStagePosition("Stage2");
        this->masterSprite->getCCSprite()->setPosition(Vec2(position.x, position.y+100));
    }
}
