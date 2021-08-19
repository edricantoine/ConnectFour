#include <iostream>
#include <vector>
#include "funs.hpp"

using namespace std;

int main() {

    char aiMark = 'X';
    char hMark = 'O';

    std::vector<std::vector<char> > grid(5, std::vector<char>(5, '-'));
  
  

    bool hasWinner = false;

    while(hasWinner == false) {

        pair<bool, char> result = isWinner(grid, aiMark, hMark);

	 cout << " ";

            for(int i = 0; i < 5; i++) {
	      cout <<  i << " ";
            }
            cout << endl;
            

            for(int i = 0; i < 5; i++) {
	      cout << i << " ";
                for(int j = 0; j < 5; j++) {
                  
                    cout << grid[i][j] << " ";
                    
                }
                cout << endl;
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

            cout << "Choose the row (0-indexed) to place your piece in.\n";
            cin >> playerR;

            cout << "Now, choose the column (0-indexed) to place your piece in.\n";
            cin >> playerC;

            if(playerR < 0 || playerR >= 5 || playerC < 0 || playerC >= 5||grid[playerR][playerC] != '-') {
                cout << "Invalid input detected.\n";
            } else {
                grid[playerR][playerC] = hMark;

		
                bestMove(grid, aiMark, hMark);
		
	        
            }

        }

    }

    return 0;

}
