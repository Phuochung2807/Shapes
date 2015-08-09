#include "SplashScreen.h"
#include "ZUtils.h"
#include "Constants.h"
#include "GameScene.h"
#include "VisibleRect.h"
USING_NS_CC;

cocos2d::Scene* SplashScreen::createScene()
{
	auto scene = Scene::create();

	auto splash = SplashScreen::create();
	scene->addChild(splash);

	return scene;
}

SplashScreen* SplashScreen::create()
{
	auto scene = new SplashScreen();
	if (scene->init())
	{
		scene->autorelease();
		return scene;
	}
	CC_SAFE_DELETE(scene);
	return NULL;
}

bool SplashScreen::init()
{
	if (!LayerColor::initWithColor(Color4B::BLACK))
	{
		return false;
	}

	//ZUtils::loadAd();
	//ZUtils::preloadFullAd();

	_timeLoading = 2.5f;

	SpriteFrameCache::getInstance()->addSpriteFramesWithFile(SPRITES);

	auto logo = Sprite::createWithSpriteFrameName(LOGO_NEWBIE);
	logo->setPosition(VisibleRect::center() + Vec2(0, 100));
	this->addChild(logo);

	logo->setOpacity(20);
	
	auto fadeOut = EaseQuarticActionIn::create(FadeIn::create(_timeLoading));
	auto callback = CallFunc::create([this](){
		loadGameScene();
	});
	auto seq = Sequence::create(fadeOut, DelayTime::create(0.5f), callback, NULL);

	logo->runAction(seq);

	return true;
}

void SplashScreen::loadGameScene()
{
	auto scene = GameScene::createScene();
	auto trans = TransitionFadeDown::create(1.0f, scene);

	Director::getInstance()->replaceScene(trans);
}
