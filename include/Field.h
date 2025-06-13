#pragma once 
#include "raylib.h"
#include <string>
#include <array>
#include "Square.h"
#include "Utility.h"
#include "Block.h"

class Square;

class Field
{
public:
  std::array<std::array<Square, 8>, 8> field_squares;

  int active_squares();//number of active squares
  
  Square get(int x, int y) const;
  SquareType get_type(int x, int y);
  
  //x = empty, y = filled, 
  Field(std::array<std::string, 8>& field);

  //return false if impossible
  bool put(const Block& block, int x, int y, SquareType type = SquareType::OCCUPIED);

  bool try_put(const Block& block, int x, int y) const;

  void clean_optionals();

  Square get_mouse_hover(Vector2 mouse_pos);

};

