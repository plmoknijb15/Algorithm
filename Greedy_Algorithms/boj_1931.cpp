#include <iostream>
#include <algorithm>

using namespace std;

pair<int, int> times[100001];

bool compare(pair<int, int> a, pair<int, int> b)
{
    if (a.second < b.second)
        return true;
    else if (a.second > b.second)
        return false;
    else // a.second == b.second
    {
        if (a.first < b.first)
            return true;
        else
            return false;
    }
}

int main()
{
    int n, prev_ix = 0, result = 0;
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
        scanf("%d %d", &times[i].first, &times[i].second);

    sort(times+1, times+n+1, compare);

    for (int i = 1; i <= n; i++)
    {
        if (times[prev_ix].second <= times[i].first)
        {
            result += 1;
            prev_ix = i;
        }
    }

    cout << result << endl;

    return 0;
}