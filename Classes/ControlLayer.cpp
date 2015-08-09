#include "ControlLayer.h"
#include "VisibleRect.h"
#include "Constants.h"
#include "ZButton.h"
#include "GameScene.h"
#include "TutorialScene.h"
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
	isShowStart = false;
	isRetryState = false;

	createLabels();
	createControls();

	return true;
}

void ControlLayer::showState(int state)
{
	if (isRetryState)
		return;

	isRetryState = true;

	if (isShowStart)
	{
		isShowStart = false;
		_btPlay->getItem()->setVisible(false);
		_btRery->getItem()->setVisible(true);
	}

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
		isRetryState = false;
	});
	auto seq = Sequence::create(move, callback, NULL);
	this->runAction(seq);
}

void ControlLayer::startGame()
{
	hide();
}

void ControlLayer::btPlayClicked()
{
	int isCompletedTut = UserDefault::getInstance()->getIntegerForKey(KEY_CURRENT_COUNT_OPEN_APP, 0);
	if (isCompletedTut < 2)
	{
		auto tutscene = TutorialScene::createScene();
		auto scene = TransitionFlipY::create(0.8f, tutscene);
		Director::getInstance()->pushScene(scene);
	}
	else
	{
		startGame();
		isShowStart = true;
		_iscore = 0;
		_score->setString(StringUtils::format("%d", _iscore));
		_score->setVisible(true);
	}
}

void ControlLayer::btRetryClicked()
{
	startGame();
}

void ControlLayer::createControls()
{
	_btPlay = ZButton::create(ZButtonStyle::CLICK, VisibleRect::center(),
		Sprite::createWithSpriteFrameName(UI_BT_PLAY_NORMAL), Sprite::createWithSpriteFrameName(UI_BT_PLAY_PRESS), NULL,
		[this](Ref* ref){
		btPlayClicked();
	}
	);

	_btRery = ZButton::create(ZButtonStyle::CLICK, VisibleRect::center() + Vec2(0, -16),
		Sprite::createWithSpriteFrameName(UI_BT_RETRY_NORMAL), Sprite::createWithSpriteFrameName(UI_BT_RETRY_PRESS), NULL,
		[this](Ref* ref){
		btRetryClicked();
	}, _btPlay->getMenu()
		);

	_btRery->getItem()->setVisible(false);

	_btPlay->getItem()->setScale(4.0f);
	_btPlay->getItem()->setOpacity(0.0f);

	_btPlay->getItem()->runAction(Spawn::create( ScaleTo::create(1.5f, 1.0f), FadeIn::create(1.5f), NULL ));

	this->addChild(_btPlay->getMenu());
}

void ControlLayer::createLabels()
{
	_logo = Sprite::createWithSpriteFrameName(UI_LOGO);
	this->addChild(_logo);
	_logo->setPosition(320, 1300);

	_logo->runAction(MoveBy::create(1.5f, Vec2(0, -400)));

	_score = Label::createWithBMFont(FONT_NUMBER, "0");
	_score->setPosition(VisibleRect::center());

	_score->setVisible(false);

	this->addChild(_score);
}

void ControlLayer::addScore(int amount)
{
	_iscore += amount;
	_score->setString(StringUtils::format("%d", _iscore));
}
