#ifndef _Lib_TextureCreator_H_
#define _Lib_TextureCreator_H_

#include "cocos2d.h"

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
     @param texture 原始圖紋
     @return 縮放過的圖紋
     */
    Texture2D* getAutoSizeTexture2d(Texture2D* texture);
    
    /**
     @brief 依裝置解析度來縮放指定圖紋的尺寸
     @param img 原始圖紋的檔案路徑
     @return 縮放過的圖紋
     */
    Texture2D* getAutoSizeTexture2d(std::string img);
    
    /**
     @brief 依裝置解析度來縮放指定的精靈影格
     @param fram 原始影格
     @return 縮放過的影格
     */
    SpriteFrame* getAutoSizeFrame(SpriteFrame* frame);
private:
    /**
     @brief 建構式
     */
    TextureCreator();

    // 靜態實例
    static TextureCreator* instance;
};


#endif /* _Lib_TextureCreator_H_ */
