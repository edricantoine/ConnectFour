#include <iostream>
#include <vector>
#include "2funs.hpp"

using namespace std;

int main() {

    char aiMark = 'X';
    char hMark = 'O';
    bool goFirst = false;

    std::vector<char> grid(16, '-');

    bestMove(grid, aiMark, hMark);
   

    while(true) {

        pair<bool, char> result = isWinner(grid, aiMark, hMark);
        cout << "  0 1 2 3\n";
        int printRow = 0;
        for(int i = 0; i < 16; i+= 4) {
            cout << printRow << " " << grid[i] << " " << grid[i + 1] << " " << grid[i+2] << " " << grid[i+3] << "\n";
            printRow++;
        }

	 


        if(result.first != false) {


	        if(result.second == aiMark) {
                cout << "The computer wins!\n";
                return 0;
            } else if (result.second == hMark) {
                cout << "You win!\n";
                return 0;
            } else {
                cout << "Draw! Nobody wins.\n";
                return 0;
            }

        } else {

	 

            int playerR;
            int playerC;
            int playerS;

            cout << "Choose the row (0-indexed) to place your piece in.\n";
            cin >> playerR;

            cout << "Now, choose the column (0-indexed) to place your piece in.\n";
            cin >> playerC;

            playerS = playerC + (4 * playerR);

            if(playerR < 0 || playerR >= 4 || playerC < 0 || playerC >= 4||grid[playerS] != '-') {
                cout << "Invalid input detected.\n";
            } else {
                
                grid[playerS] = hMark;

		
                bestMove(grid, aiMark, hMark);
		
		
	        
            }

        }

    }

    return 0;

}
