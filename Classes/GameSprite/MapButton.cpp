#include "MapButton.h"
#include "Controller/GameController.h"

namespace GameSprite
{
    MapButton::MapButton(std::string image, int mapNumber) : GameSprite::BaseSprite(image)
    {
        this->isLocked = false;
        this->mapNumber = mapNumber;
        this->addEventListener();
    }
    
    void MapButton::locked()
    {
        if (this->isLocked == false) {
            std::stringstream filePath;
            filePath << "image/EpisodeLockedButton_" << this->mapNumber << ".png";
            this->isLocked = true;
            TextureCreator* textureCreator = TextureCreator::getInstance();
            Texture2D* lockedTexutre = textureCreator->getAutoSizeTexture2d(filePath.str());
            this->setTexture(lockedTexutre);
            Director::getInstance()->getEventDispatcher()->removeEventListenersForTarget(this);
        }
    }
    
    void MapButton::unlocked()
    {
        if (this->isLocked == true) {
            std::stringstream filePath;
            filePath << "image/EpisodeButton_" << this->mapNumber << ".png";
            this->isLocked = false;
            TextureCreator* textureCreator = TextureCreator::getInstance();
            Texture2D* texutre = textureCreator->getAutoSizeTexture2d(filePath.str());
            this->setTexture(texutre);
            this->addEventListener();
        }
    }
    
    void MapButton::addEventListener()
    {
        auto listener = EventListenerTouchOneByOne::create();
        listener->setSwallowTouches(true);
        listener->onTouchBegan = MapButton::onTouchBegan;
        listener->onTouchEnded = MapButton::onTouchEnded;
        listener->onTouchMoved = MapButton::onTouchMoved;
        listener->onTouchCancelled = MapButton::onTouchCanceled;
        Director::getInstance()->getEventDispatcher()
        ->addEventListenerWithSceneGraphPriority(listener, this);
    }
    
    bool MapButton::onTouchBegan(Touch *touch, Event *event)
    {
        auto target = static_cast<Sprite*>(event->getCurrentTarget());
        Vec2 locationInNode = target->convertToNodeSpace(touch->getLocation());
        Size s = target->getContentSize();
        Rect rect = Rect(0, 0, s.width, s.height);
        
        if (rect.containsPoint(locationInNode)) {
            log("map began... x = %f, y = %f", locationInNode.x, locationInNode.y);
            target->setScale(1.2);
            return true;
        }
        return false;
    }
    
    void MapButton::onTouchEnded(Touch *touch, Event *event)
    {
        auto target = static_cast<MapButton*>(event->getCurrentTarget());
        Vec2 locationInNode = target->convertToNodeSpace(touch->getLocation());
        Size s = target->getContentSize();
        Rect rect = Rect(0, 0, s.width, s.height);
        if (rect.containsPoint(locationInNode)) {
            log("MapButton ended... x = %f, y = %f", locationInNode.x, locationInNode.y);
            target->setScale(1.0);
            Controller::GameController::getInstance()->selectionSceneToMapScene(target->mapNumber);
        } else {
            target->setScale(1.0);
        }
    }
    
    void MapButton::onTouchMoved(Touch *touch, Event *event)
    {
    }
    
    void MapButton::onTouchCanceled(Touch *touch, Event *event)
    {
        auto target = static_cast<Sprite*>(event->getCurrentTarget());
        target->setScale(1.0);
        log("map onTouchCanceled..");
    }

}
