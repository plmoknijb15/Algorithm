#include <iostream>

using namespace std;

int dp[16][16] = {0, };

int func(int n, int m)
{
    if (dp[n][m] != 0)
        return dp[n][m];
    else
        return dp[n][m] = func(n-1, m) + func(n, m-1);
}

int main()
{
    int n, m, k, des_n, des_m, x;
    cin >> n >> m >> k;

    for (int i = 1; i <= n; i++)
        dp[i][1] = 1;
    for (int i = 1; i <= m; i++)
        dp[1][i] = 1;

    if (k != 0)
    {
        int des_n = (k - 1)/m + 1;
        int des_m = (k%m != 0) ? k%m : m;

        x = func(des_n , des_m);

        for (int i = des_n; i <= n; i++)
            dp[i][des_m] = x;
        for (int i = des_m; i <= m; i++)
            dp[des_n][i] = x;
    }

    cout << func(n, m) << endl;

    return 0;
}