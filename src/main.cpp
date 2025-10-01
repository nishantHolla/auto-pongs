#include "auto_pong.hpp"
#include "raylib.h"

int main(void) {
  Game game;

  while (game.is_running()) {
    game.show();
    game.update();
  }

  return 0;
}
