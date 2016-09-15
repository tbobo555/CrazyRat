#include "CareerButton.h"
#include "Controller/GameController.h"

namespace GameSprite
{
    CareerButton::CareerButton(std::string image) : GameSprite::BaseSprite(image)
    {
        this->addEventListener();
    }
    
    void CareerButton::addEventListener()
    {
        auto listener = EventListenerTouchOneByOne::create();
        listener->setSwallowTouches(true);
        listener->onTouchBegan = CareerButton::onTouchBegan;
        listener->onTouchEnded = CareerButton::onTouchEnded;
        listener->onTouchMoved = CareerButton::onTouchMoved;
        listener->onTouchCancelled = CareerButton::onTouchCanceled;
        Director::getInstance()->getEventDispatcher()
        ->addEventListenerWithSceneGraphPriority(listener, this);        
    }
    
    bool CareerButton::onTouchBegan(Touch* touch, Event* event)
    {
        auto target = static_cast<Sprite*>(event->getCurrentTarget());
        Vec2 locationInNode = target->convertToNodeSpace(touch->getLocation());
        Size s = target->getContentSize();
        Rect rect = Rect(0, 0, s.width, s.height);

        if (rect.containsPoint(locationInNode)) {
            Manager::SoundsManager::getInstance()->playSound("audio/sounds/ButtonClick.caf");
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
            log("CareerButton began... x = %f, y = %f", locationInNode.x, locationInNode.y);
            target->setScale(0.95);
            return true;
        }
        return false;
    }
    
    void CareerButton::onTouchEnded(Touch* touch, Event* event)
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
            log("CareerButton began... x = %f, y = %f", locationInNode.x, locationInNode.y);
            target->setScale(1.0);
            Controller::GameController::getInstance()->startSceneToSelectionScene();
        } else {
            target->setScale(1.0);
        }
    }
    
    void CareerButton::onTouchMoved(Touch* touch, Event* event)
    {
    }

    void CareerButton::onTouchCanceled(Touch* touch, Event* event)
    {
        auto target = static_cast<Sprite*>(event->getCurrentTarget());
        target->setScale(1.0);
    }
    
}
