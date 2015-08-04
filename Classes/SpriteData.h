#ifndef __SPRITE_DATA__
#define __SPRITE_DATA__

#include "cocos2d.h"

class BlockDataSprite;

class SpriteData
{
public:
	std::vector<BlockDataSprite*> _data;

	static SpriteData* getIntance();
	static void DestroyInstance();
	virtual ~SpriteData();
private:
	void init();
};

class BlockDataSprite
{
public: 
	std::string background;
	std::string inline_shape;
	std::string inline_fill;

	BlockDataSprite(std::string background, std::string inline_shape, std::string inline_fill)
	{
		this->background = background;
		this->inline_shape = inline_shape;
		this->inline_fill = inline_fill;
	}
};
#endif