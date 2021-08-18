#include <iostream>
#include "funs.hpp"

using namespace std;

int main() {

    char grid[5][5];
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            grid[i][j] = '-';
        }
    }

    return 0;

}
