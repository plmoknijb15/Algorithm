#include <iostream>

using namespace std;

long long int memo[91] = {0,};

long long int fibo(int n)
{
    if (n <= 1)
        return n;
    if (memo[n] != 0)
        return memo[n];

    return memo[n] = fibo(n-1) + fibo(n-2);
}

int main()
{
    int n;
    cin >> n;

    cout << fibo(n) << endl;

    return 0;
}