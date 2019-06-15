// CSci 1113 HW 10
// Yi-ting Chiang
// HW Problem 10B

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstddef>
#include <cstring>
using namespace std;

class Player //base class
{
	protected:
		int Guess;
	public:
		Player() 	//default constructor 
		{
			Guess = 0;
		}
		Player(int Pg)	//constructor 
		{
			Guess = Pg;
		}
		virtual int getGuess()=0;	//virtual function which return 0
	
};

class HumanPlayer :public Player	//derived class HumanPlayer 
{
	
	public:
	HumanPlayer():Player()
	{	
	}
	
	HumanPlayer(int Hg):Player(Hg)
	{
	}
	int getGuess();
};

int HumanPlayer::getGuess()	// getGuess defintion for HumanPlayer  
{
	int x;
	cout <<"Please enter a number: ";	//prompt user to enter number 
	cin >> x;
	
	return x; //return number entered from the keyboard 
}

class ComputerPlayer: public Player 	//derived class ComputerPlayer 
{
	public:
	ComputerPlayer():Player()
	{
	}
	
	ComputerPlayer(int Cg): Player(Cg)
	{
	}
	int getGuess();
	
};

int ComputerPlayer::getGuess()		// getGuess defintion for ComputerPlayer 
{	
	return rand()%100;		//return the random number between 0 and 99
}

void play(Player &player1, Player &player2);
bool checkForWin(int guess, int answer);


int main()
{
	HumanPlayer p1, p2, p3, p4, p5;
	ComputerPlayer c1,c2,c3,c4,c5;
	cout <<"Human vs Human Round 1! " << endl << endl;
	play(p1,p2);	//first instance of play between two humans
	cout << endl;
	cout <<"Human vs Human Round 2! " << endl << endl;
	play(p4,p5);	//second instance of play between two humans
	cout << endl;
	cout << "Human vs Computer! " << endl << endl;
	play(p3,c3);	// instance of play between human and computer 
	cout << endl;
	cout << "Computer vs Computer Round 1! "<< endl << endl;
	play(c1,c2);	//first instance of play between two computers
	cout << endl;
	cout << "Computer vs Computer Round 2!"<< endl << endl;
	play(c4,c5);	//second instance of play between two computers
	
	return 0;
}




void play(Player &player1, Player &player2) //function for guessing game
{
	int answer = rand()%100;
	int guess = 0;
	bool win = false;
	while (!win) 
	{
		cout << "Player 1's turn to guess." << endl;
		guess = player1.getGuess();
		win = checkForWin(guess, answer);
		if (win) return;
		cout << "Player 2's turn to guess." << endl;
		guess = player2.getGuess();
		win = checkForWin(guess, answer);
	}
}

bool checkForWin(int guess, int answer) //function for checking win or not
{
	cout << "You guessed " << guess << ". ";
	if (answer == guess) 
	{
		cout << "You're right! You win!" << endl;
		return true;
	}
	else if (answer < guess) 
	{
		cout << "Your guess is too high." << endl;
	}
	else 
	{
		cout << "Your guess is too low." << endl;
	}
	return false;
}








