#include <iostream>

using namespace std;

int coins[11];

int main()
{
    int n, k, result = 0;
    cin >> n >> k;

    for (int i = 1; i <= n; i++)
        cin >> coins[i];

    for (int i = n; i >= 1; i--)
    {
        result += k/coins[i];
        k %= coins[i];
    }
    
    cout << result << endl;
    
    return 0;
}