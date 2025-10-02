#include "auto_pong.hpp"
#include "raymath.h"
#include <cmath>

void two_pong_setup(Grid& grid, PongMap& pongs) {
  for (int r = 0, rows = ROW_COUNT; r < rows; ++r) {
    for (int c = 0, cols = COL_COUNT; c < cols; ++c) {
      grid[r][c] = (c < cols / 2) ? 0 : 1;
    }
  }

  pongs[0] = {
    {3 * CELL_WIDTH, (int)(ROW_COUNT / 2) * CELL_HEIGHT},
    random_vector_with_mag(7),
    {3, 3},
    0,
    {212, 212, 216, 255},
    {39, 39, 42, 255}
  };

  pongs[1] = {
    {(COL_COUNT - 3) * CELL_WIDTH, int(ROW_COUNT / 2) * CELL_HEIGHT},
    random_vector_with_mag(7),
    {WINDOW_WIDTH - 65, 3},
    0,
    {39, 39, 42, 255},
    {212, 212, 216, 255}
  };
}

void three_pong_setup(Grid& grid, PongMap& pongs) {
  for (int r = 0, rows = ROW_COUNT; r < rows; ++r) {
    for (int c = 0, cols = COL_COUNT; c < cols; ++c) {
      if (r < ROW_COUNT / 2 && c < COL_COUNT / 2)
        grid[r][c] = 0;
      else if (r >= ROW_COUNT / 2 && c >= COL_COUNT / 2)
        grid[r][c] = 2;
      else
        grid[r][c] = 1;
    }
  }

  pongs[0] = {
    {3 * CELL_WIDTH, 3 * CELL_HEIGHT},
    random_vector_with_mag(7),
    {3, 3},
    0,
    {252, 165, 165, 255},
    {239, 68, 68, 255}
  };

  pongs[1] = {
    {(COL_COUNT - 3) * CELL_WIDTH, 3 * CELL_HEIGHT},
    random_vector_with_mag(7),
    {WINDOW_WIDTH - 65, 3},
    0,
    {134, 239, 172, 255},
    {34, 197, 94, 255}
  };

  pongs[2] = {
    {(COL_COUNT - 3) * CELL_WIDTH, (ROW_COUNT - 3) * CELL_HEIGHT},
    random_vector_with_mag(7),
    {WINDOW_WIDTH - 65, WINDOW_HEIGHT - 35},
    0,
    {147, 197, 253, 255},
    {59, 130, 246, 255}
  };
}

void four_pong_setup(Grid& grid, PongMap& pongs) {
  for (int r = 0, rows = ROW_COUNT; r < rows; ++r) {
    for (int c = 0, cols = COL_COUNT; c < cols; ++c) {
      if (r < ROW_COUNT / 2 && c < COL_COUNT / 2)
        grid[r][c] = 0;
      else if (r >= ROW_COUNT / 2 && c >= COL_COUNT / 2)
        grid[r][c] = 3;
      else if (r >= ROW_COUNT / 2 && c < COL_COUNT / 2)
        grid[r][c] = 2;
      else
        grid[r][c] = 1;
    }
  }

  pongs[0] = {
    {3 * CELL_WIDTH, 3 * CELL_HEIGHT},
    random_vector_with_mag(7),
    {3, 3},
    0,
    {252, 165, 165, 255},
    {239, 68, 68, 255}
  };

  pongs[1] = {
    {(COL_COUNT - 3) * CELL_WIDTH, 3 * CELL_HEIGHT},
    random_vector_with_mag(7),
    {WINDOW_WIDTH - 65, 3},
    0,
    {134, 239, 172, 255},
    {34, 197, 94, 255}
  };

  pongs[2] = {
    {3 * CELL_WIDTH, (ROW_COUNT - 3) * CELL_HEIGHT},
    random_vector_with_mag(7),
    {3, WINDOW_HEIGHT - 35},
    0,
    {253, 224, 71, 255},
    {234, 179, 8, 255}
  };

  pongs[3] = {
    {(COL_COUNT - 3) * CELL_WIDTH, (ROW_COUNT - 3) * CELL_HEIGHT},
    random_vector_with_mag(7),
    {WINDOW_WIDTH - 65, WINDOW_HEIGHT - 35},
    0,
    {147, 197, 253, 255},
    {59, 130, 246, 255}
  };
}

Vector2 random_vector_with_mag(float magnitude) {
  float angle = ((float)GetRandomValue(0, 10000) / 10000.0f) * 2.0f * PI;
  Vector2 v = { cosf(angle), sinf(angle) };

  return Vector2Scale(v, magnitude);
}
