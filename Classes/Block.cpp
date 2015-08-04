#include "Block.h"
#include "Constants.h"
#include "SpriteData.h"

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
	if (!Node::init())
	{
		return false;
	}
	BlockDataSprite* data = SpriteData::getIntance()->_data.at(_color);

	this->_content = Sprite::createWithSpriteFrameName(data->background);
	this->_content->setAnchorPoint(Vec2::ANCHOR_BOTTOM_LEFT);

	_stencil = Sprite::createWithSpriteFrameName(data->inline_fill);
	_stencil->retain();

	auto clipper = ClippingNode::create();
	clipper->setInverted(true);
	clipper->setAlphaThreshold(0.5f);
	clipper->setStencil(_stencil);


	clipper->addChild(_content);

	_shape = Sprite::createWithSpriteFrameName(data->inline_shape);
	this->addChild(_shape, 1);

	this->setZScaleX(getScaleShape(_type));

	this->addChild(clipper, 0);
	return true;
}

bool Block::isMatch(int color)
{
	return isVisible() && _color == color;
}

float Block::getScaleShape(int type)
{
	switch (type)
	{
	case 0:
		return 1.0f;
	case 1:
		return 213.0f / 320.0f;
	case 2:
		return 160.0f / 320.0f;
	case 3:
		return 128.0f / 320.0f;
	case 4:
		return 106.0f / 320.0f;
	default:
		break;
	}
}

float Block::getCurrentScaleX()
{
	return _content->getScaleX();
}

void Block::setZScaleX(float scaleX)
{
	_content->setScaleX(scaleX);
	_stencil->setPosition(getZWidth() / 2.0f, _content->getContentSize().height / 2.0f);
	_shape->setPosition(getZWidth() / 2.0f, _content->getContentSize().height / 2.0f);
}

float Block::getZWidth()
{
	return _content->getContentSize().width * _content->getScaleX();
}





