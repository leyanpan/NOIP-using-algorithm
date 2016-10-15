#include <stdio.h>
#include <iostream>
#include <cmath>
using namespace std;
#define MAX 10010
#define FOR(i, N) for(int i = 0;i < N;++i)
int n, V, C, c[MAX], v[MAX];

int dp[MAX];
int main()
{
    ios::sync_with_stdio(false);
    cin >> V >> n >> C;
    FOR(i, n)
    {
	cin >> v[i] >> c[i];
    }
    FOR(i, n)
    {
	for(int j = C; j >= c[i];--j)
	{
	    int __t;
	    if(dp[j] < (__t = dp[j - c[i]] + v[i]))
	    {
		dp[j] = __t;
	    }
	}
    }
    int t;
    FOR(i, C + 1)
    {
	if(dp[i] >= V)
	{
	    cout << C - i << endl;
	    return 0;
	}
    }
    cout << "Impossible";
    return 0;
}
