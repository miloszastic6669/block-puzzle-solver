#include "Drawing.h"
#include <iostream>
//#define DEBUG_DRAW


namespace Draw
{
  int selected_block = 0;
}
void Draw::draw_field(const Field &f)
{

  //draw board
  for(int i = 0; i < 8; ++i)//x
  {
    for(int j = 0; j < 8; ++j)//y
    {
      DrawRectangleLines(i*(SIZE/8), j*(SIZE/8), SIZE/8, SIZE/8, WHITE);
    }

  }

  //draw field squares
  for(const auto& row : f.field_squares)
  {
    for(const auto& col : row)
    {
      switch (col.type)
      {
      case SquareType::OCCUPIED:
        DrawRectangle((col.get_x()*SIZE/8)+5, (col.get_y()*SIZE/8)+5, (SIZE/8)-10,(SIZE/8)-10, DARKBLUE );
        break;
      case SquareType::EMPTY:
      break;
      case SquareType::OPTIONAL:
        DrawRectangle((col.get_x()*SIZE/8)+5, (col.get_y()*SIZE/8)+5, (SIZE/8)-10,(SIZE/8)-10, DARKGRAY );
        break;
      default:
        break;
      }
    }
  }

}

void Draw::draw_blocks(const std::array<Block, 3>& blocks)
{
  
  int x_offset = SIZE/5;
  int y_offset = SIZE + (SIZE_WINDOW-SIZE)/3;
  int square_size = 30;
  if(IsKeyDown(KEY_ONE)) selected_block = 0;
  if(IsKeyDown(KEY_TWO)) selected_block = 1;
  if(IsKeyDown(KEY_THREE)) selected_block = 2;
  for(int k = 0; k < blocks.size(); k++)
  {
    auto block = blocks[k];
    //draw block
    auto data = block.get_data();
    for(int i = 0; i < data.size(); i++)
    {
      for(int j = 0; j < data[0].length(); j++)
      {
        Color block_color = BLUE;
        if(k == selected_block) block_color = WHITE;
        if(data[i][j] == 'y') 
          DrawRectangle(x_offset+j*square_size, y_offset + i*square_size, square_size-2, square_size-2, block_color);
      }
    }
    x_offset += SIZE/5;
  }
}

void Draw::draw_placement(const Block& block, Field& f, int x, int y, bool put)
{
  //get selected block and draw what it would look like on the field
  //check whether any block piece collides with present blocks on the field
  if(x == -1 or y == -1) 
  {
    f.clean_optionals();
    return;
  }
  if(!f.try_put(block, x,y)) return;
  f.put(block, x,y, put ? SquareType::OCCUPIED : SquareType::OPTIONAL);

  if(put)
    f.update();

}
