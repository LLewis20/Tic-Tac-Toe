#include <iostream>0
using namespace std;

char board[3][3] = { {'1','2','3'},{'4','5','6'},{'7','8','9'} };
int row;
int col;
char playerSymbol = 'X';
bool tie = false;
bool gameContinue = true;

//creating the board to print
void makingBoard() {

	cout << "    |    |    " << endl;
	cout << "  " << board[0][0] << " | " << board[0][1] << "  | " << board[0][2] << endl;
	cout << "____|____|____" << endl;
	cout << "    |    |    " << endl;
	cout << "  " << board[1][0] << " | " << board[1][1] << "  | " << board[1][2] << endl;
	cout << "____|____|____" << endl;
	cout << "    |    |    " << endl;
	cout << "  " << board[2][0] << " | " << board[2][1] << "  | " << board[2][2] << endl;
}
//changing the value of the slot from a num to X or O
void changingSlotValue() {
	int slot;
	cout << "Please Enter Value you want to take: ";
	cin >> slot;

	switch (slot) {
	case 1:
		row = 0;
		col = 0;
		break;
	case 2:
		row = 0;
		col = 1;
		break;
	case 3:
		row = 0;
		col = 2;
		break;
	case 4:
		row = 1;
		col = 0;
		break;
	case 5:
		row = 1;
		col = 1;
		break;
	case 6:
		row = 1;
		col = 2;
		break;
	case 7:
		row = 2;
		col = 0;
		break;
	case 8:
		row = 2;
		col = 1;
		break;
	case 9:
		row = 2;
		col = 2;
		break;
	default:
		cout << "Invalid slot" << endl;
	}
	if (board[row][col] != playerSymbol && board[row][col] != 'O' && playerSymbol == 'X') {
		board[row][col] = 'X';
		playerSymbol = 'O';
	}
	else if (board[row][col] != playerSymbol && board[row][col] != 'X' && playerSymbol == 'O') {
		board[row][col] = 'O';
		playerSymbol = 'X';
	}
	else {
		cout << "This slot is already filled, please choose another" << endl;
		changingSlotValue();
	}

	system("CLS");
}
//checking for the 3 chars in a row
bool threeInARow() {
	for (int i = 0; i < 3; i++) {
		if (board[i][0] == board[i][1] && board[i][0] == board[i][2] || board[0][i] == board[1][i] && board[0][i] == board[2][i]) {
			gameContinue = false;
			return true;
		}
		if (board[0][0] == board[1][1] && board[1][1] == board[2][2] || board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
			gameContinue = false;
			return true;
		}
	}
}
//checking for a tie
int findingTie() {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (board[i][j] == 'X' || 'O') {
				tie = true;
			}
			else {
				tie = false;
				break;
			}
		}
	}
	return 0;
}

int main() {
	for (int i = 0; i < 9; i++) {
		makingBoard();
		changingSlotValue();
		threeInARow();
		findingTie();
	}

	//print winner and tie
	if (playerSymbol == 'O' && tie == false) {
		cout << "X wins the game!" << endl;
	}
	else if (playerSymbol == 'X' && tie == false) {
		cout << "O wins the game!" << endl;
	}
	else if (tie == true) {
		cout << "The game was a tie!" << endl;
	}
}


