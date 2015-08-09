#ifndef __PIX_MANAGER__
#define __PIX_MANAGER__

#include "cocos2d.h"

class Pix;
class GameScene;

class PixManager
{
public:
	static PixManager* create();
	virtual bool init();

	void addAllPoolToScene(GameScene* gamescene, int zorder);
	Pix* getPix(int color);
	void reset();
protected:

	cocos2d::Vector<Pix*> _pixPools;
};
#endif