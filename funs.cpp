#include <iostream>
#include <vector>
using namespace std;

pair<bool, char> isWinner(std::vector<std::vector<char> >& grid, char aiMark, char hMark) {

  pair<bool, char> temp;
  temp.first = true;
  temp.second = '-';

    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            if(grid[i][j] != '-') {
	      temp.first = (temp.first && true);
	      
            } else {
	      temp.first = (temp.first && false);
	    }
        }
    }

    for (int j = 0; j < 2 ; j++ ){
        for (int i = 0; i < 2; i++){
            if (grid[i][j] == aiMark && grid[i][j+1] == aiMark && grid[i][j+2] == aiMark && grid[i][j+3] == aiMark){
                 temp.first = true;
		 temp.second = aiMark;
		 return temp;
            } else if (grid[i][j] == hMark && grid[i][j+1] == hMark && grid[i][j+2] == hMark && grid[i][j+3] == hMark) {
                 temp.first = true;
		 temp.second = hMark;
		 return temp;
            }           
        }
    }
    
    for (int i = 0; i < 2; i++ ){
        for (int j = 0; j < 2; j++){
           if (grid[i][j] == aiMark && grid[i+1][j] == aiMark && grid[i+2][j] == aiMark && grid[i+3][j] == aiMark){
                temp.first = true;
		 temp.second = aiMark;
		 return temp;
            } else if (grid[i][j] == hMark && grid[i+1][j] == hMark && grid[i+2][j] == hMark && grid[i+3][j] == hMark){
                 temp.first = true;
		 temp.second = hMark;
		 return temp;
            }           
        }
    }
     
    for (int i = 3; i < 5; i++){
        for (int j = 0; j < 2; j++){
            if (grid[i][j] == aiMark && grid[i-1][j+1] == aiMark && grid[i-2][j+2] == aiMark && grid[i-3][j+3] == aiMark) {
                temp.first = true;
		 temp.second = aiMark;
		 return temp;
            } else if (grid[i][j] == hMark && grid[i-1][j+1] == hMark && grid[i-2][j+2] == hMark && grid[i-3][j+3] == hMark) {
                 temp.first = true;
		 temp.second = hMark;
		 return temp;
            } 
                
        }
    }
    
    for (int i = 3; i < 5; i++){
        for (int j = 3; j < 5; j++){
            if (grid[i][j] == aiMark && grid[i-1][j-1] == aiMark && grid[i-2][j-2] == aiMark && grid[i-3][j-3] == aiMark) {
                temp.first = true;
		 temp.second = aiMark;
		 return temp;
            } else if (grid[i][j] == hMark && grid[i-1][j-1] == hMark && grid[i-2][j-2] == hMark && grid[i-3][j-3] == hMark) {
                 temp.first = true;
		 temp.second = hMark;
		 return temp;
            }
                
        }
    }
    return temp;
    

}


int minimax(std::vector<std::vector<char> >& grid, int depth, bool maxim, char aiMark, char hMark) {

    pair<bool, char> result = isWinner(grid, aiMark, hMark);
    
    if(result.first != false) {

        if(result.second == aiMark) {
            return depth;
        } else if (result.second == hMark) {
            return (depth * -1);
        } else {
	  return 0;
	}

        

    } else {

      

    if(maxim == true) {
        int best = INT_MIN;

        for(int i = 0; i < 5; i++) {
            for(int j = 0; j < 5; j++) {

                if(grid[i][j] == '-') {
		  
                    grid[i][j] = aiMark;
		    
                    int score = minimax(grid, depth - 1, !maxim, aiMark, hMark);
                    grid[i][j] = '-';

                    best = max(best, score);

                }

            }
        }
        

        return best;

    } else {
        int worst = INT_MAX;

        for(int i = 0; i < 5; i++) {
            for(int j = 0; j < 5; j++) {

                if(grid[i][j] == '-') {
                    grid[i][j] = hMark;
                    int score = minimax(grid, depth - 1, !maxim, aiMark, hMark);
                    grid[i][j] = '-';

                    worst = min(worst, score);
                }

            }
        }

        return worst;
    }
    }

    

}


void bestMove(std::vector<std::vector<char> >& grid,  char aiMark, char hMark) {

    int best = INT_MIN;
    int finalRow;
    int finalCol;

    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {

            if(grid[i][j] == '-') {
                grid[i][j] = aiMark;
                int score = minimax(grid, 25, true, aiMark, hMark);
                grid[i][j] = '-';

                if(score > best) {
                    best = score;
                    finalRow = i;
		    finalCol = j;
                }
                
            }

        }
    }

    grid[finalRow][finalCol] = aiMark;
    return;
    

}

