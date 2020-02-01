// N과 M (1)

#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<int> v;
int visited[9] = { 0, };

void dfs(int cnt)
{	
	if (cnt == m)
	{
		for (int i = 0; i < m; i++)
			printf("%d ", v[i]);
		printf("\n");
		return;
	}
	
	for (int i = 1; i <= n; i++)
	{
		if (!visited[i])
		{
			visited[i] = 1;
			v.push_back(i);
			dfs(cnt + 1);
			v.pop_back();
			visited[i] = 0;
		}
	}
}

int main()
{
	cin >> n >> m;
	dfs(0);
	
	return 0;
}	