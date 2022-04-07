#include "Block.h"



Block::Block()
{
}

Block::~Block()
{
}

void Block::Start()
{
	BlockRender_ = CreateRenderer("Blocks.bmp");
}