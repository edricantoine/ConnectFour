#include <iostream>
#include <vector>
using namespace std;

void bestMove(std::vector<char>& grid, char aiMark, char hMark);

int minimax(std::vector<char>& grid, int depth, bool maxim, char aiMark, char hMark, int al, int be);

pair<bool, char> isWinner(std::vector<char>& grid, char aiMark, char hMark);
