#include "DonateMoneyButton.h"

namespace GameSprite
{
    DonateMoneyButton::DonateMoneyButton(std::string image, int money) : GameSprite::BaseSprite(image)
    {
        this->isSetLocalCurrency = false;
        this->addEventListener();
        this->money = money;
        std::string price;
        float fonstSize = 37;
        if (this->money == 2) {
            price = "USD $1.99";
        } else {
            price = "USD $4.99";
        }
        this->moneyText = Label::createWithTTF(price, "fonts/KOMIKAX.ttf", fonstSize);
        this->moneyText->retain();
        this->moneyText->setColor(Color3B(247, 241, 30));
        this->moneyText->setPosition(this->getMoneyTextPoition());
        this->addChild(this->moneyText, 1);
        this->setMoneyTextWithLocalCurrency();
    }
    
    DonateMoneyButton::~DonateMoneyButton()
    {
        this->moneyText->release();
    }
    
    void DonateMoneyButton::setMoneyTextWithLocalCurrency()
    {
        if (this->isSetLocalCurrency) {
            return;
        }
        //get products list and set price with local currency.
        std::vector<sdkbox::Product> p = sdkbox::IAP::getProducts();
        for (int index = 0; index < p.size(); index++) {
            std::stringstream key;
            key << "idv.GameDeisgner555.Pro.Donate" << this->money;
            if (key.str().compare(p.at(index).id) == 0) {
                std::string text = p.at(index).price;
                if (text.compare("") == 0) {
                    break;
                }
                this->moneyText->setString(text);
                key.clear();
                this->isSetLocalCurrency = true;
                break;
            }
            key.clear();
        }
    }
    
    int DonateMoneyButton::getMoney()
    {
        return this->money;
    }
    
    void DonateMoneyButton::addEventListener()
    {
        auto listener = EventListenerTouchOneByOne::create();
        listener->setSwallowTouches(true);
        listener->onTouchBegan = DonateMoneyButton::onTouchBegan;
        listener->onTouchEnded = DonateMoneyButton::onTouchEnded;
        listener->onTouchMoved = DonateMoneyButton::onTouchMoved;
        listener->onTouchCancelled = DonateMoneyButton::onTouchCanceled;
        Director::getInstance()->getEventDispatcher()
        ->addEventListenerWithSceneGraphPriority(listener, this);
    }
    
    Vec2 DonateMoneyButton::getMoneyTextPoition()
    {
        return Vec2(this->getContentSize().width * 0.78, this->getContentSize().height * 0.48);
    }
    
    bool DonateMoneyButton::onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *event)
    {
        auto target = static_cast<Sprite*>(event->getCurrentTarget());
        Vec2 locationInNode = target->convertToNodeSpace(touch->getLocation());
        Size s = target->getContentSize();
        Rect rect = Rect(0, 0, s.width, s.height);
        if (rect.containsPoint(locationInNode)) {
            Manager::SoundsManager::getInstance()->playSound("audio/sounds/ButtonClick.caf");
            log("DonateMoneyButton began... x = %f, y = %f", locationInNode.x, locationInNode.y);
            target->setScale(0.95);
            return true;
        }
        return false;
    }
    
    void DonateMoneyButton::onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *event)
    {
        auto target = static_cast<DonateMoneyButton*>(event->getCurrentTarget());
        Vec2 locationInNode = target->convertToNodeSpace(touch->getLocation());
        Size s = target->getContentSize();
        Rect rect = Rect(0, 0, s.width, s.height);
        if (rect.containsPoint(locationInNode)) {
            log("DonateButton ended... x = %f, y = %f", locationInNode.x, locationInNode.y);
            target->setScale(1.0);
            std::stringstream key;
            key << "donate" << target->getMoney();
            sdkbox::IAP::purchase(key.str());
        } else {
            target->setScale(1.0);
        }
    }
    
    void DonateMoneyButton::onTouchMoved(cocos2d::Touch *touch, cocos2d::Event *event)
    {
        
    }
    
    void DonateMoneyButton::onTouchCanceled(cocos2d::Touch *touch, cocos2d::Event *event)
    {
        auto target = static_cast<Sprite*>(event->getCurrentTarget());
        target->setScale(1.0);
    }
}
