#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

const char ROCK = 'r';
const char PAPER = 'p';
const char SCISSORS = 's';
unsigned int userScore = 0;
unsigned int computerScore = 0;

using namespace std;



char getComputerOptions() {
	srand(time(0));
	int num = rand() % 3;
	if (num == 0) return 'r';
	if (num == 1) return 'p';
	if (num == 2) return 's';
}

char getUserChoice() {
	
	cout << "Please pick Rock, Paper, Scissors: " << endl;
	cout << "----------------------------------------" << endl;
	string choice;
	cin >> choice;
	transform(choice.begin(), choice.end(), choice.begin(), [](unsigned char c) {return tolower(c); });
	if (choice == "exit") return 'e';
	while (choice != "rock" && choice != "paper" && choice != "scissors") {
		cout << "Please pick Rock, Paper, Scissors: ";
		cin >> choice;
		transform(choice.begin(), choice.end(), choice.begin(), [](unsigned char c) {return tolower(c); });
	}
	if (choice == "rock") return 'r';
	if (choice == "paper") return 'p';
	if (choice == "scissors") return 's';
	return NULL;
}

void showSelectedOptions(char c) {
	if (c == 'r') cout << "Rock" << endl;
	if (c == 'p') cout << "Paper" << endl;
	if (c == 's') cout << "Scissors" << endl;
	if (c == 'e') cout << "Cya next time!!" << endl;
}

void chooseWinner(char uChoice, char cChoice) { 
	//pc wins
	if (uChoice == ROCK && cChoice == PAPER) {
		cout << "Computer Wins!! Paper warps Rock. " << endl;
		computerScore++;
	}

	else if (uChoice == PAPER && cChoice == SCISSORS) {
		cout << "Computer wins!! scissors cut Paper. " << endl;
		computerScore++;
	}
	else if (uChoice == SCISSORS && cChoice == ROCK) {
		cout << "Computer wins!! Rock smashes Scissors" << endl;
		computerScore++;
	}
	//you win
	else if (uChoice == ROCK && cChoice == SCISSORS) {
		cout << "You Win! Paper wraps Rock." << endl;
		userScore++;
	}
	else if (uChoice == PAPER && cChoice == ROCK) {
		cout << "You Win! Paper wraps Rock." << endl;
		userScore++;
	}
	else if (uChoice == SCISSORS && cChoice == PAPER) {
		cout << "You Win! Scissors cut Paper." << endl;
		userScore++;
	}
	else cout << "Tie, Play again to win the game! " << endl;
}



int main() {

	cout << "Welcome to Rock Paper Scissors game!!!" << endl;
	cout << "If you wish to exit, type exit at any given time! " << endl;
	while (1) {

		//user input
		char yourChoice = getUserChoice();
		if (yourChoice == 'e')
			break;
		cout << "Your choice is: ";
		showSelectedOptions(yourChoice);
		
		//pc input
		char computerChoice = getComputerOptions();
		cout << "Computer Choice is: ";
		showSelectedOptions(computerChoice);
		chooseWinner(yourChoice, computerChoice);
		cout << "---------------------------------------" << endl;
		cout << "New Game starting..." << endl;
		cout << "Your score is: " << userScore << " Computer Score is: " << computerScore << endl;
		cout << endl << endl;
	}
	return 0;
}
