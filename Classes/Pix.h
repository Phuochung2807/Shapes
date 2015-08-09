#ifndef __PIX__
#define __PIX__

#include "cocos2d.h"

class Pix : public cocos2d::Sprite
{
public:
	static Pix* create(int color);
	bool init();
protected:
	CC_SYNTHESIZE_READONLY(int, _color, ZColor)
};
#endif // !__PIX__
