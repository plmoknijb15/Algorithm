#include <iostream>
#include <vector>

using namespace std;

void dfs(int k, int previous_ix, int arr[], int visited[], vector<int> &v)
{
    if (v.size() == 6)
    {
        for (int i = 0; i < 6; i++)
            cout << v[i] << " ";
        cout << endl;

        return;
    }
    
    for (int i = previous_ix + 1; i <= k; i++)
    {
        if (!visited[i])
        {
            v.push_back(arr[i]);
            visited[i] = 1;
            dfs(k, i, arr, visited, v);
            v.pop_back();
            visited[i] = 0;
        }
    }    
}

int main()
{
    while (true)
    {
        int k, arr[13], visited[13] = {0, };
        vector<int> v;
        cin >> k;

        if (k == 0)
            break;

        for (int i = 1; i <= k; i++)
            cin >> arr[i];

        dfs(k, 0, arr, visited, v);
        cout << endl;
    }
    
    return 0;
}