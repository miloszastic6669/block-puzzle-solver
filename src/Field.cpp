#include "Field.h"
#include <stdexcept>
#include "Drawing.h"
#include <iostream>
int Field::active_squares()
{
  return 0;
}

Square Field::get(int x, int y) const
{
  return field_squares[y][x];
}

SquareType Field::get_type(int x, int y)
{
  return this->get(x,y).type;
}

Field::Field(std::array<std::string, 8>& field)
{
  for(int i = 0; i < 8; i++)//x
  {
    for(int j = 0; j < 8; j++)//y
    {
      field_squares[j][i] = Square(i,j); 
      switch (field[j][i])
      {
        case 'x':
        field_squares[j][i].type = SquareType::EMPTY;
        break;

        case 'y':
        field_squares[j][i].type = SquareType::OCCUPIED;
        break;
      
      default:
        throw std::domain_error("invalid char");
        break;
      }
    }
  }
}

bool Field::put(const Block &block, int _x, int _y, SquareType _type)
{
  auto data = block.get_data();
  
  if(!try_put(block, _x, _y)) return false;//if block doesn't fit

  for(int y = 0; y < data.size(); y++)//y
  {
    for(int x = 0; x < data[0].length(); x++)//x
    {
      SquareType type = block.get_type(x,y);
      if(type == SquareType::OCCUPIED ) field_squares[y+_y][x+_x].type = _type; 
    }
  }
  return true;
}

bool Field::try_put(const Block &block, int _x, int _y) const
{
  auto data = block.get_data();
  if(_x < 0 or _y < 0) return false;
  for(int y = 0; y < data.size(); y++)//y
  {
    for(int x = 0; x < data[0].length(); x++)//x
    {
      if(data[y][x] == 'x') continue;
      SquareType type = block.get_type(x,y);
      if(type == SquareType::OCCUPIED && get(_x+x, _y+y).type == SquareType::OCCUPIED) return false;
      if(x+_x > 7 || y+_y > 7) return false;
    }
  }

  return true;
}

void Field::clean_optionals()
{
  for(auto& row : field_squares)
  {
    for(auto& square : row)
    {
      if(square.type == SquareType::OPTIONAL) 
        {
          square.type = SquareType::EMPTY;      
        }
    }
  }
}

Square Field::get_mouse_hover(Vector2 mouse_pos)
{
  int x, y;
  
  //invalid
  if(mouse_pos.x > SIZE or mouse_pos.y > SIZE) return Square();
  if(mouse_pos.x <= 0 or mouse_pos.y <= 0) return Square();

  x = int( (mouse_pos.x)/(SIZE/8) );
  y = int( (mouse_pos.y)/(SIZE/8) );

  return get(x,y);


}

void Field::update()
{
  
  std::vector<Square*> squares;
  //check filled rows
  for(auto& row : field_squares)
  {
    bool filled = true;
    for(auto& square : row)
    {
      if(square.type == SquareType::EMPTY)
        filled = false;
    }
    if(filled)
    {
      for(auto& square : row)
        squares.push_back(&square); 
    }
  }


  //check filled columns
  for(int i = 0; i < field_squares.size(); ++i)
  {

    bool filled = true;
    for(int j = 0; j < field_squares[i].size(); ++j)
    {
      if(field_squares[j][i].type == SquareType::EMPTY)
      {
        filled = false;
        break;
      }
    }
    if(filled)
    {
      for(int j = 0; j < field_squares[i].size(); ++j)
      {
        squares.push_back(&field_squares[j][i]);
      }
    }

    

  } 

  //delete away
  for(auto& s : squares)
  {
    s->set_type(SquareType::EMPTY);

  }
}
