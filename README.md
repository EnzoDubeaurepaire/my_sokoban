# My_Sokoban

Welcome to My_Sokoban, a Sokoban game implemented in C using the ncurses library!

## Description
My_Sokoban is a classic puzzle game where the player needs to push boxes onto designated spots in a maze. The game features simple yet challenging gameplay, requiring strategic thinking and planning to solve each level.

## Installation
To get started with My Sokoban, follow these steps:

1. **Clone the repository**: You can clone this repository to your local machine using the following command:
    ```bash
    git clone https://github.com/EnzoDubeaurepaire/my_sokoban.git
    ```

2. **Navigate to the directory**: Once cloned, navigate to the directory where you cloned the repository:
    ```bash
    cd my_sokoban
    ```

3. **Compile the game**: Compile the game using the provided Makefile:
    ```bash
    make
    ```

3. **Launch the game**:
    ```bash
    ./my_sokoban [path_to_map]
    ```

## How to Play
- Use the arrow keys to move the player character (P) around the maze.
- Push the boxes (X) into the goal positions (O) to complete each level.
- Avoid getting trapped by pushing boxes into inaccessible areas or against walls.

## Map File Format
- The game requires a map file to be provided as an argument when launching.
- The map file should contain the layout of the level, using the following characters:
  - `#` for walls
  - `P` for the player's starting position
  - `X` for boxes
  - `O` for goal positions
  - ` ` for empty spaces

## Example Map File
```
##########
#O       #
#####    #
#   X    #
#        #
#P       #
##########
```
