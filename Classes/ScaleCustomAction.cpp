#include "ScaleCustomAction.h"
#include "Block.h"

USING_NS_CC;


ScaleCustomAction* ScaleCustomAction::create(float duration, float deltaScaleX, float x)
{
	auto action = new ScaleCustomAction();
	action->_duration = duration;
	action->_deltaScaleX = deltaScaleX;
	action->_xx = x;
	if (action && action->init())
	{
		action->autorelease();
		return action;
	}
	CC_SAFE_DELETE(action);
	return NULL;
}

bool ScaleCustomAction::init()
{
	if (!ActionInterval::initWithDuration(_duration))
	{
		return false;
	}
	
	return true;
}

void ScaleCustomAction::update(float time)
{
	auto b = (Block*)_target;
	b->setZScaleX(_initScale + _delta * time);
	b->setPositionX(_initX + _deltaX * time);
}

void ScaleCustomAction::startWithTarget(Node *target)
{
	ActionInterval::startWithTarget(target);
	auto b = (Block*)_target;
	_initScale = b->getCurrentScaleX();
	_delta = _deltaScaleX - _initScale;

	_initX = b->getPositionX();
	_deltaX = _xx - _initX;
}
