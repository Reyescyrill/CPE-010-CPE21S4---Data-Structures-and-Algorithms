#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

int countPathsDP(const vector<vector<int>>& mat, int m, int n, int cost, map<string, int>& memo) {
    if (m == 0 && n == 0) {
        return (mat[0][0] == cost) ? 1 : 0;
    }

    if (cost < 0) return 0;

    string key = to_string(m) + "," + to_string(n) + "," + to_string(cost);

    if (memo.find(key) != memo.end()) {
        return memo[key];
    }

    int totalPaths = 0;

    if (m == 0) {
        totalPaths = countPathsDP(mat, 0, n - 1, cost - mat[m][n], memo);
    } else if (n == 0) {
        totalPaths = countPathsDP(mat, m - 1, 0, cost - mat[m][n], memo);
    } else {
        totalPaths = countPathsDP(mat, m - 1, n, cost - mat[m][n], memo) +
                     countPathsDP(mat, m, n - 1, cost - mat[m][n], memo);
    }

    memo[key] = totalPaths;
    return memo[key];
}

int main() {
    vector<vector<int>> mat = {
        {4, 7, 1, 6},
        {6, 7, 3, 9},
        {3, 8, 1, 2},
        {7, 1, 7, 3}
    };

    int targetCost = 25;
    int M = mat.size();
    int N = mat[0].size();

    map<string, int> memo;
    int totalPaths = countPathsDP(mat, M - 1, N - 1, targetCost, memo);

    cout << "Matrix Size: " << M << "x" << N << endl;
    cout << "Target Cost: " << targetCost << endl;
    cout << "Total paths with cost " << targetCost << " : " << totalPaths << endl;

    return 0;
}