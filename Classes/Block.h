#ifndef __BLOCK__
#define __BLOCK__

#include "cocos2d.h"

enum BlockType
{
	Block_1,
	Block_2,
	Block_3,
	Block_4,
	Block_5
};

enum BlockColor
{
	Color_1,
	Color_2,
	Color_3,
	Color_4,
	Color_5,
	Color_6,
};

class Block : public cocos2d::Node
{
public:
	static Block* create(int color, int type);

	static float getScaleShape(int type);

	virtual bool init();
	bool isMatch(int color);

	float getCurrentScaleX();

	void setZScaleX(float scaleX);
	float getZWidth();
protected:
	CC_SYNTHESIZE_READONLY(int, _color, ZColor);
	CC_SYNTHESIZE_READONLY(int, _type, ZType);
	
	CC_SYNTHESIZE(cocos2d::Sprite*, _content, Content);
	CC_SYNTHESIZE(cocos2d::Sprite*, _shape, Shape);
	CC_SYNTHESIZE(cocos2d::Sprite*, _stencil, Stencil);

	
};
#endif