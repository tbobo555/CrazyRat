#ifndef _Manager_SoundsManager_H_
#define _Manager_SoundsManager_H_

#include "SimpleAudioEngine.h"
#include "Db/SwitchSetting.h"

namespace Manager
{
    /**
     @brief 音效管理者
     */
    class SoundsManager
    {
    public:
        /**
         @brief 取得靜態實例
         */
        static SoundsManager* getInstance();
        
        /**
         @brief 播放音效
         @param filName 音效檔名
         */
        void playSound(const char *fileName);
    private:
        // 靜態實例
        static SoundsManager* instance;
        
        /**
         @brief 建構式
         */
        SoundsManager();
    };
}

#endif /* _Manager_SoundsManager_H_ */
