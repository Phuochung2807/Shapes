#ifndef _CONSTANTS_H_
#define _CONSTANTS_H_

#include "cocos2d.h"

#define DESIGN_RESOLUTION_WIDTH 640.0f
#define DESIGN_RESOLUTION_HEIGHT 1138.0f

#define DESIGN_RESOURCE_PATH "640"

#define FONT_BUTTON "fonts/fontnewF.txt"
#define FONT_NUMBER	"fonts/number2F.txt"

#define SPRITE_BACKGROUND "background.png"

#define SPRITES	"block.plist"

#define NUM_OF_COLOR	6
#define TYPE_BLOCK	5

static const char *BLUE[TYPE_BLOCK] = {
	"blue_1.png",
	"blue_2.png",
	"blue_3.png",
	"blue_4.png",
	"blue_5.png",
};

static const char *ORANGE[TYPE_BLOCK] = {
	"orange_1.png",
	"orange_2.png",
	"orange_3.png",
	"orange_4.png",
	"orange_5.png",
};

static const char *GREEN[TYPE_BLOCK] = {
	"green_1.png",
	"green_2.png",
	"green_3.png",
	"green_4.png",
	"green_5.png",
};

static const char *YELLOW[TYPE_BLOCK] = {
	"yellow_1.png",
	"yellow_2.png",
	"yellow_3.png",
	"yellow_4.png",
	"yellow_5.png",
};

static const char *PINK[TYPE_BLOCK] = {
	"pink_1.png",
	"pink_2.png",
	"pink_3.png",
	"pink_4.png",
	"pink_5.png",
};

static const char *BROWN[TYPE_BLOCK] = {
	"brown_1.png",
	"brown_2.png",
	"brown_3.png",
	"brown_4.png",
	"brown_5.png",
};

#define UI_LOGO	"logo.png"

#define UI_GAMEOVER	"gameover.png"

#define UI_BT_PLAY_NORMAL	"ui_bt_play_normal.png"
#define UI_BT_PLAY_PRESS	"ui_bt_play_press.png"

#define UI_BT_REPLY_NORMAL	"ui_bt_replay_normal.png"
#define UI_BT_REPLY_PRESS	"ui_bt_replay_press.png"

#define LOGO_NEWBIE	"LOGO_Newbie.png"

#define KEY_HIGH_SCORE	"key_high_score"
#define KEY_CURRENT_COUNT_OPEN_APP	"key_current_count_open_app"

#define AD_MOB_ID "ca-app-pub-3738202989627662/7310321232"
#define AD_MOB_INTER_ID	"ca-app-pub-3738202989627662/8787054433"

#if(CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)//android, win32 => .mp3

#else(CC_TARGET_PLATFORM == CC_PLATFORM_WP8)//wp8 => .wav

#endif

#endif