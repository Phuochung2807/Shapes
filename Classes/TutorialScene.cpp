#include "TutorialScene.h"
#include "Constants.h"
#include "ZButton.h"
#include "VisibleRect.h"
USING_NS_CC;


cocos2d::Scene* TutorialScene::createScene()
{
	auto scene = Scene::create();

	auto splash = TutorialScene::create();
	scene->addChild(splash);

	return scene;
}

TutorialScene* TutorialScene::create()
{
	auto scene = new TutorialScene();
	if (scene->init())
	{
		scene->autorelease();
		return scene;
	}
	CC_SAFE_DELETE(scene);
	return NULL;
}

bool TutorialScene::init()
{
	if (!Layer::init())
	{
		return false;
	}

	auto bg = Sprite::create(UI_BG_HOWTOPLAY);
	this->addChild(bg);
	bg->setPosition(VisibleRect::center());

	auto bt = ZButton::create(ZButtonStyle::CLICK, Vec2(DESIGN_RESOLUTION_WIDTH / 2.0f, 52),
		Sprite::createWithSpriteFrameName(UI_BT_ALREADY_NORMAL), Sprite::createWithSpriteFrameName(UI_BT_ALREADY_PRESS), NULL,
		[this](Ref* ref)
	{
		Director::getInstance()->popScene();
		int s = UserDefault::getInstance()->getIntegerForKey(KEY_CURRENT_COUNT_OPEN_APP, 0);
		UserDefault::getInstance()->setIntegerForKey(KEY_CURRENT_COUNT_OPEN_APP, s + 1);
	}

		);

	this->addChild(bt->getMenu());
	
	bt->getItem()->runAction(RepeatForever::create( Sequence::createWithTwoActions( ScaleTo::create(0.4, 1.1f), ScaleTo::create(0.3f, 1.0f) ) ));

	auto dispatcher = Director::getInstance()->getEventDispatcher();
	auto listener = EventListenerTouchOneByOne::create();

	listener->onTouchEnded = CC_CALLBACK_2(TutorialScene::onTouchEnded, this);

	dispatcher->addEventListenerWithSceneGraphPriority(listener, this);

	return true;
}

void TutorialScene::onTouchEnded(Touch *touch, Event *event)
{
		Director::getInstance()->popScene();
		int s = UserDefault::getInstance()->getIntegerForKey(KEY_CURRENT_COUNT_OPEN_APP, 0);
		UserDefault::getInstance()->setIntegerForKey(KEY_CURRENT_COUNT_OPEN_APP, s + 1);
}