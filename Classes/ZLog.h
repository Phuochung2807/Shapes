#ifndef _Z_LOG_H_
#define _Z_LOG_H_

#include "cocos2d.h"
#include "Config.h"

#ifdef LOG_LEVEL_DEBUG
#define ZLOG_D(FORMAT, ...) cocos2d::log(FORMAT, ##__VA_ARGS__)
#else
	#define ZLOG_D(...) {}           
#endif

#ifdef LOG_LEVEL_INFO
#define ZLOG_I(FORMAT, ...) cocos2d::log(FORMAT, ##__VA_ARGS__)
#else
	#define ZLOG_I(...) {}           
#endif

#ifdef LOG_LEVEL_ERROR
#define ZLOG_E(FORMAT, ...) cocos2d::log(FORMAT, ##__VA_ARGS__)
#else
#define ZLOG_E(...) {}           
#endif

#endif