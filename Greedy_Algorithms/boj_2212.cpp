#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n, k, result = 0;
    cin >> n >> k;

    if (n <= k)
        cout << 0 << endl;
    else
    {
        vector<int> v(n);
        vector<int> diff(n-1);

        for (int i = 0; i < n; i++)
            cin >> v[i];

        sort(v.begin(), v.end());

        for (int i = 0; i < n; i++)
            diff[i]  = v[i+1] - v[i];

        sort(diff.begin(), diff.end(), greater<int>() );

        for (int i = k-1; i < n-1; i++)
            result += diff[i];

        cout << result << endl;
    }

    return 0;
}