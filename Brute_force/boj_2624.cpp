#include <iostream>
#include <algorithm>

using namespace std;

int coins[101][1002] = { 0, };
long long int dp[101][10001] = { 0, };

int dp_sum(int itr, int k)
{
    int sum = 0;
    for (int i = 1; i < itr; i++)
        sum += dp[i][k];

    return sum;
}

int main()
{
    int n, k, num_of_coins;
    cin >> k >> n;

    for (int i = 1; i <= n; i++)
    {
        scanf("%d %d", &coins[i][1], &num_of_coins);
        coins[i][0] = num_of_coins;
        for (int j = 2; j <= num_of_coins; j++)
            coins[i][j] = coins[i][1] * j;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            for (int coin_ix = 1; coin_ix <= coins[i][0]; coin_ix++)
            {
                if (j - coins[i][coin_ix] == 0)
                    dp[i][j] += 1;

                if (j - coins[i][coin_ix] > 0)
                    dp[i][j] += dp_sum(i, j - coins[i][coin_ix]);
            }
        }
    }
    
    cout << dp_sum(n + 1, k) << endl;

    return 0;
}
