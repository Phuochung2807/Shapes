#include "PixManager.h"
#include "Pix.h"
#include "Constants.h"
#include "GameScene.h"

USING_NS_CC;

#define MAX_CACHE_PER_PIX	4

PixManager* PixManager::create()
{
	auto pm = new PixManager();
	if (pm && pm->init())
	{
		return pm;
	}
	CC_SAFE_DELETE(pm);
	return NULL;
}

bool PixManager::init()
{
	for (int i = 0; i < NUM_OF_COLOR; i++)
	{
		for (int k = 0; k < MAX_CACHE_PER_PIX; k++)
		{
			auto pix = Pix::create(i);
			pix->setTag(i);
			_pixPools.pushBack(pix);
		}
	}

	this->reset();

	return true;
}

Pix* PixManager::getPix(int color)
{
	Pix* tmp = _pixPools.at(color * MAX_CACHE_PER_PIX);
	for (int i = 0; i < MAX_CACHE_PER_PIX; i++)
	{
		int idx = color * MAX_CACHE_PER_PIX + i;
		if (!_pixPools.at(idx)->isVisible())
		{
			tmp = _pixPools.at(idx);
			break;
		}
	}
	return tmp;
}

void PixManager::reset()
{
	for (int i = 0, imax = _pixPools.size(); i < imax; i++)
	{
		auto p = _pixPools.at(i);
		p->setPosition(10000, 10000);
		p->setVisible(false);
	}
}

void PixManager::addAllPoolToScene(GameScene* gamescene, int zorder)
{
	for (int i = 0, imax = _pixPools.size(); i < imax; i++)
	{
		gamescene->addChild(_pixPools.at(i), zorder);
	}
}
