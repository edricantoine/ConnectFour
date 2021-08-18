#include <iostream>
using namespace std;

void bestMove(int& grid[5][5], char aiMark, char hMark) {

    int best = INT_MIN;
    pair<int, int> finalSpot;

    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {

            if(grid[i][j] == '-') {
                grid[i][j] = aiMark;
                int score = minimax(grid, 25, true, aiMark);
                grid[i][j] = '-';

                if(score > best) {
                    best = score;
                    finalSpot = {i, j};
                }
                
            }

        }
    }

    board[finalSpot.first][finalSpot.second] = aiMark;
    return;

}

int minimax(int& grid[5][5], int depth, bool maxim, char aiMark, char hMark) {

    pair<bool, char> result = isWinner(grid, aiMark, hMark);
    if(result.first != false) {

        if(result.second == aiMark) {
            return depth;
        } else if (result.second == hMark) {
            return (depth * -1);
        } else {
            return 0;
        }

    }

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

pair<bool, char> isWinner(int grid[5][5], char aiMark, char hMark) {

    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            if(grid[i][j] == '-') {
                return {true, '-'};
            }
        }
    }

    for (int j = 0; j < 2 ; j++ ){
        for (int i = 0; i < 2; i++){
            if (grid[i][j] == aiMark && grid[i][j+1] == aiMark && grid[i][j+2] == aiMark && grid[i][j+3] == aiMark){
                return {true, aiMark};
            } else if (grid[i][j] == hMark && grid[i][j+1] == hMark && grid[i][j+2] == hMark && grid[i][j+3] == hMark) {
                return {true, hMark};
            }           
        }
    }
    
    for (int i = 0; i < 2; i++ ){
        for (int j = 0; j < 2; j++){
           if (grid[i][j] == aiMark && grid[i+1][j] == aiMark && grid[i+2][j] == aiMark && grid[i+3][j] == aiMark){
                return {true, aiMark};
            } else if (grid[i][j] == hMark && grid[i+1][j] == hMark && grid[i+2][j] == hMark && grid[i+3][j] == hMark){
                return {true, hMark};
            }           
        }
    }
     
    for (int i = 3; i < 5; i++){
        for (int j = 0; j < 2; j++){
            if (grid[i][j] == aiMark && grid[i-1][j+1] == aiMark && grid[i-2][j+2] == aiMark && grid[i-3][j+3] == aiMark) {
                return {true, aiMark};
            } else if (grid[i][j] == hMark && grid[i-1][j+1] == hMark && grid[i-2][j+2] == hMark && grid[i-3][j+3] == hMark) {
                return {true, hMark};
            } 
                
        }
    }
    
    for (int i = 3; i < 5; i++){
        for (int j = 3; j < 5; j++){
            if (grid[i][j] == aiMark && grid[i-1][j-1] == aiMark && grid[i-2][j-2] == aiMark && grid[i-3][j-3] == aiMark) {
                return {true, aiMark};
            } else if (grid[i][j] == hMark && grid[i-1][j-1] == hMark && grid[i-2][j-2] == hMark && grid[i-3][j-3] == hMark) {
                return {true, hMark};
            }
                
        }
    }
    return {false, '-'};

}