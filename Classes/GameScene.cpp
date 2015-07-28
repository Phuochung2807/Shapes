#include "GameScene.h"
#include "Config.h"
#include "Constants.h"
#include "VisibleRect.h"
#include "ZButton.h"
#include "ZLog.h"
#include "ControlLayer.h"
#include "ZUtils.h"
#include "BlockManager.h"

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

	//ZUtils::playBackgroundMusic(MUSIC_BACKGROUND, true);
	//ZUtils::stopBackgroundMusic();

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

	//ZUtils::resumeBackgroundMusic();
}

void GameScene::initValues()
{
	_gameMode = GameMode::Init;

	_gameMode = GameMode::Playing;
}

void GameScene::pausedGame()
{

}

void GameScene::resumeGame()
{

}

bool GameScene::onTouchBegan(Touch *touch, Event *event)
{
	if (_gameMode == GameMode::Playing)
	{
		_blockManager->next();
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
			//Director::getInstance()->end();
		}
		else
		{
			ZUtils::showAdInter();
			this->scheduleOnce([this](float dt){
			}, 3.0f, "keyzendgame");
		}
	}
}

void GameScene::update(float deltaTime)
{

}


GameScene::~GameScene()
{
	
}


