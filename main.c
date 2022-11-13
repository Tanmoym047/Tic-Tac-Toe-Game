#include <stdio.h>
#include <time.h>
#include <ctype.h>
#include <stdlib.h>

char board[3][3];
const char PLAYER = 'X';
const char COMPUTER = 'O';


void ResetBoard();
void PrintBoard();
int CheckFreeSpace();
void PlayerMove();
void ComputerMove();
char CheckWinner();
void PrintWinner(char);


int main()
{
    char winner = ' ';

    ResetBoard();

    while(winner == ' ' && CheckFreeSpace() != 0)
    {
        PrintBoard();

        PlayerMove();
    }
    


    return 0;
}

void ResetBoard()
{
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
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
    printf("\n %c | %c | %c ", board[2][0], board[2][1], board[2][2]);
    
}
int CheckFreeSpace()
{
    int FreeSpace = 9;
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            if(board[i][j] != ' ')
            {
                FreeSpace --;
            }
        }
    }
    return FreeSpace;

}
void PlayerMove()
{
    

}
void ComputerMove()
{

}
char CheckWinner()
{

}
void PrintWinner(char)
{


}