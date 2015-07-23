#ifndef __SPLASH_SCREEN__
#define __SPLASH_SCREEN__

#include "cocos2d.h"

class SplashScreen : public cocos2d::LayerColor
{
public:
	static cocos2d::Scene* createScene();
	static SplashScreen* create();
	virtual bool init();

private:
	float _timeLoading;


	void loadGameScene();
};

#endif