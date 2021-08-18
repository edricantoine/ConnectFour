#include <iostream>
using namespace std;

void bestMove(int& grid[5][5], char aiMark, char hMark);

int minimax(int& grid[5][5], int depth, bool maxim, char aiMark, char hMark);

pair<bool, char> isWinner(int grid[5][5], char aiMark, char hMark);