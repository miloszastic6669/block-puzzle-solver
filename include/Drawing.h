#pragma once
#include "raylib.h"
#include "Field.h"
#include "Utility.h"


#define SIZE 800
#define SIZE_WINDOW 1000

namespace Draw
{
  extern int selected_block;
  void draw_field(const Field& f);
  void draw_blocks(const std::array<Block, 3>& b);
  void draw_placement(const Block& block, Field& f, int x, int y, bool put = false); //put = true if the user clicked the mouse button to place block

}


