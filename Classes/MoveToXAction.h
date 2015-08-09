#ifndef __MOVE_TO_X_ACTION__
#define __MOVE_TO_X_ACTION__

#include "cocos2d.h"

class MoveToXAction : public cocos2d::ActionInterval
{
public:
	static MoveToXAction* create(float duration, float X);

	virtual bool init();
	virtual void update(float time) override;
	virtual void startWithTarget(cocos2d::Node *target) override;
protected:
	float _x;
	float _deltaX;
	float _initX;
};

#endif