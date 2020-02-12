#include <iostream>

using namespace std;

long long int n, sum = 0;
long long int dp[101][10] = {0, };

int main()
{ 
    dp[1][1] = dp[1][2] = dp[1][3] = dp[1][4] = dp[1][5] = dp[1][6] = dp[1][7] = dp[1][8] = dp[1][9] = 1;

    cin >> n;

    for (int i = 2; i <= n; i++)
    {
        for (int j = 0; j <= 9; j++)
        {
            if (j == 0)
                dp[i][j] = dp[i-1][j+1];
            else if(j == 9)
                dp[i][j] = dp[i-1][j-1];
            else
                dp[i][j] = (dp[i-1][j-1] + dp[i-1][j+1]) % 1000000000;
        }
    }

    for (int i = 0; i <= 9; i++)
    {
        sum += dp[n][i];
        sum %= 1000000000;
    }
        
    cout << sum << endl;

    return 0;
}