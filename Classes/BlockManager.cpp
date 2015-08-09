#include "BlockManager.h"
#include "Block.h"
#include "Constants.h"
#include "ScaleCustomAction.h"
#include "Pix.h"

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
	for (int color = 0; color < NUM_OF_COLOR; color++)
	{
		for (int k = 0; k < 2; k++)
		{
			auto b = Block::create(color, 0);
			_blocksPools.push_back(b);
			this->addChild(b);
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
	auto tmp = _blocksPools.at(color * 2);
	if (tmp->isVisible())
	{
		tmp = _blocksPools.at(color * 2 + 1);
	}
	tmp->setZScaleX(Block::getScaleShape(type));
	return tmp;
}

bool BlockManager::next()
{
	if (isLocking)
		return false;

	isLocking = true;
	bool noticeSwitch = false;
	_type = getBMTypeByCount(_count, noticeSwitch);
	if (noticeSwitch)
	{
		auto b = getBlock(_currentBlocks.size(), _type - 3);
		b->setPosition(640.0f, 0.0f);
		b->setVisible(true);
		_currentBlocks.push_back(b);

		for (int i = 0, imax = _currentBlocks.size() - 1; i < imax; i++)
		{
			_currentBlocks[i]->runAction(ScaleCustomAction::create(0.35f, Block::getScaleShape(_type - 2), i * widthBlock[_type]));
		}
		_currentBlocks.at(_currentBlocks.size() - 1)->runAction(Sequence::create(ScaleCustomAction::create(0.35f, Block::getScaleShape(_type - 2), (_currentBlocks.size() - 1) * widthBlock[_type]), CallFunc::create([this](){
			switchTypeCompleted();
		}), NULL));
		return true;
	}
	else
	{
		auto b = getBlock(_currentBlocks.at(0)->getZColor(), _type - 2);
		b->setPosition(getPositionForNextBlock(_currentBlocks.at(_currentBlocks.size() - 1)));
		b->setVisible(true);
		_currentBlocks.push_back(b);

		for (int i = 0, imax = _currentBlocks.size() - 1; i < imax; i++)
		{
			auto b = _currentBlocks.at(i);
			b->runAction(MoveBy::create(TIME_TRANSITION[_type], Vec2(-widthBlock[_type], 0)));
		}
		_currentBlocks.at(_currentBlocks.size() - 1)->runAction(Sequence::create(MoveBy::create(TIME_TRANSITION[_type], Vec2(-widthBlock[_type], 0)), CallFunc::create([this](){
			transitionCompleted();
		}), NULL));
	}
	return false;
}


void BlockManager::reset()
{
	for (auto b : _blocksPools)
	{
		b->setVisible(false);
		b->setZScaleX(1.0f);
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
	float x = b->getPositionX();
	x += b->getZWidth();
	return Vec2(x, 0);
}

int BlockManager::getBMTypeByCount(int count, bool& noticeSwitch)
{
	int newtype = -1;
	if (count < 2)
	{
		newtype =  BlockManagerType::B_2;
	}
	else if (count < 10)
	{
		newtype = BlockManagerType::B_3;
	}
	else if (count < 18)
	{
		newtype = BlockManagerType::B_4;
	}
	else if (count < 30)
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

void BlockManager::switchTypeCompleted()
{
	_count++;
	isLocking = false;
}

int BlockManager::getType()
{
	return _type;
}

bool BlockManager::isMatching(Pix* pix)
{
	Block* b = getLane(pix->getTag());
	if (b->isMatch(pix->getZColor()))
	{
		return true;
	}
	return false;
}

Block* BlockManager::getLane(int lane)
{
	if (lane >= 0 && lane < _currentBlocks.size())
	{
		return _currentBlocks[lane];
	}
	return NULL;
}




