#include <iostream>
using namespace std;

void drawBoard(char*);
bool isWinner(char*);
void switchPlayers(char&);

int main() {
	//This is an array. You may not know what an array is yet but they are an extremely powerful way to collect data.
	char board[9] = { '-', '-', '-', '-', '-', '-', '-', '-', '-' };

	//Essentially I create 9 slots of memory. For now they are all '-'. To access one of these slots I can called
	//board[0], board[1], board[2], board[3], etc...
	//This allows me to easily loop through the data inside a loop if I need to.
	//
	//I am using this array to make a tic-tac-toe board that looks like this:
	//
	//	[0] [1] [2]
	//  [3] [4] [5]
	//  [6] [7] [8]

	//A character to hold the current palyer.
	char currentPlayer = 'X';

	//The location that the user wants their piece placed.
	int location = 0;

	//if there is no winner, we should constantly loop the game.
	while (!isWinner(board)) {
		cout << "0 1 2" << endl << "3 4 5" << endl << "6 7 8" << endl << endl;
		cout << currentPlayer << "'s choose a location: " << endl;
		//Ask the current player to place their piece,
		cin >> location;

		//make sure the user entered a possible location! board[10] doesn't exist does it?!
		//Make sure the player doesn't overwrite the other player's piece either!
		if (location >= 0 && location<9 && board[location] == '-') {
			//save the piece into the proper location
			board[location] = currentPlayer;
			//draw the board and switch players.
			drawBoard(board);
			switchPlayers(currentPlayer);
		}
		else { cout << "That is not a valid location!!" << endl; }
	}

	//Everything I did in the while loop above is called a function. Creating functions are easy ways to not repeat your code.
	//If you ever have to write code more than 2 times in your program, put it in a function to save time and space.
	//calling "isWinner" is much easier to understand than a massive if statement :)

	//We are now out of the while loop. That means a winner has been determined.
	//Switch the player to the winner and let them know!
	switchPlayers(currentPlayer);

	cout << "Player " << currentPlayer << " wins!" << endl;
	return 0;
}

void drawBoard(char* boardState) {
	//Draw the board
	//This is called a function. You put code in a function so that you don't repeat your code.
	//Your file was 300+ lines long! That's insane for tic-tac toe. 
	//Instead of drawing the board 20 gazillion times we can just loop the whole game until there's a winner

	for (int i = 0; i<9; i++) {
		if (i % 3 == 0) {
			cout << endl;
		}
		cout << boardState[i];
	}
	cout << endl;
}

bool isWinner(char* boardState) {
	//Pass in the board state and check if there is a winner

	//This is why I chose to use an array. It is super easy to access each location on the board.
	if (boardState[0] == boardState[1] && boardState[0] == boardState[2] && boardState[0] != '-' ||
		boardState[3] == boardState[4] && boardState[3] == boardState[5] && boardState[3] != '-' ||
		boardState[6] == boardState[7] && boardState[6] == boardState[8] && boardState[6] != '-' ||
		boardState[0] == boardState[3] && boardState[0] == boardState[6] && boardState[0] != '-' ||
		boardState[1] == boardState[4] && boardState[1] == boardState[7] && boardState[1] != '-' ||
		boardState[2] == boardState[5] && boardState[2] == boardState[8] && boardState[2] != '-' ||
		boardState[0] == boardState[4] && boardState[0] == boardState[8] && boardState[0] != '-' ||
		boardState[2] == boardState[4] && boardState[2] == boardState[6] && boardState[2] != '-') {
		return true;
	}
	else { return false; }
}

void switchPlayers(char &player) {
	//This is called pass by reference. 
	//That means whatever is passed into this function as a parameter will be updated.
	//Therefore, this function is actually switching the player

	if (player == 'X') {
		player = 'O';
	}
	else { player = 'X'; }
}