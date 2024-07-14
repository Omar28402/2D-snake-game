Snake Game
This is a simple Snake Game implemented using C++ and OpenGL with GLUT. The game features multiple map selections, customizable snake colors, and varying difficulty levels. The project is divided into two main files: main.cpp and game.cpp.

Files Description
game.cpp
This file contains the main application logic, including the GLUT setup and the main game loop. It handles:

Initialization of the game window and display settings.
The main menu for selecting maps and snake colors.
Key bindings for navigating the menu and controlling the snake.
The main display callback to render the game elements.
Timer and reshape callbacks to manage game timing and window resizing.
main.cpp
This file contains the game logic and rendering functions, including:

Initializing the game grid.
Drawing the grid, snake, food, and damage elements.
Handling random number generation for food placement.
Functions for game updates and collision detection.

Controls
Arrow Keys: Navigate the menu and control the snake's direction during gameplay.
Page Up/Page Down: Change the snake's color in the menu.
F1: Start the game from the menu.
Features
Multiple Maps: Choose from three different maps to play.
Customizable Snake Colors: Select from seven different snake colors.
Difficulty Levels: Adjust the game's difficulty to match your skill level.
Game Over Pop-Up: Displays your score when the game is over.
Dependencies
OpenGL
GLUT
License
This project is open-source and available under the MIT License.
