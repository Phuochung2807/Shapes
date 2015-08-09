#include "GameScene.h"
#include "Config.h"
#include "Constants.h"
#include "VisibleRect.h"
#include "ZButton.h"
#include "ZLog.h"
#include "ControlLayer.h"
#include "ZUtils.h"
#include "BlockManager.h"
#include "PixManager.h"
#include "Block.h"
#include "Pix.h"
#include "MoveToXAction.h"
#include "ZUtils.h"
#include <algorithm>

USING_NS_CC;

Scene* GameScene::createScene()
{
	ZUtils::showAd();

	auto scene = Scene::create();

	auto gamelayer = GameScene::create();
	scene->addChild(gamelayer, kGame);

	auto controllayer = ControlLayer::create(gamelayer);
	scene->addChild(controllayer, kMenu);

	gamelayer->_controlLayer = controllayer;

	ZUtils::playBackgroundMusic(MUSIC_BACKGROUND, true);

	return scene;
}

GameScene* GameScene::create()
{
	auto scene = new GameScene();
	if (scene->init())
	{
		scene->autorelease();
		return scene;
	}
	CC_SAFE_DELETE(scene);
	return NULL;
}

bool GameScene::init()
{
	if (!Layer::init())
	{
		return false;
	}

	initGame();
	initValues();
	initControls();

	return initTouch();
}

void GameScene::initGame()
{
	auto visibleSize = Director::getInstance()->getVisibleSize();

	auto background = Sprite::create(SPRITE_BACKGROUND);
	this->addChild(background, kBackground);
	background->setPosition(VisibleRect::center());

	_blockManager = BlockManager::create(0);
	this->addChild(_blockManager, kInGame);

	_pixManager = PixManager::create();
	_pixManager->addAllPoolToScene(this, kInGame);

	_blockManager->setVisible(false);

	int bestscore = UserDefault::getInstance()->getIntegerForKey(KEY_HIGH_SCORE, 0);
	_lbScore = Label::createWithBMFont(FONT_NUMBER, StringUtils::format("%d", bestscore));
	_lbScore->setPosition(VisibleRect::center() + Vec2(0, 190));
	this->addChild(_lbScore, kBackground);

	countAppOpen = UserDefault::getInstance()->getIntegerForKey(KEY_CURRENT_COUNT_OPEN_APP, 0);
	rateShowAd = 7 - countAppOpen;
	if (rateShowAd < 3)
	{
		rateShowAd = 3;
	}
	isShowAdFull = false;
	isNeedLoadAdFull = false;
}


void GameScene::initControls()
{

}

bool GameScene::initTouch()
{
	auto dispatcher = Director::getInstance()->getEventDispatcher();
	auto listener = EventListenerTouchOneByOne::create();

	listener->onTouchBegan = CC_CALLBACK_2(GameScene::onTouchBegan, this);
	listener->onTouchMoved = CC_CALLBACK_2(GameScene::onTouchMoved, this);
	listener->onTouchEnded = CC_CALLBACK_2(GameScene::onTouchEnded, this);

	dispatcher->addEventListenerWithSceneGraphPriority(listener, this);

	auto pKeybackListener = EventListenerKeyboard::create();
	pKeybackListener->onKeyReleased = CC_CALLBACK_2(GameScene::onKeyReleased, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(pKeybackListener, this);
	
	return true;
}

void GameScene::startGame()
{
	initValues();

	_blockManager->setVisible(true);

	if (isShowAdFull)
	{
		if (isNeedLoadAdFull)
		{
			ZUtils::preloadFullAd();
			isNeedLoadAdFull = false;
			isShowAdFull = false;
		}
		else
		{
			isNeedLoadAdFull = true;
		}
	}

	this->scheduleUpdate();
	_gameMode = GameMode::Playing;
}

void GameScene::initValues()
{
	_gameMode = GameMode::Init;

	_blockManager->reset();
	_pixManager->reset();

	_currentPixs.clear();

	_iScore = 0;
	_lbScore->setString(StringUtils::format("%d", _iScore));

	_timeMovePix = 6.0f;
	_rateCreatePix = 3.5f;
	_timer = 4.5f;
}

//void GameScene::pausedGame()
//{
//
//}
//
//void GameScene::resumeGame()
//{
//
//}

int count = 0;
bool isSwitchType = false;

bool GameScene::onTouchBegan(Touch *touch, Event *event)
{
	if (_gameMode == GameMode::Playing)
	{

		isSwitchType = _blockManager->next();
		int type = _blockManager->getType();
		if (isSwitchType)
		{
			ZUtils::playEffect(SOUND_SWITCH_TYPE);
			for (size_t i = 0, imax = _currentPixs.size(); i < imax; i++)
			{
				auto pix = _currentPixs.at(i);
				int tag = pix->getTag();
				float x = INIT_POSITION[type - 2][tag];
				pix->runAction(MoveToXAction::create(0.33f, x));
			}
		}
		else
		{
			ZUtils::playEffect(SOUND_BLOCKSWITCH);
		}
		return true;
	}
	
	return false;
}

void GameScene::onTouchMoved(Touch *touch, Event *event)
{
	
}

void GameScene::onTouchEnded(Touch *touch, Event *event)
{

}

void GameScene::onKeyReleased(EventKeyboard::KeyCode keyCode, Event *event)
{
	if (keyCode == EventKeyboard::KeyCode::KEY_BACK)
	{
		if (_controlLayer->getPositionY() < 10)
		{
			Director::getInstance()->end();
		}
		else
		{
			ZUtils::showAdInter();
			this->scheduleOnce([this](float dt){
				Director::getInstance()->end();
			}, 2.0f, "keyzendgame");
		}
	}
}

int color;
int lane;

void GameScene::update(float deltaTime)
{
	if (_gameMode != GameMode::Playing)
	{
		return;
	}

	_timer += deltaTime;
	if (_timer > _rateCreatePix)
	{
		_timer -= _rateCreatePix;
		int type = _blockManager->getType();
		color = RandomHelper::random_int(0, type - 1);
		lane = RandomHelper::random_int(0, type - 1);
		
		//for (int i = 0; i < 5 && color == lane; i++)
		//{
		//	lane = RandomHelper::random_int(color, type - 1);
		//}
		auto pix = _pixManager->getPix(color);
		pix->setPosition(INIT_POSITION[type - 2][lane], 1170.0f);
		pix->setTag(lane);
		pix->setVisible(true);
		_currentPixs.push_back(pix);
		pix->runAction(Sequence::create(MoveBy::create(_timeMovePix, Vec2(0, -1115)), CallFuncN::create([this](Node* node){
			std::vector<Pix*>::iterator position = std::find(_currentPixs.begin(), _currentPixs.end(), (Pix*)node);
			if (position != _currentPixs.end())
			{
				_currentPixs.erase(position);
			}
			_timeMovePix -= 0.03 * _timeMovePix;
			_rateCreatePix -= 0.03 * _rateCreatePix;
			log("update %d %f %f", _blockManager->getCount(), _timeMovePix, _rateCreatePix);
			checkMatch((Pix*)node);
		}), NULL));
	}

}

void GameScene::onRestart()
{

}

void GameScene::checkMatch(Pix* pix)
{
	if (_blockManager->isMatching(pix))
	{
		ZUtils::playEffect(SOUND_MATCH);
		updateScore();
		pix->runAction(Sequence::create(ScaleTo::create(0.5f, 1.5f), CallFuncN::create([this](Node* node){
			auto p = (Pix*)node;
			p->setVisible(false);
			p->setPosition(10000, 10000);
			p->setScale(1.0f);
		}), NULL ));
	}
	else
	{
		ZUtils::playEffect(SOUND_FAIL);
		auto p = ParticleSystemQuad::create("explode.plist");
		p->setPosition(pix->getPosition() + Vec2(0, 64));
		p->setAutoRemoveOnFinish(true);
		this->addChild(p, kControl);
		pix->setPosition(10000, 10000);
		pix->setVisible(false);
		onLoose();
	}
}


void GameScene::onLoose()
{
	int currentbestscore = UserDefault::getInstance()->getIntegerForKey(KEY_HIGH_SCORE, 0);
	if (_iScore > currentbestscore)
	{
		UserDefault::getInstance()->setIntegerForKey(KEY_HIGH_SCORE, _iScore);
		_lbScore->runAction(Repeat::create(Sequence::createWithTwoActions(ScaleTo::create(0.5f, 1.2f), ScaleTo::create(0.3f, 1.0f)), 2));
	}
	_gameMode = GameMode::Paused;
	this->unscheduleUpdate();
	for (auto pix : _currentPixs)
	{
		pix->stopAllActions();
		pix->setVisible(false);
		pix->setPosition(10000, 10000);
	}
	_controlLayer->showState();

	countLost++;
	
	if (countLost > rateShowAd)
	{
		countLost -= rateShowAd;
		this->scheduleOnce([this](float dt){
			ZUtils::showAdInter();
			isShowAdFull = true;
			isNeedLoadAdFull = false;
		}, 0.5f, "asdsadsadsads");
	}
}

void GameScene::updateScore()
{
	_iScore++;
	_lbScore->setString(StringUtils::format("%d", _iScore));
}

GameScene::~GameScene()
{
	CC_SAFE_DELETE(_pixManager);
}










