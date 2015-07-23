#ifndef _CONFIG_H_
#define _CONFIG_H_

#include "cocos2d.h"
USING_NS_CC;

#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
#define IS_DEBUG_MODE 1
#else
#define IS_DEBUG_MODE 0
#endif

#if( IS_DEBUG_MODE > 0 )
#define LOG_LEVEL_DEBUG
#define LOG_LEVEL_INFO
#define LOG_LEVEL_ERROR
#endif


#endif /* _CONFIG_H_ */