#include <iostream>
#include <vector>

using namespace std;

int d_row[] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int d_col[] = { 0, 1, 1, 1, 0, -1, -1, -1 };

void dfs(int row, int col, vector<vector<int>>& map, vector<vector<int>>& visited)
{
	visited[row][col] = 1;

	for (int i = 0; i < 8; i++)
	{
		if (map[row + d_row[i]][col + d_col[i]] && !visited[row + d_row[i]][col + d_col[i]])
			dfs(row + d_row[i], col + d_col[i], map, visited);
	}
}

int main()
{
	while (true)
	{
		vector<vector<int>> map(52, vector<int>(52, 0));
		vector<vector<int>> visited(52, vector<int>(52, 0));
		int row, col, graph_num = 0;

		cin >> col >> row;
		
		if (row == 0 && col == 0)
			break;

		for (int i = 1; i <= row; i++)
			for (int j = 1; j <= col; j++)
				cin >> map[i][j];

		for (int i = 1; i <= row; i++)
		{
			for (int j = 1; j <= col; j++)
			{
				if (map[i][j] && !visited[i][j])
				{
					dfs(i, j, map, visited);
					graph_num++;
				}
			}
		}

		cout << graph_num << endl;
	}

	return 0;
}
