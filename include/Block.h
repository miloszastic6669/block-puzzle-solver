#pragma once
#include <string>
#include <vector>
#include "Utility.h"

class Block
{
private:
  std::vector<std::string> block;
public:  
  Block(const std::vector<std::string>& data);
  
  const std::vector<std::string>& get_data() const;

  const SquareType get_type(int x, int y) const;
};

namespace Blocks
{
  Block get_random_block();
  const std::vector<Block> blocks = 
  {
    Block({"xyx",
           "yyy"}),
    Block({"yyy",
           "xyx"}),
    Block({"xy",
           "yy",
           "xy"}), 
    Block({"yx",
           "yy",
           "yx"}),
          };

}