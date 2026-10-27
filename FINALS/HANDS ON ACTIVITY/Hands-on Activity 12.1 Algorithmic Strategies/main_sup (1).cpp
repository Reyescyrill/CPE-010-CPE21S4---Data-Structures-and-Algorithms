#include <iostream>
using namespace std;

#define M 4
#define N 4

int countPaths(int mat[M][N], int i, int j, int cost) {
    if (i >= M || j >= N || cost < 0) {
        return 0;
    }

    if (i == M - 1 && j == N - 1) {
        return (cost == mat[i][j]) ? 1 : 0;
    }

    return countPaths(mat, i, j + 1, cost - mat[i][j]) +
           countPaths(mat, i + 1, j, cost - mat[i][j]);
}

int main() {
    int mat[M][N] = {
        {4, 7, 1, 6},
        {6, 7, 3, 9},
        {3, 8, 1, 2},
        {7, 1, 7, 3}
    };
    
    int cost = 25;
    cout << "Number of paths with cost " << cost << " is: " 
         << countPaths(mat, 0, 0, cost) << endl;

    return 0;
}