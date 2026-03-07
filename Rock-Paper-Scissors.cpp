//A Rock Paper scissor game usign OOP
# include <iostream>
# include <string>
using namespace std;
int draws;
class Player //Created a class named player
{
	private:
		string name; //storing the name of the player
		int* moves; // a dynamic array to store the last 5 moves
		int totalWins; 
	public:
		Player() //default constructor to initialize the object
		{
			name = "Unknown";
			moves = new int [5];
			totalWins = 0;
			for (int i = 0; i < 5; ++i) //initializing all to -1
			{
				moves[i] = -1;
			}
		}
		Player(string Name)
		{
			this->name = Name;
			moves = new int [5];
			totalWins = 0;
			for (int i = 0; i < 5; ++i) //initializing all to -1
			{
				moves[i] = -1;
			}
		}
/*
 * SHALLOW COPY PROBLEM - Do NOT rely on the default compiler copy:
 * Player cheater = p1; without our copy constructor would copy 
 * the pointer address only. Both cheater.moves and p1.moves 
 * would point to the SAME array in memory.
 * * Result 1: Changing cheater's moves corrupts p1's move history.
 * Result 2: When cheater is destroyed, delete[] frees that memory.
 * p1.moves is now a dangling pointer — crash!
 * * DEEP COPY SOLUTION:
 * We allocate a new array and copy values individually.
 * cheater and p1 are now fully independent objects.
 */		
		Player(const Player& other)//making a copy constructor for handling the shallow copy
		{
			name = other.name;
			totalWins = other.totalWins;
			moves = new int[5];
			for (int i = 0; i < 5; ++i)
			{
				moves[i] = other.moves[i];
			}
			
		}
		string displayMove(int index)
		{
			if (moves[index]==0) return "Rock";
			else if (moves[index]==1) return "Paper";
			else return "Scissors";
		}
		//Getter Functions
		string getName()
		{
			return name;
		}
		int getWins()
		{
			return totalWins;
		}
		int getMove(int index)
		{
			return moves[index];
		}
		//setter functions
		void setName(string n)
		{
			this->name = n;
		}
		void setWins()
		{
			totalWins += 1;
		}
		void setMoves(int index , int value)
		{
			moves[index] = value;
		}
		//destructor
		~Player()//making a destructor 
		{
			delete[] moves;
			cout<<"Destructor called for "<<name<<endl;
		}
};
void addWin(Player& p1,Player& p2, int roundNo)//win check fucntion
{
	int p1move = p1.getMove(roundNo);
	int p2move = p2.getMove(roundNo);
	if (p1move == p2move)
	{
		draws +=1;
		cout<<"Draw"<<endl;
		return;
	}
	if (p1move == 0)
	{
		if (p2move == 1) 
		{
			p2.setWins();
			cout<<p2.getName()<<" wins this round!\n";
		}
		else
		{
			p1.setWins();
			cout<<p1.getName()<<" wins this round!\n";
		}
	}
	if (p1move == 1)
	{
		if (p2move == 2) 
		{
			p2.setWins();
			cout<<p2.getName()<<" wins this round!\n";
		}
		else
		{
			p1.setWins();
			cout<<p1.getName()<<" wins this round!\n";
		}
	}
	if (p1move == 2)
	{
		if (p2move == 0) 
		{
			p2.setWins();
			cout<<p2.getName()<<" wins this round!\n";
		}
		else
		{
			p1.setWins();
			cout<<p1.getName()<<" wins this round!\n";
		}
	}
}
void playRound(Player& p1,Player& p2, int roundNo)
{
	int move;
	if (roundNo >= 5)//base case
	{
		cout<<"\n=====Final Results=====\n";
		cout<<p1.getName()<<" Total Wins = "<<p1.getWins()<<endl;
		cout<<p2.getName()<<" Total Wins = "<<p2.getWins()<<" (includes cheater's Round 3 win)\n";
		cout<<"Total Draws = "<<draws<<endl;
		return;
	}
	cout<<"\n-----Round "<<roundNo+1<<"------\n";
	if(roundNo == 2) // cheatting case 
	{
		cout<<"Cheating has been activated \n";
		cout<<p1.getName()<<" enter your move (0 = Rock, 1 = Paper, 2 = Scissors) ";
		cin>>move;
		p1.setMoves(roundNo, move);
		Player cheater = p1; // callin my own copy constructor
		cheater.setName("cheater");
		int lastMove = cheater.getMove(roundNo);
		int cheatMove = (lastMove+1) % 3;
		cout<<"Cheater saw "<<p1.displayMove(roundNo)<<" and chose "<<cheatMove<<endl;
		p2.setMoves(roundNo,cheatMove);
	}
	else
	{
		cout<<p1.getName()<<" enter your move (0 = Rock, 1 = Paper, 2 = Scissors) ";
		cin>>move;
		p1.setMoves(roundNo,move);
		cout<<p2.getName()<<" enter your move (0 = Rock, 1 = Paper, 2 = Scissors) ";
		cin>>move;
		p2.setMoves(roundNo,move);
	}
	cout<<"\n"<<p1.getName()<<"'s move: "<<p1.displayMove(roundNo)<<endl;
	cout<<p2.getName()<<"'s move: "<<p2.displayMove(roundNo)<<endl;
	addWin(p1,p2,roundNo);//checking and displaying the winners
		
	playRound(p1, p2, roundNo + 1);
}

int main()
{
	Player p1 , p2;
	string name;
	cout<<"Enter Player 1's name : ";
	getline (cin, name);
	p1.setName(name);
	cout<<"Enter Player 2's name : ";
	getline (cin, name);
	p2.setName(name);
	playRound(p1, p2, 0);
	return 0;
}