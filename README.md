# Conway's Game of Life in C

A clean and efficient implementation of John Conway's legendary cellular automaton, written in C.

## About the Project
The simulation runs on a 20x40 grid. Each cell can be in one of two states: alive (`#`) or dead (`.`). The initial state is randomized, making every simulation unique.

### The Rules:
1. **Underpopulation:** Any live cell with fewer than 2 live neighbours dies.
2. **Survival:** Any live cell with 2 or 3 live neighbours lives on to the next generation.
3. **Overpopulation:** Any live cell with more than 3 live neighbours dies.
4. **Reproduction:** Any dead cell with exactly 3 live neighbours becomes a live cell.

## Technical Features
* **Double Buffering:** Uses a temporary buffer array to prevent state update conflicts during calculation.
* **Modularity:** Logic is divided into clear functions: `init_board`, `seed_board`, `count_neighbours`, `update_board`, and `print_board`.
* **Boundary Handling:** Safely checks neighbours at the edges of the grid to prevent memory access errors.
* **Interactive Mode:** Allows users to manually trigger the next generation.

## How to Run
This project was developed using Visual Studio (Windows).

1. Copy the code from the `.c` file.
2. Compile it in your C environment (Visual Studio, Code::Blocks, or via GCC).
3. Run the program and watch your cellular population evolve!

## Preview (3x18)
.......#..#.......
..###..#..........
.......#...##.....
