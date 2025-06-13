#include "Block.h"
#include <stdexcept>
#include <random>
Block::Block(const std::vector<std::string>& data)
{
  if(data.size() == 0)
    throw std::invalid_argument("data.size() == 0");
  
  if(data[0].length() == 0)
    throw std::invalid_argument("data[0].length() == 0");
  
  
  block = data;
}

const std::vector<std::string>& Block::get_data() const  
{
  return block;
}

const SquareType Block::get_type(int x, int y) const
{
  if(x < 0 || x > this->block[0].length()-1) throw std::out_of_range("x too large!");
  if(y < 0 || y > this->block.size()-1) throw std::out_of_range("y too large!");

  if(block[y][x] == 'x') return SquareType::EMPTY;
  if(block[y][x] == 'y') return SquareType::OCCUPIED;

}

Block Blocks::get_random_block()
{
  static std::random_device rd;
  static std::mt19937 gen(rd());
  static std::uniform_int_distribution<> dist(0, blocks.size());
  return blocks[dist(gen)];
}
