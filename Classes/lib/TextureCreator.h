#ifndef _Lib_TextureCreator_H_
#define _Lib_TextureCreator_H_

#include "cocos2d.h"

USING_NS_CC;

class TextureCreator
{
public:
    static TextureCreator* getInstance();
    Texture2D* getAutoSizeTexture2d(Texture2D* texture);
    Texture2D* getAutoSizeTexture2d(std::string img);
private:
    TextureCreator();
    static TextureCreator* instance;
};


#endif /* _Lib_TextureCreator_H_ */
