#include "BlockManager.h"
#include "Block.h"
#include "Constants.h"
USING_NS_CC;


BlockManager* BlockManager::create(int idx)
{
	auto bm = new BlockManager();
	bm->_idx = idx;
	if (bm && bm->init())
	{
		bm->autorelease();
		return bm;
	}
	CC_SAFE_DELETE(bm);
	return NULL;
}

bool BlockManager::init()
{
	if (!Node::init())
	{
		return false;
	}

	initPools();
	reset();

	return true;
}

void BlockManager::initPools()
{

	for (int type = 0; type < TYPE_BLOCK; type++)
	{
		for (int color = 0; color < NUM_OF_COLOR; color++)
		{
			for (int k = 0; k < 2; k++)
			{
				auto b = Block::create(color, type);
				b->setAnchorPoint(Vec2::ANCHOR_BOTTOM_LEFT);
				_blocksPools.push_back(b);
				this->addChild(b);
			}
		}
	}
}

Vec2 BlockManager::getPositionForBlock(int blockId, int type)
{
	float per = DESIGN_RESOLUTION_WIDTH / type;
	return Vec2(per * blockId, 0);
}

Block* BlockManager::getBlock(int color, int type)
{
	auto tmp = _blocksPools.at(NUM_OF_COLOR * (type) + color * 2);
	if (tmp->isVisible())
		return _blocksPools.at(NUM_OF_COLOR * (type) + color * 2 + 1);
	else
		return tmp;
}

void BlockManager::next()
{
	if (isLocking)
		return;
	isLocking = true;
	bool noticeSwitch = false;
	_type = getBMTypeByCount(_count, noticeSwitch);
	if (noticeSwitch)
	{
		_currentBlocks.clear();

	}
	else
	{
		auto b = getBlock(_currentBlocks.at(0)->getZColor(), _currentBlocks.at(0)->getZType());
		b->setVisible(true);
		b->setPosition(getPositionForNextBlock(_currentBlocks.at(_currentBlocks.size() - 1)));
		b->setVisible(true);
		_currentBlocks.push_back(b);
		this->runAction(Sequence::create(MoveBy::create(TIME_TRANSITION[_type], Vec2(-widthBlock[_type], 0)), CallFunc::create([this](){
			transitionCompleted();
		}), NULL));
	}

}


void BlockManager::reset()
{
	for (auto b : _blocksPools)
	{
		b->setVisible(false);
	}

	_currentBlocks.clear();
	_type = BlockManagerType::B_2;
	_idxLast = 1;

	for (int i = 0; i < _type ; i++)
	{
		Block* b = getBlock(i, _type - 2);
		b->setVisible(true);
		b->setPosition(getPositionForBlock(i, _type));
		_currentBlocks.push_back(b);
	}
	isLocking = false;
	_count = 0;
	this->setPosition(Vec2::ZERO);
}

void BlockManager::onSwitchBlock()
{

}

void BlockManager::transitionCompleted()
{
	_currentBlocks.at(0)->setVisible(false);
	auto t = _currentBlocks.erase(_currentBlocks.begin());
	_count++;
	isLocking = false;
}

Vec2 BlockManager::getPositionForNextBlock(Block* b)
{
	float x = 0;
	x = b->getPositionX() + b->getContentSize().width;
	return Vec2(x, 0);
}

int BlockManager::getBMTypeByCount(int count, bool& noticeSwitch)
{
	int newtype = -1;
	if (count < 2)
	{
		newtype =  BlockManagerType::B_2;
	}
	else if (count < 6)
	{
		newtype = BlockManagerType::B_3;
	}
	else if (count < 10)
	{
		newtype = BlockManagerType::B_4;
	}
	else if (count < 14)
	{
		newtype = BlockManagerType::B_5;
	}
	else
	{
		newtype = BlockManagerType::B_6;
	}
	noticeSwitch = (newtype != _type);
	return newtype;
}




