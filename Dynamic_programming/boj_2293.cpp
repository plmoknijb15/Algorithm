#include <iostream>

using namespace std;

int coins[101] = {0,};
int dp[10001] = {0,};

int main()
{
    int n, k;
    cin >> n >> k;

    for (int i = 1; i <= n; i++)
        scanf("%d", &coins[i]);

    dp[0] = 1;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= k; j++)
            if (j - coins[i] >= 0)
                dp[j] += dp[j - coins[i]];

    cout << dp[k] << endl;

    return 0;
}
