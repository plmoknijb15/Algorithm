// N과 M (2)

#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<int> v;

void func(int cnt)
{
    if (cnt == m)
    {
        for (int i = 1; i < v.size(); i++)
            cout << v[i] << " ";
        cout << endl;
        return;
    }
    
    for (int i = 1; i <= n; i++)
    {
        if (v.back() < i)
        {
            v.push_back(i);
            func(cnt + 1);
            v.pop_back();
        }
    }
}

int main()
{
    cin >> n >> m;
    v.push_back(0);

    func(0);
        
    return 0;
}