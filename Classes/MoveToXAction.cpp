#include "MoveToXAction.h"

USING_NS_CC;

MoveToXAction* MoveToXAction::create(float duration, float X)
{
	auto action = new MoveToXAction();
	action->_duration = duration;
	action->_x = X;
	if (action && action->init())
	{
		action->autorelease();
		return action;
	}
	CC_SAFE_DELETE(action);
	return NULL;
}

bool MoveToXAction::init()
{
	if (!ActionInterval::initWithDuration(_duration))
	{
		return false;
	}
	return true;
}

void MoveToXAction::update(float time)
{
	_target->setPositionX(_initX + _deltaX * time);
}

void MoveToXAction::startWithTarget(cocos2d::Node *target)
{
	ActionInterval::startWithTarget(target);
	_initX = target->getPositionX();
	_deltaX = _x - _initX;
}
