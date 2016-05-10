#include "StageButton.h"
#include "Controller/GameController.h"

namespace GameSprite
{
    StageButton::StageButton(std::string image, int pMapNumber, int pStageNumber) : GameSprite::BaseSprite(image)
    {
        this->isLocked = false;
        this->mapNumber = pMapNumber;
        this->stageNumber = pStageNumber;
        this->addEventListener();
    }
    
    void StageButton::locked()
    {
        if (this->isLocked == false) {
            this->isLocked = true;
            TextureCreator* textureCreator = TextureCreator::getInstance();
            std::string lockedStageButtonImage = "image/StageLockedButton.png";
            Texture2D* lockedTexutre =
            textureCreator->getAutoSizeTexture2d(lockedStageButtonImage);
            this->setTexture(lockedTexutre);
            Director::getInstance()->getEventDispatcher()->removeEventListenersForTarget(this);
        }
    }
    
    void StageButton::unlocked()
    {
        if (this->isLocked == true) {
            this->isLocked = false;
            TextureCreator* textureCreator = TextureCreator::getInstance();
            std::stringstream stagePath;
            stagePath << "image/StageButton_" << this->stageNumber << ".png";
            Texture2D* texutre = textureCreator->getAutoSizeTexture2d(stagePath.str());
            this->setTexture(texutre);
            this->addEventListener();
        }
    }
    
    void StageButton::addEventListener()
    {
        auto listener = EventListenerTouchOneByOne::create();
        listener->setSwallowTouches(true);
        listener->onTouchBegan = StageButton::onTouchBegan;
        listener->onTouchEnded = StageButton::onTouchEnded;
        listener->onTouchMoved = StageButton::onTouchMoved;
        listener->onTouchCancelled = StageButton::onTouchCanceled;
        Director::getInstance()->getEventDispatcher()
        ->addEventListenerWithSceneGraphPriority(listener, this);
    }
    
    bool StageButton::onTouchBegan(Touch *touch, Event *event)
    {
        auto target = static_cast<Sprite*>(event->getCurrentTarget());
        Vec2 locationInNode = target->convertToNodeSpace(touch->getLocation());
        Size s = target->getContentSize();
        Rect rect = Rect(0, 0, s.width, s.height);
        
        if (rect.containsPoint(locationInNode)) {
            log("StageButton began... x = %f, y = %f", locationInNode.x, locationInNode.y);
            target->setScale(1.2);
            return true;
        }
        return false;
    }
    
    void StageButton::onTouchEnded(Touch *touch, Event *event)
    {
        auto target = static_cast<StageButton*>(event->getCurrentTarget());
        Vec2 locationInNode = target->convertToNodeSpace(touch->getLocation());
        Size s = target->getContentSize();
        Rect rect = Rect(0, 0, s.width, s.height);
        if (rect.containsPoint(locationInNode)) {
            auto controller = Controller::GameController::getInstance();
            log("StageButton ended... x = %f, y = %f", locationInNode.x, locationInNode.y);
            target->setScale(1.0);
            controller->MapSceneToPlayScene(target->mapNumber, target->stageNumber);
        } else {
            target->setScale(1.0);
        }
    }
    
    void StageButton::onTouchMoved(Touch *touch, Event *event)
    {
    }

    void StageButton::onTouchCanceled(Touch *touch, Event *event)
    {
        auto target = static_cast<Sprite*>(event->getCurrentTarget());
        target->setScale(1.0);
    }
    
}
