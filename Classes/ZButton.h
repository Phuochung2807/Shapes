#ifndef _Z_BUTTON_H_
#define _Z_BUTTON_H_

#include "cocos2d.h"

enum ZButtonStyle
{
	CLICK,
	TOGGLE
};

class ZButton
{
public:
	
	static ZButton* create(int type, cocos2d::Vec2 position,
		cocos2d::Sprite* nrmSprite, cocos2d::Sprite* pressSprite, cocos2d::Sprite* disSprite,
		cocos2d::ccMenuCallback callback, cocos2d::Menu* menu = NULL, std::string name = "", 
		cocos2d::Vec2 offset = cocos2d::Vec2::ZERO);

private:
	CC_SYNTHESIZE_READONLY(cocos2d::Menu*, _menu, Menu);
	CC_SYNTHESIZE_READONLY(int, _type, Type);
	CC_SYNTHESIZE_READONLY(cocos2d::MenuItem*, _item, Item);
	CC_SYNTHESIZE_READONLY(cocos2d::Label*, _label, Label);

	CC_SYNTHESIZE(std::string, _name, Name);

	cocos2d::Sprite *_nrmSprite, *_pressSprite, *_disSprite;
	cocos2d::ccMenuCallback _callBack;
	cocos2d::Vec2 _postion;
	cocos2d::Vec2 _offset;


	bool init();
	bool buildButtonClick();
	bool buildButtonToggle();
};

#endif