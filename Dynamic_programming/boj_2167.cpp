#include <iostream>
#include <cstdio>

using namespace std;

int dp[301][301] = {0, };
int arr[301][301] = {0, }; 

int func(int n, int m)
{
    if (n == 0 || m == 0)
        return 0;

    if (dp[n][m])
        return dp[n][m];
    
    return dp[n][m] = arr[n][m] + func(n-1, m) + func(n, m-1) - func(n-1, m-1);
}

int main()
{
    int n, m, t;
    scanf("%d %d", &n, &m);

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            scanf("%d", &arr[i][j]);

    cin >> t;

    for (int k = 0; k < t; k++)
    {
        int x1, x2, y1, y2, result;
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        
        result = func(x2, y2) - func(x2, y1 - 1) - func(x1 - 1, y2) + func(x1 - 1, y1 - 1);
        printf("%d\n", result);
    }

    return 0;
}