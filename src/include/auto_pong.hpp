#ifndef AUTO_PONG_H_
#define AUTO_PONG_H_

#include "raylib.h"

#include <vector>
#include <unordered_map>

#define SHOW_DEBUG_GRID 0

constexpr int WINDOW_WIDTH = 800;
constexpr int WINDOW_HEIGHT = 800;
constexpr const char* WINDOW_TITLE = "Auto Pong";

constexpr int ROW_COUNT = 10;
constexpr int COL_COUNT = 10;
constexpr int CELL_WIDTH = (WINDOW_WIDTH / COL_COUNT);
constexpr int CELL_HEIGHT = (WINDOW_HEIGHT / ROW_COUNT);
constexpr int PONG_RADIUS = CELL_WIDTH * 0.2;

struct Pong {
  Vector2 pos;
  Vector2 vel;
  Color bg_color;
  Color fg_color;
};

typedef std::vector<std::vector<int>> Grid;
typedef std::unordered_map<int, Pong> PongMap;

class Game {
public:
  Game();
  ~Game();
  void draw_background() const;
  void draw_pongs() const;
  bool is_running() const;
  void show() const;
  void update();

private:
  Grid grid;
  PongMap pongs;
  bool in_bound(int x, int y);
};


#endif // !AUTO_PONG_H_
