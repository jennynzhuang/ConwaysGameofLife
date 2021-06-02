// Jennifer Zhuang 
// Summer 2020 
// Game of Life Implementation in C++
//
// BOARD CLASS FILE
//

// 
// Header
//
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "cell.cpp"

#define BLUE    "\033[34m"  
#define RESET   "\033[0m"


//
// Board Class
//
class Board {
private:
	int height;
	int width;
	Cell *array;      // 1D array of Cell objects, simulates a 2D array
public: 
	Board(int h, int w);          // constructor 
	~Board();                     // destructor
	int getIndex(int h, int w);
	void loadBoard();
	void inputBoard();
	bool validCoord(int h, int w);
	bool checkNeighbors(int h, int w);
	void updateBoard();
	void printBoard();
};

//
// Board Class Constructor & Destructor
//
Board::Board(int h, int w) {
	height = h;
	width = w;
	array = new Cell[h*w];
}

Board::~Board() {
	delete[] array;
}

//
// Board Class Member Functions
//
int Board::getIndex(int h, int w) {   // given the h/w coords of a cell, return actual array index
	return h * width-1 + w;
}

void Board::loadBoard() {            // prompt user for file, update Board object
	// variables
	string filename;
	int test = -1;

	while (test < 0)
	{
		cout << "Enter name of file to read from: "<<endl;
		cin  >> filename;
		ifstream myfile(filename);
		if (myfile.is_open())
		{
			// successfully opened file
			test = 1;
			string line,ht,wt;

			while (getline(myfile,line))
			  {
			  	// extract coordinates
			    stringstream ss(line);
			    getline(ss,ht,' ');
			    getline(ss,wt,' ');
			    int h = stoi(ht);
			    int w = stoi(wt);
			    //update board
			    int i = getIndex(h, w);
			    array[i].alive();
			}
			break;
		}
		else
		{
			// unsuccessfully opened file
			cout << "Unable to read file, try again. " << endl;
		}
	}
}

void Board::inputBoard () {            // prompt user for inputs, update Board object
	int cells = -1;
	int test = -1;

	// prompt user for number of alive cells
	while (test < 0)
	{
		cout << "Enter the number of live cells you want to input: " << endl;
		cin >> cells;
		if (cells < 0 or cells > height * width)
		{
			cout << "Invalid number of cells. Try again." << endl;
		}
		else 
			test = 1;
	}

	// prompt user for coordinates of alive cells
	for (int x = 0; x < cells; x++)
	{
		int test1 = -1;
		int ht, wt, i;
		while (test1 < 0)
		{
			cout << "Enter height and width coordinates for cell #" << x+1 << endl;
			cin >> ht >> wt;
			i = getIndex(ht, wt);
			if (ht < 0 or wt < 0 or ht >= height or wt >= width)
			{
				cout << "Invalid coordinates. Try Again." << endl;
			}
			else if (array[i].getState())
			{
				cout << "Cell is already alive. Try Again." << endl;
			}
			else
			{
				cout << "Cell #" << x+1 << " is updated." << endl;
				array[i].alive();
				test1 = 1;
			}
		}
	}
}

bool Board::validCoord(int h, int w) {                // helper function that checks if coordinates are in bounds
	if (h < 0 or h >= height)
		return false;
	else if (w < 0 or w >= width)
		return false;
	else
		return true;
}

bool Board::checkNeighbors(int h, int w) {     // given the coords of a cell, return if alive/dead next generation
	int liveNeighbors = 0;

	// Check each individual neighbor, update counter
	//
	// check left top diagonal
	if (validCoord(h-1, w-1) and array[getIndex(h-1, w-1)].getState())
		liveNeighbors++;
	// check top center
	if (validCoord(h-1, w) and array[getIndex(h-1, w)].getState())
		liveNeighbors++;
	// check right top diagonal
	if (validCoord(h-1, w+1) and array[getIndex(h-1, w+1)].getState())
		liveNeighbors++;
	// check left
	if (validCoord(h, w-1) and array[getIndex(h, w-1)].getState())
		liveNeighbors++;
	// check right 
	if (validCoord(h, w+1) and array[getIndex(h, w+1)].getState())
		liveNeighbors++;
	// check left bottom diagonal 
	if (validCoord(h+1, w-1) and array[getIndex(h+1, w-1)].getState())
		liveNeighbors++;
	// check bottom center
	if (validCoord(h+1, w) and array[getIndex(h+1, w)].getState())
		liveNeighbors++;
	// check right bottom diagonal
	if (validCoord(h+1, w+1) and array[getIndex(h+1, w+1)].getState())
		liveNeighbors++;

	// Check alive neighbor counter for both types of cells
	if (array[getIndex(h, w)].getState())   // check alive cell rules
	{
		if (liveNeighbors == 2 or liveNeighbors == 3)
			return true;
		else
			return false;
	}
	else                        // check dead cell rules
	{
		if (liveNeighbors == 3)
			return true;
		else 
			return false;
	}
}

void Board::updateBoard() {
	// create temp array 
	Cell *arrayCopy = new Cell[height * width]; 

	//check array
	for (int h = 0; h < height; h++)
	{
		for (int w = 0; w < width; w++)
		{
			int i = getIndex(h, w);
			if (checkNeighbors(h, w))
				arrayCopy[i].alive();
			else 
				arrayCopy[i].dead();
		}
	}
	array = arrayCopy;
}

void Board::printBoard() {
	for (int h = 0; h < height; h++)
	{
		for (int w = 0; w < width; w++)
		{
			int i = getIndex(h,w);
			Cell c = array[i];
			if (c.getState())
			{
				cout << BLUE;
				cout << " o ";
				cout << RESET;
			}
			else
				cout << " . ";
		}
		cout << endl;
	}
	cout << endl;
}