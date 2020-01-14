#include <iostream>
#include <vector>

using namespace std;

vector<int> graph[1001];
int visited[1001] = { 0, };
int parent[1001] = { 0, };
int graph_num = 0, parent_node;

void DFS(int vertex)
{
	visited[vertex] = parent_node;

	for (int i = 0; i < graph[vertex].size(); i++)
	{
		if (!visited[graph[vertex][i]])
			DFS(graph[vertex][i]);
	}
}

int main()
{
	int vertex_num, edge_num, vertex_1, vertex_2;
	cin >> vertex_num >> edge_num;

	for (int i = 1; i <= edge_num; i++)
	{
		cin >> vertex_1 >> vertex_2;
		graph[vertex_1].push_back(vertex_2);
		graph[vertex_2].push_back(vertex_1);
	}

	for (int i = 1; i <= vertex_num; i++)
	{
		parent_node = i;
		if (!visited[i])
		{
			DFS(i);
			graph_num += 1;
		}

	}
	
	cout << graph_num << endl;

	return 0;
}