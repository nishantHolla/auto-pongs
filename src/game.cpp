#include "auto_pong.hpp"
#include "raylib.h"

#include <vector>

Game::Game() : grid(ROW_COUNT, std::vector(COL_COUNT, 0)) {
  InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE);
  SetTargetFPS(60);

  for (int r = 0, rows = ROW_COUNT; r < rows; ++r) {
    for (int c = 0, cols = COL_COUNT; c < cols; ++c) {
      grid[r][c] = (c < cols / 2) ? 0 : 1;
    }
  }

  pongs[0] = {
    {3, 7},
    {0, 0},
    {255, 255, 255, 255},
    {  0,   0,   0, 255}
  };

  pongs[1] = {
    {12, 7},
    {0, 0},
    {  0,   0,  0,  255},
    {255, 255, 255, 255}
  };

}

Game::~Game() {
  CloseWindow();
}

void Game::draw_background() const {
  for (int r = 0, rows = grid.size(); r < rows; ++r) {
    for (int c = 0, cols = grid[r].size(); c < cols; ++c) {
      const int x = c * CELL_WIDTH;
      const int y = r * CELL_HEIGHT;
      const Pong& p = pongs.at(grid[r][c]);
      DrawRectangle(x, y, CELL_WIDTH, CELL_HEIGHT, p.bg_color);
    }
  }
}

void Game::draw_pongs() const {
  for (auto& [id, pong] : pongs) {
    const int x = (int)pong.pos.x * CELL_WIDTH + CELL_WIDTH / 2;
    const int y = (int)pong.pos.y * CELL_HEIGHT + CELL_HEIGHT / 2;
    const int r = CELL_WIDTH / 2;
    DrawCircle(x, y, r, pong.fg_color);
  }
};

bool Game::is_running() const {
  return !WindowShouldClose();
}

void Game::show() const {
  BeginDrawing();
  ClearBackground(BLACK);

  draw_background();
  draw_pongs();

  EndDrawing();
}

void Game::update() {
}
