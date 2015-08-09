#include "AppDelegate.h"
#include "SplashScreen.h"
#include "Constants.h"
#include "Config.h"
#include "SimpleAudioEngine.h"
#include "ZUtils.h"

USING_NS_CC;

AppDelegate::AppDelegate() {

}

AppDelegate::~AppDelegate()
{
}

//if you want a different context,just modify the value of glContextAttrs
//it will takes effect on all platforms
void AppDelegate::initGLContextAttrs()
{
	//set OpenGL context attributions,now can only set six attributions:
	//red,green,blue,alpha,depth,stencil
	//GLContextAttrs glContextAttrs = { 8, 8, 8, 8, 24, 8 };
	GLContextAttrs glContextAttrs = { 5, 6, 5, 0, 16, 8 };

	GLView::setGLContextAttrs(glContextAttrs);
}

bool AppDelegate::applicationDidFinishLaunching() {
	// initialize director
	auto director = Director::getInstance();
	auto glview = director->getOpenGLView();
	if (!glview) {
		glview = GLViewImpl::create("Shapes");
		//glview->setFrameSize(DESIGN_RESOLUTION_WIDTH, DESIGN_RESOLUTION_HEIGHT);
#if (CC_PLATFORM_WIN32 == CC_TARGET_PLATFORM)
		glview->setFrameSize(480, 800);
#endif
		director->setOpenGLView(glview);
	}

	auto fileUtils = FileUtils::getInstance();

	glview->setDesignResolutionSize(DESIGN_RESOLUTION_WIDTH, DESIGN_RESOLUTION_HEIGHT, ResolutionPolicy::FIXED_WIDTH);
	auto screenSize = glview->getFrameSize();
	
	fileUtils->addSearchPath(DESIGN_RESOURCE_PATH);

	// turn on display FPS
	director->setDisplayStats(false);

	// set FPS. the default value is 1.0/60 if you don't call this
	director->setAnimationInterval(1.0 / 60.0f);

	int count = UserDefault::getInstance()->getIntegerForKey(KEY_CURRENT_COUNT_OPEN_APP, 0);
	count++;
	UserDefault::getInstance()->setIntegerForKey(KEY_CURRENT_COUNT_OPEN_APP, count);

	// create a scene. it's an autorelease object
	auto scene = SplashScreen::createScene();

	ZUtils::reloadSound();
	ZUtils::loadAd();
	ZUtils::showAd();
	ZUtils::preloadFullAd();

	// run
	director->runWithScene(scene);

	return true;
}

// This function will be called when the app is inactive. When comes a phone call,it's be invoked too
void AppDelegate::applicationDidEnterBackground() 
{
	Director::getInstance()->stopAnimation();
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground() 
{
	Director::getInstance()->startAnimation();
}
