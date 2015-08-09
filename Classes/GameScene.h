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
	kInGame,
	kText,
	kControl
};

class BackgroundColor;
class ControlLayer;
class BlockManager;
class PixManager;
class Pix;

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

	//void pausedGame();
	//void resumeGame();

	void onLoose();
	void onRestart();
	void checkMatch(Pix* param1);
	void updateScore();
	int _gameMode;

	ControlLayer *_controlLayer;
	BlockManager* _blockManager;
	PixManager* _pixManager;

	std::vector<Pix*> _currentPixs;

	int _iScore;
	cocos2d::Label* _lbScore;

	int countLost;
	int countAppOpen;
	int rateShowAd;
	bool isShowAdFull;
	bool isNeedLoadAdFull;

	//speed game
	float _timeMovePix;
	float _rateCreatePix;

	float _timer;

};

#endif /* _GAMESCENE_H_ */