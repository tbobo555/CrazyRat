#include "EpisodeButton.h"
#include "Controller/GameController.h"

namespace GameSprite
{
    EpisodeButton::EpisodeButton(std::string image, int episodeNumber) : GameSprite::BaseSprite(image)
    {
        this->isLocked = false;
        this->episodeNumber = episodeNumber;
        this->addEventListener();
    }
    
    void EpisodeButton::locked()
    {
        if (this->isLocked == false) {
            std::stringstream filePath;
            filePath << "image/EpisodeLockedButton_" << this->episodeNumber << ".png";
            this->isLocked = true;
            TextureCreator* textureCreator = TextureCreator::getInstance();
            Texture2D* lockedTexutre = textureCreator->getAutoSizeTexture2d(filePath.str());
            this->setTexture(lockedTexutre);
            Director::getInstance()->getEventDispatcher()->removeEventListenersForTarget(this);
        }
    }
    
    void EpisodeButton::unlocked()
    {
        if (this->isLocked == true) {
            std::stringstream filePath;
            filePath << "image/EpisodeButton_" << this->episodeNumber << ".png";
            this->isLocked = false;
            TextureCreator* textureCreator = TextureCreator::getInstance();
            Texture2D* texutre = textureCreator->getAutoSizeTexture2d(filePath.str());
            this->setTexture(texutre);
            this->addEventListener();
        }
    }
    
    void EpisodeButton::addEventListener()
    {
        auto listener = EventListenerTouchOneByOne::create();
        listener->setSwallowTouches(true);
        listener->onTouchBegan = EpisodeButton::onTouchBegan;
        listener->onTouchEnded = EpisodeButton::onTouchEnded;
        listener->onTouchMoved = EpisodeButton::onTouchMoved;
        listener->onTouchCancelled = EpisodeButton::onTouchCanceled;
        Director::getInstance()->getEventDispatcher()
        ->addEventListenerWithSceneGraphPriority(listener, this);
    }
    
    bool EpisodeButton::onTouchBegan(Touch *touch, Event *event)
    {
        auto target = static_cast<Sprite*>(event->getCurrentTarget());
        Vec2 locationInNode = target->convertToNodeSpace(touch->getLocation());
        Size s = target->getContentSize();
        Rect rect = Rect(0, 0, s.width, s.height);
        
        if (rect.containsPoint(locationInNode)) {
            log("episode began... x = %f, y = %f", locationInNode.x, locationInNode.y);
            target->setScale(1.2);
            return true;
        }
        return false;
    }
    
    void EpisodeButton::onTouchEnded(Touch *touch, Event *event)
    {
        auto target = static_cast<EpisodeButton*>(event->getCurrentTarget());
        Vec2 locationInNode = target->convertToNodeSpace(touch->getLocation());
        Size s = target->getContentSize();
        Rect rect = Rect(0, 0, s.width, s.height);
        if (rect.containsPoint(locationInNode)) {
            log("EpisodeButton ended... x = %f, y = %f", locationInNode.x, locationInNode.y);
            target->setScale(1.0);
            Controller::GameController::getInstance()->selectionSceneToEpisodeScene(target->episodeNumber);
        } else {
            target->setScale(1.0);
        }
    }
    
    void EpisodeButton::onTouchMoved(Touch *touch, Event *event)
    {
    }
    
    void EpisodeButton::onTouchCanceled(Touch *touch, Event *event)
    {
        auto target = static_cast<Sprite*>(event->getCurrentTarget());
        target->setScale(1.0);
        log("episode onTouchCanceled..");
    }

}
