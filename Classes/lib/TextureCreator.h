#ifndef _Lib_TextureCreator_H_
#define _Lib_TextureCreator_H_

#include "cocos2d.h"
#include <math.h>

USING_NS_CC;


/**
 圖紋產生器，單例模式，可依據裝置解析度，產生相對大小的圖紋。
 */
class TextureCreator
{
public:
    /**
     @brief 取得實體物件
     */
    static TextureCreator* getInstance();
    
    /**
     @brief 依裝置解析度來縮放指定圖紋的尺寸
     @param img 原始圖紋的檔案路徑
     @return 縮放過的圖紋
     */
    Texture2D* getAutoSizeTexture2d(std::string img);
private:
    /**
     @brief 建構式
     */
    TextureCreator();

    // 靜態實例
    static TextureCreator* instance;
    
    // Rect的預設保留空間，當sprite被縮方後，會因浮點數導致圖片邊緣被裁切，此變數則用來增大容納sprite的rect以避免圖騙被裁切
    float rectPadding;
};


#endif /* _Lib_TextureCreator_H_ */
