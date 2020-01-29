// DFS와 BFS

#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

int adj[1001][1001] = {0,};

void bfs(int n, int m, int start_vertex)
{ 
	queue<int> q;
	vector<int> visited(n+1, 0);
	
	q.push(start_vertex);
	visited[start_vertex] = 1;

	while (!q.empty())
	{
		cout << q.front() << " ";
		for (int i = 1; i <= n; i++)
		{
			if (adj[q.front()][i] && !visited[i])
			{
				q.push(i);
				visited[i] = 1;
			}
		}
		q.pop();
	}
}

void dfs(int n, int m, int start_vertex)
{
	stack<int> s;
	vector<int> visited(n + 1, 0);

	cout << start_vertex << " ";
	s.push(start_vertex);
	visited[start_vertex] = 1;

	while (!s.empty())
	{
		for (int i = 1; i <= n; i++)
		{
			if (adj[s.top()][i] && !visited[i])
			{
				cout << i << " ";
				s.push(i);
				visited[i] = 1;
				i = 0;
			}
		}
		s.pop();
	}
}


int main()
{
	int n, m, start_vertex, to, from;
	
	cin >> n >> m >> start_vertex;

	for (int i = 0; i < m; i++)
	{
		cin >> to >> from;
		adj[to][from] = 1;
		adj[from][to] = 1;
	}

	dfs(n, m, start_vertex);
	cout << endl;
	bfs(n, m, start_vertex);

	return 0;
}