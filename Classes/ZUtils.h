#ifndef _Z_UTILS_H_
#define _Z_UTILS_H_

#include "cocos2d.h"

#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID || CC_TARGET_PLATFORM == CC_PLATFORM_WIN32 || CC_TARGET_PLATFORM == CC_PLATFORM_WP8)

#define MUSIC_BACKGROUND "sound/background_music.mp3"

#define SOUND_BLOCKSWITCH	"sound/blockswitch.wav"
#define SOUND_FAIL	"sound/fail.wav"
#define SOUND_SWITCH_TYPE	"sound/switchtype.wav"
#define SOUND_MATCH	"sound/match.wav"

#endif

static int NUM_OF_SOUND = 4;
static char* GAME_SOUNDS[] = { SOUND_BLOCKSWITCH, SOUND_FAIL, SOUND_SWITCH_TYPE, SOUND_MATCH };

class ZUtils
{
public:
	static void reloadSound();

	static void playEffect(const char* path);

	static void playBackgroundMusic(const char* path, bool isLoop);

	static void stopBackgroundMusic();

	static void resumeBackgroundMusic();

	static void loadAd();

	static void showAd();

	static void hideAd();

	static void preloadFullAd();

	static void showAdInter();

	static char* encodeInt(int score);

	static int decodeInt(const char* score);

	static bool is_number(char * s);
};

#endif