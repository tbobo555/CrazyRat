#include "BaseScene.h"

namespace GameScene
{
    BaseScene::BaseScene() : Scene()
    {
        this->visibleSize = Director::getInstance()->getVisibleSize();
        this->visibleOrigin = Director::getInstance()->getVisibleOrigin();
        this->center = Vec2(visibleOrigin.x + visibleSize.width / 2,
                            visibleOrigin.y + visibleSize.height / 2);
        this->leftTop = Vec2(visibleOrigin.x,
                             visibleOrigin.y + visibleSize.height);
        this->rightTop = Vec2(visibleOrigin.x + visibleSize.width,
                              visibleOrigin.y + visibleSize.height);
        this->leftBottom = Vec2(visibleOrigin.x,
                                visibleOrigin.y);
        this->rightBottom = (Vec2(visibleOrigin.x + visibleSize.width,
                                  visibleOrigin.y ));
        this->init();
        this->autorelease();
        this->retain();
    }
    
    BaseScene::~BaseScene(){}
    
    void BaseScene::initScene(){}
    
    void BaseScene::releaseScene(){}
}
