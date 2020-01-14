#include <iostream>
#include <vector>

using namespace std;

vector<int> graph[101];
int visited[101] = { 0, };
int graph_size = 0;

void DFS(int vertex)
{
	visited[vertex] = 1;
	graph_size += 1;

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

	DFS(1);
	cout << graph_size - 1 << endl;

	return 0;
}