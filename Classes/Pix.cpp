#include "Pix.h"
#include "Constants.h"

USING_NS_CC;

Pix* Pix::create(int color)
{
	auto pix = new Pix();
	pix->_color = color;
	if (pix && pix->init())
	{
		pix->autorelease();
		return pix;
	}
	CC_SAFE_DELETE(pix);
	return NULL;
}

bool Pix::init()
{
	if (!Sprite::initWithSpriteFrameName(SHAPES[_color]))
	{
		return false;
	}
	auto p = ParticleSystemQuad::create(PARTICLES[_color]);
	this->addChild(p, -1);
	p->setPosition(this->getContentSize().width / 2.0f, this->getContentSize().height * 0.70f);
	return true;
}
