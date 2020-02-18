// P(N) = P(N-1) + P(N-5) (N > 5)
#include <iostream>

using namespace std;

long long int dp[101] = {0,};

long long int func(int n)
{
    if (dp[n] != 0)
        return dp[n];

    return dp[n] = func(n - 1) + func(n - 5);
}

int main()
{
    dp[1] = dp[2] = dp[3] = 1;
    dp[4] = dp[5] = 2;

    int t, n;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        cin >> n;
        cout << func(n) << endl;
    }

    return 0;
}