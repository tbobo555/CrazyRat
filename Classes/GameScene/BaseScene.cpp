#include "BaseScene.h"

namespace GameScene
{
    BaseScene::BaseScene()
    {
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

}
