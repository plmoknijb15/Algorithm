#include <iostream>
#include <algorithm>

using namespace std;

int ropes[100001];

int main()
{
    int n, next_max, prev_max = 0;
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
        scanf("%d", &ropes[i]);

    sort(ropes+1, ropes+n+1);

    for (int i = n; i >= 1; i--)
    {
        next_max = ropes[i] * (n - i + 1);
        
        if (next_max > prev_max)
            prev_max = next_max;
    }

    cout << prev_max << endl; 
    
    return 0;
}