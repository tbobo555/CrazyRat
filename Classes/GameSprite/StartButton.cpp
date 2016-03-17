#include "StartButton.h"
#include "Controller/GameController.h"

namespace GameSprite
{
    const std::string StartButton::originImage = ImageConfig::getInstance()->getImagePath("StartButton");
    
    StartButton::StartButton() : GameSprite::BaseSprite(StartButton::originImage)
    {
        this->sprite->setPosition(PositionConfig::getInstance()->getBasePsotion("StartButton"));
        this->addEventListener();
    }
    
    void StartButton::addEventListener()
    {
        auto listener = EventListenerTouchOneByOne::create();
        listener->setSwallowTouches(true);
        listener->onTouchBegan = StartButton::onTouchBegan;
        listener->onTouchEnded = StartButton::onTouchEnded;
        listener->onTouchMoved = StartButton::onTouchMoved;
        listener->onTouchCancelled = StartButton::onTouchCanceled;
        Director::getInstance()->getEventDispatcher()
        ->addEventListenerWithSceneGraphPriority(listener, this->sprite);
    }
    
    bool StartButton::onTouchBegan(Touch* touch, Event* event)
    {
        auto target = static_cast<Sprite*>(event->getCurrentTarget());
        Vec2 locationInNode = target->convertToNodeSpace(touch->getLocation());
        Size s = target->getContentSize();
        Rect rect = Rect(0, 0, s.width, s.height);
        
        if (rect.containsPoint(locationInNode)) {
            log("Win Size: %f  %f",
                Director::getInstance()->getWinSize().width, Director::getInstance()->getWinSize().height);
            log("Win Size In pixels: %f  %f",
                Director::getInstance()->getWinSizeInPixels().width,
                Director::getInstance()->getWinSizeInPixels().height);
            log("View Size: %f  %f",
                Director::getInstance()->getVisibleSize().width,
                Director::getInstance()->getVisibleSize().height);
            log("opengl Size: %f  %f",
                Director::getInstance()->getOpenGLView()->getFrameSize().width,
                Director::getInstance()->getOpenGLView()->getFrameSize().height);
            log("contetn factor: %f  ", Director::getInstance()->getContentScaleFactor());
            log("StartButton began... x = %f, y = %f", locationInNode.x, locationInNode.y);
            target->setScale(1.2);
            return true;
        }
        return false;
    }
    
    void StartButton::onTouchEnded(Touch* touch, Event* event)
    {
        auto target = static_cast<Sprite*>(event->getCurrentTarget());
        target->setScale(1.0);
        Controller::GameController::getInstance()->startSceneToSelectionScene();
    }
    
    void StartButton::onTouchMoved(Touch* touch, Event* event)
    {
    }

    void StartButton::onTouchCanceled(Touch* touch, Event* event)
    {
        auto target = static_cast<Sprite*>(event->getCurrentTarget());
        target->setScale(1.0);
    }
    
}
