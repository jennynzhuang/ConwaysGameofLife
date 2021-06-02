// Jennifer Zhuang 
// Summer 2020 
// Game of Life Implementation in C++
//
// MAIN FILE
//

// 
// HEADER
//
#include <iostream>
#include <chrono>
#include <thread>
#include "board.cpp"
using namespace std;
using namespace std::this_thread;     // sleep_for, sleep_until
using namespace std::chrono_literals; // ns, us, ms, s, h, etc.
using std::chrono::system_clock;

//
// Constants for i/o color
//
#define BOLD     "\033[1m\033[34m" 
#define BLUE    "\033[34m"  
#define RESET   "\033[0m"

int main()
{
	//
	// introductory information
	//
	system("clear");   // clear screen, put program on new page
	cout << BOLD;
	cout << endl;
	cout << endl;
	cout << "                               WELCOME TO CONWAY'S " << endl;
	cout << "                                 GAME OF LIFE" << endl;
	cout << RESET;
	cout << "A simulation where a configuration of cells evolves over time based on a set of rules" << endl;
    cout << endl;
    cout << BOLD;
    cout << "                                 THE RULES OF LIFE" << endl;
    cout << RESET;
    cout << "Given a configuration of cells, the following transormations occur:" << endl;
    cout << "	1) Any live cell with two or three live neighbours survives." << endl;
    cout << "	2) Any live cell with less than two live neighbors dies (underpopulation)." << endl;
    cout << "	3) Any live cell with more than three live neighbors dies (overpopulation)." << endl;
    cout << "	4) Any dead cell with three live neighbours becomes a live cell (reproduction)." << endl;
    cout << endl;
    cout << BLUE << "o" << RESET << " - living cell" << endl;
    cout << ". - dead cell" << endl;
    cout << endl;
    cout << BOLD;
    cout << "                                   HOW TO PLAY" << endl;
    cout << RESET;
    cout << "Load an existing configuration pattern or input your own configuration." << endl;
    cout << "	- To LOAD a configuration, provide a text file name." << endl ;
    cout << " 	  Each file line is a x & y coordinate of a live cell (seaprated by a space)." << endl;
    cout << "	- To INPUT a configuration, follow the upcoming set of instructions." << endl;
    cout << endl;

    //
    // Get Configuration Information
    //
    int menuChoice = -1;
    while (menuChoice != 0 and menuChoice != 1)
    {
    	cout << "Enter" << BLUE << " 0 " << RESET << "to LOAD or enter" << BLUE << " 1 " << RESET << "to INPUT." << endl;
    	cin >> menuChoice;
    	if (menuChoice != 0 and menuChoice != 1)
    	{
    		cout << "Incorrect choice. Try again." << endl;
    	}
    }

    //
    // Get Board and Generation Information
    //
    int height, width, generation;
    cout << "Enter the height and width of your board: " << endl;
    cin >> height >> width;
    cout << "Enter the number of generations/cycles you want your board to advance: " << endl;
    cin >> generation;

    Board board(height, width);

    //
    // Configure Boards
    //
    if (menuChoice == 0)
    {
    	//load board
    	board.loadBoard();
    }
    else
    {
    	//input board
    	board.inputBoard();
    }

    //
    // Start simulation
    //
    int start = -1;
    system("clear");
    cout << BOLD;
    cout << "                       BOARD SETUP COMPLETE" << endl;
    cout << RESET;
    cout << endl;
    board.printBoard();
    cout << endl;
    cout << "Enter 1 to begin the game." << endl;
    cin >> start;

    // START
    if (start == 1)
    {
    	// START THE GAME
    	for (int x = 1; x <= generation; x++)
		{
			system("clear");
			cout << BOLD ;
	    	cout << "GENERATION #" << x << endl;
	    	cout << RESET;
			board.printBoard();
			board.updateBoard();
	    	cout << endl;
			sleep_for(10ns);
	    	sleep_until(system_clock::now() + 100ms);
		}
    	// END THE GAME
    	cout << endl << endl << endl;
    	cout << BOLD ;
    	cout << "                    ENDING GAME OF LIFE" << endl;
    	cout << RESET;
    	cout << "Thank you for trying out the game of life simulation!" << endl;
    	cout << endl << endl;
    	return 0;
    }
    // EXIT
    else 
    {
    	// END THE GAME
    	system("clear");
    	cout << BOLD ;
    	cout << "                    ENDING GAME OF LIFE" << endl;
    	cout << RESET;
    	cout << "Thank you for trying out the game of life simulation!" << endl;
    	cout << endl;
    	return 0;
    }
    return 0;
}