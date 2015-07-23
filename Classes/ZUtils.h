#ifndef _Z_UTILS_H_
#define _Z_UTILS_H_

class ZUtils
{
public:

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