# cub_3d

## Introduction 🤔
This project is inspired by the world-famous 90’s game Wolfeinstein 3D, which was the first FPS ever. 
It will enable to explore ray-casting. My goal will be to make a dynamic view inside a maze, in which you’ll have to find your way

The project runs using the MiniLibX, a simplified version of the Xlib. It can therefore only run in MacOSX, preferably on a computer with a solid CPU !



## Installation & Usage ❕

1. Download/Clone this repo

        git clone https://github.com/kazuumaVII/cub_3d.git
2. `cd` into the root directory and run `make`

        cd cub_3d
        make

3. After building the source `./test` from the project root.


## Mandatory  🌐
- Can only use C
- Must respect the school imposed coding style (42 Norme)
- No memory leaks

key  | function |
---|------|
left/right arrow or `q`/`e`| turn				|
`w` `a` `s` `d` | move					|
`space` | run		
you may edit all these settings:

resolution, ceiling and floor colors (range 0 - 255), walls and sprite textures, map. The map must be sorrounded by walls(1) and have the initial player position and direction (W- west, E- east, N-north, S-south)

```
R 1280 720

C 92, 148, 252
F 128, 208, 15

WE ./textures/walls/mario_1.XPM
EA ./textures/walls/mario_4.XPM
NO ./textures/walls/mario_2.XPM
SO ./textures/walls/mario_3.XPM
S ./textures/sprites/mario.XPM

11111111111111111111111
100S0010000100010000111
11000000000000000000111
10000000011111000000011
10020000000000000001111
10000010000000000111111
11102011000100000000011
10000011000100002000001
11000001000100000000111
11000020010110200011111
11011000001110002000111
11111111111111111111111
```


## Builtins implemented  🔨




## Final grade : 105/115 ✅
Mandatory part : 100/100

Bonus : 5/15
