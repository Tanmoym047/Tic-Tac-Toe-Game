#include <stdio.h>
#include <time.h>
#include <ctype.h>
#include <stdlib.h>

char board[3][3];
const char PLAYER1 = 'X';
const char COMPUTER = 'O';
const char PLAYER2 = '#';

void ResetBoard();
void PrintBoard();
int CheckFreeSpace();
void PlayerMove1();
void PlayerMove2();
void ComputerMove();
char CheckWinner();
void PrintWinner(char);

int main()
{
    char winner = ' ';
    char choice;
    char response;

    do
    {
        winner = ' ';
        response = ' ';
        printf("Wanna Play with Computer or Another Player??? (C/P): ");
        scanf(" %c", &choice);
        choice = toupper(choice);
        if (choice == 'C')
        {
            ResetBoard();

            while (winner == ' ' && CheckFreeSpace() != 0)
            {
                PrintBoard();

                PlayerMove1();
                winner = CheckWinner();
                if (winner != ' ' || CheckFreeSpace() == 0)
                {
                    break;
                }

                ComputerMove();
                winner = CheckWinner();
                if (winner != ' ' || CheckFreeSpace() == 0)
                {
                    break;
                }
            }
        }
        else if (choice == 'P')
        {
            ResetBoard();

            while (winner == ' ' && CheckFreeSpace() != 0)
            {
                PrintBoard();

                PlayerMove1();
                winner = CheckWinner();
                if (winner != ' ' || CheckFreeSpace() == 0)
                {
                    break;
                }
                PrintBoard();

                PlayerMove2();
                winner = CheckWinner();
                if (winner != ' ' || CheckFreeSpace() == 0)
                {
                    break;
                }
            }
        }

        PrintBoard();
        PrintWinner(winner);
        printf("\nWanna Play Again??? (Y/N): ");
        scanf(" %c", &response);
        response = toupper(response);

    } while (response == 'Y');

    printf("\n*****Thanks for playing*****");

    return 0;
}

void ResetBoard()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            board[i][j] = ' ';
        }
    }
}

void PrintBoard()
{
    printf("\n %c | %c | %c ", board[0][0], board[0][1], board[0][2]);
    printf("\n---|---|---");
    printf("\n %c | %c | %c ", board[1][0], board[1][1], board[1][2]);
    printf("\n---|---|---");
    printf("\n %c | %c | %c", board[2][0], board[2][1], board[2][2]);
}

int CheckFreeSpace()
{
    int FreeSpace = 9;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] != ' ')
            {
                FreeSpace--;
            }
        }
    }
    return FreeSpace;
}
void PlayerMove1()
{
    int x;
    int y;
    do
    {
        printf("\nEnter Row (1-3): ");
        scanf("%d", &x);
        x--;
        printf("Enter Col (1-3): ");
        scanf("%d", &y);
        y--;

        if (board[x][y] != ' ')
        {
            printf("Invalid Move!!!");
        }
        else
        {
            board[x][y] = PLAYER1;
            break;
        }
    } while (board[x][y] != ' ');
}

void PlayerMove2()
{
    int x;
    int y;
    do
    {
        printf("\nEnter Row (1-3): ");
        scanf("%d", &x);
        x--;
        printf("Enter Col (1-3): ");
        scanf("%d", &y);
        y--;

        if (board[x][y] != ' ')
        {
            printf("Invalid Move!!!");
        }
        else
        {
            board[x][y] = PLAYER2;
            break;
        }
    } while (board[x][y] != ' ');
}

void ComputerMove()
{
    // create a seed
    srand(time(0));
    int x;
    int y;
    if (CheckFreeSpace > 0)
    {
        do
        {
            x = rand() % 3;
            y = rand() % 3;
        } while (board[x][y] != ' ');

        board[x][y] = COMPUTER;
    }
    else
    {
        PrintWinner(' ');
    }
}

char CheckWinner()
{
    // check rows
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] == board[i][1] && board[i][0] == board[i][2])
        {
            return board[i][0];
        }
    }
    // check columns
    for (int i = 0; i < 3; i++)
    {
        if (board[0][i] == board[1][i] && board[0][i] == board[2][i])
        {
            return board[0][i];
        }
    }
    // check diagonal 1
    if (board[0][0] == board[1][1] && board[0][0] == board[2][2])
    {
        return board[0][0];
    }
    // check diagonal 2
    if (board[0][2] == board[1][1] && board[0][2] == board[2][0])
    {
        return board[0][2];
    }

    return ' ';
}

void PrintWinner(char winner)
{
    if (winner == PLAYER1)
    {
        printf("\n\nPLAYER1 WIN!!!");
    }
    else if (winner == COMPUTER)
    {
        printf("\n\nYou LOSE!!!");
    }
    else if (winner == PLAYER2)
    {
        printf("\n\nPLAYER2 WIN!!!");
    }
    else
    {
        printf("\n\nTIE!!!");
    }
}