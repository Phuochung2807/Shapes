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

static const char *BACKGROUND_SHAPES[NUM_OF_COLOR] = {
	"blue_1.png",
	"orange_1.png",
	"green_1.png",
	"yellow_1.png",
	"pink_1.png",
	"brown_1.png",
};

static const char *INLINE_SHAPE[NUM_OF_COLOR] = {
	"blue_inline_.png",
	"orange_inline_.png",
	"green_inline_.png",
	"yellow_inline_.png",
	"pink_inline_.png",
	"brown_inline_.png",
};

static const char *INLINE_FILL[NUM_OF_COLOR] = {
	"blue_inline.png",
	"orange_inline.png",
	"green_inline.png",
	"yellow_inline.png",
	"pink_inline.png",
	"brown_inline.png",
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