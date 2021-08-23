#include <iostream>
#include <vector>
#include "funs.hpp"

using namespace std;

int main() {

    char aiMark = 'X';
    char hMark = 'O';

    std::vector<char> grid(9, '-');
    

    
   

    while(true) {

        pair<bool, char> result = isWinner(grid, aiMark, hMark);
        cout << "  0 1 2\n";
        int printRow = 0;
        for(int i = 0; i < 9; i+= 3) {
            cout << printRow << " " << grid[i] << " " << grid[i + 1] << " " << grid[i+2] << "\n";
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

            playerS = playerC + (3 * playerR);

            if(playerR < 0 || playerR >= 3 || playerC < 0 || playerC >= 3||grid[playerS] != '-') {
                cout << "Invalid input detected.\n";
            } else {
                
                grid[playerS] = hMark;

		
                bestMove(grid, aiMark, hMark);
		
		
	        
            }

        }

    }

    return 0;

}
