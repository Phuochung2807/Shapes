#ifndef _GAMESCENE_H_
#define _GAMESCENE_H_

#include "cocos2d.h"
#include "Config.h"

enum GameMode
{
	Init,
	Paused,
	Playing, 
	Tutorial
};

enum GameLayer
{
	kGame,
	kMenu,
	kShader
};

enum MainGameLayer
{
	kBackground,
	kLine,
	kDot,
	kInGame,
	kText,
	kControl
};

class BackgroundColor;
class ControlLayer;

class GameScene : public cocos2d::Layer
{
public:
	static cocos2d::Scene* createScene();
	static GameScene* create();
	virtual bool init();
	bool onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *event);
	void onTouchMoved(cocos2d::Touch *touch, cocos2d::Event *event);
	void onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *event);
	void onKeyReleased(EventKeyboard::KeyCode keyCode, Event *event);
	void update(float deltaTime);

	void startGame();
	void rateGame();

	virtual ~GameScene();
private:
	bool initTouch();
	void initGame();
	void initValues();
	void initControls();

	void pausedGame();
	void resumeGame();

	int _gameMode;

	ControlLayer *_controlLayer;
};

#endif /* _GAMESCENE_H_ */