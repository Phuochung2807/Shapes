#include "SpriteData.h"
#include "Constants.h"

static SpriteData* _instance = NULL;

SpriteData* SpriteData::getIntance()
{
	if (_instance == NULL)
	{
		_instance = new SpriteData();
		_instance->init();
	}
	return _instance;
}

void SpriteData::init()
{
	int aaa[] = { 0, 1, 2, 3, 4, 5 };
	//int numofloop = cocos2d::RandomHelper::random_int(3, 5);
	//for (int i = 0; i < numofloop; i++)
	//{
	//	int a = cocos2d::RandomHelper::random_int(1, 3);
	//	int b = cocos2d::RandomHelper::random_int(3, NUM_OF_COLOR - 2);
	//	if (a != b)
	//	{
	//		std::swap(aaa[a], aaa[b]);
	//	}
	//}

	for (int i = 0; i < NUM_OF_COLOR; i++)
	{
		_data.push_back(new BlockDataSprite(BACKGROUND_SHAPES[aaa[i]], INLINE_SHAPE[aaa[i]], INLINE_FILL[aaa[i]]));
	}
}

SpriteData::~SpriteData()
{
	for (auto s : _data)
	{
		CC_SAFE_DELETE(s);
	}
}

void SpriteData::DestroyInstance()
{
	CC_SAFE_DELETE(_instance);
}
