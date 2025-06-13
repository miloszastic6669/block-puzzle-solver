#pragma once
#include "raylib.h"
#include "Utility.h"
#include <vector>


class Field;


class Square 
{
private:
  int x,y;

public:
  SquareType type = SquareType::EMPTY;

  Square(int _x, int _y);
  
  Square() : x(-1), y(-1)
  {
    type = SquareType::OOB;
  }

  std::vector<Square> neighbors(Field& f);//neighbors: [0]: North; [1]: East; [2]: South; [3]: West
  std::vector<SquareType> neighbors_types(const Field& f);//neighbors: [0]: North; [1]: East; [2]: South; [3]: West
  

  void set(int x, int y);
  void set_type(SquareType);
  int get_x() const {return x;}
  int get_y() const {return y;}

  

  
};