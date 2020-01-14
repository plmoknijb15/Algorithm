#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> g[101];

void bfs(int vertex, int& kevin_num)
{
	int count = 0;
	int visited[101] = { 0, };
	queue<int> q;
	q.push(vertex);

	while (!q.empty())
	{
		int q_size = q.size();

		for (int i = 0; i < q_size; i++)
		{
			vertex = q.front();
			q.pop();
			visited[vertex] = 1;

			for (int j = 0; j < g[vertex].size(); j++)
			{
				if (!visited[g[vertex][j]])
					q.push(g[vertex][j]);
			}

			kevin_num += count;
		}

		count++;
	}
}

int main()
{
	int vertex_num, edge_num, vertex_1, vertex_2;
	vector<int> kevin_num_arr;

	cin >> vertex_num >> edge_num;

	for (int i = 0; i < edge_num; i++)
	{
		cin >> vertex_1 >> vertex_2;
		
		g[vertex_1].push_back(vertex_2);
		g[vertex_2].push_back(vertex_1);
	}

	for (int i = 1; i <= vertex_num; i++)
	{
		int kevin_num = 0;
		
		bfs(i, kevin_num);
		kevin_num_arr.push_back(kevin_num);
	}

	cout << min_element(kevin_num_arr.begin(), kevin_num_arr.end()) - kevin_num_arr.begin() + 1 << endl;

	return 0;
}