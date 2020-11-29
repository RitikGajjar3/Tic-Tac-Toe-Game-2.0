/*
-------------------------------------------------------------------------------------------------------------
											Tic Tac Toe 2.0
-------------------------------------------------------------------------------------------------------------

		4X4 Tic Tac Toe Game with new exciting feature like Hint, Autoplay and showGameplay.

		Language Used : C

		Author : Ritik Gajjar

		Author Email Id : ritik.gajjar.3@gmail.com
*/
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <dos.h>				// for delay() 

#define SIZE 3

char Symbol[] = "OX";

int max(int a, int b)
{
	return a > b ? a : b;
}

int min(int a, int b)
{
	return a < b ? a : b;
}


// Function to initialise the board with the cell num.
void initialiseBoard(char board[][SIZE])
{
	char cellNum = '1';
	for (int i = 0 ; i < SIZE ; i++)
	{
		for (int j = 0 ; j < SIZE ; j++)
		{
			board[i][j] = cellNum;
			cellNum++;
		}
	}
}

// Function which displays the title of game.
void drawTitle()
{
	printf("\n");
	printf("\t\t  --- --- --- 	  ---   *   ---   --- --- ---    \n");
	printf("\t\t   |   |  |        |   /_\\  |      |  | | |__        \n");
	printf("\t\t   |  _|_ |__      |  /   \\ |__    |  |_| |__        \n");
	printf("\t\t _____________________________________________");
}


// Function which displays the New Tic Tac Toe Game
void showGameRules()
{
	clrscr();
	drawTitle();

	printf("\n\n");
	printf("		          Rules of Tic-Tac-Toe Game		\n");
	printf("\t\t\t-----------------------------  	\n");
	printf("\n\n");
	printf("\n -> The game is played on a grid that's 4 squares by 4 sqaures OR ");
	printf("\n    3 squares by squares.");

	printf("\n\n -> First Player will get O Mark,  Second Player will get X Mark.");

	printf("\n\n -> The player to get 3 of her marks in a row(up. down, diagonally)");
	printf("\n    will get 3 points.");

	printf("\n\n -> The player to get 4 of her marks in a row(up. down, diagonally)");
	printf("\n    will get 7 points.");

	printf("\n\n -> There are 2 hints available for each player.");

	printf("\n\n -> There is also Autoplay feature available, after turning");
	printf("\n    on autoplay feature every time computer will play");
	printf("\n    but 3 points will be deducted after end of game.");

	printf("\n\n Press 1 for go back.");
	int choice = -1;
	while (choice != 1)
	{
		printf("\n\nEnter your choice : ");
		scanf("%d", &choice);
		if (choice != 1)
			printf("Invalid choice...\n");
	}
}

// Function to choose the game mode whether user wants 2 player game or 1 player game.
void chooseGameMode(char player1Name[], char player2Name[], int& player2AutoPlay)
{
	int choice = -1;

	while (choice != 1 && choice != 2)
	{
		clrscr();
		drawTitle();

		printf("\n\n\n\n\n");
		printf("0.  Game Rules \n");
		printf("1.  1 Player   \n");
		printf("2.  2 Player   \n");
		printf("3.  Exit	   \n");

		printf("\n Enter your choice : ");
		scanf("%d", &choice);

		if (choice == 0)
			showGameRules();
		else if (choice == 3)
			exit(0);
		else if ( choice != 1 && choice != 2)
			printf("Invalid Choice \n\n");
	}

	if (choice == 1)
	{
		gets(player1Name);
		printf("\n Enter Player Name : ");
		gets(player1Name);

		strcpy(player2Name, "COMPUTER");
		player2AutoPlay = 1;
	}
	else
	{
		gets(player1Name);
		printf("\n Enter First Player Name : ");
		gets(player1Name);
		printf("\n Enter Second Player Name : ");
		gets(player2Name);
	}
}

// Function to display the score of each player
void showScoreBoard(char player1Name[], char player2Name[], int& player1Score, int& player2Score)
{
	cout << "\n\n";
	cout << "Score ----->       " << player1Name << " : " << player1Score << "  \t\t" << player2Name << " : " << player2Score;
}

// Function to display the Tic-Tac-Toe Board.
void drawBoard(char board[][SIZE])
{
	cout << "\n\n\n";
	printf("\t\t\t     |     |     \n");
	printf("\t\t\t  %c  |  %c  |  %c \n", board[0][0], board[0][1], board[0][2]);

	printf("\t\t\t_____|_____|_____\n");
	printf("\t\t\t     |     |     \n");

	printf("\t\t\t  %c  |  %c  |  %c \n", board[1][0], board[1][1], board[1][2]);

	printf("\t\t\t_____|_____|_____\n");
	printf("\t\t\t     |     |     \n");

	printf("\t\t\t  %c  |  %c  |  %c \n", board[2][0], board[2][1], board[2][2]);

	printf("\t\t\t     |     |     \n\n");

}

int leftDiagonalScore(char board[][SIZE], char playerSymbol, int i, int j)
{
	int score = 0;
	int symbCount = 0;
	while (i < SIZE && j < SIZE)
	{
		if (board[i][j] == playerSymbol)
			symbCount++;
		else
		{
			if (symbCount == 3)
				score += 3;
			symbCount = 0;
		}
		i++;
		j++;
	}
	if (symbCount == 4)
		score += 7;
	else if (symbCount == 3)
		score += 3;

	return score;
}

int rightDiagonalScore(char board[][SIZE], char playerSymbol, int i, int j)
{
	int score = 0;
	int symbCount = 0;
	while (i < SIZE && j >= 0)
	{
		if (board[i][j] == playerSymbol)
			symbCount++;
		else
		{
			if (symbCount == 3)
				score += 3;
			symbCount = 0;
		}
		i++;
		j--;
	}
	if (symbCount == 4)
		score += 7;
	else if (symbCount == 3)
		score += 3;

	return score;
}


// Calculating the score of given user.
int calculateScore(char board[][SIZE], char playerSymbol)
{
	int score = 0;

	for (int i = 0 ; i < SIZE ; i++)
	{
		int symbCount = 0;
		for (int j = 0 ; j < SIZE ; j++)
		{
			if (board[i][j] == playerSymbol)
				symbCount++;
			else
			{
				if (symbCount == 3)
					score += 3;
				symbCount = 0;
			}
		}
		if (symbCount == 4)
			score += 7;
		else if (symbCount == 3)
			score += 3;
	}

	for (int j = 0 ; j < SIZE ; j++)
	{
		int symbCount = 0;
		for (int i = 0 ; i < SIZE ; i++)
		{
			if (board[i][j] == playerSymbol)
				symbCount++;
			else
			{
				if (symbCount == 3)
					score += 3;
				symbCount = 0;
			}
		}
		if (symbCount == 4)
			score += 7;
		else if (symbCount == 3)
			score += 3;
	}

	score += leftDiagonalScore(board, playerSymbol, 0, 0);
	score += leftDiagonalScore(board, playerSymbol, 1, 0);
	score += leftDiagonalScore(board, playerSymbol, 0, 1);

	score += rightDiagonalScore(board, playerSymbol, 0, 2);
	score += rightDiagonalScore(board, playerSymbol, 0, 3);
	score += rightDiagonalScore(board, playerSymbol, 1, 3);

	return score;
}

// Function for calculating empty number of cells in the Board.
int calculateEmptyCell(char board[][SIZE])
{
	int emptyCell = 0;
	for (int i = 0 ; i < SIZE ; i++)
	{
		for (int j = 0 ; j < SIZE ; j++)
		{
			if (board[i][j] != 'O' && board[i][j] != 'X')
				emptyCell++;
		}
	}

	return emptyCell;
}

// Finding the best Move using Backtracking Algorithm
int findBestMove(char board[][SIZE], int emptyCell, int currPlayer, int isMax)
{
	if (emptyCell == 0)
		return calculateScore(board, Symbol[currPlayer]) - calculateScore(board, Symbol[1 - currPlayer]);

	if (isMax == 1)
	{
		int maxScore = -1000;
		char cellNum = '1';
		for (int i = 0 ; i < SIZE ; i++)
		{
			for (int j = 0 ; j < SIZE ; j++)
			{
				if (board[i][j] != 'O' && board[i][j] != 'X')
				{
					board[i][j] = Symbol[currPlayer];
					int currScore = findBestMove(board, emptyCell - 1, 1 - currPlayer, 0);
					maxScore = max(maxScore, currScore);
					board[i][j] = cellNum;
				}
				cellNum++;
			}
		}
		return maxScore;
	}
	else
	{
		int minScore = 1000;
		char cellNum = '1';
		for (int i = 0 ; i < SIZE ; i++)
		{
			for (int j = 0 ; j < SIZE ; j++)
			{
				if (board[i][j] != 'O' && board[i][j] != 'X')
				{
					board[i][j] = Symbol[currPlayer];
					int currScore = findBestMove(board, emptyCell - 1, 1 - currPlayer, 1);
					minScore = min(minScore, currScore);
					board[i][j] = cellNum;
				}
				cellNum++;
			}
		}
		return minScore;
	}
}


// Function to find the best move if the player has called Hint feature OR Autoplay feature
int getBestMove(char board[][SIZE], int currPlayer)
{
	int emptyCell = calculateEmptyCell(board);

	int maxi = -1, maxj = -1, maxScore = -1000;

	char cellNum = '1';
	for (int i = 0 ; i < SIZE ; i++)
	{
		for (int j = 0 ; j < SIZE ; j++)
		{
			if (board[i][j] != 'O' && board[i][j] != 'X')
			{
				board[i][j] = Symbol[currPlayer];
				int currScore = findBestMove(board, emptyCell - 1, 1 - currPlayer, 0);
				if (maxScore < currScore)
				{
					maxi = i;
					maxj = j;
					maxScore = currScore;
				}
				board[i][j] = cellNum;
			}
			cellNum++;
		}
	}

	return (maxi * SIZE) + maxj;
}


// Function to take the choice from the user.
int getChoice(char board[][SIZE], int& currPlayerHint, int& playerAutoPlay, int currPlayer)
{
	if (playerAutoPlay == 1)
		return  getBestMove(board, currPlayer);

	printf("\n -> Press -1 for Hint");
	printf("\n -> Press -2 for Autoplay");
	printf("\n -> Press -3 for Exit");
	printf("\n -> OR Enter the box Number");

	int choice = -4;
	while (choice != -1 && choice != -2)
	{
		printf("\n\n Enter your choice : ");
		scanf("%d", &choice);

		if ( (choice - 1) >= 0 && (choice - 1) < SIZE * SIZE)
		{
			choice--;
			if (board[choice / SIZE][choice % SIZE] != 'O'
			        && board[choice / SIZE][choice % SIZE] != 'X')
				return choice;
			else
			{
				printf("Given Cell is already Filled.");
				choice = -4;
			}
		}
		else if (choice == -1)
		{
			if (currPlayerHint == 0)
			{
				printf("You Hint Count is 0.");
				choice = -4;
			}
			else
			{
				currPlayerHint--;
				return getBestMove(board, currPlayer);
			}
		}
		else if (choice == -2)
		{
			playerAutoPlay = 1;
			return getBestMove(board, currPlayer);
		}
		else if (choice == -3)
			exit(0);
		else
			printf("Invalid Move \n");
	}

	return 0;
}

// Function to display the one by one move of each player of previous game.
void showGamePlay(int moves[], char player1Name[], char player2Name[])
{
	clrscr();

	char board[SIZE][SIZE];
	initialiseBoard(board);

	for (int i = 0 ; i < SIZE * SIZE; i++)
	{
		clrscr();
		drawTitle();

		int choice = moves[i];
		if (i % 2 == 0)			// Player1 Move
		{
			board[choice / SIZE][choice % SIZE] = 'O';
			cout << "\n\n" << player1Name << " Move : " << choice + 1;
		}
		else
		{
			board[choice / SIZE][choice % SIZE] = 'X';
			cout << "\n\n" << player2Name << " Move : " << choice + 1;
		}
		drawBoard(board);
		delay(3000);
	}
}


// Function to display the Result of Game after Game Ends.
int showResult(int moves[], char player1Name[], char player2Name[], int player1Score, int player2Score)
{
	int choice = -1;
	while (choice == -1)
	{
		clrscr();
		drawTitle();
		printf("\n\n\n\n");

		if (player1Score == player2Score)
			printf("\t\t\t      Game is a Draw");
		else
			printf("\t\t\t Winner is : %s", player1Score > player2Score ? player1Name : player2Name);
		printf("\n\n\n");

		printf("1. Play Again  			\n");
		printf("2. Show Previous Gameplay 	\n");
		printf("3. Exit 			  	\n");

		printf("\n\n Enter your choice : ");
		scanf("%d", &choice);

		if (choice == 1)
			return 1;
		else if (choice == 2)
			showGamePlay(moves, player1Name, player2Name);
		else if (choice == 3)
			return 0;
		else
		{
			printf("Invalid Choice");
			choice = -1;
			delay(1000);
		}
	}

	return 0;
}


// Main function of Tic Tac Toe Game
void playTicTacToe()
{
	int gameOn = 1;
	while (gameOn == 1)
	{
		char board[SIZE][SIZE];
		initialiseBoard(board);

		char player1Name[50];
		char player2Name[50];

		int player1Hint = 2, player2Hint = 2;
		int player1Score = 0, player2Score = 0;

		int player1AutoPlay = 0;
		int player2AutoPlay = 0;

		int moves[SIZE * SIZE] = {0};

		chooseGameMode(player1Name, player2Name, player2AutoPlay);

		for (int i = 1 ; i <= SIZE * SIZE ; i++)
		{
			clrscr();
			drawTitle();
			showScoreBoard(player1Name, player2Name, player1Score, player2Score);
			drawBoard(board);

			int choice;
			if ( (i % 2) != 0)				// Player 1 Turn
			{
				choice = getChoice(board, player1Hint, player1AutoPlay, 0);

				board[choice / SIZE][choice % SIZE] = 'O';
			}
			else							// Player 2 Turn
			{
				choice = getChoice(board, player2Hint, player2AutoPlay, 1);

				board[choice / SIZE][choice % SIZE] = 'X';
			}
			moves[i - 1] = choice;			// Storing the each player Move in queue order.

			player1Score = calculateScore(board, 'O');
			player2Score = calculateScore(board, 'X');
		}

		/*		if(SIZE == 4)
				{
					if(player1AutoPlay == 1)
						player1Score -= 3;
					if(player2AutoPlay == 1)
						player2Score -= 3;
				}
		*/
		gameOn = 0;
		gameOn = showResult(moves, player1Name, player2Name, player1Score, player2Score);
	}
}

int main()
{
	clrscr();
	playTicTacToe();
	return 0;
}





