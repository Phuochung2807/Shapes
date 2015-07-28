#ifndef __BLOCK_MANAGER__
#define __BLOCK_MANAGER__

#include "cocos2d.h"

enum BlockManagerType{
	B_2 = 2,
	B_3,
	B_4,
	B_5,
	B_6,
};

static float TIME_TRANSITION[] = {0, 0, 0.5f, 0.45f, 0.45f, 0.4f, 0.4f};
static float widthBlock[] = {0, 0, 320.0f, 213.0f, 160.0f, 128.0f, 106.0f};
class Block;

class BlockManager : public cocos2d::Node
{
public:
	static BlockManager* create(int idx);
	virtual bool init();

	void reset();
	void next();
protected:
	int _idx;
	int _type;
	int _idxLast;
	std::vector<Block*> _blocksPools;
	std::vector<Block*> _currentBlocks;
	cocos2d::Vec2 getPositionForBlock(int blockId, int type);
	Block* getBlock(int color, int type);
	void initPools();
	void onSwitchBlock();
	void transitionCompleted();
	cocos2d::Vec2 getPositionForNextBlock(Block* b);

	bool isLocking;
	CC_SYNTHESIZE(int, _count, Count);

	int getBMTypeByCount(int count, bool& noticeSwitch);
};

#endif