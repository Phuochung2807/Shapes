#ifndef __SCALE_CUSTOM_ACTION__
#define __SCALE_CUSTOM_ACTION__

#include "cocos2d.h"

class ScaleCustomAction : public cocos2d::ActionInterval
{
public:
	static ScaleCustomAction* create(float duration, float deltaScaleX, float x);

	virtual bool init();
	virtual void update(float time) override;
	virtual void startWithTarget(cocos2d::Node *target) override;
protected:
	float _initScale;
	float _deltaScaleX;
	float _duration;

	float _delta;

	float _xx;
	float _initX;
	float _deltaX;
};

#endif