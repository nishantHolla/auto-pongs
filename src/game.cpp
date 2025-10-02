#include "auto_pong.hpp"
#include "raylib.h"
#include "raymath.h"

#include <vector>

Game::Game() : grid(ROW_COUNT, std::vector(COL_COUNT, 0)) {
  InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE);
  SetTargetFPS(60);
  four_pong_setup(grid, pongs);

  for (auto& [id, pong] : pongs) {
    pong.score = 0;
  }

  for (int r = 0, rows = grid.size(); r < rows; ++r) {
    for (int c = 0, cols = grid[r].size(); c < cols; ++c) {
      ++pongs[grid[r][c]].score;
    }
  }
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

#if SHOW_DEBUG_GRID == 1
  for (int r = 0, rows = grid.size(); r < rows; ++r) {
    DrawLine(0, r * CELL_HEIGHT, WINDOW_WIDTH, r * CELL_HEIGHT, RED);
  }

  for (int c = 0, cols = grid[0].size(); c < cols; ++c) {
    DrawLine(c * CELL_WIDTH, 0, c * CELL_WIDTH, WINDOW_HEIGHT, RED);
  }
#endif // SHOW_DEBUG_GRID
}

void Game::draw_scores() const {
  for (auto& [id, pong] : pongs) {
    DrawText(TextFormat("%i", pong.score), pong.text_pos.x, pong.text_pos.y, 40, pong.fg_color);
  }
}

void Game::draw_pongs() const {
  for (auto& [id, pong] : pongs) {
    DrawCircle(pong.pos.x, pong.pos.y, PONG_RADIUS, pong.fg_color);
  }
};

bool Game::is_running() const {
  return !WindowShouldClose();
}

void Game::show() const {
  BeginDrawing();
  ClearBackground(BLACK);

  draw_background();
  draw_scores();
  draw_pongs();

  EndDrawing();
}

void Game::update() {
  for (auto& [id, pong] : pongs) {
    Vector2 top = Vector2Add(pong.pos, { 0, -PONG_RADIUS });
    int top_col = top.x / CELL_WIDTH;
    int top_row = top.y / CELL_HEIGHT;

    if (in_bound(top_col, top_row) && grid[top_row][top_col] != id) {
      --pongs[grid[top_row][top_col]].score;
      ++pong.score;
      grid[top_row][top_col] = id;
      pong.vel.y *= -1;
    }

    Vector2 right = Vector2Add(pong.pos, { PONG_RADIUS, 0 });
    int right_col = right.x / CELL_WIDTH;
    int right_row = right.y / CELL_HEIGHT;

    if (in_bound(right_col, right_row) && grid[right_row][right_col] != id) {
      --pongs[grid[right_row][right_col]].score;
      ++pong.score;
      grid[right_row][right_col] = id;
      pong.vel.x *= -1;
    }

    Vector2 bottom = Vector2Add(pong.pos, { 0, PONG_RADIUS });
    int bottom_col = bottom.x / CELL_WIDTH;
    int bottom_row = bottom.y / CELL_HEIGHT;

    if (in_bound(bottom_col, bottom_row) && grid[bottom_row][bottom_col] != id) {
      --pongs[grid[bottom_row][bottom_col]].score;
      ++pong.score;
      grid[bottom_row][bottom_col] = id;
      pong.vel.y *= -1;
    }

    Vector2 left = Vector2Add(pong.pos, { -PONG_RADIUS, 0 });
    int left_col = left.x / CELL_WIDTH;
    int left_row = left.y / CELL_HEIGHT;

    if (in_bound(left_col, left_row) && grid[left_row][left_col] != id) {
      --pongs[grid[left_row][left_col]].score;
      ++pong.score;
      grid[left_row][left_col] = id;
      pong.vel.x *= -1;
    }

    pong.pos = Vector2Add(pong.pos, pong.vel);

    if (pong.pos.x - PONG_RADIUS < 0 || pong.pos.x + PONG_RADIUS >= WINDOW_WIDTH) {
      pong.vel.x *= -1;
    }

    if (pong.pos.y - PONG_RADIUS < 0 || pong.pos.y + PONG_RADIUS >= WINDOW_HEIGHT) {
      pong.vel.y *= -1;
    }

    pong.pos.x = Clamp(pong.pos.x, PONG_RADIUS, WINDOW_WIDTH - PONG_RADIUS);
    pong.pos.y = Clamp(pong.pos.y, PONG_RADIUS, WINDOW_HEIGHT - PONG_RADIUS);
  }
}

bool Game::in_bound(int x, int y) {
  return (x >= 0 && y >= 0 && x < COL_COUNT && y < ROW_COUNT);
}
