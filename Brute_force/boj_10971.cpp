#include <iostream>
#include <vector>

using namespace std;

int N, MIN = 999999999;
int map[11][11] = {0, };
int visited[11] = {0, };
int start_point; 
vector<int> v;

void dfs(int from)
{	
	if (v.size() == N)
	{
		int sum = 0;
        for (int i = 0; i < N; i++)
			sum += v[i];
		if (sum < MIN)
            MIN = sum;

		return;
	}
	
	for (int i = 1; i <= N; i++)
	{
		if (v.size() != N-1 && i == start_point)
            return;
        
        if (!visited[i] && map[from][i] != 0)
		{
            visited[i] = 1;
			v.push_back(map[from][i]);
			dfs(i);
			v.pop_back();
			visited[i] = 0;
		}
	}
}

int main()
{
    cin >> N;
    
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            cin >> map[i][j];

    for (int i = 1; i <= N; i++)
    {
        start_point = i;
        dfs(i);
    }

    cout << MIN << endl;

    return 0;
}