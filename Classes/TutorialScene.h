#ifndef __TUTORIAL_SCENE__
#define __TUTORIAL_SCENE__

#include "cocos2d.h"

class TutorialScene : public cocos2d::Layer
{
public:
	static cocos2d::Scene* createScene();
	static TutorialScene* create();
	virtual bool init();

	void onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *event);
protected:
};

#endif