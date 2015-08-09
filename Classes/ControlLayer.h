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

	void createControls();

	void showState(int state = 0);
	void hide();
private:
	CC_SYNTHESIZE(GameScene*, _gameScene, GameScene);
	void startGame();
	void btPlayClicked();
	void btRetryClicked();
	void createLabels();
	void addScore(int amount);
	cocos2d::Size _visibleSize;

	ZButton *_btPlay, *_btRery;
	cocos2d::Sprite* _logo;
	cocos2d::Label *_score, *_lbScore;
	cocos2d::Label *_highScore, *_lbHighscore;

	bool isShowStart;

	bool isRetryState;

	int _iscore;
};

#endif