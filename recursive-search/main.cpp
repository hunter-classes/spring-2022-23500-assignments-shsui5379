#include <iostream>
#include <iomanip>
#include <unistd.h>

void printBoard(int board[5][5]);
void solve(int board[5][5], int row, int column, int &lastMark);
bool solved(int board[5][5]);

int main()
{
   std::cout << "[2J;\n";
   int data[5][5];
   int num = 0;

   for (int i = 0; i < 5; i++)
      for (int j = 0; j < 5; j++)
         data[i][j] = 0;

   printBoard(data);
   solve(data, 0, 0, num);

   return 0;
}

void printBoard(int board[5][5])
{
   usleep(200000);
   std::cout << "[0;0H\n";

   std::cout << std::setw(2) << board[0][0];

   for (int i = 1; i < 5; i++)
      std::cout << "|" << std::setw(2) << board[0][i];

   std::cout << "\n---------------\n";

   for (int i = 1; i < 5; i++)
   {
      std::cout << std::setw(2) << board[i][0];

      for (int j = 1; j < 5; j++)
      {
         std::cout << "|" << std::setw(2) << board[i][j];
      }

      std::cout << "\n---------------\n";
   }
}

void solve(int board[5][5], int row, int column, int &lastMark)
{
   if (solved(board))
      exit(0);

   if (board[row][column] != 0 || row < 0 || column < 0 || row > 4 || column > 4)
      return;

   lastMark++;
   board[row][column] = lastMark;
   printBoard(board);

   solve(board, row - 2, column + 1, lastMark);
   solve(board, row - 1, column + 2, lastMark);
   solve(board, row + 1, column + 2, lastMark);
   solve(board, row + 2, column + 1, lastMark);
   solve(board, row + 2, column - 1, lastMark);
   solve(board, row + 1, column - 2, lastMark);
   solve(board, row - 1, column - 2, lastMark);
   solve(board, row - 2, column - 1, lastMark);

   lastMark--;
   board[row][column] = 0;
}

bool solved(int board[5][5])
{
   for (int i = 0; i < 5; i++)
      for (int j = 0; j < 5; j++)
         if (board[i][j] == 0)
            return false;

   return true;
}