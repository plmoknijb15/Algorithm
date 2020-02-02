#include <iostream>
#include <algorithm>

using namespace std;

int arr[1001] = {0,};
int check[1001] = {0,};

int main()
{
    int n, max;
    cin >> n;

    for (int i = 1; i <= n; i++)
        cin >> arr[i];

    for (int i = 1; i <= n; i++)
    {
        int max = 0;

        for (int j = i - 1; j >= 0; j--)
        {
            if (arr[j] < arr[i] && max < check[j] + 1)
                max = check[j] + 1;
        }

        check[i] = max;
    }

    cout << *max_element(check, check+n+1) << endl;

    return 0;
}