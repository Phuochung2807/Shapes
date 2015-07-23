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

	ZUtils::loadAd();
	ZUtils::preloadFullAd();

	_timeLoading = 3.0f;

	auto logo = Sprite::create(LOGO_NEWBIE);
	logo->setPosition(VisibleRect::center() + Vec2(0, 100));
	this->addChild(logo);

	logo->setOpacity(0);
	
	auto fadeOut = EaseQuarticActionIn::create(FadeIn::create(_timeLoading * 0.9f));
	auto callback = CallFunc::create([this](){
		loadGameScene();
	});
	auto seq = Sequence::create(fadeOut, callback, NULL);

	logo->runAction(seq);

	return true;
}

void SplashScreen::loadGameScene()
{
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile(SPRITES);

	auto scene = GameScene::createScene();
	auto trans = TransitionCrossFade::create(1.0f, scene);

	Director::getInstance()->replaceScene(trans);
}
