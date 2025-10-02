#include "auto_pong.hpp"
#include "raylib.h"

int main(void) {
  Game game(
    4 // Number of pongs (can be 2, 3, 4)
  );

  while (game.is_running()) {
    game.show();
    game.update();
  }

  return 0;
}
