#ifndef _Manager_MusicManager_H_
#define _Manager_MusicManager_H_

#include "SimpleAudioEngine.h"
#include "Db/SwitchSetting.h"

namespace Manager
{
    /**
     @brief 音樂管理者
     */
    class MusicManager
    {
    public:
        /**
         @brief 取得靜態實例
         */
        static MusicManager* getInstance();
        
        /**
         @brief 播放背景音樂
         @param fileName 音樂的檔案名稱
         */
        void playMusic(const char* fileName);
        
        /**
         @brief 播放音樂(單一次)
         @param fileName 音樂的檔案名稱
         */
        void playMusicNoLoop(const char* fileName);
        
        /**
         @brief 停止音樂
         */
        void stopMusic();
        
        /**
         @brief 暫停音樂
         */
        void pauseMusic();

        /**
         @brief 繼續播放音樂
         */
        void resumeMusic();

        /**
         @brief 開啟音樂(音量調整為1)
         */
        void turnOnMusic();
        
        /**
         @brief 關閉音樂(音量調整為0)
         */
        void turnOffMusic();
    private:
        /**
         @brief 建構式
         */
        MusicManager();
        
        // 靜態實例
        static MusicManager* instance;
        // 現在播放的音樂名稱
        const char* musicName;
        
    };
}


#endif /* _Manager_MusicManager_H_ */
