#include <iostream>

void tictacdisp(char *arr)
{
std::cout << "Game Board:" << std::endl;
std::cout << "|~~~|~~~|~~~|" << std::endl;
std::cout << "| " << arr[0] <<" | " << arr[1] <<" | " << arr[2] <<" |" << std::endl;
std::cout << "|~~~|~~~|~~~|" << std::endl;
std::cout << "| " << arr[3] <<" | " << arr[4] <<" | " << arr[5] <<" |" << std::endl;
std::cout << "|~~~|~~~|~~~|" << std::endl;
std::cout << "| " << arr[6] <<" | " << arr[7] <<" | " << arr[8] <<" |" << std::endl;
std::cout << "|~~~|~~~|~~~|" << std::endl;
}

int checkslot(char *arr,int slot) //return 1 for X and -1 for O
{
if(arr[slot] == 'X') return 1;
else if(arr[slot] == 'O') return -1;
else return 0;

}

int reset(char *arr) //reset all numbers in position to 1 to 9
{
for(int i = 0; i < 9; i++) arr[i] = ('1' + i);
}

int main()
{
int GameCondition = 0, player = 1, Action = 0, wincondi[8]={0},i,turns = 0;
char positions[10] = "123456789";
while(GameCondition != -1)
{
	if(GameCondition == 3) {reset(positions);GameCondition = 0;turns = 0;} //reset condition
	else if(GameCondition == 0) //normal game condition
	{
		tictacdisp(positions);
		Action = 0;
		if(player == 1) //player one turn
		{
			std::cout << "Player One make a X by inputing a number position thats not X or O" << std::endl;
			std::cin >> Action;
			std::cout << std::endl;
		}
		else	//player Two turn
		{
			std::cout << "Player Two make a O by inputing a number position thats not X or O" << std::endl;
			std::cin >> Action;
			std::cout << std::endl;
		}
		// deteremine action :
		if((Action < 1)||(Action > 9)) std::cout << "incorrect movement" << std::endl; // if not within 1 to 9
		else if(checkslot(positions,(Action-1)) != 0) std::cout << "Already filled" << std::endl; // check if X or O
		else if(player == 1){positions[Action-1] = 'X'; player = 2;turns++;} 	//fill in X for player one and switch to player two
		else if(player == 2){positions[Action-1] = 'O'; player = 1;turns++;} 	//fill in O for player two and switch to player one

		for(i = 0; i<8; i++) wincondi[i]=0; // reset win conditions
		for(i = 0; i<9; i++) // V1 V2 V3 H1 H2 H3 D1 D2 <- win conditions vertical and horiznal diag. 3 for player one to win -3 for player 2
		{
			if(i == 0)
			{
				wincondi[0]+=checkslot(positions,i);
				wincondi[3]+=checkslot(positions,i);
				wincondi[6]+=checkslot(positions,i);
			}
			else if(i == 1)
			{
				wincondi[1]+=checkslot(positions,i);
				wincondi[3]+=checkslot(positions,i);
			}
			else if(i == 2)
			{
				wincondi[2]+=checkslot(positions,i);
				wincondi[3]+=checkslot(positions,i);
				wincondi[7]+=checkslot(positions,i);
			}
			else if(i == 3)
			{
				wincondi[0]+=checkslot(positions,i);
				wincondi[4]+=checkslot(positions,i);
			}
			else if(i == 4)
			{
				wincondi[1]+=checkslot(positions,i);
				wincondi[4]+=checkslot(positions,i);
				wincondi[6]+=checkslot(positions,i);
				wincondi[7]+=checkslot(positions,i);
			}
			else if(i == 5)
			{
				wincondi[2]+=checkslot(positions,i);
				wincondi[4]+=checkslot(positions,i);
			}
			else if(i == 6)
			{
				wincondi[0]+=checkslot(positions,i);
				wincondi[5]+=checkslot(positions,i);
				wincondi[7]+=checkslot(positions,i);
			}
			else if(i == 7)
			{
				wincondi[1]+=checkslot(positions,i);
				wincondi[5]+=checkslot(positions,i);
			}
			else if(i == 8)
			{
				wincondi[2]+=checkslot(positions,i);
				wincondi[5]+=checkslot(positions,i);
				wincondi[6]+=checkslot(positions,i);
			}
		}
		for(i = 0; i<8; i++) {if(wincondi[i]==3) GameCondition = 1; if(wincondi[i]==-3) GameCondition = 2;} //check if any condition = 3 or -3
		if((turns == 9)&(GameCondition == 0)&(GameCondition == 0)) GameCondition = 4; // if no one won by tuen 9 it is a draw
	}
	else if((GameCondition == 1)||(GameCondition == 2)||(GameCondition == 4)) //victory or draw, 1 for player one 2 for player 2 4 for draw
	{
		tictacdisp(positions);
		if(GameCondition == 1) std::cout << "Congrats Player One won!\n";
		else if(GameCondition == 2) std::cout << "Congrats Player Two won!\n";
		else std::cout << "it was a DRAW!\n";
		std::cout << "if you want to reset type 3 otherwise -1 to quit :\n";
		std::cin >> Action;
		if(Action == 3) GameCondition = 3;else if(Action == -1) GameCondition = -1;
		std::cout << "\n\n";
		player = 1;
	}
}
}