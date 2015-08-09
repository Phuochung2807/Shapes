#include "ZButton.h"
#include "Constants.h"

USING_NS_CC;

ZButton* ZButton::create(int type, cocos2d::Vec2 position, 
	cocos2d::Sprite* nrmSprite, cocos2d::Sprite* pressSprite, cocos2d::Sprite* disSprite, 
	cocos2d::ccMenuCallback callback, 
	cocos2d::Menu* menu /*= NULL*/, 
	std::string name /*= ""*/, 
	Vec2 offset /*= Vec2.ZERO*/)
{
	auto zbutton = new ZButton();
	zbutton->_type = type;
	zbutton->_postion = position;
	zbutton->_nrmSprite = nrmSprite;
	zbutton->_pressSprite = pressSprite;
	zbutton->_disSprite = disSprite;
	zbutton->_callBack = callback;
	zbutton->_menu = menu;
	zbutton->_name = name;
	zbutton->_offset = offset;

	if (zbutton && zbutton->init())
	{
		return zbutton;
	}
	CC_SAFE_DELETE(zbutton);
	return NULL;
}

bool ZButton::init()
{
	if (_menu == NULL)//chua co menu
	{
		_menu = Menu::create();
		_menu->setPosition(0, 0);
	}

	if (_type == ZButtonStyle::CLICK)
	{
		buildButtonClick();
	}
	else if (_type == ZButtonStyle::TOGGLE)
	{
		buildButtonToggle();
	}

	_item->setPosition(_postion);
	_item->setUserData(this);
	_menu->addChild(_item);
	return true;
}

bool ZButton::buildButtonClick()
{
	_item = MenuItemSprite::create(_nrmSprite, _pressSprite, _disSprite, _callBack);
	if (_name != "")
	{
		_label = Label::createWithBMFont(FONT_BUTTON, _name, TextHAlignment::CENTER);
		_label->setPositionX(_item->getContentSize().width / 2.0f + _offset.x);
		_label->setPositionY(_item->getContentSize().height / 2.0f + _offset.y);
		_item->addChild(_label);
	}

	return true;
}

bool ZButton::buildButtonToggle()
{
	auto nor = MenuItemSprite::create(_nrmSprite, NULL);
	auto press = MenuItemSprite::create(_pressSprite, NULL);
	_item = MenuItemToggle::createWithCallback(_callBack, nor, press, NULL);

	return true;
}
