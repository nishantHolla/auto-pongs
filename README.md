# Auto Pong

A C++/Raylib implementation of [Pong Wars](https://github.com/vnglst/pong-wars) where multiple
pong games fight for territory on the screen.
<br />
Supports any number of pongs, not just 2.

## Screenshots

### Two pongs


https://github.com/user-attachments/assets/6f35d3b9-5290-4791-bd9b-b85de5945eb0


### Three pongs


https://github.com/user-attachments/assets/e22238ed-71a4-4798-89c9-34eb8c4e7874


### Four pongs

https://github.com/user-attachments/assets/918d68c0-0201-4846-8dad-404f8fe75e52

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
