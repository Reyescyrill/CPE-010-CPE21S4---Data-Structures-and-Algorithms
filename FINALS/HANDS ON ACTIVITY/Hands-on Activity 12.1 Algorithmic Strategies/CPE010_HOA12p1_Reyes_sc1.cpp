#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> memo;

int getMinSteps(int n) 
{
    if (n == 1) return 0;
    if (memo[n] != -1) return memo[n];

    int r = 1 + getMinSteps(n - 1);
    if (n % 2 == 0) r = min(r, 1 + getMinSteps(n / 2));
    if (n % 3 == 0) r = min(r, 1 + getMinSteps(n / 3));

    memo[n] = r;
    return r;
}

int main() 
{
    int n;
    cout << "Enter positive integer n: ";
    cin >> n;

    memo.assign(n + 1, -1);

    cout << "Minimum steps for n = " << n << " is: " << getMinSteps(n) << endl;

    return 0;
}