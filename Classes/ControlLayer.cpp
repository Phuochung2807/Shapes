#include "ControlLayer.h"
#include "VisibleRect.h"
#include "Constants.h"
#include "ZButton.h"
#include "GameScene.h"
USING_NS_CC;

ControlLayer* ControlLayer::create(GameScene *gamescene)
{
	auto controllayer = new ControlLayer();
	controllayer->_gameScene = gamescene;
	if (controllayer && controllayer->init())
	{
		controllayer->autorelease();
		return controllayer;
	}
	CC_SAFE_DELETE(controllayer);
	return NULL;
}

bool ControlLayer::init()
{
	if (!Layer::init())
	{
		return false;
	}
	
	_visibleSize = Director::getInstance()->getVisibleSize();

	return true;
}

void ControlLayer::showState(int state)
{
	auto move = MoveBy::create(1.0f, Vec2(0, -_visibleSize.height));
	auto callback = CallFunc::create([this](){
		
	});
	auto seq = Sequence::create(move, callback, NULL);
	this->runAction(seq);
}

void ControlLayer::hide()
{
	auto move = MoveBy::create(1.0f, Vec2(0, _visibleSize.height));
	auto callback = CallFunc::create([this](){
		_gameScene->startGame();
	});
	auto seq = Sequence::create(move, callback, NULL);
	this->runAction(seq);
}

void ControlLayer::startGame()
{
	hide();
}
