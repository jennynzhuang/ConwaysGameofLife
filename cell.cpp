// Jennifer Zhuang 
// Summer 2020 
// Game of Life Implementation in C++
//
// CELL CLASS FILE
//

// 
// Header 
//
#include <iostream>
using namespace std;

//
// Cell Class
// 
//
class Cell {
private:
	bool state;             // state of cell, true = alive, false = dead
public:
	Cell();
	Cell(bool s);           // constructor 
	~Cell();                // destructor
	bool getState();
	void dead();
	void alive();
};

//
// Cell Class Constructor & Destructor
//
Cell::Cell() {
	state = false;
}

Cell::Cell(bool s) {
	state = s;
}

Cell::~Cell() {
	//cout << "Cell being deleted" << endl;
}

//
// Cell Class Member Functions
//
bool Cell::getState() {   // method to return state of cell
	return state;
}

void Cell::dead() {      // method to make cell dead
	state = false;
}

void Cell::alive() {     // method to make cell alive
	state = true;
}

