#include "ZUtils.h"

#include "cocos2d.h"
#include "audio/include/AudioEngine.h"
#include "SimpleAudioEngine.h"
#include "Constants.h"

USING_NS_CC;

#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID) || (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
#include "NDKHelper/NDKHelper.h"
#endif
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8)
#include "CSUtils.h"
#endif


void ZUtils::playEffect(const char* path)
{
	CocosDenshion::SimpleAudioEngine::getInstance()->playEffect(path, false, 1.0f);
}

void ZUtils::playBackgroundMusic(const char* path, bool isLoop)
{
	CocosDenshion::SimpleAudioEngine::getInstance()->playBackgroundMusic(path, isLoop);
	CocosDenshion::SimpleAudioEngine::getInstance()->setBackgroundMusicVolume(0.5f);
}

void ZUtils::stopBackgroundMusic()
{
	CocosDenshion::SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
}

void ZUtils::resumeBackgroundMusic()
{
	CocosDenshion::SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
}

void ZUtils::loadAd(){
	//int count = UserDefault::getInstance()->getIntegerForKey(KEY_CURRENT_COUNT_OPEN_APP, 0);
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID) || (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	ValueMap valueMap;
	valueMap["ad_mob_id"] = AD_MOB_ID;
	Value parameters = Value(valueMap);
	sendMessageWithParams("loadAd", parameters);
#endif
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8)
	CSUtils::Instance->loadAd();
#endif
}

void ZUtils::showAd(){
	CCLOG("showAd");
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID) || (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	Value parameters = Value();
	sendMessageWithParams("showAd", parameters);
#endif
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8)
	CSUtils::Instance->showAd();
#endif
}

void ZUtils::preloadFullAd()
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID) || (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	ValueMap valueMap;
	valueMap["ad_mob_inter_id"] = AD_MOB_INTER_ID;
	Value parameters = Value(valueMap);
	sendMessageWithParams("preloadFullAd", parameters);
#endif
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8)
	CSUtils::Instance->preloadFullAd();
#endif
}
void ZUtils::showAdInter()
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID) || (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	Value parameters = Value();
	sendMessageWithParams("showAdInter", parameters);
#endif
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8)
	CSUtils::Instance->showAdInters();
#endif
}

void ZUtils::hideAd()
{
	CCLOG("hideAd");
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID) || (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	Value parameters = Value();
	sendMessageWithParams("hideAd", parameters);
#endif
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8)
	CSUtils::Instance->hideAd();
#endif
}

char* ZUtils::encodeInt(int score)
{
	char *out;
	__String * str = __String::createWithFormat("%d", score);
	size_t ret = 10;
	base64Encode((unsigned char*)str->getCString(), (unsigned int)ret, &out);
	char *_out = new char[18];
	_out[0] = out[0];
	_out[1] = 'q';
	_out[2] = 'K';
	for (int i = 3; i < 18; i++)
		_out[i] = out[i - 2];
	return _out;
}

int ZUtils::decodeInt(const char* out){
	char *_out = new char[16];
	_out[0] = out[0];
	for (int i = 1; i < 16; i++)
		_out[i] = out[i + 2];
	unsigned char * decodedData = nullptr;
	int decodedDataLen = base64Decode((unsigned char*)_out, (unsigned int)strlen(_out), &decodedData);
	if (!is_number((char*)decodedData)) return 0;
	return atoi((char*)decodedData);
}

bool ZUtils::is_number(char * s)
{
	if (strlen(s) <= 0) return false;

	for (int i = 0; i < strlen(s); i++)
	if (s[i] < -1 && s[i] > 255 && !isdigit(s[i])) return false;


	return true;
}

void ZUtils::reloadSound()
{
	CocosDenshion::SimpleAudioEngine::getInstance()->preloadBackgroundMusic(MUSIC_BACKGROUND);

	for (int i = 0; i < NUM_OF_SOUND; i++)
	{
		CocosDenshion::SimpleAudioEngine::getInstance()->preloadEffect(GAME_SOUNDS[i]);
	}
}