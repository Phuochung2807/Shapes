#ifndef _CONTROL_LAYER_H_
#define _CONTROL_LAYER_H_

#include "cocos2d.h"

class GameScene;
class ZButton;

enum ControlState
{
	START,
	RETRY
};

class ControlLayer : public cocos2d::Layer
{
public:
	static ControlLayer* create(GameScene *gamescene);

	virtual bool init();
	void showState(int state);
	void hide();
private:
	CC_SYNTHESIZE(GameScene*, _gameScene, GameScene);
	void startGame();
	cocos2d::Size _visibleSize;
};

#endif