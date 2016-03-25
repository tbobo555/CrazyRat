#include "BaseScene.h"

namespace GameScene
{
    BaseScene::BaseScene()
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
        this->rightBottom = (Vec2(visibleOrigin.x + visibleSize.height,
                                  visibleOrigin.y));
        this->scene = Scene::create();
        this->scene->retain();
    }
    
    BaseScene::~BaseScene()
    {
        if (this->scene) {
            this->scene->release();
        }
    }
    
    void BaseScene::release()
    {
        delete this;
    }
    
    Scene* BaseScene::getCCScene()
    {
        return this->scene;
    }
    
    void BaseScene::initScene(){}
    
    void BaseScene::releaseScene(){}

}
