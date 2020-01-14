#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int d_row[] = { -1, 0, 1, 0 };
int d_col[] = { 0, 1, 0, -1 };
priority_queue<int, vector<int>, greater<int>> pq;
vector<vector<int>> map(27, vector<int>(27, 0));
vector<vector<int>> visited(27, vector<int>(27, 0));
int graph_num = 0;

void dfs(int row, int col, int& house_num)
{
	visited[row][col] = 1;
	house_num++;

	for (int i = 0; i < 4; i++)
	{
		if (map[row + d_row[i]][col + d_col[i]] && !visited[row + d_row[i]][col + d_col[i]])
			dfs(row + d_row[i], col + d_col[i], house_num);
	}
}

int main()
{	
	int n, house_num;
	cin >> n;

	for (int row = 1; row <= n; row++)
		for (int col = 1; col <= n; col++)
			scanf("%1d", &map[row][col]);

	for (int row = 1; row <= n; row++)
	{
		for (int col = 1; col <= n; col++)
		{
			if (map[row][col] && !visited[row][col])
			{
				house_num = 0;
				graph_num++;

				dfs(row, col, house_num);
				pq.push(house_num);
			}
		}
	}

	printf("%d\n", graph_num);
	for (int i = 0; i < graph_num; i++)
	{
		printf("%d\n", pq.top());
		pq.pop();
	}
		
	return 0;
}