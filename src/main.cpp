#include "raylib.h"
#include <iostream>
#include <string>
#include <vector>
#include "Drawing.h"

int main()
{
  // x -> empty, y -> occupied
  std::array<std::string, 8>  field = 
  {
    "xxxxxxxx",
    "xxxxxxxx",
    "xxxxxxxx",
    "xxxxxxxx",
    "xxxxxxxx",
    "xxxxxxxx",
    "xxxxxxxx",
    "xxxxxxxx"
  };
  Field f(field);
  std::cout << "Sizeof(f):" << sizeof(f) << "\n";
  std::array<Block, 3> current_blocks = { Blocks::blocks[0],Blocks::blocks[1],Blocks::blocks[2]  };
  InitWindow(SIZE_WINDOW, SIZE_WINDOW, "cock");
  Square prev;
  while (!WindowShouldClose())
  {
    Square s = f.get_mouse_hover(GetMousePosition());
    BeginDrawing();
    ClearBackground(BLACK);

    Draw::draw_field(f);
    Draw::draw_blocks(current_blocks);
    
    if(prev.get_x() != s.get_x() or prev.get_y() != s.get_y())
    f.clean_optionals();
    
    prev = s;
    
    if(IsMouseButtonDown(MOUSE_BUTTON_LEFT))
      Draw::draw_placement(current_blocks[Draw::selected_block], f, s.get_x(), s.get_y(), true);
    else 
      Draw::draw_placement(current_blocks[Draw::selected_block], f, s.get_x(), s.get_y());

    EndDrawing();
    //check should close window
    if(IsKeyDown(KEY_LEFT_CONTROL) and IsKeyDown(KEY_C))
    {
      CloseWindow();
    }
    if(IsKeyPressed(KEY_SPACE))
    {
      std::cout << f.put(Blocks::blocks[1], 3,2);
    }
  }

  CloseWindow();

  return 0;
}
