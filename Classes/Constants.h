#ifndef _CONSTANTS_H_
#define _CONSTANTS_H_

#include "cocos2d.h"

#define DESIGN_RESOLUTION_WIDTH 640.0f
#define DESIGN_RESOLUTION_HEIGHT 1138.0f

#define DESIGN_RESOURCE_PATH "640"

#define FONT_BUTTON "fonts/fontnewF.txt"
#define FONT_NUMBER	"fonts/font.txt"

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

static const char *SHAPES[NUM_OF_COLOR] = {
	"blue.png",
	"orange.png",
	"green.png",
	"yellow.png",
	"pink.png",
	"brown.png",
};

static const char *PARTICLES[NUM_OF_COLOR] = {
	"blue.plist",
	"orange.plist",
	"green.plist",
	"yellow.plist",
	"pink.plist",
	"brown.plist",
};

#define UI_LOGO	"logo.png"

#define UI_GAMEOVER	"gameover.png"

#define UI_BT_PLAY_NORMAL	"ui_bt_play_normal.png"
#define UI_BT_PLAY_PRESS	"ui_bt_play_press.png"

#define UI_BT_RETRY_NORMAL	"ui_bt_replay_normal.png"
#define UI_BT_RETRY_PRESS	"ui_bt_replay_press.png"

#define UI_BG_HOWTOPLAY	"howtoplay.png"

#define UI_BT_ALREADY_NORMAL	"taptoplay.png"
#define UI_BT_ALREADY_PRESS		"taptoplay.png"

#define LOGO_NEWBIE	"LOGO_Newbie.png"

#define KEY_HIGH_SCORE	"key_high_score"
#define KEY_CURRENT_COUNT_OPEN_APP	"key_current_count_open_app"
#define KEY_COMPLETED_TUTORIAL	"key_completed_tutorial"

#define AD_MOB_ID "ca-app-pub-3738202989627662/7310321232"
#define AD_MOB_INTER_ID	"ca-app-pub-3738202989627662/8787054433"

//#define AD_MOB_ID "ca-app-pub-3738202989627662/4770703634"
//#define AD_MOB_INTER_ID	"ca-app-pub-3738202989627662/6247436830"

static const float INIT_POSITION[5][6] = {
	{160.0f, 480.0f},
	{107.0f, 320.0f, 533.0f},
	{80.0f, 240.0f, 400.0f, 560.0f},
	{64.0f, 192.0f, 320.0f, 448.0f, 576.0f},
	{53.0f, 159.0f, 265.0f, 371.0f, 477.0f, 583.0f},
};

#endif