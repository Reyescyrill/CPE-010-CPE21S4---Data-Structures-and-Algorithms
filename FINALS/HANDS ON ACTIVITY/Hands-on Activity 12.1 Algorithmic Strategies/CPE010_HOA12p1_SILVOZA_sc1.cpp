#include <iostream>
#include <algorithm>

using namespace std;

int memo[1000];

int getMinSteps(int n)
{
    if ( n == 1 ) return 0;
    if( memo[n] != -1 ) return memo[n];
    int r = 1 + getMinSteps( n - 1 );
    if( n%2 == 0 ) r = min( r, 1 + getMinSteps( n / 2 ) ) ; 
    if( n%3 == 0 ) r = min( r, 1 + getMinSteps( n / 3 ) ) ; 
    memo[n] = r ; 
    return r;
}

int main()
{
    int n = 10;
    
    for (int i = 0; i <= n; i++) {
        memo[i] = -1;
    }
    
    cout << "Minimum steps for n = " << n << " (Memoization): " << getMinSteps(n) << endl;
    return 0;
}