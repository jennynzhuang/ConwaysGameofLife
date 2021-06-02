# Conway's Game of Life
A C++ console application that simulates John Conway's Game of Life

### “The Rules to Life” 
Conway’s Game of Life is a simulation game that is supposed to model cellular life. The game is zero-player, meaning the board evolves based on an initial configuration of cells and a set of rules. The rules are as follows, given a configuration of cells, the following transformations occur every generation/iteration (Wikipedia):
<li> Any live cell with two or three live neighbors survives
<li> Any live cell with less than two live neighbors dies as if from underpopulation.
<li> Any live cell with more than three live neighbors dies as if from overpopulation
<li> Any dead cell with three live neighbors becomes a live cell as if from reproduction.

### Setting up the game
Users can play the game by loading a preformatted .txt document or inputting the individual height and width coordinates of the initial configuration. 
Text files should be formatted where each line of the file is a height and width coordinate.
After configuring the board, users determine the size of the board they require to fit the configuration and the number of generations they want to simulate. 
Then the simulation can begin. 

### Running the game
Compiled and ran the main file GameofLife.cpp using the g++ command, a c++ GNU compiler
