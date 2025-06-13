#include "Square.h"
#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include "Field.h"

Square::Square(int _x, int _y) : x(_x), y(_y)
{
  if(_x < 0)
  {
    throw std::out_of_range("x is less than 0");
  }
  else if(_x > 7)
  {
    throw std::out_of_range("x is more than 7");
  } 

  if(_y < 0)
  {
    throw std::out_of_range("y is less than 0");
  }
  else if(_y > 7)
  {
    throw std::out_of_range("y is more than 7");
  } 
  type = SquareType::EMPTY;
}

std::vector<Square> Square::neighbors(Field &f)
{
  std::vector<Square> r;
  Square n(x, y-1);
  Square e(x+1, y);
  Square s(x, y+1);
  Square w(x-1, y);

  //neighbors: [0]: North; [1]: East; [2]: South; [3]: West
  
  r.push_back(f.get(n.x, n.y));
  r.push_back(f.get(e.x, e.y));
  r.push_back(f.get(s.x, s.y));
  r.push_back(f.get(w.x, w.y));
  return r;
}

std::vector<SquareType> Square::neighbors_types(const Field &f)
{
  std::vector<SquareType> r;
  return r;
}

void Square::set(int _x, int _y)
{
  if(_x < 0 || _x > 7) throw std::out_of_range("x is too little or too large!");
  if(_y < 0 || _y > 7) throw std::out_of_range("y is too little or too large!");
  x = _x;
  y = _y;
}

void Square::set_type(SquareType st)
{
  type = st;
  
}
