# Auto Pong

A C++/Raylib implementation of [Pong Wars](https://github.com/vnglst/pong-wars) where multiple
pong games fight for territory on the screen.
<br />
Supports any number of pongs, not just 2.

## Screenshots

### Two pongs

![Tow pongs](./docs/assets/2_pong.gif)

### Three pongs

![Three pongs](./docs/assets/3_pong.gif)

### Four pongs

![Four pongs](./docs/assets/4_pong.gif)

## Build and Run

- Clone the repo with all the submodules (raylib)
```bash
git clone --recurse-submodules https://github.com/nishantHolla/auto-pong.git
cd auto-pong
```

- Build using cmake
```bash
mkdir build && cd build
cmake ..
cmake --build . && ./AutoPong
```
