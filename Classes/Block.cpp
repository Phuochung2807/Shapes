#include "Block.h"
#include "Constants.h"

USING_NS_CC;

Block* Block::create(int color, int type)
{
	auto b = new Block();
	b->_color = color;
	b->_type = type;
	if (b && b->init())
	{
		b->autorelease();
		return b;
	}
	CC_SAFE_DELETE(b);
	return NULL;
}

bool Block::init()
{
	std::string spritename = getSprite(_color, _type);
	if (!Sprite::initWithSpriteFrameName(spritename))
	{
		return false;
	}

	return true;
}

bool Block::isMatch(int color)
{
	return isVisible() && _color == color;
}

std::string Block::getSprite(int color, int type)
{
	switch (color)
	{
	case 0:
		return BLUE[type];
	case 1:
		return ORANGE[type];
	case 2:
		return GREEN[type];
	case 3:
		return YELLOW[type];
	case 4:
		return PINK[type];
	case 5:
		return BROWN[type];
	default:
		return "";
	}
}





